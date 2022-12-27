#pragma once
#include <iostream>
#include "Person.h"
#include <string>
#include "Appointment.h"
using namespace std;
class Patient : public Person{
public:
	Patient() {
		condition = "";
		numberOfVisits = 0;
	}
	void set_condition(string condition) {
		this->condition = condition;
	}
	void set_NOV(int nov) {
		this->numberOfVisits = nov;
	}
	void set_appointment(Appointment * appointment) {
		this->appointment = appointment;
	}
	string get_condition() {
		return condition;
	}
	int get_nov() {
		return numberOfVisits;
	}
	Appointment* get_appointment() {
		return appointment;
	}
	void display() {
		printf("Patient Name: ");
		std::cout << get_name() << std::endl;
		printf("Patient Condition: ");
		std::cout << get_condition() << endl;
	}
private:
	int numberOfVisits;
	string condition;
	Appointment* appointment;
};
