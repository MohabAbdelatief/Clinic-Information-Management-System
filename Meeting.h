#pragma once
#include <string>
#include <iostream>
class Meeting {
private:
    int meeting_id;
    float meeting_duration; // IN HOURS
    std::string meeting_location;
    int start_end_time[2];
public:
    void set_id(int id) {
        this->meeting_id = id;
    }
    void set_duration(float duration) {
        this->meeting_duration = duration;
    }
    void set_location(std::string location) {
        this->meeting_location = location;
    }
    void set_start_end_time(int start, int end) {
        this->start_end_time[0] = start;
        this->start_end_time[1] = end;
    }

    int get_id() {
        return meeting_id;
    }
    float get_duration(){
        return meeting_duration;
    }
    std::string get_location() {
        return meeting_location;
    }
    int get_start_time(){
        return start_end_time[0];
    }
    int get_end_time() {
        return start_end_time[1];
    }

    void display_meeting() {
        std::cout << "\nMeeting ID: " << get_id();
        std::cout << "\nMeeting Duration: " << get_duration();
        std::cout << "\nMeeting Location: " << get_location();
        std::cout << "\nMeeting Starting time: " << get_start_time();
        std::cout << "\nMeeting ending time: " << get_end_time();
    }
};


