#pragma once
#include "Staff.h"
#include <fstream>
#include "Meeting.h"
class Adminstrator {
public:
   void add_staff(Staff* staff);
   void view_staff();
   void create_meeting(Meeting* meeting);
   Adminstrator();
};
void Adminstrator::add_staff(Staff* staff) {
   std::fstream user_file;
   user_file.open("users.txt", ios::app);
   if (user_file.is_open()) {
      user_file << '\n' << staff->get_username() << "," << staff->get_password();  
   }
   user_file.close();
}
void Adminstrator::view_staff(){
   std::fstream user_file;
   std::string line;
   user_file.open("users.txt");
   if (user_file.is_open()) {
      while (getline(user_file, line)) {
         std::cout << line << endl;
      }
   }
   user_file.close();
}
void Adminstrator::create_meeting(Meeting* meeting) {
   fstream meeting_file;
   meeting_file.open("Meetings.txt", ios::out);
   meeting_file << "ID: " << meeting->get_id() << endl; 
   meeting_file << "Duration: " << meeting->get_duration() << endl; 
   meeting_file << "Start Time: " << meeting->get_start_time() << endl; 
   meeting_file << "End Time: " << meeting->get_end_time() << endl; 
   meeting_file << "Location: " << meeting->get_location() << endl; 

}
Adminstrator::Adminstrator() {
   
}


