#pragma once
#include "DeviceReading.h"
#include <iostream>
class Heartrate : public DeviceReading {
public:
	void set_bpm(int bpm) {
		this->bpm = bpm;
	}
	int get_bpm() {
		return bpm;
	}
	void display() {
		std::cout << "\nHeartrate: " << get_bpm() << " per minute";
	}

private:
	int bpm;
};
