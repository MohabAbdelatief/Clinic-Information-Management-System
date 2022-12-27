#pragma once
#include <string>
#include <iostream>
using namespace std;
class Person
{
public:
	Person() {
		name = " ";
		address = nullptr;
		DOB = nullptr;
		age = 0;
		id = 0;
	}
	// SET
	void set_name(string name) {
		this->name = name;
	}
	void set_age(int age) {
		this->age = age;
	}
	void set_dob(string* dob) {
		this->DOB = dob;
	}
	void set_address(string* address) {
		this->address = address;
	}
	void set_id(int id) {
		this->id = id;
	}
	void create_person(string name, int age, string* dob, string* address, int id) {
		this->name = name;
		this->age = age;
		this->DOB = dob;
		this->address = address;
		this->id = id;
	}
	void display_personalInfo() {
		cout << "Name: " << get_name();
		cout << "Age: " << get_age();
		cout << "Date of Birth: " << get_dob();
		cout << "Address: " << get_address();
		cout << "ID: " << get_id();
	}
	// GET
	string get_name(){
		return name;
	}
	int get_age(){
		return age;
	}
	string* get_dob(){
		return DOB;
	}
	string *get_address(){
		return address;
	}
	int get_id() {
		return id;
	}

private:
	string name;
	string* address;
	string* DOB;
	int age;
	int id;
};
