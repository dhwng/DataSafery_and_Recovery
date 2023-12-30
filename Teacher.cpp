#include "Teacher.h"

void Teacher::InputTeacher() {
	cout << "Nhap id:" << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.getline(this->id, sizeof(this->id));

	cout << "Nhap ten:" << endl;
	cin.getline(this->name, sizeof(this->name));

	cout << "Nhap tuoi:" << endl;
	cin.getline(this->age, sizeof(this->age));

	cout << "Nhap so dien thoai:" << endl;
	cin.getline(this->phone, sizeof(this->phone));

	cout << "Nhap cccd:" << endl;
	cin.getline(this->cccd, sizeof(this->cccd));

	this->isDeleted = false;
}

char* Teacher::getId() {
	return this->id;
}
char* Teacher::getName() {
	return this->name;
}

char* Teacher::getAge() {
	return this->age;
}

char* Teacher::getPhone() {
	return this->phone;
}

char* Teacher::getCCCD() {
	return this->cccd;
}

bool Teacher::getIsDeleted() {
	return this->isDeleted;
}

void Teacher::setIsDeleted(bool isDeleted) {
	this->isDeleted = isDeleted;
}