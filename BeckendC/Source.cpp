#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/beast.hpp>

using tcp = boost::asio::ip::tcp;
namespace http = boost::beast::http;

int main() {
    try {
        // �������� io_context ��� ���������� ������������ ���������� �����-������
        boost::asio::io_context io_context;

        // �������� resolver ��� ���������� DNS � ��������� IP-������ �������
        tcp::resolver resolver(io_context);

        // ���������� DNS � ��������� IP-������ �������
        auto endpoints = resolver.resolve("portal.students.it-college.ru", "http");

        // �������� ������
        tcp::socket socket(io_context);

        // ��������� ���������� � ��������
        boost::asio::connect(socket, endpoints);

        // ������������ �������
        http::request<http::empty_body> request{ http::verb::get, "/api/w3t1/20", 11 };
        request.set(http::field::host, "portal.students.it-college.ru");
        request.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
        request.set("Stud-ID", "i22so997");

        // �������� �������
        http::write(socket, request);

        // ��������� ������
        boost::beast::flat_buffer buffer;
        http::response<http::dynamic_body> response;
        http::read(socket, buffer, response);

        // ����� ������ �� �����
        std::cout << "Response: " << response << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
