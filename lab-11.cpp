// COMSC-210-5293 | Lab 11 | Yuyi Chen

#include <iostream>
#include <string>
using namespace std;

// Stores the information for each student
struct Student {
    string name;
    int id;
    int numGrades;
    int *grades; // Points to a dynamic array
};

// Function prototype
void inputStudent(Student *);
void displayStudent(Student *);
void deleteStudentData(Student *);

int main() {
    int numStudents;

    // Gets the unfixed number of students array size
    cout << "How many students? ";
    cin >> numStudents;
    // Make sure at least one student is entered
    while (numStudents <= 0) {
        cout << "Please enter a number greater than 0\n How many students? ";
        cin >> numStudents;
    }
    cin.ignore();

    // Creates a dynamic array of Student structs
    Student *students = new Student[numStudents];

    // Gets the information for each student
    for (int i = 0; i < numStudents; i++) {
        cout << "\nStudent #" << i + 1 << endl;
        inputStudent(&students[i]);
    }

    // Displays all student information
    cout << "\n\nStudent Summary\n";
    for (int i = 0; i < numStudents; i++) {
        displayStudent(&students[i]);
    }

    // Deletes each student's dynamic grades array first
    for (int i = 0; i < numStudents; i++) {
        deleteStudentData(&students[i]);
    }

    // Deletes the dynamic array of Student structs
    delete [] students;
    students = nullptr;

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
    // Make sure the student has at least one grade
    while (sptr->numGrades <= 0) {
        cout << "Please enter a number greater than 0: ";
        cin >> sptr->numGrades;
    }

    // Creates a dynamic grades array based on the number entered
    sptr->grades = new int[sptr->numGrades];

    // Stores each grade inside the student's dynamic array
    for (int i = 0; i < sptr->numGrades; i++) {
        cout << "Grade #" << i + 1 << ": ";
        cin >> sptr->grades[i];

        // Make sure the grades is between 0 - 100
        while (sptr->grades[i] < 0 || sptr->grades[i] > 100) {
            cout << "Please enter the grade #" << i + 1 << " between 0 - 100: ";
            cin >> sptr->grades[i];
        }
    }

    // Removes the newline before the next student's name uses getline()
    cin.ignore();
}

// displayStudent() displays information and grades for one student
// arguments: pointer to a Student
// returns: nothing
void displayStudent(Student *sptr) {
    cout << "\nName: " << sptr->name << endl;
    cout << "ID: " << sptr->id << endl;
    
    // Goes through the dynamic grades array and displays every grade
    cout << "Grades: ";
    for (int i = 0; i < sptr->numGrades; i++) {
        cout << sptr->grades[i] << " ";
    }

    cout << endl;
}

// deleteStudentData() releases the dynamic grades array for one studen
// arguments: pointer to a student
// returns: nothing
void deleteStudentData(Student *sptr) {
    // This matches the new [] used when the grades array was created
    delete [] sptr->grades;
    // Makes sure the pointer is not left pointing to deleted memory
    sptr->grades = nullptr;
}