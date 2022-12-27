#pragma once
#include <string>
#include <iostream>
#include "Medicine.h"
using namespace std;
class Prescription {
private:
    string patient_name;
    string patient_condition;
    string doctor_name;
    Medicine* medicine;
    int patient_age;
public:

    Prescription() {
        patient_name = patient_condition = doctor_name = "";
        patient_age = 0;
        medicine = nullptr;
    }
    Prescription(string p_name, string p_condition, string doc_name, int age, Medicine* meds) {
        this->patient_name = p_name;
        this->patient_condition = p_condition;
        this->doctor_name = doc_name;
        this->patient_age = age;
        this->medicine = meds;
    }
    // GETTERS AND SETTERS

    void set_patient_name(string name) {
        this->patient_name = name;
    }
    void set_patient_age(int age) {
        this->patient_age = age;
    }
    void set_patient_condition(string condition){
        this->patient_condition = condition;
    }
    void set_doctor_name(string doc_name) {
        this->doctor_name = doc_name;
    }
    void set_meds(Medicine* meds) {
        this->medicine = meds;
    }
    string get_pname() {
        return patient_name;
    }
    int get_age() {
        return patient_age;
    }
    string get_pcondition() {
        return patient_condition;
    }
    string get_dname() {
        return doctor_name;
    }
    Medicine* get_meds() {
        
        return medicine;
    }
    void display_medicines() {
        medicine->display_medicine();
    }
    void display_prescription() {
        printf("\n\tPrescription\n");
        cout << "Patient: "<< get_pname() << endl;
        cout << "Age: " << get_age() << endl;
        cout << "Condition: " << get_pcondition() << endl;
        cout << "Doctor: " << get_dname() << endl;
        printf("Medicines");
        medicine->display_medicine();
    }
};

