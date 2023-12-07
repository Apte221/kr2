
#include <iostream>
#include "list.h"

int main() {
    setlocale(LC_ALL, "Ukr");
    TaskList taskList;

    int choice;
    do {
        std::cout << "1. ������ ������\n";
        std::cout << "2. �������� ������\n";
        std::cout << "3. ���������� ������\n";
        std::cout << "4. ����� �����\n";
        std::cout << "5. ³��������� ������ �����\n";
        std::cout << "0. �����\n";
        std::cout << "������ �����: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            taskList.addTask();
            break;
        case 2:
            taskList.removeTask();
            break;
        case 3:
            taskList.editTask();
            break;
        case 4:
            taskList.searchTasks();
            break;
        case 5:
            taskList.displayTasks();
            break;
        case 0:
            std::cout << "����� �� ������������!\n";
            break;
        default:
            std::cout << "������������ ����. ��������� �� ���.\n";
        }

    } while (choice != 0);

    return 0;
}
