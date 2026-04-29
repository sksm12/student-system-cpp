#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    int id;
    string name;
    float marks[7];
    float total;
    float percentage;
    string grade;
};

Student students[100];
int count = 0;

string getGrade(float percentage) {
    if (percentage >= 90) return "A";
    else if (percentage >= 80) return "B";
    else if (percentage >= 70) return "C";
    else if (percentage >= 60) return "D";
    else return "F";
}


void addStudent() {
    if (count >= 100) {
        cout << "List is full!\n";
        return;
    }

    cout << "Enter ID: ";
    cin >> students[count].id;

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, students[count].name);

    cout << "Enter Attendance (30): ";
    cin >> students[count].marks[0];

    cout << "Enter Mid (75): ";
    cin >> students[count].marks[1];

    cout << "Enter Final (150): ";
    cin >> students[count].marks[2];

    cout << "Enter Quiz1 (15): ";
    cin >> students[count].marks[3];

    cout << "Enter Quiz2 (15): ";
    cin >> students[count].marks[4];

    cout << "Enter Quiz3 (15): ";
    cin >> students[count].marks[5];

    cout << "Enter Quiz4 (15): ";
    cin >> students[count].marks[6];

    float total = 0;
    for (int i = 0; i < 7; i++) {
        total += students[count].marks[i];
    }

    students[count].total = total;
    students[count].percentage = (total / 300.0) * 100;
    students[count].grade = getGrade(students[count].percentage);

    count++;

    cout << "Student added successfully!\n";
}

void displayStudents() {
    for (int i = 0; i < count; i++) {
        cout << "\nID: " << students[i].id;
        cout << "\nName: " << students[i].name;
        cout << "\nTotal: " << students[i].total;
        cout << "\nPercentage: " << students[i].percentage;
        cout << "\nGrade: " << students[i].grade << endl;
        cout << "---------------------\n";
    }
}

void searchStudent() {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            cout << "Found!\n";
            cout << "\nFound!\n";
cout << "ID: " << students[i].id << endl;
cout << "Name: " << students[i].name << endl;

cout << "Attendance: " << students[i].marks[0] << endl;
cout << "Midterm: " << students[i].marks[1] << endl;
cout << "Final: " << students[i].marks[2] << endl;

cout << "Quiz1: " << students[i].marks[3] << endl;
cout << "Quiz2: " << students[i].marks[4] << endl;
cout << "Quiz3: " << students[i].marks[5] << endl;
cout << "Quiz4: " << students[i].marks[6] << endl;

cout << "Total: " << students[i].total << endl;
cout << "Percentage: " << students[i].percentage << endl;
cout << "Grade: " << students[i].grade << endl;
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
             << students[i].total << " "
             << students[i].percentage << " "
             << students[i].grade << endl;
    }

    file.close();
}

void loadFromFile() {
    ifstream file("students.txt");

    while (file >> students[count].id
                >> students[count].name
                >> students[count].total
                >> students[count].percentage
                >> students[count].grade) {
        count++;
    }

    file.close();
}

int main() {

    loadFromFile();

    int choice;

    do {
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Search Student";
        cout << "\n4. Delete Student";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";

        cin >> choice;

        switch (choice) {
            case 1: addStudent(); saveToFile(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); saveToFile(); break;
            case 5: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}