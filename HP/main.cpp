#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include "menu.h"
#include "menu_manager.h"
#include "my_vector.h"
#include "Models\Parcel\Parcel.h"
#include "Models\Post\Worker.h"
#include "Models\Post\Client.h"

#pragma region �������
int sqrt25() {
	std::cout << "���������� ������ �� 25 ����� " << pow(25, 0.5) << ".";
	return 0;
}

int hello() {
	char name[25]{};
	cout << "������� ���� ���: ";
	cin.ignore(1, '\n');
	cin.getline(name, 25);
	system("cls");
	cout << "������, " << name << "!";
	return 0;
}

int printgraf() {
	cout << "_________________���1___���____���1_______________\n";
	cout << "__________________���____���____1��1______________\n";
	cout << "___________________���____���____���______________\n";
	cout << "___________________���____���____���______________\n";
	cout << "__________________���____1��1___1��1______________\n";
	cout << "________________1���____���____���1_______________\n";
	cout << "______________1���____���1___���1_________________\n";
	cout << "_____________���1___1��1___1��1___________________\n";
	cout << "____________1��1___1��1___1��1____________________\n";
	cout << "____________1��1___1��1___1���____________________\n";
	cout << "_____________���____���1___���1___________________\n";
	cout << "______________����___1���___1���__________________\n";
	cout << "_______________1���1___���1___����________________\n";
	cout << "_________________1��1____���____���_______________\n";
	cout << "___________________��1____��1____��1______________\n";
	cout << "___________________���____���____���______________\n";
	cout << "__________________1��1___1��1____��1______________\n";
	cout << "_________________���____���1___1��1_______________\n";
	cout << "________________11_____111_____11_________________\n";
	cout << "__________��������������������������������________\n";
	cout << "1�����������__����������������������������________\n";
	cout << "1�����������__1���������������������������________\n";
	cout << "1��_______��__1���������������������������________\n";
	cout << "1��_______��__1���������������������������________\n";
	cout << "1��_______��__����������������������������________\n";
	cout << "1��_______��__1���������������������������________\n";
	cout << "_�����������__����������������������������________\n";
	cout << "_�����������__����������������������������________\n";
	cout << "__________��___1�������������������������1________\n";
	cout << "__________1��___�������������������������_________\n";
	cout << "____________��������������������������11__________\n";
	cout << "11_____________________________________________111\n";
	cout << "1������������������������������������������������1\n";
	cout << "__��111111111�������������������������111111111�__" << endl;
	return 0;
}
int exitProgram() {
	system("cls");
	std::cout << "�������� ������� ������ �� ���������.\n\n";
	system("pause");
	exit(0);
}

namespace ZDV {

	int c1{};
	int c2{};
	int c3{};
	const int maxCount = 50;
}

int Users() {
	system("cls");
	cout << "����� ������� ������ Parcel" << endl;
	Parcel parcel(5000, "14.03.2022", "Kaluga");
	parcel.print();
	cout << "\n����� ������� ������ Worker" << endl;
	Worker worker("Daniil", "Zudin", 19, "log", "pas", "Postman");
	worker.print();
	cout << "\n����� ������� ������ Client" << endl;
	Client client("Nikita", "Kuzin", 18, "log", "pas", parcel.getCodeNumber());
	client.print();
	cout << "\n\n";
	system("pause");
	return 0;
}

int AddWorker(MyVector& vector) {
	system("cls");
	using namespace ZDV;
	int count{};
	cout << "\n������� ���-�� �������� ������ �������: ";
	cin >> count;
	for (int i = 0; i < count; i++) {
		cout << "\n���� ���������� �� ������� ������ #" << i + 1;
		Worker worker;
		cin >> worker;
		vector.PushBack(worker);
	}
	system("pause");
	system("cls");
	return 1;
}

int AddParcel(Parcel* parcels) {
	system("cls");
	using namespace ZDV;
	int count{};
	cout << "\n������� ���-�� �������� ������ �������: ";
	cin >> count;
	for (int i = c2; i < (c2 + count); i++) {
		cout << "\n���� ���������� �� ������� ������ #" << i + 1;
		cin >> parcels[i];
	}
	c2 += count;
	system("pause");
	system("cls");
	return 1;
}

int AddClient(Client* clients, Parcel* parcels) {
	system("cls");
	using namespace ZDV;
	int count{};
	cout << "\n������� ���-�� �������� ������ ������: ";
	cin >> count;
	for (int i = c3; i < (c3 + count); i++) {
		cout << "\n���� ���������� �� ������� ������ #" << i + 1;
		cin >> clients[i];
		clients[i].setNumber(parcels[i].getCodeNumber());
	}
	c3 += count;
	system("pause");
	system("cls");
	return 1;
}

void AddUser(MyVector& vector, Parcel* parcels, Client* clients) {
	using namespace ZDV;
	cout << "�������� ����� ��� ����������:\n1. Worker\n2. Parcel\n3. Client\nSelect >> ";
	int switcher{};
	cin >> switcher;
	switch (switcher) {
	case 1:
		AddWorker(vector);
		break;
	case 2:
		AddParcel(parcels);
		break;
	case 3:
		AddClient(clients, parcels);
		break;
	}
}

int PrintWorker(MyVector vector) {
	system("cls");
	using namespace ZDV;
	int j = 1;
	for (Worker w : vector) {
		cout << "\n\n����� ���������� �� �������� ������ ������� #" << j << "\n";
		cout << w;
		j++;
	}
	system("pause");
	return 1;
}

int PrintParcel(Parcel* parcels) {
	system("cls");
	using namespace ZDV;
	for (int i = 0; i < c2; i++) {
		cout << "\n\n����� ���������� �� �������� ������ ������� #" << i + 1 << "\n";
		cout << parcels[i] << endl;
	}
	system("pause");
	return 1;
}

int PrintClient(Client* clients) {
	system("cls");
	using namespace ZDV;
	for (int i = 0; i < c3; i++) {
		cout << "\n\n����� ���������� �� �������� ������ ������ #" << i + 1 << "\n";
		cout << clients[i] << endl;
	}
	system("pause");
	return 1;
}

void PrintUser(MyVector vector, Parcel* parcels, Client* clients) {
    using namespace ZDV;
	cout << "�������� ����� ��� ������ ����������:\n1. Worker\n2. Parcel\n3. Client\nSelect >> ";
	int switcher{};
	cin >> switcher;
	switch (switcher) {
	case 1:
		PrintWorker(vector);
		break;
	case 2:
		PrintParcel(parcels);
		break;
	case 3:
		PrintClient(clients);
		break;
	}
}

int DeleteWorker(MyVector& vector) {
	using namespace ZDV;
	int tempResult = PrintWorker(vector);
	cout << "\n�������� ����� ������� ��� ��������: ";
	int deleteNum{};
	cin >> deleteNum;
	vector.Remove(deleteNum - 1);
	return 1;
}

int DeleteParcel(Parcel* parcels) {
	using namespace ZDV;
	int tempResult = PrintParcel(parcels);
	cout << "\n�������� ����� ������� ��� ��������: ";
	int deleteNum{};
	cin >> deleteNum;
	for (int i = (deleteNum - 1); i < (maxCount - 1); i++) {
		parcels[i] = parcels[i + 1];
	}
	c2--;
	return 1;
}

int DeleteClient (Client* clients) {
	using namespace ZDV;
	int tempResult = PrintClient(clients);
	cout << "\n�������� ����� ������� ��� ��������: ";
	int deleteNum{};
	cin >> deleteNum;
	for (int i = (deleteNum - 1); i < (maxCount - 1); i++) {
		clients[i] = clients[i + 1];
	}
	c3--;
	return 1;
}

void DeleteUser(MyVector& vector, Parcel* parcels, Client* clients) {
	using namespace ZDV;
	system("cls");
	cout << "�������� ����� ��� �������� ����������:\n1. Worker\n2. Parcel\n3. Client\nSelect >> ";
	int switcher{};
	cin >> switcher;
	switch (switcher) {
	case 1:
		DeleteWorker(vector);
		break;
	case 2:
		DeleteParcel(parcels);
		break;
	case 3:
		DeleteClient(clients);
		break;
	}
}

int SortWorker(MyVector& vector) {
	using namespace ZDV;
	system("cls");
	for (int j = 0; j < vector.Size(); j++) {
		for (int i = 0; i < vector.Size() - 1; i++) {
			if (vector[i] > vector[i + 1]) {
				Worker tempWorker = vector[i + 1];
				vector[i + 1] = vector[i];
				vector[i] = tempWorker;
			}
		}
	}
	int tempResult = PrintWorker(vector);
	return 1;
}

int SortParcel(Parcel* parcels) {
	using namespace ZDV;
	system("cls");
	for (int i = 0; i < c2 - 1; i++) {
		if (parcels[i] > parcels[i + 1]) {
			Parcel tempParcel = parcels[i + 1];
			parcels[i + 1] = parcels[i];
			parcels[i] = tempParcel;
		}
	}
	int tempResult = PrintParcel(parcels);
	return 1;
}

int SortClient(Client* clients) {
	using namespace ZDV;
	system("cls");
	for (int i = 0; i < c3 - 1; i++) {
		if (clients[i] > clients[i + 1]) {
			Client tempClient = clients[i + 1];
			clients[i + 1] = clients[i];
			clients[i] = tempClient;
		}
	}
	int tempResult = PrintClient(clients);
	return 1;
}

void SortUser(MyVector& vector, Parcel* parcels, Client* clients) {
	using namespace ZDV;
	system("cls");
	cout << "�������� ����� ��� ���������� ����������:\n1. Worker\n2. Parcel\n3. Client\nSelect >> ";
	int switcher{};
	cin >> switcher;
	switch (switcher) {
	case 1:
		SortWorker(vector);
		break;
	case 2:
		SortParcel(parcels);
		break;
	case 3:
		SortClient(clients);
		break;
	}
}

void FilterWorker(MyVector vector) {
	system("cls");
	string name;
	cout << "������� ��� ������������ ��� ����������: ";
	cin >> name;
	int j = 1;
	for (Worker w : vector) {
		if (w.getName() == name) {
			cout << "\n\n����� ���������� �� �������� ������ ������� #" << j << "\n";
			cout << w;
			j++;
		}
	}
	system("pause");
}

void FilterParcel(Parcel* parcels) {
	return;
}

void FilterClient(Client* clients) {
	return;
}

void FilterUser(MyVector& vector, Parcel* parcels, Client* clients) {
	using namespace ZDV;
	system("cls");
	cout << "�������� ����� ��� ���������� ����������:\n1. Worker\n2. Parcel\n3. Client\nSelect >> ";
	int switcher{};
	cin >> switcher;
	switch (switcher) {
	case 1:
		FilterWorker(vector);
		break;
	case 2:
		FilterParcel(parcels);
		break;
	case 3:
		FilterClient(clients);
		break;
	}
}

int User() {
	return 5;
}
int AddUser() {
	return 1;
}
int PrintUser() {
	return 5;
}
int DeleteUser() {
	return 2;
}
int SortUser() {
	return 3;
}
int FilterUser() {
	return 4;
}
int BackMainMenu() {
	return 6;
}
#pragma endregion


int main() {
	using namespace ZDV;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(nullptr));
	Parcel* parcels = new Parcel[maxCount];
	MyVector vector;
	Client* clients = new Client[maxCount];

	const int itemsCount = 6;
	char squareRootOf25Name[]{ "��������� ������ �� 25" };
	char helloName[]{ "������������� � �������������" };
	char printHelloName[]{ "���������� �������� ��������������" };
	char menuTitle[]{ "������� ����" };
	char incheritance[]{ "������������" };
	char operatorOverloading[]{ "���������� ����������" };
	char ex[]{ "�����" };
	Item items[itemsCount]{
		Item {squareRootOf25Name, sqrt25},
		Item {helloName, hello},
		Item {printHelloName, printgraf},
		Item {incheritance, Users},
		Item {operatorOverloading, User},
		Item {ex, exitProgram} };
	Menu menu{ menuTitle, items, itemsCount };

	const int runMenuUsers = 6;
	char usersMenu[] = "���������������� ����";
	char addUsers[] = "�������� ������������";
	char deleteUsers[] = "������� ������������";
	char sortUsers[] = "����������� ������ �������������";
	char filterUsers[] = "����������� ������ �������������";
	char printUsers[] = "������� ���������� � ������������";
	char backToMainMenu[] = "����� � ������� ����";
	Item items_user[runMenuUsers]{
		Item {addUsers, AddUser},
		Item {deleteUsers, DeleteUser},
		Item {sortUsers, SortUser},
		Item {filterUsers, FilterUser},
		Item {printUsers, PrintUser},
		Item {backToMainMenu, BackMainMenu } };
	Menu menu_user(usersMenu, items_user, runMenuUsers);
	MenuManage managerOfMenu(menu, menu_user);

	while (managerOfMenu.runMainMenu()) {
		if (managerOfMenu.getMain_select() == User()) {
			do {
				system("cls");
				managerOfMenu.runSubMenu();
				if (managerOfMenu.getSub_select() == AddUser()) {
					AddUser(vector, parcels, clients);
				}
				else if (managerOfMenu.getSub_select() == PrintUser()) {
					PrintUser(vector, parcels, clients);
				}
				else if (managerOfMenu.getSub_select() == DeleteUser()) {
					DeleteUser(vector, parcels, clients);
				}
				else if (managerOfMenu.getSub_select() == SortUser()) {
					SortUser(vector, parcels, clients);
				}
				else if (managerOfMenu.getSub_select() == FilterUser()) {
					FilterUser(vector, parcels, clients);
				}
			} while (managerOfMenu.getSub_select() != BackMainMenu());
			system("cls");
		}
	};
	return 0;
}