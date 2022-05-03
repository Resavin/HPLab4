#include "Worker.h"
#include <string>
#include <iostream>
using namespace std;

Worker::Worker() {
	position = "";
}
Worker::Worker(string _name, string _surname, int _age, string _login, string _password, string _position) :
	User(_name, _surname, _age, _login, _password) {
	position = _position;
}
string Worker::getPosition() {
	return position;
}
void Worker::setPosition(string _position) {
	position = _position;
}

istream& operator>>(istream& in, Worker& worker) {
	cout << "\n������� ��� ����������: ";
	in >> worker.name;
	cout << "������� ������� ����������: ";
	in >> worker.surname;
	cout << "������� ������� ����������: ";
	in >> worker.age;
	cout << "������� ����� ����������: ";
	in >> worker.login;
	cout << "������� ������ ����������: ";
	in >> worker.password;
	cout << "������� ��������� ����������: ";
	in >> worker.position;
	return in;
}
ostream& operator<<(ostream& out, const Worker& worker) {
	worker.print();
	return out;
}
bool operator>(Worker& w_1, Worker& w_2) {
	return w_1.name > w_2.name;
}

void Worker::print() const {
	cout << "\n���: " << name << endl;
	cout << "�������: " << surname << endl;
	cout << "�������: " << age << endl;
	cout << "�����: " << login << endl;
	cout << "������: " << password << endl;
	cout << "���������: " << position << endl;
}
