#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

void print_projects_list()
{
    std::string file_location = "projects.txt";
    char buffer[2];
    std::ifstream file_read;
    file_read.open(file_location, std::ios::binary);
    while (!file_read.is_open())
    {
        std::cout << "\nType path to file:";
        std::getline(std::cin, file_location);
        file_read.open(file_location, std::ios::binary);
    }
    while (!file_read.eof())
    {
        file_read.read(buffer, sizeof(buffer) - 1);
        buffer[file_read.gcount()] = 0;
        std::cout << buffer;
    }
    file_read.close();
}

int main()
{
    //Init info
    std::cout << "=====PROJECTS_LIST=====" << std::endl << std::endl;
    setlocale(LC_ALL, "Rus");
    //Variables
    std::string command = "none";
    std::string text_to_add;

    //Read file contains
    print_projects_list();

    //User input new project info
    std::cout << std::endl << "\nType project number and discription: ";
    SetConsoleCP(1251);
    std::getline(std::cin, text_to_add);
    SetConsoleCP(866);
    std::cout << "\nYour text to add: ";
    //SetConsoleOutputCP(1251);
    std::cout << text_to_add << std::endl;
    SetConsoleOutputCP(866);

    //Check and confirm input from user
    std::cout << "\nPress 1 to confirm. 0 to type again: ";
    std::getline(std::cin, command);
    while (command != "1")
    {
        //User input new project info
        text_to_add.clear();
        if (text_to_add.empty())
        {
            std::cout << "\nType project number and discription: ";
            SetConsoleCP(1251);
            std::getline(std::cin, text_to_add);
            SetConsoleCP(866);
            std::cout << "\nYour text to add: " << text_to_add << std::endl;
            SetConsoleOutputCP(866);
        }
        std::cout << "\nPress 1 to confirm. 0 to type again: ";
        std::getline(std::cin, command);
        if (command == "1") break;
    }

    //Add new text to file
    if (!text_to_add.empty())
    {
        std::string file_location = "projects.txt";
        std::ofstream file_write(file_location, std::ios::app);
        SetConsoleOutputCP(1251);
        file_write << std::endl << text_to_add;
        SetConsoleOutputCP(866);
        file_write.close();

        //Read file contains
        print_projects_list();

        std::cout << std::endl << std::endl;
        std::cout << "Information successfully added to file" << std::endl;
    }
    else
    {
        std::cout << "\n\n===Empty record===\n\n";
    }

    std::cout << "\n\n===Made in Russia / Design Systems LLC / www.dsys.ru===\n\n";
    std::cin.get();
    return 0;
}

