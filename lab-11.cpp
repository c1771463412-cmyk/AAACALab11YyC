// COMSC-210-5293 | Lab 11 | Yuyi Chen

#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int id;
    int numGrades;
    int *grades;
};

void inputStudent(Student *);
void displayStudent(Student *);
void deleteStudentData(Student *);

int main() {
    int numStudents;

    cout << "How many students? ";
    cin >> numStudents;
    cin.ignore();

    Student *students = new Student[numStudents];

    for (int i = 0; i < numStudents; i++) {
        cout << "\nStudent #" << i + 1 << endl;
        inputStudent(&students[i]);
    }

    cout << "\n\nStudent Summary\n";
    for (int i = 0; i < numStudents; i++) {
        displayStudent(&students[i]);
    }

    return 0;
}

// inputStudent() gets information and grades for one student
// arguments: pointer to a Student
// returns: nothing
void inputStudent(Student *sptr) {
    cout << "Name: ";
    getline(cin, sptr->name);

    cout << "ID: ";
    cin >> sptr->id;

    cout << "How many grades? ";
    cin >> sptr->numGrades;

    sptr->grades = new int[sptr->numGrades];

    for (int i = 0; i < sptr->numGrades; i++) {
        cout << "Grade #" << i + 1 << ": ";
        cin >> sptr->grades[i];
    }

    cin.ignore();
}

// displayStudent() displays information and grades for one student
// arguments: pointer to a Student
// returns: nothing
void displayStudent(Student *sptr) {
    cout << "\nName: " << sptr->name << endl;
    cout << "ID: " << sptr->id << endl;
    
    cout << "Grades: ";
    for (int i = 0; i < sptr->numGrades; i++) {
        cout << sptr->grades[i] << " ";
    }

    cout << endl;
}