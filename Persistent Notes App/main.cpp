#include <iostream>
#include <limits>
#include <fstream>
#include <string>
#include <vector>

class Notes {
private:
    int id;
    std::string text;

public:
    Notes(int id, std::string text) : id(id), text(text) {}

    // Declare Getters
    int getId() const {return id;}
    std::string getText() const {return text;}

    // Declare Setters
    void setText(const std::string &setText) {text = setText;}
};

void showMenu() {
    std::cout << "\nMENU \n" << std::endl;

    std::cout << "1. Add a note \n2. List all notes \n3. Delete a note \n4. Save notes to file \n5. Load notes from file \n6. Exit \n" << std::endl;
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else 
        system("clear");
    #endif
}

// Create Prototypes
void addNote(std::vector<Notes> &notes, int &next_id);
void displayAllNotes(const std::vector<Notes> &notes);

int main() {
    // Initialize a vector 
    std::vector<Notes> notes;

    std::cout << "\nPersistent Notes App \n" << std::endl;
    int select_option, next_id = 1;

    while (select_option != 6) {
        showMenu();
        std::cout << "Select an option: ";
        if (!(std::cin >> select_option)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        clearScreen();
        std::cout << std::endl;

        switch (select_option) {
            case 1: addNote(notes, next_id); break;
            case 2: displayAllNotes(notes); break;
            case 3: break;
            case 4: break;
            case 5: break;
        }
    }
    
    std::cout << "System exit." << std::endl;
    return 0;
}

void addNote(std::vector<Notes> &notes, int &next_id) {
    std::cout << "\nAdd a note \n" << std::endl;
    std::string text;
    
    char repeat;
    while (repeat != 'n') {
        std::cout << "Enter note: ";
        std::cin.ignore();
        std::getline(std::cin, text);

        Notes n(next_id, text);
        notes.push_back(n);

        next_id++;

        std::cout << std::endl;
        
        std::cout << "Would you like to add a note again? [Y / N]: ";
        std::cin >> repeat;
        std::cout << std::endl;
    }
}

void displayAllNotes(const std::vector<Notes> &notes) {
    std::cout << "\nDisplay all notes \n" << std::endl;
    
    if (notes.empty()) {
        std::cout << "Your notes are empty. \n" << std::endl;
        return;
    }
    
    for (const auto&t : notes) {
        std::cout << t.getId() << ". " << t.getText() << std::endl;
    }
}