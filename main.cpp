#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Staff.h"
#include "Doctor.h"
#include "Receptionist.h"
#include "Patient.h"
#include "Nurse.h"

using namespace std;

vector<Staff*> staff_members;
Patient patient;
Nurse nurse;
Receptionist receptionists[100];
Doctor doctor;

void PrintWelcome() {
	printf("\t----------------------");
	printf("\tWelcome to CIMS System");
	printf("\t----------------------\n");
	printf("\t-----------------------------------------------------------------------\n");

}
int DisplayMenu() {
	printf("\n\t\t1- Start\n");
	printf("\t\t2- QUIT\n");
	int input;
	cin >> input;
	return input;
}
int DisplayLoginOrRegister() {
	printf("__________________CIMS________________\n");
	printf("\t\tLogin\n");
	int input;
	cin >> input;
	return input;
}
void ReceptionMenu() {
	system("cls");
	printf("\n1- Add New Patient\n");
	printf("2- Remove Existing Patient\n");
	printf("3- Display Existing Patient\n");
	printf("4- Display All Patients\n");
	printf("5- Logout\n");
}
void DoctorMenu() {
	system("cls");
	printf("\n1- Write Prescription");
	printf("\n2- Print Prescription");
	printf("\n3- View Incoming Patients");
	printf("\n4- Logout\n");
}
void NurseMenu() {
	system("cls");
	printf("\n1- Add Incoming Patient");
	printf("\n2- Add Vitals");
	printf("\n3- View All Patients");
	printf("\n4- Logout\n");

}
bool VerifyLogin(string& role) {
	string username, password;

	Staff* staff = new Staff();

	printf("Username: ");
	cin >> username;
	printf("Password: ");
	cin >> password;
	
	staff->create(username, password, role);
	if (staff->login() == true) {
		staff_members.push_back(staff);
		return true;
	}
	else {
		printf("\nUser not found!");
		staff->remove_staff(); // REMOVE VARIABLES
		staff_members.pop_back(); // REMOVE FROM LIST
		printf("\nTry Again\n");
		VerifyLogin(role);
	}
	return false;
}
//	MAIN
int main() {
	Begin:
	fstream login_file;
	login_file.open("users.txt");
	PrintWelcome();
	StartMenu:
	if (DisplayMenu() == 1) {
		Logout:
		system("cls");
		if (DisplayLoginOrRegister() == 1) {
			LoginLoop:
			system("cls");
			printf("0- Back\n");
			printf("1- Login\n");
			string x;
			cin >> x;
			if (x == "0")
				goto Begin;
			printf("Role: ");
			string role;
			cin >> role;
			if (VerifyLogin(role)) {
				MenuLoop:
				if (role == "Doctor") {
					DoctorMenu:
					string new_input;
					DoctorMenu();
					int input;
					cin >> input;
					switch (input)
					{
					case 1:
						doctor.write_prescription();
						printf("\n0- Main Menu\n");
						cin >> new_input;
						if (new_input == "0")
							goto MenuLoop;
						break;
					case 2:
						doctor.print_prescription();
						printf("\n0- Main Menu\n");
						cin >> new_input;
						if (new_input == "0")
							goto DoctorMenu;
						break;
					case 3:
						doctor.view_incoming_patients();
						printf("\n0- Main Menu\n");
						cin >> new_input;
						if (new_input == "0")
							goto DoctorMenu;
						break;
					case 4:
						goto Logout;
						break;
					default:
						goto DoctorMenu;
						break;
					}
				}
				else if (role == "Receptionist") {
					ReceptionMenu();
					int input;
					cin >> input;
					if (input == 1) {
						receptionists[0].add_patient();
						printf("\n0- Main Menu\n");
						string new_input;
						cin >> new_input;
						if (new_input == "0")
							goto MenuLoop;
					}
					else if (input == 2) {
						system("cls");
						string line;
						fstream PatientFile("patients.txt");
						if (PatientFile.is_open()) {
							while (getline(PatientFile, line)) {
								cout << line << '\n';
							}
						}
						PatientFile.close();
						// REMOVE
						string line_;
						printf("Patient you want to remove: ");
						cin >> line_;
						receptionists[0].remove_patient(line_);
						printf("\n0- Main Menu\n");
						string new_input;
						cin >> new_input;
						if (new_input == "0")
							goto MenuLoop;
					}
					else if (input == 3) {
						receptionists[0].display_patient();
						printf("\n0- Main Menu\n");
						string new_input;
						cin >> new_input;
						if (new_input == "0")
							goto MenuLoop;
					}
					else if (input == 4) {
						receptionists[0].display_all_patients();
						printf("\n0- Main Menu\n");
						string new_input;
						cin >> new_input;
						if (new_input == "0")
							goto MenuLoop;
					}
					else if (input == 5)
					{
						system("cls");
						goto Logout;
					}
					
				}
				else if (role == "Nurse") {
					NurseMenu:
					NurseMenu();
					int input;
					string new_input;
					cin >> input;
					switch (input) {
					case 1:
						nurse.add_incoming_patient();
						printf("\n0- Main Menu\n");
						cin >> new_input;
						if (new_input == "0")
							goto NurseMenu;
						break;
					case 2:
						nurse.add_vitals();
						printf("\n0- Main Menu\n");
						cin >> new_input;
						if (new_input == "0")
							goto NurseMenu;
						break;
					case 3:
						nurse.view_all_patients();
						printf("\n0- Main Menu\n");
						cin >> new_input;
						if (new_input == "0")
							goto NurseMenu;
						break;
					case 4:
						goto Logout;
						break;
					default:
						goto NurseMenu;
						break;
					}
				}
			}
		}
		else
			goto LoginLoop;
	}
	else
		exit(0);

	return 0;
}