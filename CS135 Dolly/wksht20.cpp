#include <iostream>
using namespace std;

struct studentType{
    string firstName;
    string lastName;
    int grade;
};

void getStudentData(studentType& student);

int main() {
    studentType student;

    getStudentData(student);
    cout << student.firstName << " " << student.lastName << " " << student.grade << endl;

}

void getStudentData(studentType& student) {

    string in = " ";

    cout << "Firstname: ";
    cin >> student.firstName;

    cout << "Lastname: ";
    cin >> student.lastName;

    cout << "Grade: ";
    cin >> student.grade;

    return;
}