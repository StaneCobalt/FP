#include "../include/cocomo.h"
#include <math.h>

// Intermediate COCOMO calculator
float COCOMO::getEstimate(){
	float result = a * (pow(kdsi,b));
	float costDriverValue = 1.00;
	for(unsigned i = 0; i < costDriverSize; i++){
		costDriverValue *= this->costDriverValues[i][costDrivers[i]];
	}
	result *= costDriverValue;
	return result;
}

// set a and b, 1 = organic, 2 = semidetached, 3 = embedded
void COCOMO::setConstants(short mode, bool isIntermediate){
	if(!isIntermediate){
		switch(mode){
			case 1:
				this->a = 2.4;
				this->b = 1.05;
				break;
			case 2:
				this->a = 3.0;
				this->b = 1.12;
				break;
			case 3:
				this->a = 3.6;
				this->b = 1.20;
				break;
			default:
				this->a = 2.4;
				this->b = 1.05;
				break;
		}
	} else {
		switch(mode){
			case 1:
				this->a = 3.2;
				this->b = 1.05;
				break;
			case 2:
				this->a = 3.0;
				this->b = 1.12;
				break;
			case 3:
				this->a = 2.8;
				this->b = 1.20;
				break;
			default:
				this->a = 3.2;
				this->b = 1.05;
				break;
		}
	}
}

// set estimated thousand lines of code
void COCOMO::setKDSI(float kdsi){
	this->kdsi = kdsi;
}

// mutator for costDrivers[]
// sets costDriver to the passed in value
// if value is out of bounds, sets costDriver to nominal instead
void COCOMO::setCostDrivers(float values[costDriverSize]){
	for(unsigned i = 0; i < costDriverSize; i++){
		this->costDrivers[i] = (values[i] >= 0 && values[i] < 6) ? values[i] : 2;
	}
}

// initialize all costDriver values to nominal
void COCOMO::initCostDrivers(){
	for(unsigned i = 0; i < costDriverSize; i++){
		this->costDrivers[i] = 2;
	}
}
