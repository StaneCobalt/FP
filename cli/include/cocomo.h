#ifndef COCOMO_H
#define COCOMO_H

const unsigned costDriverSize = 15; ///< references the number of cost drivers available

//! The COCOMO class

/*!
	This class performs both basic and intermediate COCOMO operations.
	Basic COCOMO just uses a, b, and kdsi to find its estimate.
	Intermediate COCOMO uses a, b, kdsi, and cost drivers to refine the estimate.
*/

class COCOMO {
	protected:
		float a; ///< The value of the multiplier.
		float b; ///< The value of the exponent.
		float kdsi; ///< The lines of code in thousands.
		
		/*! Cost drivers used for refining the estimate in intermediate COCOMO.
			Rankings: very low, low, nominal, high, very high, extra high
		*/
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

		float costDrivers[costDriverSize]; ///< Used for selecting the cost driver values.

	public:
		//! Default constructor
		COCOMO() = default;
		//! Performs COCOMO calculations
		float getEstimate();
		//! A mutator for a and b
		/*!
			\param mode is a short. 1 = organic, 2 = semi-detached, 3 = embedded, default is organic.
			\param isIntermediate is a bool. It determines whether to set a and b according to basic or intermediate COCOMO values.
		*/
		void setConstants(short mode, bool isIntermediate);
		//! A mutator for the estimated thousand lines of code
		void setKDSI(float kdsi);
		//! A mutator for costDrivers[]
		void setCostDrivers(float values[costDriverSize]);
		//! Initializes all costDriver values to the semi-detached values
		void initCostDrivers();
};

#endif
