#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/beast.hpp>

using tcp = boost::asio::ip::tcp;
namespace http = boost::beast::http;

int main() {
    try {
        // Создание io_context для управления асинхронными операциями ввода-вывода
        boost::asio::io_context io_context;

        // Создание resolver для разрешения DNS и получения IP-адреса сервера
        tcp::resolver resolver(io_context);

        // Разрешение DNS и получение IP-адреса сервера
        auto endpoints = resolver.resolve("portal.students.it-college.ru", "http");

        // Создание сокета
        tcp::socket socket(io_context);

        // Установка соединения с сервером
        boost::asio::connect(socket, endpoints);

        // Формирование запроса
        http::request<http::empty_body> request{ http::verb::get, "/api/w3t1/20", 11 };
        request.set(http::field::host, "portal.students.it-college.ru");
        request.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
        request.set("Stud-ID", "i22so997");

        // Отправка запроса
        http::write(socket, request);

        // Получение ответа
        boost::beast::flat_buffer buffer;
        http::response<http::dynamic_body> response;
        http::read(socket, buffer, response);

        // Вывод ответа на экран
        std::cout << "Response: " << response << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
