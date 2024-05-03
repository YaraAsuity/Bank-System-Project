#pragma once
#include<string>
#include <iostream>
using namespace std;

class Validation {
public:
	static bool ValidationName(string name) {
		bool flag = false;
		int size = name.size();

		if (name.size() >= 5 && size <= 20 && Validationwithnonumbers(name))
		{
			for (int i = 0; i < size; i++)
				if (isalpha(name[i])) {
					flag = true;
				}

		}
		return flag;
	}
	static bool Validationwithnonumbers(string name) {
		bool flag = true;
		int size = name.size();
		string temp = "0123456789.,;*&^%$$#@!)(><?|}{";
		int temp_size = temp.size();
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < temp_size; j++) {
				if (name[i] == temp[j])
					flag = false;

			}
		}
		return flag;
	}
	static bool ValidationPassword(string password) {
		if (password.size() >= 8 && password.size() <= 20)
		{
			return true;
		}
		else
			return false;
	}
	static string  Enterpassword() {
		string password;
		cout << "Enter New password : " << endl;
		cin >> password;
		return password;

	}
	static string  Entername() {
		string password;
		cout << "Enter New Name : " << endl;
		cin >> password;
		return password;

	}
	static double   EnterBalance() {
		double balance;
		cout << "Enter New Balance : " << endl;
		cin >> balance;
		return balance;

	}
	static bool ValidationBalance(double balance) {
		if (balance >= 1500)
			return true;
		else
			return false;
	}
	static bool ValidationSalary(double salary) {
		if (salary >= 5000)
		{
			return true;
		}
		else
			return false;
	}
};
