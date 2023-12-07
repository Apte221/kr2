// list.h

#ifndef LIST_H
#define LIST_H

#include "task.h"
#include <cstring>
#include <iostream>

struct TaskList {
    Task tasks[100];
    int taskCount;

    TaskList();

    void addTask();
    void removeTask();
    void editTask();
    void searchTasks();
    void displayTasks();

private:
    void displayTask(int index);
};

TaskList::TaskList() : taskCount(0) {}

void TaskList::addTask() {
    if (taskCount < 100) {
        Task newTask;
        std::cout << "Назва справи: ";
        std::cin.ignore();
        std::cin.getline(newTask.title, sizeof(newTask.title));
        std::cout << "Пріоритет: ";
        std::cin >> newTask.priority;
        std::cout << "Опис: ";
        std::cin.ignore();
        std::cin.getline(newTask.description, sizeof(newTask.description));
        std::cout << "Дата та час виконання: ";
        std::cin.getline(newTask.dateTime, sizeof(newTask.dateTime));

        tasks[taskCount++] = newTask;
        std::cout << "Справа успішно додана!\n";
    }
    else {
        std::cout << "Список справ заповнений. Видаліть деякі справи перед додаванням нових.\n";
    }
}

void TaskList::removeTask() {
    if (taskCount > 0) {
        int taskIndex;
        std::cout << "Введіть номер справи, яку ви хочете видалити: ";
        std::cin >> taskIndex;

        if (taskIndex >= 1 && taskIndex <= taskCount) {
            // Переміщення справ у масиві
            for (int i = taskIndex - 1; i < taskCount - 1; ++i) {
                tasks[i] = tasks[i + 1];
            }

            --taskCount;
            std::cout << "Справа успішно видалена!\n";
        }
        else {
            std::cout << "Неправильний номер справи.\n";
        }
    }
    else {
        std::cout << "Список справ порожній.\n";
    }
}

void TaskList::editTask() {
    if (taskCount > 0) {
        int taskIndex;
        std::cout << "Введіть номер справи, яку ви хочете редагувати: ";
        std::cin >> taskIndex;

        if (taskIndex >= 1 && taskIndex <= taskCount) {
            Task& task = tasks[taskIndex - 1];
            std::cout << "Нова назва справи: ";
            std::cin.ignore();
            std::cin.getline(task.title, sizeof(task.title));
            std::cout << "Новий пріоритет: ";
            std::cin >> task.priority;
            std::cout << "Новий опис: ";
            std::cin.ignore();
            std::cin.getline(task.description, sizeof(task.description));
            std::cout << "Нова дата та час виконання: ";
            std::cin.getline(task.dateTime, sizeof(task.dateTime));

            std::cout << "Справа успішно відредагована!\n";
        }
        else {
            std::cout << "Неправильний номер справи.\n";
        }
    }
    else {
        std::cout << "Список справ порожній.\n";
    }
}

void TaskList::searchTasks() {
    int searchOption;
    std::cout << "Оберіть критерій пошуку:\n";
    std::cout << "1. Назва\n";
    std::cout << "2. Пріоритет\n";
    std::cout << "3. Опис\n";
    std::cout << "4. Дата та час виконання\n";
    std::cout << "Ваш вибір: ";
    std::cin >> searchOption;

    switch (searchOption) {
    case 1: {
        char searchTitle[50];
        std::cout << "Введіть назву справи для пошуку: ";
        std::cin.ignore();
        std::cin.getline(searchTitle, sizeof(searchTitle));

        for (int i = 0; i < taskCount; ++i) {
            if (strcmp(tasks[i].title, searchTitle) == 0) {
                displayTask(i);
            }
        }
        break;
    }
    case 2: {
        char searchPriority;
        std::cout << "Введіть пріоритет для пошуку: ";
        std::cin >> searchPriority;

        for (int i = 0; i < taskCount; ++i) {
            if (tasks[i].priority == searchPriority) {
                displayTask(i);
            }
        }
        break;
    }
    case 3: {
        char searchDescription[100];
        std::cout << "Введіть опис справи для пошуку: ";
        std::cin.ignore();
        std::cin.getline(searchDescription, sizeof(searchDescription));

        for (int i = 0; i < taskCount; ++i) {
            if (strcmp(tasks[i].description, searchDescription) == 0) {
                displayTask(i);
            }
        }
        break;
    }
    case 4: {
        char searchDateTime[20];
        std::cout << "Введіть дату та час для пошуку: ";
        std::cin.ignore();
        std::cin.getline(searchDateTime, sizeof(searchDateTime));

        for (int i = 0; i < taskCount; ++i) {
            if (strcmp(tasks[i].dateTime, searchDateTime) == 0) {
                displayTask(i);
            }
        }
        break;
    }
    default:
        std::cout << "Неправильний вибір.\n";
    }
}

void TaskList::displayTasks() {
    if (taskCount > 0) {
        std::cout << "Список справ:\n";
        for (int i = 0; i < taskCount; ++i) {
            displayTask(i);
        }
    }
    else {
        std::cout << "Список справ порожній.\n";
    }
}

void TaskList::displayTask(int index) {
    std::cout << "Справа " << index + 1 << ":\n";
    std::cout << "Назва: " << tasks[index].title << '\n';
    std::cout << "Пріоритет: " << tasks[index].priority << '\n';
    std::cout << "Опис: " << tasks[index].description << '\n';
    std::cout << "Дата та час виконання: " << tasks[index].dateTime << '\n';
    std::cout << "------------------------\n";
}

#endif // LIST_H
