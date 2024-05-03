
#pragma once
#include "EmployeeManager.h"
class AdminManager
{
	static void printAdminMenu() {

		system("cls");

		cout << "(1) Display my info" << endl;
		cout << "(2) Update Password" << endl;
		cout << "(3) Add new client" << endl;
		cout << "(4) Search for client" << endl;
		cout << "(5) List all clients" << endl;
		cout << "(6) Edit client info" << endl;
		cout << "(7) Add new Employee" << endl;
		cout << "(8) Search for Employee" << endl;
		cout << "(9) List all Employees" << endl;
		cout << "(10) Edit Employee info" << endl;
		cout << "(11) Logout\n" << endl;
	}
	static void back(Admin* admin) {
		cout << endl;
		system("pause");
		adminOptions(admin);
	}
public:
	static Admin* login(int id, string password) {
		for (aIt = allAdmins.begin(); aIt != allAdmins.end(); aIt++) {
			if (aIt->Get_Id() == id && aIt->Get_Password() == password) return aIt._Ptr;
		}
		return NULL;
	}
	static bool adminOptions(Admin* admin) {
		printAdminMenu();
		cout << "Your choice is: ";
		Employee e;
		int choice, id;
		cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			admin->Disply();
			break;
		case 2:
			ClientManager::updatePassword(admin);
			FileManager::updateAdmins();
			break;
		case 3:
			EmployeeManager::newClient(admin);
			break;
		case 4:
			EmployeeManager::searchForClient(admin);
			break;
		case 5:
			EmployeeManager::ListAllClients(admin);
			break;

		case 6:
			EmployeeManager::editClientInfo(admin);
			break;
		case 7:
			e.Set_Name(Validation::Entername());
			e.Set_Password(Validation::Enterpassword());
			e.Set_Salary(Validation::EnterBalance());
			e.Set_ID(filehelper::getLast("EmployeeLastId.txt") + 1);
			admin->addEmployee(e);
			FileManager::updateEmployees();

			cout << "\nEmployee added successfully. \n";
			break;

		case 8:
			system("cls");

			cout << "Enter employee id: ";
			cin >> id;

			if (admin->searchEmployee(id) == NULL) cout << "\n€mployee not found. \n";
			else admin->searchEmployee(id)->Disply();

			break;

		case 9:
			system("cls");
			cout << "ALL employees: \n" << endl;
			admin->listEmployee();
			break;
		case 10:

			system("cls");

			cout << "Enter employee id: ";

			cin >> id;

			if (admin->searchEmployee(id) == NULL) cout << "\nEmployee not found. \n";
			else {

				string name = Validation::Entername();

				string password = Validation::Enterpassword();
				double salary = Validation::EnterBalance();
				admin->editEmployee(id, name, password, salary);
				FileManager::updateEmployees();
				cout << "\nEmployee info updated. \n";
			}
			break;
		case 11:
			return false;
			break;
		default:
			system("cls");
			adminOptions(admin);
			return true;
		}
		back(admin);
		return true;
	}


};