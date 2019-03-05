#include "../include/functionPoint.h"
#include <iostream>
using std::cout;

// mutator for complexities
void FunctionPoint::setComplexities(short inp, short out, short inq, short maf, short inf){
	short maxRange = 2;
    this->inp = (inp >= 0 && inp <= maxRange) ? inp : maxRange;
    this->out = (out >= 0 && out <= maxRange) ? out : maxRange;
    this->inq = (inq >= 0 && inq <= maxRange) ? inq : maxRange;
    this->maf = (maf >= 0 && maf <= maxRange) ? maf : maxRange;
    this->inf = (inf >= 0 && inf <= maxRange) ? inf : maxRange;
}

// mutator for components for UFP
void FunctionPoint::setComponents(int nInp, int nOut, int nInq, int nMaf, int nInf){
	this-> nInp = nInp;
	this-> nOut = nOut;
	this-> nInq = nInq;
	this-> nMaf = nMaf;
	this-> nInf = nInf;
}

// mutator for factors for DI and TCF
void FunctionPoint::setTechnicalFactors(int dcomm, int dpro, int perf, int util, int trans, int entry, 
    int eff, int upd, int comp, int reuse, int inst, int oper, int port, int maint){
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

// function points calculator
float FunctionPoint::getEstimate(){
	// unadjusted function point
	int ufp = (nInp * input[inp]) + (nOut * output[out]) + (nInq * inquiry[inq]) + (nMaf * master[maf]) + (nInf * interface[inf]);
	
	// degree of influence, range 0 to 70
	int di = dcomm + dpro + perf + util + trans + entry + eff + upd + comp + 
        reuse + inst + oper + port + maint;

	// technical complexity factor, range 0.65 to 1.35
	float tcf = 0.65f + 0.01f * di;

	return (ufp * tcf);
}
