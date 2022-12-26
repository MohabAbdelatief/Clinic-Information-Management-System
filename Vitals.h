#pragma once
#include "BloodPressure.h";
#include "Heartrate.h"
#include <iostream>
using namespace std;
class Vitals
{
public:
	void create_vitals(BloodPressure bp, Heartrate hr) {
		int mmHg, bmp;
		printf("Blood Pressure: ");
		cin >> mmHg;
		bp.set_mmHg(mmHg);
		printf("Heart rate: ");
		cin >> bmp;
		hr.set_bpm(bmp);
	}


private:
	BloodPressure bp;
	Heartrate hr;
};

