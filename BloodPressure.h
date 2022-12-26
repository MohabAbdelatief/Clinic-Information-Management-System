#pragma once
#include "DeviceReading.h"
#include <iostream>
class BloodPressure : public DeviceReading
{
public:
	void set_mmHg(int n) {
		this->mmHg = n;
	}
	int get_mmHg() {
		return mmHg;
	}
	void display() {
		std::cout << "\nBlood Pressure: " << get_mmHg();
	}

private:
	int mmHg;
};
