#pragma once
#include <string>
#include <fstream>
#include "Staff.h"
#include "Prescription.h"
class Doctor : public Staff {
public:
	Prescription* prescription;
	int index;
	Doctor() {
		speciality = " ";
	}
	void create(std::string speciality) {
		this->speciality = speciality;
	}
	void edit() {
		printf("Enter new speciality: ");
		std::cin >> speciality;
	}
	void remove() {
		speciality = "Deleted";
	}
	void dislpay_speciality() {
		printf("Doctor: ");
		std::cout << get_name();
		printf("is a special in: ");
		std::cout << this->speciality;
	}
	
	void view_incoming_patients() {
		system("cls");
		printf("\nINCOMING PATIENTS TEXT FILE\n");
		std::fstream incoming_file;
		incoming_file.open("incoming.txt");
		std::string line;
		while (getline(incoming_file, line))
			std::cout << line << std::endl;
		incoming_file.close();
	}
	void write_prescription() {
		system("cls");
		string name1, name2, conditon;
		int age, no_of_meds;
		printf("Patient name: ");
		cin >> name1;
		printf("Patient Condition: ");
		cin >> conditon;
		printf("Patient Age: ");
		cin >> age;
		printf("Doctor name: ");
		cin >> name2;
		printf("Amout of medicines: ");
		cin >> no_of_meds;
		Medicine* meds = new Medicine[no_of_meds];
		for (size_t i = 0; i < no_of_meds; i++) {
			meds->create_medicine();
		}
		index++;
		prescription = new Prescription(name1, conditon, name2, age, meds);
		
	}
	void print_prescription() {
		system("cls");
		printf("\n\t\tPRINTING.....");
		std::fstream pp;
		string Filename = "prescription"+ to_string(index) + ".txt";
		pp.open(Filename, ios::out);
		if (pp.is_open()) {
			pp << "Patient: " << prescription->get_pname() << endl;
			pp << "Condition: " << prescription->get_pcondition()  << endl;
			pp << "Age: "  << prescription->get_age() << endl;
			pp << "Doctor: " << prescription->get_dname() << endl;
			pp << "Medicine: " << prescription->get_meds()->get_name();
		}
		pp.close();
	}
private:
	std::string speciality;
};
