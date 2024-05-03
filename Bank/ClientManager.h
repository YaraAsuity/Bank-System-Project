
#pragma once
#include <stdlib.h>
#include <iostream>
#include "Client.h"
#include"Person.h"
#include"Employee.h"
#include "FileManager.h"
using namespace std;

class ClientManager
{
	static void Printclientmenu() {
		system("cls");
		cout << "1 : Disply Info " << endl;
		cout << "2 : Check Balance " << endl;
		cout << "3 : update  Password  " << endl;
		cout << "4 : Withdraw " << endl;
		cout << "5 : Deposit " << endl;
		cout << "6 : Transfer amount " << endl;
		cout << "7 : Logout " << endl;
	}
	static void back(Client* client) {
		cout << endl;
		system("pause");
		clientOptions(client);

	}
public:
	static void updatePassword(Person* person) {
		person->Set_Password(Validation::Enterpassword());
		cout << "\nPassword updated \n";
	}
	static Client* Login(int id, string password) {
		for (clIt = allClients.begin(); clIt != allClients.end(); clIt++) {
			if (clIt->Get_Id() == id && clIt->Get_Password() == password)
				return clIt._Ptr;
		}
		return NULL;
	}
	static bool clientOptions(Client* client) {
		Printclientmenu();
		cout << "Your choice is: ";
		Employee e;
		double amount;
		int choice, id;
		cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			client->Disply();
			break;
		case 2:
			system("cls");
			client->checkBalance();
			break;
		case 3:
			updatePassword(client);
			FileManager::updateClients();
			break;
		case 4:
			system("cls");
			cout << "Enter amount to withdraw: ";
			cin >> amount;
			client->withdraw(amount);
			FileManager::updateClients();
			break;
		case 5:
			system("cls");
			cout << "Enter amount to deposit: ";
			cin >> amount;
			client->deposit(amount);
			FileManager::updateClients();
			break;
		case 6:
			system("cls");
			cout << "Enter id of the recipient: ";
			cin >> id;
			while (e.searchClient(id) == NULL) {
				system("cls");
				cout << "Invalid id. \n";
				cout << "\nEnter id of the recipient: ";
				cin >> id;
			}
			cout << "\nEnter amount to transfer: ";
			cin >> amount;
			client->transferTo(amount, *e.searchClient(id));
			FileManager::updateClients();
			break;
		case 7:
			return false;
			break;
		default:
			system("cls");
			clientOptions(client);
			return true;

		}
		back(client);
		return true;


	}
};