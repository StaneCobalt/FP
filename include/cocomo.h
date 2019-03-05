#ifndef COCOMO_H
#define COCOMO_H

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

#endif
