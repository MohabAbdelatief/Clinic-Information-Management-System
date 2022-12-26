#pragma once
#include <fstream>
#include "Staff.h"
#include "Patient.h"
class Nurse : public Staff
{
public:
	void view_patient(Patient patient)
	{
		patient.display();
	}
	void add_incoming_patient()
	{
		system("cls");
		fstream incoming;
		incoming.open("incoming.txt", ios::out);
		string name, condition, id;
		printf("\nID: ");
		cin >> id;
		printf("\nName: ");
		cin >> name;
		printf("\nCondition: ");
		cin >> condition;
		incoming << id << ',' << name << ',' << condition;
		incoming.close();
		
	}
	void add_vitals()
	{
	}
	void view_all_patients()
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

private:
};
