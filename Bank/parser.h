// Parser
#pragma once
#include <vector>
#include <string>
#include <sstream>
#include "Admin.h"
#include "Client.h"
#include "Employee.h"
using namespace std;
class parser
{
public:
	static vector<string> spilt(string line) {
		stringstream s(line);
		vector <string> info;
		string data;
		while (getline(s, data, '&'))
		{
			info.push_back(data);
		}
		return info;
	}
	static Client parsetoclient(string line) {
		vector<string> info = spilt(line);
		Client c(info[0], info[1], stoi(info[2]), stod(info[3]));
		return c;
	}
	static Admin parsetoadmin(string line) {
		vector<string> info = spilt(line);
		Admin a(info[0], info[1], stoi(info[2]), stod(info[3]));
		return a;
	}
	static Employee parsetoEmployee(string line) {
		vector<string> info = spilt(line);
		Employee e(info[0], info[1], stoi(info[2]), stod(info[3]));
		return e;
	}
};