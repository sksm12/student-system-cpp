#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    int id;
    string name;
    float gpa;
};
Student students[100];
int count = 0;
void addStudent() {
    cout << "Enter ID: ";
    cin >> students[count].id;

    cout << "Enter Name: ";
    cin >> students[count].name;

    cout << "Enter GPA: ";
    cin >> students[count].gpa;

    count++;
}
void displayStudents() {
    for (int i = 0; i < count; i++) {
        cout << "ID: " << students[i].id << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "GPA: " << students[i].gpa << endl;
        cout << "-------------------" << endl;
    }
}
void searchStudent() {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            cout << "Found!\n";
            cout << students[i].name << " - " << students[i].gpa << endl;
            return;
        }
    }

    cout << "Student not found\n";
}
void deleteStudent() {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            cout << "Deleted successfully\n";
            return;
        }
    }

    cout << "Student not found\n";
}
void saveToFile() {
    ofstream file("students.txt");

    for (int i = 0; i < count; i++) {
        file << students[i].id << " "
             << students[i].name << " "
             << students[i].gpa << endl;
    }

    file.close();
}

void loadFromFile() {
    ifstream file("students.txt");

    while (file >> students[count].id
                >> students[count].name
                >> students[count].gpa) {
        count++;
    }

    file.close();
}
int main() {
    
    loadFromFile();  

    int choice;

    do {
        cout << "\n1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); saveToFile();  break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent();  saveToFile(); break;
            case 5: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}
