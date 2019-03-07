#ifndef COCOMO_H
#define COCOMO_H

const unsigned costDriverSize = 15;

class COCOMO {
	private:
		float a;
		float b;
		float kdsi;
		// cost drivers used for refining the estimate
		// ranking: very low, low, nominal, high, very high, extra high
		float costDriverValues[costDriverSize][6] = {
			{0.75, 0.88, 1.00, 1.15, 1.40, 1.40}, // required software reliability
			{0.94, 0.94, 1.00, 1.08, 1.16, 1.16}, // database size
			{0.70, 0.85, 1.00, 1.15, 1.30, 1.65}, // product complexity
			{1.00, 1.00, 1.00, 1.11, 1.30, 1.66}, // execution time constant
			{1.00, 1.00, 1.00, 1.06, 1.21, 1.56}, // main storage constraint
			{0.87, 0.87, 1.00, 1.15, 1.30, 1.30}, // virtual machine volatility
			{0.87, 0.87, 1.00, 1.07, 1.15, 1.15}, // computer turnaround time
			{1.46, 1.19, 1.00, 0.86, 0.71, 0.71}, // analyst capabilities
			{1.29, 1.13, 1.00, 0.91, 0.82, 0.82}, // applications experience
			{1.42, 1.17, 1.00, 0.86, 0.70, 0.70}, // programmer capability
			{1.21, 1.10, 1.00, 0.90, 0.90, 0.90}, // virtual machine experience
			{1.14, 1.07, 1.00, 0.95, 0.95, 0.95}, // programming language experience
			{1.24, 1.10, 1.00, 0.91, 0.82, 0.82}, // use of modern programming practices
			{1.24, 1.10, 1.00, 0.91, 0.83, 0.83}, // use of software tools
			{1.23, 1.08, 1.00, 1.04, 1.10, 1.10}, // required development schedule
		};
		// used for selecting the cost driver value
		float costDrivers[costDriverSize];

	public:
		COCOMO() = default;
		// Intermediate COCOMO calculator
		float getEstimate();
		// set a and b, 1 = organic, 2 = nominal, 3 = embedded
		void setConstants(short mode);
		// set estimated thousand lines of code
		void setKDSI(float kdsi);
		// mutator for costDrivers[]
		void setCostDrivers(float values[costDriverSize]);
		// initialize all costDriver values to nominal
		void initCostDrivers();
};

#endif
