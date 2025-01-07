#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Structure to hold employee details
class Employee {
	private:
    	int id;
    	string name;
    	string department;
    	double salary;
    public:
    	void displayMenu();
    	void insertRecord();
    	void searchRecord();
    	void editRecord();
    	void deleteRecord();
    	void displayRecords();
    	void salarySlip();
    	void searchDepartment();
};

vector<Employee> employees;

// Function to insert a new employee record
void Employee :: insertRecord() {
//	system("cls");
    Employee emp;
    cout << "\nEnter Employee ID: ";
    cin >> emp.id;
    cout << "Enter Employee Name: ";
    cin.ignore();
    getline(cin, emp.name);
    cout << "Enter Department: ";
    getline(cin, emp.department);
    cout << "Enter Salary: ";
    cin >> emp.salary;
    employees.push_back(emp);
    cout << "\nRecord Added Successfully!\n";
    system("pause");
}

// Function to search for an employee by ID
void Employee :: searchRecord() {
//	system("cls");
    int id;
    cout << "\nEnter Employee ID to Search: ";
    cin >> id;
    for (size_t i = 0; i < employees.size(); i++) {
        if (employees[i].id == id) {
            cout << "\nEmployee Found:\n";
            cout << "ID: " << employees[i].id << "\nName: " << employees[i].name << "\nDepartment: " << employees[i].department << "\nSalary: " << employees[i].salary << "\n";
            system("pause");
			return;
        }
    }
    cout << "\nEmployee Not Found!\n";
    system("pause");
}

// Function to edit an existing employee record
void Employee :: editRecord() {
//	system("cls");
    int id;
    cout << "\nEnter Employee ID to Edit: ";
    cin >> id;
    for (size_t i = 0; i < employees.size(); i++) {
        if (employees[i].id == id) {
            cout << "\nEditing Record for Employee ID: " << id << "\n";
            cout << "Enter New Name: ";
            cin.ignore();
            getline(cin, employees[i].name);
            cout << "Enter New Department: ";
            getline(cin, employees[i].department);
            cout << "Enter New Salary: ";
            cin >> employees[i].salary;
            cout << "\nRecord Updated Successfully!\n";
            system("pause");
            return;
        }
    }
    cout << "\nEmployee Not Found!\n";
    system("pause");
}

// Function to delete an employee record by ID
void Employee :: deleteRecord() {
//	system("cls");
    int id;
    cout << "\nEnter Employee ID to Delete: ";
    cin >> id;
    for (size_t i = 0; i < employees.size(); i++) {
        if (employees[i].id == id) {
            employees.erase(employees.begin() + i);
            cout << "\nRecord Deleted Successfully!\n";
            system("pause");
            return;
        }
    }
    cout << "\nEmployee Not Found!\n";
    system("pause");
}

// Function to display all employee records
void Employee :: displayRecords() {
//	system("cls");
    if (employees.empty()) {
        cout << "\nNo Records Found!\n";
        system("pause");
        return;
    }
    cout << "\n\nEmployee Records:\n";
    cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(20) << "Department" << setw(10) << "Salary" << "\n";
    cout << string(60, '=') << "\n";
    for (size_t i = 0; i < employees.size(); i++) {
        cout << left << setw(10) << employees[i].id << setw(20) << employees[i].name << setw(20) << employees[i].department << setw(10) << employees[i].salary << "\n";
    }
    system("pause");
}

// Function to generate a salary slip for an employee
void Employee :: salarySlip() {
//	system("cls");
    int id;
    cout << "\nEnter Employee ID for Salary Slip: ";
    cin >> id;
    for (size_t i = 0; i < employees.size(); i++) {
        if (employees[i].id == id) {
            cout << "\nSalary Slip:\n";
            cout << "============================\n";
            cout << "Employee ID: " << employees[i].id << "\n";
            cout << "Name: " << employees[i].name << "\n";
            cout << "Department: " << employees[i].department << "\n";
            cout << "Salary: " << employees[i].salary << "\n";
            cout << "============================\n";
            system("pause");
            return;
        }
    }
    cout << "\nEmployee Not Found!\n";
    system("pause");
}

// Function to search employees by department
void Employee :: searchDepartment() {
//	system("cls");
    string dept;
    cout << "\nEnter Department to Search: ";
    cin.ignore();
    getline(cin, dept);
    bool found = false;
    cout << "\nEmployees in Department: " << dept << "\n";
    cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(20) << "Department" << setw(10) << "Salary" << "\n";
    cout << string(60, '=') << "\n";
    for (size_t i = 0; i < employees.size(); i++) {
        if (employees[i].department == dept) {
            found = true;
            cout << left << setw(10) << employees[i].id << setw(20) << employees[i].name << setw(20) << employees[i].department << setw(10) << employees[i].salary << "\n";
        }
    }
    if (!found) cout << "No Employees Found in This Department!\n";
    system("pause");
}

void Employee :: displayMenu() {
        int choice;
        do {
        	system("cls");
            cout << "\n\n\t\t\t=========================";
            cout << "\n\n\t\t\t EMPLOYEE CONTROL PANEL";
            cout << "\n\n\t\t\t=========================";
            cout << "\n\n\n 1. INSERT RECORD";
            cout << "\n 2. SEARCH RECORD";
            cout << "\n 3. EDIT RECORD";
            cout << "\n 4. DELETE RECORD";
            cout << "\n 5. DISPLAY RECORD";
            cout << "\n 6. SALARY SLIP";
            cout << "\n 7. SEARCH DEPARTMENT";
            cout << "\n 8. EXIT";
            cout << "\n\n YOUR CHOICE: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    insertRecord();
                    break;
                case 2:
                    searchRecord();
                    break;
                case 3:
                    editRecord();
                    break;
                case 4:
                    deleteRecord();
                    break;
                case 5:
                    displayRecords();
                    break;
                case 6:
                    salarySlip();
                    break;
                case 7:
                    searchDepartment();
                    break;
                case 8:
                    cout << "\nExiting Program. Goodbye!\n";
                    break;
                default:
                    cout << "\nInvalid Choice. Please Try Again!\n";
            }
        } while (choice != 8);
    }


int main() {
	Employee ems;
    ems.displayMenu();
    return 0;
}

