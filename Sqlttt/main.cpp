#include <mysql_connection.h>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <iostream>
#include <cppconn/connection.h>
#include <cppconn/driver.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_driver.h>

#include <iostream>
#include <string>

int main() {
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    std::string hostName = "mysql.students.it-college.ru";
    std::string userName = "i22s0997";
    std::string password = "vWkkYUdP";
    std::string databaseName = "i22s0997";
    std::string tableName1 = "User2";
    std::string tableName2 = "Currency";

    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect(hostName, userName, password);

        // Select the database
        con->setSchema(databaseName);

        // Prompt user for inputs
        std::string name, surname, phone, email;
        std::cout << "Enter Name: ";
        std::cin >> name;
        std::cout << "Enter Surname: ";
        std::cin >> surname;
        std::cout << "Enter Phone: ";
        std::cin >> phone;
        std::cout << "Enter Email: ";
        std::cin >> email;

        // Insert data into User2 table
        sql::PreparedStatement* pstmt1 = con->prepareStatement("INSERT INTO " + tableName1 + " (Name, Surname, Phone, Email) VALUES (?, ?, ?, ?)");
        pstmt1->setString(1, name);
        pstmt1->setString(2, surname);
        pstmt1->setString(3, phone);
        pstmt1->setString(4, email);
        pstmt1->executeUpdate();
        delete pstmt1;

        // Insert data into Currency table
        sql::PreparedStatement* pstmt2 = con->prepareStatement("INSERT INTO " + tableName2 + " (Name2) SELECT Name FROM " + tableName1 + " WHERE Name = ?");
        pstmt2->setString(1, name);
        pstmt2->executeUpdate();
        delete pstmt2;

        std::cout << "Data inserted successfully." << std::endl;
    }
    catch (sql::SQLException& e) {
        std::cout << "SQL Exception: " << e.what() << std::endl;
    }

    delete con;
    return 0;
}








       
//
//    case 2:
//        try {
//            driver = sql::mysql::get_mysql_driver_instance();
//            con = driver->connect(hostName, userName, password);
//
//            // Select the database
//            con->setSchema(databaseName);
//
//            // Prompt user for student ID
//            int studentId;
//            std::cout << "Enter Student ID: ";
//            std::cin >> studentId;
//
//            // Prompt user for Name and Surname inputs
//            std::string name, surname;
//            std::cout << "Enter New Name: ";
//            std::cin >> name;
//            std::cout << "Enter New Surname: ";
//            std::cin >> surname;
//
//            // Prepare the SQL statement to update student's Name and Surname
//            std::string sqlStatement = "UPDATE " + tableName + " SET Name=?, Surname=? WHERE studentid=?";
//            sql::PreparedStatement* preparedStatement = con->prepareStatement(sqlStatement);
//            preparedStatement->setString(1, name);
//            preparedStatement->setString(2, surname);
//            preparedStatement->setInt(3, studentId);
//
//            // Execute the SQL statement
//            preparedStatement->executeUpdate();
//
//            std::cout << "Student information updated successfully!" << std::endl;
//
//            delete preparedStatement;
//            delete con;
//        }
//        catch (sql::SQLException& e) {
//            std::cout << "SQL Exception: " << e.what() << std::endl;
//        }
//
//        return 0;
//
//
//    case 3:
//        try {
//            // Создаем экземпляр драйвера MySQL
//            sql::mysql::MySQL_Driver* driver;
//            driver = sql::mysql::get_mysql_driver_instance();
//
//            // Устанавливаем соединение с базой данных
//
//            sql::Connection* con;
//            con = driver->connect(hostName, userName, password);
//            con->setSchema(databaseName);
//
//            // Запрашиваем у пользователя ID студента для удаления
//            int studentId;
//            std::cout << "Введите ID студента для удаления: ";
//            std::cin >> studentId;
//
//            // Готовим SQL-запрос на удаление
//            std::string tableName = "Hello3";
//            std::string sqlStatement = "DELETE FROM " + tableName + " WHERE studentid=?";
//            sql::PreparedStatement* preparedStatement;
//            preparedStatement = con->prepareStatement(sqlStatement);
//            preparedStatement->setInt(1, studentId);
//
//            // Выполняем SQL-запрос на удаление
//            preparedStatement->executeUpdate();
//
//            // Отображаем сообщение об успешном удалении
//            std::cout << "Студент успешно удален!" << std::endl;
//
//            // Освобождаем ресурсы
//            delete preparedStatement;
//            delete con;
//        }
//        catch (sql::SQLException& e) {
//            std::cout << "SQL Exception: " << e.what() << std::endl;
//        }
//
//    case 4:
//        try
//        {
//            driver = sql::mysql::get_mysql_driver_instance();
//            con = driver->connect(hostName, userName, password);
//            con->setSchema(databaseName);
//            int n = 0;
//            std::string h;
//
//            std::cout << "Enter Disciplineid: ";
//            std::cin >> n;
//
//            std::cout << "Enter Name: ";
//            std::cin >> h;
//
//            sql::Statement* stmt;
//            stmt = con->createStatement();
//            std::string query = "INSERT INTO Discipline (Disciplineid, Name) VALUES (" + std::to_string(n) + ", '" + h + "')";
//            stmt->execute(query);
//
//            delete stmt;
//            delete con;
//        }
//        catch (sql::SQLException& e)
//        {
//            std::cout << "SQL Exception: " << e.what() << std::endl;
//        }
//
//    case 5:
//        driver = sql::mysql::get_mysql_driver_instance();
//        con = driver->connect(hostName, userName, password);
//        con->setSchema(databaseName);
//
//        // Выполнение SQL запроса для обновления значений
//        
//
//        
//        delete con;
//        
//        
//
//    }
//
//}