#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>

class Book {
private:
    std::string title;
    std::string author;
    bool available;

public:
    Book(std::string t, std::string a) 
        : title(t), author(a), available(true) {}
    
    // Getters
    std::string getTitle() const {return title;}
    std::string getAuthor() const {return author;}
    bool isAvailable() const {
        return available;
    }

    void borrowBook() {
        if (available == true) {
            available = false;
            std::cout << "You borrowed the book.\n" << std::endl;
        }
        
        std::cout << "The book is unavailable.\n" << std::endl;
    }

    void returnBook() {
        if (available == true) {
            std::cout << "You dont have a book to return.\n" << std::endl;
            return;
        }
        
        available = true;
        std::cout << "You returned the book.\n" << std::endl;
    }

    void showDetails() {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "Available: " << (available ? "Yes" : "No") << std::endl;
    }
};

class Library {
private:
    std::vector<Book> books;

public:
    void addBook();
    void showBooks();
    void loadBooks();
};

void Library::addBook() {
    std::cout << "\nAdd a book\n" << std::endl;
    std::string title, author;
    
    std::cout << "Book name: ";
    std::cin.ignore(1000, '\n');
    std::getline(std::cin >> std::ws, title);
    
    std::cout << "Author name: ";
    std::getline(std::cin >> std::ws, author);
    
    std::fstream outFile("books.txt", std::ios::app);
    

    if (!outFile) {
        std::cout << "Couldn't save.\n" << std::endl;
        return;
    }
    
    Book book(title, author);
    books.push_back(book);
    outFile << book.getTitle() << "|" << book.getAuthor() << "|" << (book.isAvailable() ? "Available" : "Not Available") << "\n";
}

void Library::showBooks() {
    if (books.empty()) {
        std::cout << "Library is empty.\n" << std::endl;
        return;
    }

    for (int i = 0; i < books.size(); i++) {
        std::cout << "\n[" << i << "]\n";
        books[i].showDetails();
    }
}

void Library::loadBooks() {
    std::ifstream file("books.txt");
    if (!file.is_open()) {
        return;
    }
    
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);

        std::string title, author, availableStr;
        
        std::getline(ss, title, '|');
        std::getline(ss, author, '|');
        std::getline(ss, availableStr, '|');

        bool available = (availableStr == "Available");

        Book book(title, author);
        if (!available) {
            book.borrowBook();
        }
        
        books.push_back(book);
    }
}

void showMenu() {
    std::cout << "\nMENU\n" << std::endl;
    std::cout << "1. Add a book \n2. Borrow a book \n3. Return book \n4. Show Books \n5. Exit" << std::endl;
}

int main() {
    std::cout << "Library System\n" << std::endl;
    int select_option;

    Library library;
    library.loadBooks();
    while (select_option != 5) {
        showMenu();
        std::cout << "\nSelect an option: ";
        std::cin >> select_option;

        #ifdef _WIN32
            system("cls");
        #else 
            system("clear");
        #endif
        
        switch (select_option) {
            case 1: library.addBook(); break;
            case 4: library.showBooks(); break;
        }
    }
}
