#pragma once
#include "Patient.h"
#include "Staff.h"
#include <fstream>
#include "Receipt.h"
#include "Appointment.h"
class Receptionist : public Staff
{
public:
	void add_patient()
	{
		// ADD NEW PATIENT
		system("cls");
		printf("------------------");
		printf("ADDING NEW PATIENT");
		printf("------------------\n");
		string name, *dob, *address;
		dob = new string[3];
		address = new string[3];
		int age, id;
		string condition;
		int number;
		Patient patient;

		cout << "Name: ";
		cin >> name;
		cout << "Age: ";
		cin >> age;
		cout << "Id: ";
		cin >> id;
		cout << "Date of birth: ";
		cin >> dob[0] >> dob[1] >> dob[2];
		cout << "Address: ";
		cin >> address[0] >> address[1] >> address[2];
		cout << "Condition: ";
		cin >> condition;
		cout << "Number of visits: ";
		cin >> number;

		patient.create_person(name, age, dob, address, id);
		patient.set_condition(condition);
		patient.set_NOV(number);

		printf("\n-------");
		printf("\nPatient Added to the system");
		printf("\n-------");
		std::fstream file;
		file.open("patients.txt", ios::app);
		file << patient.get_id() << "," << patient.get_name() << "," << patient.get_condition() << "," << patient.get_age() << endl;
	}
	void remove_patient(string patientLine)
	{
		printf("REMOVING...\n");
		string line;
		std::fstream myfile;
		std::fstream temp;
		myfile.open("patients.txt");
		temp.open("temp.txt", ios::out);

		while (myfile.good())
		{
			getline(myfile, line);
			if (line != patientLine)
				temp << line << endl;
		}
		myfile.close();
		temp.close();
		remove("patients.txt");
		rename("temp.txt", "patients.txt");
		printf("\nREMOVE SUCCESFUL");
	}
	void display_patient()
	{
		system("cls");
		printf("Enter Patient ID: ");
		string id;
		cin >> id;
		string line;
		Patient patient;
		string temp_id;
		string temp_name, temp_condition;
		fstream PatientFile("patients.txt");
		if (PatientFile.is_open())
		{
			while (getline(PatientFile, line))
			{
				stringstream x(line);
				getline(x, temp_id, ',');
				getline(x, temp_name, ',');
				getline(x, temp_condition, ',');
				if (id == temp_id)
				{
					patient.set_name(temp_name);
					patient.set_condition(temp_condition);
				}
			}
		}
		patient.display();
	}
	void display_all_patients()
	{
		system("cls");
		string line;
		fstream PatientFile("patients.txt");
		if (PatientFile.is_open())
		{
			while (getline(PatientFile, line))
			{
				cout << line << '\n';
			}
		}
		PatientFile.close();
	}
	void print_receipt() {
		Patient patient;
		Receipt* receipt;
		string name, doctor_name;
		int price;
		cout << "Patient name: ";
		cin >> name;
		cout << "Doctor name: ";
		cin >> doctor_name;
		cout << "Price: ";
		cin >> price;
		patient.set_name(name);
		receipt = new Receipt(name, doctor_name, price);
		fstream receipt_file;
		receipt_file.open("receipt.txt", ios::out);

		receipt_file << "\n----------------";
		receipt_file << "\nPRINTING RECEIPT";
		receipt_file << "----------------\n";
		receipt_file << "Patient name: " << patient.get_name() << endl ;
		receipt_file << "Doctor name: " << receipt->get_doctor_name() << endl;
		receipt_file << "Price: " << receipt->get_price() << endl;

		receipt_file.close();
	}
	void create_appointment(Patient* patient) {
		fstream appointments;
		string time, doctor_name, patient_name;
		int price;
		cin >> time >> doctor_name >> patient_name;
		cin >> price;
		Appointment* appointment;
		appointment = new Appointment(time, doctor_name, patient_name , price);
		patient->set_appointment(appointment);	
		appointments.open("appointments.txt", ios::out);
		appointments << "Time: "<< appointment->get_time();
		appointments << "Doctor: " << appointment->get_d_name();
		appointments << "Patient: " << patient->get_name();
		appointments << "Price: " << appointment->get_price();
		appointments.close();

	}
};
