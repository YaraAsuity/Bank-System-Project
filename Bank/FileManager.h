// FileManager
#pragma once
#include "Datasource.h"
#include "filehelper.h"
class FileManager :public Datasource
{
private:
	static void addClient(Client client) {
		filehelper::saveClient(client);
	}
	static void addEmployee(Employee employee) {
		filehelper::saveEmployee("Employees.txt", "EmployeeLastId.txt", employee);
	}
	static void addAdmin(Admin admin) {
		filehelper::saveEmployee("Admins.txt", "AdminLastId.txt", admin);
	}
	static void getAllClients() {
		filehelper::getClients();
	}
	static void getAllEmployees() {
		filehelper::getEmployees();
	}
	static void getAllAdmins() {
		filehelper::getAdmins();
	}
	static void removeAllClients() {
		filehelper::clearFile("Clients.txt", "ClientLastId.txt");
	}
	static void removeAllEmployees() {
		filehelper::clearFile("Employees.txt", "EmployeeLastId.txt");
	}
	static void removeAllAdmins() {
		filehelper::clearFile("Admins.txt", "AdminLastId.txt");
	}
public:
	static void getAllData() {
		getAllClients();
		getAllEmployees();
		getAllAdmins();
	}
	static void updateClients() {
		removeAllClients();
		for (clIt = allClients.begin(); clIt != allClients.end(); clIt++) addClient(*clIt);
	}
	static void updateEmployees() {
		removeAllEmployees();
		for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) addEmployee(*eIt);
	}
	static void updateAdmins() {
		removeAllAdmins();
		for (aIt = allAdmins.begin(); aIt != allAdmins.end(); aIt++) addAdmin(*aIt);
	}
};
