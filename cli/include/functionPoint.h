#ifndef FUNCTION_POINT_H
#define FUNCTION_POINT_H

class FunctionPoint {
	private:
		//complexities: simple, average, complex
		const short input[3] = {3,4,6};
		const short output[3] = {4,5,7};
		const short inquiry[3] = {3,4,6};
		const short master[3] = {7,10,15};
		const short interface[3] = {5,7,10};
		
        // complexities range 0 to 2
        short inp, out, inq, maf, inf;

		//number of inputs, outputs, inquiries, masters, and interfaces
		int nInp, nOut, nInq, nMaf, nInf;
		
		/*	measures for influence, goes on a scale of 0 to 5 per factor
		 *	data communication, distributed data processing, performance criteria, heavily utilized hardware,
		 *	high transaction rates, online data entry, end-user proficiency, online updating, complex computations,
		 *	reusability, ease of installation, ease of operation, portability, maintainability */
		short dcomm, dpro, perf, util, trans, entry, eff, upd, comp, reuse, inst, oper, port, maint;
	public:
		FunctionPoint() = default;
		// function points calculator
		float getEstimate();
        // mutator for complexities
        void setComplexities(short inp, short out, short inq, short maf, short inf);
		// mutator for components for UFP
		void setComponents(int nInp, int nOut, int nInq, int nMaf, int nInf);
		// mutator for factors for DI and TCF
		void setTechnicalFactors(int dcomm, int dpro, int perf, int util, int trans, int entry, 
            int eff, int upd, int comp, int reuse, int inst, int oper, int port, int maint);
};

#endif