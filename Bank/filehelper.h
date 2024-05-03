// FileHealper

#pragma once
#include <vector>
#include <string>
#include <sstream>
#include "Admin.h"
#include "Client.h"
#include "Employee.h"
#include "parser.h"
#include <fstream>
using namespace std;
class filehelper
{
public:
	static void savelast(string filename, int id) {

		ofstream file;
		file.open(filename);
		file << id;
		file.close();

	}
	//ClientLastID
	static int getLast(string fileName) {
		ifstream file;
		file.open(fileName);
		int id;
		file >> id;
		file.close();
		return id;
	}
	static void saveClient(Client c) {

		int id = getLast("ClientLastId.txt");
		fstream file;
		file.open("Clients.txt", ios::app);
		file << c.Get_Name() << '&' << c.Get_Password() << '&' << id + 1 << '&' << c.Get_Balance() << "\n";
		file.close();
		savelast("ClientLastId.txt", id + 1);
	}
	static void saveEmployee(string fileName, string lastIdFile, Employee e) {
		int id = getLast(lastIdFile);
		fstream file;
		file.open(fileName, ios::app);
		file << e.Get_Name() << '&' << e.Get_Password() << '&' << id + 1 << '&' << e.Get_Salary() << "\n";
		file.close();
		savelast(lastIdFile, id + 1);
	}
	static void getClients() {
		string line;
		ifstream file;
		file.open("Clients.txt");
		while (getline(file, line)) {
			Client c = parser::parsetoclient(line);
			allClients.push_back(c);
		}
		file.close();
	}
	static void getEmployees() {
		string line;
		ifstream file;
		file.open("Employees.txt");
		while (getline(file, line)) {
			Employee e = parser::parsetoEmployee(line);
			allEmployees.push_back(e);
		}
		file.close();
	}
	static void getAdmins() {
		string line;
		ifstream file;
		file.open("Admins.txt");
		while (getline(file, line)) {
			Admin a = parser::parsetoadmin(line);
			allAdmins.push_back(a);
		}
		file.close();
	}
	static void clearFile(string fileName, string lastIdFile) {
		fstream file1, file2;
		file1.open(fileName, ios::out, ios::trunc);
		file1.close();
		file2.open(lastIdFile, ios::out);
		file2 << 0;
		file2.close();
	}
};