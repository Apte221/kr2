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
        std::cout << "����� ������: ";
        std::cin.ignore();
        std::cin.getline(newTask.title, sizeof(newTask.title));
        std::cout << "��������: ";
        std::cin >> newTask.priority;
        std::cout << "����: ";
        std::cin.ignore();
        std::cin.getline(newTask.description, sizeof(newTask.description));
        std::cout << "���� �� ��� ���������: ";
        std::cin.getline(newTask.dateTime, sizeof(newTask.dateTime));

        tasks[taskCount++] = newTask;
        std::cout << "������ ������ ������!\n";
    }
    else {
        std::cout << "������ ����� ����������. ������� ���� ������ ����� ���������� �����.\n";
    }
}

void TaskList::removeTask() {
    if (taskCount > 0) {
        int taskIndex;
        std::cout << "������ ����� ������, ��� �� ������ ��������: ";
        std::cin >> taskIndex;

        if (taskIndex >= 1 && taskIndex <= taskCount) {
            // ���������� ����� � �����
            for (int i = taskIndex - 1; i < taskCount - 1; ++i) {
                tasks[i] = tasks[i + 1];
            }

            --taskCount;
            std::cout << "������ ������ ��������!\n";
        }
        else {
            std::cout << "������������ ����� ������.\n";
        }
    }
    else {
        std::cout << "������ ����� �������.\n";
    }
}

void TaskList::editTask() {
    if (taskCount > 0) {
        int taskIndex;
        std::cout << "������ ����� ������, ��� �� ������ ����������: ";
        std::cin >> taskIndex;

        if (taskIndex >= 1 && taskIndex <= taskCount) {
            Task& task = tasks[taskIndex - 1];
            std::cout << "���� ����� ������: ";
            std::cin.ignore();
            std::cin.getline(task.title, sizeof(task.title));
            std::cout << "����� ��������: ";
            std::cin >> task.priority;
            std::cout << "����� ����: ";
            std::cin.ignore();
            std::cin.getline(task.description, sizeof(task.description));
            std::cout << "���� ���� �� ��� ���������: ";
            std::cin.getline(task.dateTime, sizeof(task.dateTime));

            std::cout << "������ ������ ������������!\n";
        }
        else {
            std::cout << "������������ ����� ������.\n";
        }
    }
    else {
        std::cout << "������ ����� �������.\n";
    }
}

void TaskList::searchTasks() {
    int searchOption;
    std::cout << "������ ������� ������:\n";
    std::cout << "1. �����\n";
    std::cout << "2. ��������\n";
    std::cout << "3. ����\n";
    std::cout << "4. ���� �� ��� ���������\n";
    std::cout << "��� ����: ";
    std::cin >> searchOption;

    switch (searchOption) {
    case 1: {
        char searchTitle[50];
        std::cout << "������ ����� ������ ��� ������: ";
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
        std::cout << "������ �������� ��� ������: ";
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
        std::cout << "������ ���� ������ ��� ������: ";
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
        std::cout << "������ ���� �� ��� ��� ������: ";
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
        std::cout << "������������ ����.\n";
    }
}

void TaskList::displayTasks() {
    if (taskCount > 0) {
        std::cout << "������ �����:\n";
        for (int i = 0; i < taskCount; ++i) {
            displayTask(i);
        }
    }
    else {
        std::cout << "������ ����� �������.\n";
    }
}

void TaskList::displayTask(int index) {
    std::cout << "������ " << index + 1 << ":\n";
    std::cout << "�����: " << tasks[index].title << '\n';
    std::cout << "��������: " << tasks[index].priority << '\n';
    std::cout << "����: " << tasks[index].description << '\n';
    std::cout << "���� �� ��� ���������: " << tasks[index].dateTime << '\n';
    std::cout << "------------------------\n";
}

#endif // LIST_H
