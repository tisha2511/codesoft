#include <iostream>
#include <string>

using namespace std;

class ToDo {
    string tasks[100];
    bool completed[100];  // Parallel array to store task status
    int taskCount = 0;

public:
    void addTask() {
        if (taskCount >= 100) {
            cout << "Task list is full!\n";
            return;
        }

        cout << "Enter task: ";
        cin.ignore();
        getline(cin, tasks[taskCount]);
        completed[taskCount] = false; // default: pending
        taskCount++;

        cout << "Task added successfully.\n";
    }

    void viewTasks() {
        if (taskCount == 0) {
            cout << "No tasks available.\n";
            return;
        }

        cout << "\nYour To-Do List:\n";
        for (int i = 0; i < taskCount; ++i) {
            cout << i + 1 << ". " << tasks[i]
                 << " [" << (completed[i] ? "Completed" : "Pending") << "]\n";
        }
    }

    void deleteTask() {
        if (taskCount == 0) {
            cout << "No tasks to delete.\n";
            return;
        }

        viewTasks();
        cout << "\nEnter task number to delete: ";
        int num;
        cin >> num;

        if (num < 1 || num > taskCount) {
            cout << "Invalid task number.\n";
            return;
        }

        for (int i = num - 1; i < taskCount - 1; ++i) {
            tasks[i] = tasks[i + 1];
            completed[i] = completed[i + 1];
        }

        taskCount--;
        cout << "Task deleted successfully.\n";
    }

    void markCompleted() {
        if (taskCount == 0) {
            cout << "No tasks to mark as completed.\n";
            return;
        }

        viewTasks();
        cout << "\nEnter task number to mark as completed: ";
        int num;
        cin >> num;

        if (num < 1 || num > taskCount) {
            cout << "Invalid task number.\n";
            return;
        }

        if (completed[num - 1]) {
            cout << "Task is already completed.\n";
        } else {
            completed[num - 1] = true;
            cout << "Task marked as completed.\n";
        }
    }
};

int main() {
    ToDo todo;
    int choice;

    do {
        cout << "\n===== TO-DO LIST MENU =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Delete Task\n";
        cout << "4. Mark Task as Completed\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: todo.addTask(); break;
        case 2: todo.viewTasks(); break;
        case 3: todo.deleteTask(); break;
        case 4: todo.markCompleted(); break;
        case 5: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
