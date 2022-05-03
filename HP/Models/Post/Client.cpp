#include "Client.h"
#include <string>
#include <iostream>
using namespace std;

Client::Client() {}
Client::Client(string _name, string _surname, int _age, string _login, string _password, int _codeNumber) :
	User(_name, _surname, _age, _login, _password) {
	codeNumber = _codeNumber;
}

int Client::getNumber() {
	return codeNumber;
}
void Client::setNumber(int _codeNumber) {
	codeNumber = _codeNumber;
}

istream& operator>>(istream& in, Client& client) {
	cout << "\n������� ��� �������: ";
	in >> client.name;
	cout << "������� ������� �������: ";
	in >> client.surname;
	cout << "������� ������� �������: ";
	in >> client.age;
	cout << "������� ����� �������: ";
	in >> client.login;
	cout << "������� ������ �������: ";
	in >> client.password;
	return in;
}
ostream& operator<<(ostream& out, const Client& client) {
	client.print();
	return out;
}
bool operator>(Client& c_1, Client& c_2) {
	return c_1.name > c_2.name;
}

void Client::print() const {
	cout << "\n���: " << name << endl;
	cout << "�������: " << surname << endl;
	cout << "�������: " << age << endl;
	cout << "�����: " << login << endl;
	cout << "������: " << password << endl;
	cout << "������� ����� �������: " << codeNumber << endl;
}