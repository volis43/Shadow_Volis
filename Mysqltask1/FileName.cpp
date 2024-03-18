#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <iostream>

int main() {
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;

    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "username", "password"); // �������� username � password �� ���� ������� ������

    if (con) {
        std::cout << "Connected to MySQL database!" << std::endl;

        sql::Statement* stmt;
        stmt = con->createStatement();
        sql::ResultSet* res;
        res = stmt->executeQuery("SELECT * FROM your_table"); // �������� your_table �� ��� ����� �������

        while (res->next()) {
            std::cout << "Column1: " << res->getString(1) << ", Column2: " << res->getString(2) << std::endl; // �������� 1 � 2 �� ������� ��������, ������� �� ������ �������
        }

        delete res;
        delete stmt;
        delete con;
    }
    else {
        std::cerr << "Failed to connect to MySQL database" << std::endl;
    }

    return 0;
}