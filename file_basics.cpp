#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::cout << "Enter name: "; 
    std::string name;
    std::getline(std::cin, name);
    
    // write file 
    std::ofstream outFile("name.txt");

    if (!outFile) {
        std::cout << "Couldn't write the file. \n";
        return 1;
    }

    outFile << "Welcome back, " << name << "\n";
    outFile.close();

    // read file
    std::ifstream inFile("name.txt");

    if (!inFile) {
        std::cout << "Couldn't read file. \n";
        return 1;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::cout << line << std::endl;
    }
    inFile.close();
}