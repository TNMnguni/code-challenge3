#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "SecondYearStudent.cpp" 
using namespace std;

void loadStudentInfo(const string fileName, SecondYearStudent studentsObj[]) {
    ifstream fileObj(fileName);
    if (!fileObj.is_open()) {
        cerr << "Error: Unable to open file " << fileName << endl;
        exit(EXIT_FAILURE);
    }
    else {
        string Codes[] = { "DSO", "TPG", "ISY", "SSF" };

        for (int i = 0; i < 4; ++i) {
            int studentNumber;
            string name, surname;
            double assignmentMark[4], testMark[4];

            fileObj >> studentNumber;
            fileObj.ignore();
            getline(fileObj, name, ',');
            getline(fileObj, surname, ',');

            for (int j = 0; j < 4; ++j) {
                fileObj >> assignmentMark[j];
                fileObj.ignore();
                fileObj >> testMark[j];
                fileObj.ignore();
            }

            // Set student data using the SecondYearStudent methods
            studentsObj[i].setStudent(studentNumber, name.c_str(), surname.c_str(), Codes, assignmentMark, testMark);
            studentsObj[i].calcPredicate();
            studentsObj[i].calcFinalMark();
        }
    }
    fileObj.close();
}

int main() {
    const string fileName = "Students.csv";
    SecondYearStudent students[4]; // Define an array of SecondYearStudent objects

    loadStudentInfo(fileName, students);

    for (int i = 0; i < 4; ++i) {
        //cout << "Student " << i + 1 << " Details:" << endl;
        students[i].displayStudent();
        cout << endl;
    }

    return 0;
}
