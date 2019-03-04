#ifndef COCOMO_H
#define COCOMO_H

#include <math.h>

class COCOMO {
	private:
		float a;
		float b;
		float kdsi;

	public:
		COCOMO() = default;
		// Intermediate COCOMO calculator
		float getEstimate();
		// set a and b, 0 = organic, 1 = nominal, 2 = embedded
		void setConstants(short mode);
		// set estimated thousand lines of code
		void setKDSI(float kdsi);
};

float COCOMO::getEstimate(){
	float result = a * (pow(kdsi,b));
	
	return result;
}

void COCOMO::setConstants(short mode){
	switch(mode){
		case 0:
			this->a = 3.2;
			this->b = 1.05;
		case 1:
			this->a = 3.0;
			this->b = 1.10;
		case 2:
			this->a = 2.8;
			this->b = 1.20;
		default:
			this->a = 3.2;
			this->b = 1.05;
	}
}

void COCOMO::setKDSI(float kdsi){
	this->kdsi = kdsi;
}

#endif
