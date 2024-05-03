//Person.h
#pragma once
#include <string>
#include <iostream>
#include "Validation.h"
using namespace std;
class Person {
protected:
	int id;
	string name, password;

public:
	//Setter
	void Set_Name(string name) {

		if (Validation::ValidationName(name))
			this->name = name;
		else
			cout << "Error ! in Name" << endl;
	}
	void Set_Password(string password) {
		if (Validation::ValidationPassword(password))
		{
			this->password = password;
		}
		else
			cout << "Error ! in Password" << endl;

	}
	void Set_ID(int id) {
		this->id = id;
	}
	//Getter
	string Get_Name() {
		return this->name;
	}
	string Get_Password() {
		return this->password;
	}
	int Get_Id() {
		return this->id;
	}

	Person() {
		this->name = " ";
		this->password = " ";
		this->id = 0;

	}
	Person(string name, string password, int id) {
		Set_Name(name);
		Set_Password(password);
		Set_ID(id);

	}
	void Disply() {
		cout << "Name :  " << this->name << endl;
		cout << "Password : " << this->password << endl;
		cout << "ID : " << this->id << endl;


	}
};
