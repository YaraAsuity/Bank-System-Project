#include <stdlib.h>
#include <iostream>
#include "Client.h"
#include"Person.h"
#include"Employee.h"
#include "FileManager.h"
#include"filehelper.h"
#include"ClientManager.h"
#pragma once
class EmployeeManager
{
	static void printEmployeeMenu() {
		system("cls");

		cout << "(1) Display my info" << endl;

		cout << "(2) Update Password" << endl;
		cout << "(3) Add new client" << endl;
		cout << "(4) Search for client" << endl;
		cout << "(5) List all clients" << endl;
		cout << "(6) Edit client info" << endl;
		cout << "(7) Logout\n" << endl;
	}
	static void back(Employee* employee) {
		cout << endl;
		system("pause");

		employeeOptions(employee);
	}
public:
	static void newClient(Employee* employee) {

		Client client;
		client.Set_ID(filehelper::getLast("ClientLastId.txt") + 1);
		string password;
		client.Set_Name(Validation::Entername());
		client.Set_Password(Validation::Enterpassword());
		client.Set_Balance(Validation::EnterBalance());
		employee->addClient(client);
		FileManager::updateClients();
		cout << "\nClient added successfully. \n";
	}
	static void searchForClient(Employee* employee) {
		int id;
		system("cls");
		cout << "Enter client id: ";
		cin >> id;
		if (employee->searchClient(id) == NULL) cout << "\nClient not found.\n";
		else employee->searchClient(id)->Disply();
	}
	static void ListAllClients(Employee* employee) {
		system("cls");
		cout << "ALL clients: \n" << endl;
		employee->listClient();
	}
	static void editClientInfo(Employee* employee) {

		int id;

		system("cls");

		cout << "Enter client id: ";

		cin >> id;

		if (employee->searchClient(id) == NULL) cout << "\nClient not found. \n";

		else {
			string name = Validation::Entername();
			string password = Validation::Enterpassword();
			double balance = Validation::EnterBalance();
			employee->editClient(id, name, password, balance);
			FileManager::updateClients();

			cout << "\nClient info updated. \n";

		}
	}
	static Employee* login(int id, string password) {
		for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) {
			if (eIt->Get_Id() == id && eIt->Get_Password() == password) return eIt._Ptr;
		}
		return NULL;
	}
	static bool employeeOptions(Employee* employee) {



		printEmployeeMenu();

		cout << "Your choice is: ";

		int choice;

		cin >> choice;

		switch (choice) {

		case 1:
			system("cls");
			employee->Disply();
			break;

		case 2:

			ClientManager::updatePassword(employee);
			FileManager::updateEmployees();
			break;
		case 3:
			newClient(employee);
			break;
		case 4:
			searchForClient(employee);
			break;
		case 5:
			ListAllClients(employee);
			break;
		case 6:
			editClientInfo(employee);
			break;
		case 7:
			return false;
			break;

		default:
			system("cls");
			employeeOptions(employee);
			return true;

		}
		back(employee);
		return true;

	}


};