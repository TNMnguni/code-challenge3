
#include <iostream>
#include <array>
#include <cstring>
using namespace std;

class Student {
private:
	int studentNumber;
	array<char, 30>	name;
	array<char, 30> surname;
public:
	Student() {
		studentNumber = 0;
		name.fill('\0');
		surname.fill('\0');
	};
	void setStudent(int studentNumber, const char* name, const char* surname) {
		this->studentNumber = studentNumber;
		strncpy_s(this->name.data(), this->name.size(), name, this->name.size() - 1);
		this->name[this->name.size() - 1] = '\0';

		strncpy_s(this->surname.data(), this->surname.size(), surname, this->surname.size() - 1);
		this->surname[this->surname.size() - 1] = '\0';
	}
	virtual void displayStudent() {
		cout << studentNumber << " " << name.data() << " " << surname.data() << endl;
	}

};