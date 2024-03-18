#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <iostream>

int main() {
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;

    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "username", "password"); // Замените username и password на ваши учетные данные

    if (con) {
        std::cout << "Connected to MySQL database!" << std::endl;

        sql::Statement* stmt;
        stmt = con->createStatement();
        sql::ResultSet* res;
        res = stmt->executeQuery("SELECT * FROM your_table"); // Замените your_table на имя вашей таблицы

        while (res->next()) {
            std::cout << "Column1: " << res->getString(1) << ", Column2: " << res->getString(2) << std::endl; // Замените 1 и 2 на индексы столбцов, которые вы хотите вывести
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