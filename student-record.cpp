#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Student
{ // per row
    int id;
    string name;
    int age;
    float grade;
    string status;
};

vector<Student> students;

void addStudent(vector<Student> &students);
void displayStudents(vector<Student> &students);
void averageGrade(vector<Student> &students);
void deleteStudent(vector<Student> &students);
void searchStudent(vector<Student> &students);
void editStudent(vector<Student> &students);

// Clear screen function 
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else 
        system("clear");
    #endif
}

int main()
{
    cout << "======STUDENT RECORD====== \n"
         << endl;
    while (true)
    {
        cout << "1. Add Student \n2. Display all students \n3. Average grade \n4. Delete Student \n5. Search Student \n6. Edit Student \n7. Exit \n"
             << endl;
        cout << "Select an option: ";
        int option;
        cin >> option;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input must be an integer. Please try again." << endl;
            continue;
        }

        clearScreen();

        switch (option)
        {
        case 1:
            addStudent(students);
            break;
        case 2:
            displayStudents(students);
            break;
        case 3:
            averageGrade(students);
            break;
        case 4:
            deleteStudent(students);
            break;
        case 5:
            searchStudent(students);
        break;
        case 6:
            editStudent(students);
        break;
        case 7:
            cout << "System exit." << endl;
            std::exit(0);
            break;
        }
        cout << endl;
    }
}

int nextID = 1;

void addStudent(vector<Student> &students)
{
    Student student;
    cout << "ADD STUDENT \n"
         << endl;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, student.name);

    cout << "Enter age: ";
    cin >> student.age;

    cout << "Enter grade: ";
    cin >> student.grade;

    student.id = nextID++;
    student.status = (student.grade >= 70 ? "Passed" : "Failed");
    students.push_back(student);
}

void displayStudents(vector<Student> &students)
{
    if (students.empty())
    {
        cout << "Students list is empty." << endl;
        return;
    }

    cout << "STUDENTS LIST \n"
         << endl;
    cout << left
         << setw(5) << "ID"
         << setw(25) << "Name"
         << setw(10) << "Age"
         << setw(10) << "Grade" 
         << setw(15) << "Status" << endl;
    for (int i = 0; i < students.size(); i++)
        cout << setw(5) << students[i].id
             << setw(25) << students[i].name
             << setw(10) << students[i].age
             << setw(10) << students[i].grade 
             << setw(15) << students[i].status << endl;

    {
    }
}

void averageGrade(vector<Student> &students)
{
    if (students.empty())
    {
        cout << "Students list is empty. No grade to compute." << endl;
        return;
    }

    cout << "AVERAGE GRADE \n"
         << endl;
    int sum = 0;
    float average = 0;

    for (auto s : students)
    {
        sum += s.grade;
    }

    average = (float)sum / students.size();
    cout << "Average: " << average << endl;
}

void deleteStudent(vector<Student> &students)
{
    if (students.empty())
    {
        cout << "Students list is empty." << endl;
        return;
    }
    cout << "DELETE STUDENT \n"
         << endl;
    int select_id;
    cout << "Enter student ID: ";
    cin >> select_id;

    for (auto it = students.begin(); it != students.end(); it++)
    {
        if (it->id == select_id)
        {
            students.erase(it);
            cout << "Student deleted.\n";
            return;
        }
    }
    cout << "Student no found. \n";
}

void searchStudent(vector<Student> &students) {
    if (students.empty()) {
        cout << "Students list is empty." << endl;
        return;
    }
    
    cout << "SEARCH STUDENT \n" << endl;
    int search_id;
    cout << "Enter student ID: ";
    cin >> search_id;

    for (auto it = students.begin(); it != students.end(); it++) {
        if (it->id == search_id) {
            cout << "Name: " << it->name << " | Age: " << it->age << " |  Grade: " << it->grade << " |  Status: " << it->status << endl;
            return;
        }
    }
}

void editStudent(vector<Student> &students) {
    Student s;
    if (students.empty()) {
        cout << "Students list is empty." << endl;
        return;
    }
    
    cout << "EDIT STUDENT \n" << endl;
    int search_id;
    cout << "Enter student ID: ";
    cin >> search_id;

    for (auto it = students.begin(); it != students.end(); it++) {
        if (it->id == search_id) {
            cout << "Enter name: ";
            string new_name;
            cin.ignore();
            getline(cin, new_name);

            cout << "Enter age: ";
            int new_age;
            cin >> new_age;

            cout << "Enter grade: ";
            int new_grade;
            cin >> new_grade;

            cout << endl;

            it->name = new_name;
            it->age = new_age;
            it->grade = new_grade;
            
            it->status = (new_grade >= 70 ? "Passed" : "Failed");
            return;
        }
    }
}