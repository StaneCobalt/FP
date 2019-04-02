#ifndef FUNCTION_POINT_H
#define FUNCTION_POINT_H

//! The Function Point Class

/*!
	Calculates Complexity based on the following:
	number of functions to be implemented,
	complexity of each function,
	and function type.
*/


class FunctionPoint {
	protected:
		// complexities: simple, average, complex
		const short input[3] = {3,4,6}; ///< holds complexity values for the input type of component
		const short output[3] = {4,5,7}; ///< holds complexity values for the output type of component
		const short inquiry[3] = {3,4,6}; ///< holds complexity values for the inquiry type of component
		const short master[3] = {7,10,15}; ///< holds complexity values for the master type of component
		const short interface[3] = {5,7,10}; ///< holds complexity values for the interface type of component
		
        // complexities range 0 to 2
        short inp; ///< holds index for selecting input complexity
		short out; ///< holds index for selecting output complexity
		short inq; ///< holds index for selecting inquiry complexity
		short maf; ///< holds index for selecting master complexity
		short inf; ///< holds index for selecting interface complexity

		int nInp; ///< Number of inputs.
		int nOut; ///< Number of outputs.
		int nInq; ///< Number of inquiries.
		int nMaf; ///< Number of masters.
		int nInf; ///< Number of interfaces.
		
		//	measures for influence, goes on a scale of 0 to 5 per factor
		short dcomm; ///< Measure of influence for data communication
		short dpro; ///< Measure of influence for distributed data processing
		short perf; ///< Measure of influence for performance criteria
		short util; ///< Measure of influence for heavily utilized hardware
		short trans; ///< Measure of influence for high transaction rates
		short entry; ///< Measure of influence for online data entry
		short eff; ///< Measure of influence for end-user proficiency
		short upd; ///< Measure of influence for online updating
		short comp; ///< Measure of influence for complex computations
		short reuse; ///< Measure of influence for reusability
		short inst; ///< Measure of influence for ease of installation
		short oper; ///< Measure of influence for ease of operation
		short port; ///< Measure of influence for portability
		short maint; ///< Measure of influence for maintainability
		
	public:
		//! Default Constructor
		FunctionPoint() = default;
		//! Performs function points calculation
		float getEstimate();
        //! A mutator for complexities
        void setComplexities(short inp, short out, short inq, short maf, short inf);
		//! A mutator for components for Unadjusted Function Points (UFP)
		void setComponents(int nInp, int nOut, int nInq, int nMaf, int nInf);
		//! A mutator for factors for Degree of Influence (DI) and Technical Complexity Factors (TCF)
		void setTechnicalFactors(int dcomm, int dpro, int perf, int util, int trans, int entry, 
            int eff, int upd, int comp, int reuse, int inst, int oper, int port, int maint);
};

#endif
