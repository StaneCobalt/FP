#ifndef ESTIMATE_H
#define ESTIMATE_H

public class Estimate {
	private:
		//complexities: simple, average, complex
		const int input[3] = {3,4,6};
		const int output[3] = {4,5,7};
		const int inquiry[3] = {3,4,6}, 
		const int master[3] = {7,10,15};
		const int interface[3] = {5,7,10};
		
		//number of inputs, outputs, inquiries, masters, and interfaces
		int nInp, nOut, nInq, nMaf, nInf;
		
		/*	measures for influence, goes on a scale of 0 to 5 per factor
		 *	data communication, distributed data processing, performance criteria, heavily utilized hardware,
		 *	high transaction rates, online data entry, end-user proficiency, online updating, complex computations,
		 *	reusability, ease of installation, ease of operation, portability, maintainability */
		int dcomm, dpro, perf, util, trans, entry, eff, upd, comp, reuse, inst, oper, port, maint;
	public:
		Estimate() = default;
		// function points calculator
		float FP(int inp, int out, int inq, int maf, int inf);
		// mutator for components for UFP
		void setComponents(int nInp, int nOut, int nInq, int nMaf, int nInf);
		// mutator for factors for DI and TCF
		void setTechnicalFactors(int dcomm, int dpro, int perf, int util, int trans, int entry, int eff, 
			int upd, int comp, int reuse, int inst, int oper, int port, int maint);
};

void Estimate::setComponents(int nInp, int nOut, int nInq, int nMaf, int nInf){
	this-> nInp = nInp;
	this-> nOut = nOut;
	this-> nInq = nInq;
	this-> nMaf = nMaf;
	this-> nInf = nInf;
}

void Estimate::setTechnicalFactors(int dcomm, int dpro, int perf, int util, int trans, int entry, int eff, 
	int upd, int comp, int reuse, int inst, int oper, int port, int maint){
	this->dcomm = dcomm;
	this->dpro = dpro;
	this->perf = perf;
	this->util = util;
	this->trans = trans;
	this->entry = entry;
	this->eff = eff;
	this->upd = upd;
	this->comp = comp;
	this->reuse = reuse;
	this->inst = inst;
	this->oper = oper;
	this->port = port;
	this->maint = maint;
}

float Estimate::FP(int inp, int out, int inq, int maf, int inf){
	// unadjusted function point
	int ufp = (nInp * input[inp]) + (nOut * output[out]) + (nInq + inquiry[inq]) + 
		(nMaf + master[maf]) + (nInf + interface[inf]);
	
	// degree of influence, range 0 to 70
	int di = dcomm + dpro + perf + util + trans + entry + eff + 
		upd + comp + reuse + inst + oper + port + maint;
	
	// technical complexity factor, range 0.65 to 1.35
	float tcf = 0.65 + 0.01 * di;
	
	return (ufp * tcf);
}

#endif
