#pragma once
#include <iostream>
#include <string>
using namespace std;
class Receipt {
private:
    string patient_name, doctor_name;
    int price;
public:
    Receipt();
    Receipt(string patient_name, string doctor_name, int price);
    string get_patient_name();
    string get_doctor_name();
    int get_price();
    void display_receipt();
};

Receipt::Receipt() {
    patient_name = doctor_name = "";
    price = 0;
}
Receipt::Receipt(string patient_name, string doctor_name, int price) {
    this->patient_name = patient_name;
    this->doctor_name = doctor_name;
    this->price = price;
}
string Receipt::get_doctor_name(){
    return doctor_name;
}
string Receipt::get_patient_name() {
    return patient_name;
}
int Receipt::get_price() {
    return price;
}
void Receipt::display_receipt() {
    cout << "\nPatient name: " << get_patient_name();
    cout << "\nDoctor name: " << get_doctor_name();
    cout << "\nPrice " << get_price();
}

