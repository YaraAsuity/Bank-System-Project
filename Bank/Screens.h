#pragma once
#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <windows.h>
#include "AdminManager.h"
using namespace std;
class Screens
{

	static void BankName() {
		cout << "\t\t   ##    ##  ########    ########  ####      ##  ##   ## \n";
		cout << "\t\t   ##   ##   ##     ##   ##    ##  ## ##     ##  ##  ## \n";
		cout << "\t\t    # ##     ########    ########  ##   ##   ##  ## # \n";
		cout << "\t\t    ##       ##     ##   ###  ###  ##    ##  ##  ##  ## \n";
		cout << "\t\t  ##         ########    ###  ###  ##     ####   ##   ## \n";
		Sleep(3500);
		system("cls");
	}
	static void loginoption() {
		cout << "(1) Admin " << endl;
		cout << "(2) Employee" << endl;
		cout << "(3) Client " << endl;
		cout << "login as: ";

	}
	static int loginAs() {
		loginoption();
		int choice;
		cin >> choice;
		if (choice == 1 || choice == 2 || choice == 3) {
			system("cls");
			return choice;
		}
		else {
			system("cls");
			return loginAs();
		}
	}
	static void invalid(int c) {
		system("cls");
		cout << "error in id or password \n" << endl;
		loginscreen(c);

	}
	static void logout() {
		system("cls");
		loginscreen(loginAs());
	}
	static void loginscreen(int c) {
		int choice = c, id;
		string pass;
		cout << "Enter id : ";
		cin >> id;
		cout << "Enter password : ";
		cin >> pass;
		switch (choice) {

		case 1:
			if (AdminManager::login(id, pass) != NULL) {
				while (AdminManager::adminOptions(AdminManager::login(id, pass)) != false);
				logout();
			}
			else
				invalid(1);
			break;

		case 2:
			if (EmployeeManager::login(id, pass) != NULL) {
				while (EmployeeManager::employeeOptions(EmployeeManager::login(id, pass)) != false);
				logout();
			}
			else
				invalid(2);
			break;
		case 3:
			if (ClientManager::Login(id, pass) != NULL) {
				while (ClientManager::clientOptions(ClientManager::Login(id, pass)) != false);
				logout();
			}
			else
				invalid(3);
			break;
		default:
			system("cls");
			loginoption();
		}


	}
public:
	static void runApp() {
		FileManager::getAllData();
		BankName();
		loginscreen(loginAs());

	}
};

