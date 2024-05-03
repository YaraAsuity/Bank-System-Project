//Client.h
#pragma once
#include "Person.h"
#include <vector>

class Client :public Person {
	double balance;
public:
	void Set_Balance(double balance) {
		if (Validation::ValidationBalance(balance))
			this->balance = balance;
		else
			cout << "Error ! in Balance" << endl;

	}
	double Get_Balance() {
		return this->balance;
	}
	void deposit(double amount) {
		this->balance += amount;
	}
	void withdraw(double amount) {
		if (this->balance >= amount) {
			this->balance -= amount;
		}
		else
			cout << "\nAmount Exceeded.\n";
	}
	void transferTo(double amount, Client& cli) {
		if (this->balance >= amount) {
			this->balance -= amount;
			cli.balance += amount;
		}
		else
			cout << "\nAmount Exceeded.\n";
	}
	void checkBalance() {
		cout << "Balance : " << this->balance << endl;
	}
	Client() :Person() {
		this->balance = 0.0;
	}
	Client(string name, string password, int id, double balance) :Person(name, password, id)
	{
		Set_Balance(balance);
	}
	void Disply() {
		Person::Disply();
		cout << "Balance : " << this->balance << endl;
	}

};
static vector<Client> allClients;
static vector<Client>::iterator clIt;
