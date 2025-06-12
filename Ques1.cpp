/*
 * Ques1.cpp
 *Q1. Create a class called Student with the following private data members:
1. name (string): to store the name of the student.
2. rollNumber (int): to store the roll number of the student.
3. marks (float): to store the marks obtained by the student.
4. grade (char): to store the grade calculated based on the marks.
Implement getter and setter member functions for each data member
Create a member function calculateGrade() that calculates the grade based on the following
grading scale:
A: 90-100
B: 80-89
C: 70-79
D: 60-69
F: Below 60
Implement a menu-driven program in the main() function with the following options:
1. Accept Information
2. Display information
3. Calculate Grade
4. Exit the program.
 *
 */
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    float marks;
    char grade;

public:
    char getGrade() {
        return grade;
    }

    void setGrade(char grade) {
        this->grade = grade;
    }

    float getMarks() {
        return marks;
    }

    void setMarks(float marks) {
        this->marks = marks;
    }

    const string& getName() {
        return name;
    }

    void setName(const string &name) {
        this->name = name;
    }

    int getRollNumber() {
        return rollNumber;
    }

    void setRollNumber(int rollNumber) {
        this->rollNumber = rollNumber;
    }

    void calculateGrade() {
        if (marks >= 90 && marks <= 100) {
            grade = 'A';
        } else if (marks >= 80) {
            grade = 'B';
        } else if (marks >= 70) {
            grade = 'C';
        } else if (marks >= 60) {
            grade = 'D';
        } else {
            grade = 'F';
        }
    }

    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks: " << marks << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main() {
    Student s;
    int choice;

    do {
        cout << "\n----- Student Menu ------\n";
        cout << "1. Accept Information\n";
        cout << "2. Display Information\n";
        cout << "3. Calculate Grade\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            int roll;
            float marks;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter roll number: ";
            cin >> roll;
            cout << "Enter marks: ";
            cin >> marks;

            s.setName(name);
            s.setRollNumber(roll);
            s.setMarks(marks);
            break;
        }
        case 2:
            s.displayInfo();
            break;
        case 3:
            s.calculateGrade();
            cout << "Grade calculated successfully.\n";
            break;
        case 4:
            cout << "Exiting Program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
