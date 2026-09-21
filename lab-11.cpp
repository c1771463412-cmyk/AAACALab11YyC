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


}