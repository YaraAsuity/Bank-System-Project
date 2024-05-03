// Admin.h
#pragma once
#include <vector>
#include "Employee.h"
class Admin :public Employee {
public:
	Admin() :Employee() {}
	Admin(string name, string password, int id, double salary) :Employee(name, password, id, salary) {}
	void addEmployee(Employee& employee) {
		allEmployees.push_back(employee);
	}
	Employee* searchEmployee(int id) {
		for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) {
			if (eIt->Get_Id() == id) return eIt._Ptr;
		}
		return NULL;
	}
	void editEmployee(int id, string name, string password, double salary) {
		searchEmployee(id)->Set_Name(name);
		searchEmployee(id)->Set_Password(password);
		searchEmployee(id)->Set_Salary(salary);
	}
	void listEmployee() {
		for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) {
			eIt->Disply();
			cout << "--------------------\n";
		}
	}
};
static vector<Admin> allAdmins;
static vector<Admin>::iterator aIt;
