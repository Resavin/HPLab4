#include "Parcel.h"
#include <string>
#include <iostream>
using namespace std;

Parcel::Parcel() {}

Parcel::Parcel(int _codeNumber, string _departureDate, string _destinationAdress) :
	codeNumber(_codeNumber), departureDate(_departureDate), destinationAdress(_destinationAdress) {}

int Parcel::getCodeNumber() {
	return codeNumber;
}
string Parcel::getDepartureDate() {
	return departureDate;
}
string Parcel::getDestinationAdress() {
	return destinationAdress;
}

void Parcel::setCodeNumber(int _codeNumber) {
	codeNumber = _codeNumber;
}
void Parcel::setDepartureDate(string _departureDate) {
	departureDate = _departureDate;
}
void Parcel::setDestinationAdress(string _destinationAdress) {
	destinationAdress = _destinationAdress;
}

istream& operator>>(istream& in, Parcel& parcel) {
	cout << "\n������� ������� ����� �������: ";
	in >> parcel.codeNumber;
	cout << "������� ���� ����������� �������: ";
	in >> parcel.departureDate;
	cout << "������� ����� ���������� �������: ";
	in >> parcel.destinationAdress;
	return in;
}
ostream& operator<<(ostream& out, const Parcel& parcel) {
	parcel.print();
	return out;
}
bool operator>(Parcel& p_1, Parcel& p_2) {
	return p_1.codeNumber > p_2.codeNumber;
}

void Parcel::print() const {
	cout << "\n������� �����: " << codeNumber << endl;
	cout << "���� �����������: " << departureDate << endl;
	cout << "����� ����������: " << destinationAdress << endl;
}