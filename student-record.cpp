#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

struct Student
{ // per row
    string name;
    int age;
    float grade;
};

vector<Student> students;

void addStudent(vector<Student> &students);
void displayStudents(vector<Student> &students);
void averageGrade(vector<Student> &students);

int main()
{
    while (true)
    {
        cout << "======STUDENT RECORD====== \n"
             << endl;
        cout << "1. Add Student \n2. Display all students \n3. Average grade \n4. Exit \n"
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

        cout << endl;

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
        }
    }
}

void addStudent(vector<Student> &students)
{
    Student student;
    cout << "ADD STUDENT \n"
         << endl;
    cout << "Enter name: ";
    cin >> student.name;

    cout << "Enter age: ";
    cin >> student.age;

    cout << "Enter grade: ";
    cin >> student.grade;

    students.push_back(student);
}

void displayStudents(vector<Student> &students)
{
    cout << "STUDENTS LIST \n"
         << endl;
    for (int i = 0; i < students.size(); i++)
    {
        cout << i + 1 << ". " << students[i].name << " | " << students[i].age << " | " << students[i].grade << endl;
    }
}

void averageGrade(vector<Student> &students)
{
    Student s;
    cout << "AVERAGE GRADE \n"
         << endl;
    int sum = 0;
    float average = 0;

    for (auto s : students) {
        sum += s.grade;
    }

    average = (float)sum / students.size();
    cout << "Average: " << average << endl;
}