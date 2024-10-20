#include <iostream>
#include <vector>
#include <limits> // For std::numeric_limits

using namespace std;

void AddTask(vector<string>& tasks);
void RemoveTask(vector<string>& tasks);
void CompleteTask(vector<string>& tasks);
void DisplayTask(const vector<string>& tasks);

int main() {
    int choice;
    vector<string> tasks;

    do {
        cout << "\nTo-Do List Menu: \n";
        string options[5] = {"Add Task", "Remove Task", "Complete Task", "Display Tasks", "Exit"};
        for (int i = 0; i < 5; i++) {
            cout << i + 1 << ". " << options[i] << endl;
        }
        cout << "Enter your choice: ";
        
        // Input validation
        while (!(cin >> choice) || choice < 1 || choice > 5) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid choice. Please enter a number between 1 and 5: ";
        }

        switch (choice) {
            case 1: AddTask(tasks); break;
            case 2: RemoveTask(tasks); break;
            case 3: CompleteTask(tasks); break;
            case 4: DisplayTask(tasks); break;
            case 5: cout << "Exiting...\n"; break;
        }

    } while (choice != 5);

    return 0;
}

void AddTask(vector<string>& tasks) {
    string in_task;
    cout << "Enter task description: ";
    cin.ignore(); // Clear newline character left by previous input
    getline(cin, in_task); // Use getline to allow spaces in task description
    tasks.push_back(in_task);
    cout << "Task added\n";
}

void RemoveTask(vector<string>& tasks) {
    int index;
    cout << "Enter the index of the task to remove: ";
    cin >> index;

    // Check if index is valid
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
        cout << "Task removed.\n";
    } else {
        cout << "Invalid index.\n";
    }
}

void CompleteTask(vector<string>& tasks) {
    int index;
    cout << "Enter the index of the task to mark as completed: ";
    cin >> index;

    // Check if index is valid
    if (index >= 0 && index < tasks.size()) {
        tasks[index] += " (completed)";
        cout << "Task marked as completed.\n";
    } else {
        cout << "Invalid index.\n";
    }
}

void DisplayTask(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i << ". " << tasks[i] << "\n";
    }
}
