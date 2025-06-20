// Memory Calculate using vector

// Method Using 
/*
    This C++ project involving std::vector that has to implement a simple student management system using vectors. This project will help you practice using vectors for storing and managing data.

    Project Criteria : 
    Requirements :
    - Vector & Template

    Class Structure :
    1. Create Class Template : Memory Calculate
    Attributes : 
        - Id
        - Name
    Methods : 
    Implement the following :
        - A constructor to initialize the id and name.
        - A method to display the student's details. 
    
    2. Task Performed : 
        - Add a student : Use push_back() to add a students to the vector.
        - Display all students : Iterate through the vector to display all students. 
        - Remove a students by ID : Search the vector for a student by ID and remove the students if found. 
        - Search for a student by ID : Search and display the student with the given ID. 

    Requirements : 
    Create a students Management System that performs the following operations : 

    1. Add students to a list. 
    2. Display the list of students. 
    3. Remove a students from the list by ID. 
    4. Search for a student by ID. 
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
class Student {
private:
    T id;
    string name;

public:
    Student(T id, string name) {
        this->id = id;
        this->name = name;
    }

    void display() const {
        cout << "ID: " << id << ", Name: " << name << endl;
    }

    T getId() const {
        return id;
    }
};

template <typename T>
class StudentManager {
private:
    vector<Student<T>> students;

public:
    void addStudent(T id, string name) {
        students.push_back(Student<T>(id, name));
        cout << "Student added" << endl;
    }

    void displayStudents() const {
        if (students.empty()) {
            cout << "No students available" << endl;
            return;
        }

        for (const Student<T>& student : students) {
            student.display();
        }
    }

    void removeStudent(T id) {
        // typename std::vector<Student<T>>::iterator it;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == id) {
                students.erase(students.begin() + i);
                cout << "Student removed" << endl;
                return;
            }
        }
        cout << "Student not found" << endl;
    }

    void searchStudent(T id) const {
        for (const Student<T>& student : students) {
            if (student.getId() == id) {
                cout << "Student found: " << endl;
                student.display();
                return;
            }
        }
        cout << "Student not found" << endl;
    }

    void calculateMemory() const {
        size_t objectSize = sizeof(Student<T>);
        size_t total = objectSize * students.size();
        cout << "Memory used: " << total << " bytes (" << total / 1024.0 << " KB)" << endl;
    }
};


int main() {
    StudentManager<int> manager;
    int choice, id;
    string name;

    do {
        cout << "--- Student Management Menu ---" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Remove Student by ID" << endl;
        cout << "4. Search Student by ID" << endl;
        cout << "5. Calculate Memory Used" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: " << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter ID: " << endl;
                cin >> id;
                cout << "Enter Name: " << endl;
                cin.ignore();
                getline(cin, name);
                manager.addStudent(id, name);
                break;
            case 2:
                manager.displayStudents();
                break;
            case 3:
                cout << "Enter ID to remove: " << endl;
                cin >> id;
                manager.removeStudent(id);
                break;
            case 4:
                cout << "Enter ID to search: " << endl;
                cin >> id;
                manager.searchStudent(id);
                break;
            case 5:
                manager.calculateMemory();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice..." << endl;
        }

    } while (choice != 6);

    return 0;
}
