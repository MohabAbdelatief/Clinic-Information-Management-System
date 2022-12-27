#pragma once
#include <string>
#include <iostream>
using namespace std;
class Appointment {
private:
    string time, doctor_name, patient_name;
    int price;
public:
    Appointment() {
        time = doctor_name = patient_name = "";
        price = 0;
    }
    // OVERLOAD CONSTRUCTOR
    Appointment(string time, string doctor_name, string patient_name, int price) {
        this->time = time;
        this->doctor_name = doctor_name;
        this->patient_name = patient_name;
        this->price = price; 
    }
    string get_time() {
        return time;
    }
    string get_d_name() {
        return doctor_name;
    }
    string get_p_name() {
        return patient_name;
    }
    int get_price() {
        return price;
    }
    void display_appointment() {
        cout << "Time: " << get_time() << endl;
        cout << "Doctor name: " << get_d_name() << endl;
        cout << "Patient name: " << get_p_name() << endl;
        cout << "Price: " << get_price() << endl;
    }

};
