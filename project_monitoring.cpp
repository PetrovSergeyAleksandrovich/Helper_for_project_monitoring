#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

int main()
{
    //Init info
    std::cout << "=====PROJECTS_LIST=====" << std::endl;
    setlocale(LC_ALL, "Rus");

    //Variables
    std::string file_location = R"(C:\Users\Poizone\Projects_Monitoring\projects.txt)";
    std::string command = "none";
    char buffer[2];
    std::string text_to_add;

    //Read file contains
    std::ifstream file_read(file_location, std::ios::binary);
    while (!file_read.eof())
    {
        file_read.read(buffer, sizeof(buffer) - 1);
        buffer[file_read.gcount()] = 0;
        std::cout << buffer;
    }
    file_read.close();

    //User input new project info
    std::cout << std::endl << "\nВведите текст / Input text: ";
    SetConsoleCP(1251);
    std::getline(std::cin, text_to_add);
    SetConsoleOutputCP(1251);
    std::cout << "\nТекст для добавления / Your text to add: " << text_to_add << std::endl;

    //Check and confirm input from user
    std::cout << "\nНажмите 1 подтвердить. 0 для повторного ввода\nPress 1 to confirm. Press 0 to repeat input: ";
    std::getline(std::cin, command);
    while (command != "1")
    {
        SetConsoleOutputCP(1251);
        //User input new project info
        text_to_add.clear();
        if (text_to_add.empty())
        {
            std::cout << "\nВведите текст снова / Input text again: ";
            SetConsoleCP(1251);
            std::getline(std::cin, text_to_add);
            std::cout << "\nТекст для добавления / Text to add: " << text_to_add << std::endl;
        }

        std::cout << "\nНажмите 1 подтвердить. 0 для повторного ввода\nPress 1 to confirm. Press 0 to repeat input: ";
        std::getline(std::cin, command);
        if (command == "1") break;

    }

    //Add new text to file
    if (!text_to_add.empty())
    {
        std::ofstream file_write(file_location, std::ios::app);
        file_write << std::endl << text_to_add;
        file_write.close();

        //Read file contains
        std::cout << std::endl << std::endl << "=====PROJECTS_LIST_NEW=====" << std::endl;
        file_read.open(file_location, std::ios::binary);
        while (!file_read.eof())
        {
            file_read.read(buffer, sizeof(buffer) - 1);
            buffer[file_read.gcount()] = 0;
            std::cout << buffer;
        }
        file_read.close();
        std::cout << std::endl << std::endl << std::endl;
        SetConsoleOutputCP(1251);
        std::cout << "Информация успешно добавлена в файл\Information successfully added to file" << std::endl << std::endl;
    }
    else
    {
        std::cout << "\n\n===Пустая запись/Empty record===\n\n";
    }

    return 0;
}

