/*
 * Ques__4.cpp
 *
 *  Q4. You are tasked with creating an Employee Payroll Management System in C++. Your
program should allow the user to perform the following tasks through a menu-driven
interface:
1. Add a new employee: - Create a class Employee with the following private data members: - int empID (Employee ID) - string empName (Employee Name) - double empSalary (Employee Salary) - Include appropriate getter and setter methods for these data members. - Ensure that the Employee ID is unique for each employee.
2. Calculate the gross salary for an employee: - Create a member function calculateGrossSalary in the Employee class. - The gross salary should be calculated based on the following rules: - If the employee's salary is less than or equal to 5000, add a 10% bonus. - If the employee's salary is greater than 5000 but less than or equal to 10000, add a
15% bonus. - If the employee's salary is greater than 10000, add a 20% bonus. - Display the gross salary for the chosen employee.
3. Display the employee details: - Create a member function displayEmployeeDetails in the Employee class to display
all the details of an employee (ID, Name, Salary, and Gross Salary).
4. Update employee information: - Allow the user to update the employee's name and salary using setter methods.
5. Exit the program.
 */

#include <iostream>
#include <vector>
using namespace std;

class Employee {
private:
    int empID;
    string empName;
    double empSalary;

public:
    // Constructor
    Employee(int id, string name, double salary) {
        empID = id;
        empName = name;
        empSalary = salary;
    }

    // Getter methods
    int getEmpID() const {
        return empID;
    }

    string getEmpName() const {
        return empName;
    }

    double getEmpSalary() const {
        return empSalary;
    }

    // Setter methods
    void setEmpName(string name) {
        empName = name;
    }

    void setEmpSalary(double salary) {
        empSalary = salary;
    }

    // Calculate gross salary based on rules
    double calculateGrossSalary() const {
        double bonus = 0.0;

        if (empSalary <= 5000) {
            bonus = empSalary * 0.10;
        } else if (empSalary <= 10000) {
            bonus = empSalary * 0.15;
        } else {
            bonus = empSalary * 0.20;
        }

        return empSalary + bonus;
    }

    // Display employee details
    void displayEmployeeDetails() const {
        cout << "\n--- Employee Details ---\n";
        cout << "Employee ID     : " << empID << endl;
        cout << "Employee Name   : " << empName << endl;
        cout << "Basic Salary    : ₹" << empSalary << endl;
        cout << "Gross Salary    : ₹" << calculateGrossSalary() << endl;
    }
};

// Function to find an employee by ID in the list
Employee* findEmployeeByID(vector<Employee>& employees, int id) {
    for (auto& emp : employees) {
        if (emp.getEmpID() == id)
            return &emp;
    }
    return nullptr;
}

int main() {
    vector<Employee> employees;
    int choice;

    do {
        cout << "\n==== Employee Payroll Menu ====\n";
        cout << "1. Add New Employee\n";
        cout << "2. Calculate Gross Salary\n";
        cout << "3. Display Employee Details\n";
        cout << "4. Update Employee Info\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                string name;
                double salary;

                cout << "Enter Employee ID: ";
                cin >> id;

                // Check uniqueness of ID
                if (findEmployeeByID(employees, id)) {
                    cout << "Employee ID already exists. Try a different ID.\n";
                    break;
                }

                cin.ignore(); // To ignore leftover newline
                cout << "Enter Employee Name: ";
                getline(cin, name);
                cout << "Enter Employee Salary: ₹";
                cin >> salary;

                employees.emplace_back(id, name, salary);
                cout << "Employee added successfully.\n";
                break;
            }

            case 2: {
                int id;
                cout << "Enter Employee ID to calculate gross salary: ";
                cin >> id;

                Employee* emp = findEmployeeByID(employees, id);
                if (emp) {
                    cout << "Gross Salary: ₹" << emp->calculateGrossSalary() << endl;
                } else {
                    cout << "Employee not found.\n";
                }
                break;
            }

            case 3: {
                int id;
                cout << "Enter Employee ID to display details: ";
                cin >> id;

                Employee* emp = findEmployeeByID(employees, id);
                if (emp) {
                    emp->displayEmployeeDetails();
                } else {
                    cout << "Employee not found.\n";
                }
                break;
            }

            case 4: {
                int id;
                cout << "Enter Employee ID to update: ";
                cin >> id;

                Employee* emp = findEmployeeByID(employees, id);
                if (emp) {
                    string newName;
                    double newSalary;

                    cin.ignore();
                    cout << "Enter new name: ";
                    getline(cin, newName);
                    cout << "Enter new salary: ₹";
                    cin >> newSalary;

                    emp->setEmpName(newName);
                    emp->setEmpSalary(newSalary);
                    cout << "Employee updated successfully.\n";
                } else {
                    cout << "Employee not found.\n";
                }
                break;
            }

            case 5:
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}



