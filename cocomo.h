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
		// set a and b, 1 = organic, 2 = nominal, 3 = embedded
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
		case 1:
			this->a = 3.2;
			this->b = 1.05;
			break;
		case 2:
			this->a = 3.0;
			this->b = 1.10;
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

void COCOMO::setKDSI(float kdsi){
	this->kdsi = kdsi;
}

#endif
