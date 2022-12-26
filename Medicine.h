#pragma once
#include <string>
class Medicine
{
private:
    std::string name;
    float concetration;
    int* reminder;
public:
    Medicine() {
        name = "";
        concetration = 0.0f;
        reminder = nullptr;
    }
    int reminder_no;
    void create_medicine() {
        printf("Name: ");
        cin >> name;
        printf("Concentration: ");
        cin >> concetration;
        printf("How Many times should patient take ");
        std::cout << name  << ": ";
        cin >> reminder_no;
        reminder = new int[reminder_no];
        for (size_t i = 0; i < reminder_no; i++) {
            std::cout << "Reminder " << i << ": ";
            cin >> *reminder;
        }
        printf("Medicine Created Successfully");
    }
    void display_medicine() {
        std::cout << "Name: " << name;
        std::cout << "Concentration: " << concetration;
        for (size_t i = 0; i < reminder_no; i++)
            std::cout << "Reminder " << i << ": " << *reminder;
    }

};
