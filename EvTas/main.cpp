#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>

int main() {
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    std::string hostName = "mysql.students.it-college.ru";
    std::string userName = "i22s0997";
    std::string password = "vWkkYUdP";
    std::string databaseName = "i22s0997";
    std::string tableName = "Hello3";

    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect(hostName, userName, password);
    con->setSchema(databaseName);

    int choice = 0;

    std::cout << "1) Put student" << std::endl;
    std::cout << "2) Change Name or Surname" << std::endl;
    std::cout << "3) Delete student" << std::endl;
    std::cout << "4) disciplin" << std::endl;
    std::cout << "5) score" << std::endl;

    // Дальнейший код для выполнения выбранного действия

    delete con;
    return 0;
}