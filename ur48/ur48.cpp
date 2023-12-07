
#include <iostream>
#include "list.h"

int main() {
    setlocale(LC_ALL, "Ukr");
    TaskList taskList;

    int choice;
    do {
        std::cout << "1. Додати справу\n";
        std::cout << "2. Видалити справу\n";
        std::cout << "3. Редагувати справу\n";
        std::cout << "4. Пошук справ\n";
        std::cout << "5. Відобразити список справ\n";
        std::cout << "0. Вийти\n";
        std::cout << "Оберіть опцію: ";
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
            std::cout << "Дякую за використання!\n";
            break;
        default:
            std::cout << "Неправильний вибір. Спробуйте ще раз.\n";
        }

    } while (choice != 0);

    return 0;
}
