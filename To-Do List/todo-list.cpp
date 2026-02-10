#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <limits>

class Task
{
private:
    int id;
    std::string description;
    bool done;

public:
    Task(int id, std::string desc) : id(id), description(desc), done(false) {}

    // Getters
    int getId() const { return id; }
    std::string getDescription() const { return description; }
    bool isDone() const { return done; }

    // Setters
    void setDescription(const std::string &desc) { description = desc; }
    void markDone() { done = true; }
};

void showMenu()
{
    std::cout << "\n To-Do List System \n"
              << std::endl;

    std::cout << "1. Add Task \n2. Display Tasks \n3. Mark Task \n4. Delete Task \n5. Edit Task \n6. Search Task \n7. Exit\n " << std::endl;
    std::cout << "Select an option: ";
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Prototypes for menu functions
void addTask(std::vector<Task> &tasks, int &next_id);
void displayTask(const std::vector<Task> &tasks);
void markTaskDone(std::vector<Task> &tasks);
void deleteTask(std::vector<Task> &tasks);
void editTask(std::vector<Task> &tasks);
void searchTask(const std::vector<Task> &tasks);
void systemExit();

int main()
{
    std::vector<Task> tasks;
    int next_id = 1;
    int choice;
    

    while (true)
    {
        showMenu();
        if(!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        clearScreen();

        switch (choice)
        {
        case 1: addTask(tasks, next_id); break;
        case 2: displayTask(tasks); break;
        case 3: markTaskDone(tasks); break;
        case 4: deleteTask(tasks); break;
        case 5: editTask(tasks); break;
        case 6: searchTask(tasks); break;
        case 7: systemExit(); break;
        default: 
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Input must be an integer. Please try again. " << std::endl;
                continue;
        break;
        }
    }
}

void addTask(std::vector<Task> &tasks, int &next_id)
{
    std::cout << "\n Add Task \n"
              << std::endl;

    std::string desc;
    std::cin.ignore();
    std::cout << "Enter description: ";
    std::getline(std::cin, desc);

    Task t(next_id, desc);
    tasks.push_back(t);
    next_id++;
}

void displayTask(const std::vector<Task> &tasks) {
    std::cout << "\n Display Task \n"
              << std::endl;

    if (tasks.empty()) {
        std::cout << "No tasks available." << std::endl;
        return;
    }
    for (const auto& t : tasks) {
        std::cout << t.getId() << ": "
                  << t.getDescription()
                  << " | Done: " << (t.isDone() ? "Yes" : "No")
                 << std::endl;
    }
}

void markTaskDone(std::vector<Task> &tasks) {
    std::cout << "\n Mark your task done! \n"
              << std::endl;

    if (tasks.empty()) {
        std::cout << "No tasks available." << std::endl;
        return;
    }

    std::cout << "Task ID: ";
    int id;
    std::cin >> id;

    for (auto &t : tasks) {
        if (t.getId() == id) {
            t.markDone();
            std::cout << "Task marked done." << std::endl;
            return;
        }
    }
    
    std::cout << "Task ID not found!" << std::endl;
}

void deleteTask(std::vector<Task> &tasks) {
    std::cout << "\n Delete Task \n"
              << std::endl;

    if (tasks.empty()) {
        std::cout << "No tasks available." << std::endl;
        return;
    }

    std::cout << "Task ID: ";
    int id;
    std::cin >> id;

    for (auto it = tasks.begin(); it < tasks.end(); it++) {
        if (it->getId() == id) {
            tasks.erase(it);
            std::cout << "Task deleted!" << std::endl;
            return;
        }
    }
    
    std::cout << "ID not found!" << std::endl;
}

void editTask(std::vector<Task> &tasks) {
    std::cout << "\n Edit Task \n" << std::endl;

    if (tasks.empty())  {
        std::cout << "No tasks available." << std::endl;
        return;
    }
    
    std::cout << "Task ID to edit: ";
    int id;
    std::cin >> id;

    for (auto it = tasks.begin(); it < tasks.end(); it++) {
        if (it->getId() == id) {
            std::cout << "Task Description: ";
            std::string desc;
            std::cin.ignore();
            std::getline(std::cin, desc);
            it->setDescription(desc);
            return;
        }
    }
    
    std::cout << "No task found!" << std::endl;
}

void searchTask(const std::vector<Task> &tasks) {
    std::cout << "\n Search Task \n" << std::endl;
    
    if (tasks.empty()) {
        std:: cout << "No task available." << std::endl;
        return;
    }
    
    std::cout << "Task ID to search: ";
    int id;
    std::cin >> id;

    for (auto it = tasks.begin(); it < tasks.end(); it++) {
        if (it->getId() == id) {
            std::cout << " \nID: " << it->getId() << "\n" << "Description: " << it->getDescription() << "\n" << "Done: " << (it->isDone() ? "Yes" : "No") << "\n" << std::endl; 
            return;
        }
    }
    
    std::cout << "ID not found!" << std::endl;
}

void systemExit() {
    std::cout << "System exit." << std::endl;
    std::exit(0);
}