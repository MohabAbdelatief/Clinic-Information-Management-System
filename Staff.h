#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Person.h"
using namespace std;
class Staff : public Person {
public:
	std::fstream file;
	bool login() {
		file.open("users.txt");
		std::string temp, temp_username, temp_password;
		bool isFound = false;
		if (file.is_open()) {
			while (getline(file, temp) && !isFound) {
				std::stringstream line(temp);
				getline(line, temp_username, ',');
				getline(line, temp_password, ',');
				if (username == temp_username && password == temp_password) {
					printf("---------------------");
					printf("\nLogin Successful\n");
					printf("---------------------");
					isFound = true;
					return true;
				}
			}
		}
		file.close();
		
		return false;
		
	}
	void create(std::string username, std::string password, std::string role) {
		this->username = username;
		this->password = password;
		this->role = role;
	}
	void edit() {
		printf("What do you want to edit: ");
		std::string input;
		std::cin >> input;
		if (input == "username") {
			std::string new_username;
			printf("New username: ");
			std::cin >> new_username;
			this->username = new_username;
		}
		else if (input == "password") {
			std::string new_password;
			printf("New Password: ");
			std::cin >> new_password;
			this->password = new_password;
		}
		else if (input == "role") {
			std::string new_role;
			printf("New Password: ");
			std::cin >> new_role;
			this->password = new_role;
		}
	}
	void remove_staff() {
		username = password = role = "Deleted";
	}
private:
	std::string username, password, role;
};
