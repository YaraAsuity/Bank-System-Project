//Employee.h
#pragma once
#include "Person.h"
#include <vector>
#include "Client.h"
class Employee :public Person {
protected:
	double salary;
public:
	void Set_Salary(double salary) {
		if (Validation::ValidationSalary(salary))
		{
			this->salary = salary;
		}
		else
			cout << "Error ! in salary" << endl;

	}
	double Get_Salary() {
		return this->salary;
	}
	Employee() :Person() {
		this->salary = 0.0;
	}
	Employee(string name, string password, int id, double salary) :Person(name, password, id) {
		Set_Salary(salary);
	}
	void Disply() {
		Person::Disply();
		cout << "Salary :" << this->salary << endl;
	}
	void addClient(Client& client) {
		allClients.push_back(client);
	}
	Client* searchClient(int id) {
		for (clIt = allClients.begin(); clIt != allClients.end(); clIt++) {
			if (clIt->Get_Id() == id) return clIt._Ptr;
		}
		return NULL;
	}
	void listClient() {
		for (clIt = allClients.begin(); clIt != allClients.end(); clIt++) {
			clIt->Disply();
			cout << "-------------------------\n";
		}
	}
	void editClient(int id, string name, string password, double balance) {
		searchClient(id)->Set_Name(name);
		searchClient(id)->Set_Password(password);
		searchClient(id)->Set_Balance(balance);
	}
};
static vector<Employee> allEmployees;
static vector<Employee>::iterator eIt;