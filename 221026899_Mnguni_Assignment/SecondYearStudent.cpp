
#include <iostream>
#include <array>
#include <cstdlib>
#include "Student.cpp"
using namespace std;

class SecondYearStudent :public  Student {
private:
	array <string, 4> code;
	array <double, 4> assignment;
	array <double, 4> test;
	array <double, 4> predicate;
	array <double, 4> exam;
	array <double, 4> final;
	int  testWeight;
	int  assignmentWeight;

public:
	SecondYearStudent() : testWeight(60), assignmentWeight(40)
	{
		for (int i = 0; i < 4; ++i) {
			code[i] = "";
			assignment[i] = 0.0;
			test[i] = 0.0;
			predicate[i] = 0.0;
			exam[i] = 0.0;
			final[i] = 0.0;
		}
	}
	void setStudent(int studentNumber, const char* firstName, const char* surname, const string code[], const double assignment[], const double test[]) {
		Student::setStudent(studentNumber, firstName, surname);

		for (int i = 0; i < 4; ++i) {
			this->code[i] = code[i];
			this->assignment[i] = assignment[i];
			this->test[i] = test[i];
		}
	}
	friend void loadStudentInfo(string fileName, SecondYearStudent secondYrStdObj[]);

	void calcPredicate() {
		for (int i = 0; i < 4; i++) {
			predicate[i] = (assignment[i] * (static_cast<double>(assignmentWeight) / 100.0)) + (test[i] * (static_cast<double>(testWeight) / 100.0));
		}

	}
public:
	void calcFinalMark() {

		for (int i = 0; i < 4; i++) {
			if (predicate[i] > 0.0) {
				exam[i] = rand() % 101;
			}
			else {
				cout << "ERROR: Calculate predicate mark" << endl;
			}
		}
		for (int i = 0; i < 4; i++) {
			final[i] = (exam[i] + predicate[i]) * 0.5;
		}
	}
private:
	double determineStudentAvg() {
		double sum = 0.0;
		for (int i = 0; i < 4; i++) {
			sum += final[i];
		}
		double studentAverage = sum / 4;
		return studentAverage;
	}
public:
	void displayStudent()override {
		Student::displayStudent();
		for (int i = 0; i < 4; ++i) {
			cout << "                  " << code[i] << "  " << predicate[i] << "   " << exam[i] << "   " << final[i] << endl;
		}

		cout << "Average : " << determineStudentAvg() << endl;
	}

};