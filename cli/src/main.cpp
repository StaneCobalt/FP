#include "../include/cocomo.h"
#include "../include/functionPoint.h"
#include <iostream>

void FunctionPointHelper();
void COCOMOHelper(bool costDriversUsed);

int main(){
	
	short choice = 0;
	bool flagged = true;
	
	while(flagged){
		std::cout << "What would you like to estimate?\n1) Function Points\n2) Basic COCOMO\n3) Intermediate COCOMO";
		std::cin >> choice;
		switch(choice){
			case 1:
				FunctionPointHelper();
				flagged = false;
				break;
			case 2:
				COCOMOHelper(false);
				flagged = false;
				break;
			case 3:
				COCOMOHelper(true);
				flagged = false;
				break;
			default:
				std::cout << "Invalid option.\n";
				break;
		}
	}
	
	std::cout << std::endl;
	system("pause");
	return 0;
}

void FunctionPointHelper(){
	short fComp[5]; // function complexities
	int nFunc[5]; // number of function types
		std::cout << "Number of Inputs: ";
		std::cin >> nFunc[0];
		std::cout << "Complexity of Inputs (0-2): ";
		std::cin >> fComp[0];
		std::cout << "Number of Outputs: ";
		std::cin >> nFunc[1];
		std::cout << "Complexity of Outputs (0-2): ";
		std::cin >> fComp[1];
		std::cout << "Number of Inquiries: ";
		std::cin >> nFunc[2];
		std::cout << "Complexity of Inquiries (0-2): ";
		std::cin >> fComp[2];
		std::cout << "Number of Masters: ";
		std::cin >> nFunc[3];
		std::cout << "Complexity of Masters (0-2): ";
		std::cin >> fComp[3];
		std::cout << "Number of Interfaces: ";
		std::cin >> nFunc[4];
		std::cout << "Complexity of Interfaces (0-2): ";
		std::cin >> fComp[4];
	
	short tf[14]; // technical factors
		std::cout << "Influence of Data Communication (0-5): ";
		std::cin >> tf[0];
		std::cout << "Influence of Distributed Data Processing (0-5): ";
		std::cin >> tf[1];
		std::cout << "Influence of Performance Criteria (0-5): ";
		std::cin >> tf[2];
		std::cout << "Influence of Heavily Utilized Hardware (0-5): ";
		std::cin >> tf[3];
		std::cout << "Influence of High Transaction Rates (0-5): ";
		std::cin >> tf[4];
		std::cout << "Influence of Online Data Entry (0-5): ";
		std::cin >> tf[5];
		std::cout << "Influence of End-User Proficiency (0-5): ";
		std::cin >> tf[6];
		std::cout << "Influence of Online Updating (0-5): ";
		std::cin >> tf[7];
		std::cout << "Influence of Complex Computations (0-5): ";
		std::cin >> tf[8];
		std::cout << "Influence of Reusability (0-5): ";
		std::cin >> tf[9];
		std::cout << "Influence of Ease of Installation (0-5): ";
		std::cin >> tf[10];
		std::cout << "Influence of Ease of Operation (0-5): ";
		std::cin >> tf[11];
		std::cout << "Influence of Portability (0-5): ";
		std::cin >> tf[12];
		std::cout << "Influence of Maintainability (0-5): ";
		std::cin >> tf[13];
	
	FunctionPoint FP;
		FP.setComplexities(fComp[0],fComp[1],fComp[2],fComp[3],fComp[4]);
		FP.setComponents(nFunc[0], nFunc[1], nFunc[2], nFunc[3], nFunc[4]);
		FP.setTechnicalFactors(tf[0],tf[1],tf[2],tf[3],tf[4],tf[5],tf[6],tf[7],tf[8],tf[9],tf[10],tf[11],tf[12],tf[13]);
		float estimate = FP.getEstimate();
		std::cout << "Function Points = " << estimate << std::endl;
}

void COCOMOHelper(bool costDriversUsed){
	short mode = 1;
		std::cout << "Select mode\n1) organic\n2) nominal\n3) embedded\n";
		std::cin >> mode;
	
	float kdsi = 1.0f;
		std::cout << "Enter KDSI (lines of code in thousands): ";
		std::cin >> kdsi;
	
	if(costDriversUsed){
		float costs[costDriverSize];
			std::cout << "Required software reliability (0-5): ";
			std::cin >> costs[0];
			std::cout << "Database size (0-5): ";
			std::cin >> costs[1];
			std::cout << "Product complexity (0-5): ";
			std::cin >> costs[2];
			std::cout << "Execution time constant (0-5): ";
			std::cin >> costs[3];
			std::cout << "Main storage constraint (0-5): ";
			std::cin >> costs[4];
			std::cout << "Virtual machine volatility (0-5): ";
			std::cin >> costs[5];
			std::cout << "Computer turnaround time (0-5): ";
			std::cin >> costs[6];
			std::cout << "Analyst capabilities (0-5): ";
			std::cin >> costs[7];
			std::cout << "Applications experience (0-5): ";
			std::cin >> costs[8];
			std::cout << "Programmer capability (0-5): ";
			std::cin >> costs[9];
			std::cout << "Virtual machine experience (0-5): ";
			std::cin >> costs[10];
			std::cout << "Programming language experience (0-5): ";
			std::cin >> costs[11];
			std::cout << "Use of modern programming practices (0-5): ";
			std::cin >> costs[12];
			std::cout << "Use of software tools (0-5): ";
			std::cin >> costs[13];
			std::cout << "Required development schedule (0-5): ";
			std::cin >> costs[14];
	}
	
	COCOMO cocomo;
		cocomo.setConstants(mode, costDriversUsed);
		cocomo.setKDSI(kdsi);
		if(costDriversUsed) {
			cocomo.setCostDrivers(costs);
		} else {
			cocomo.initCostDrivers();
		}
		float estimate = cocomo.getEstimate();
		std::cout << "Person-Hours = " << estimate << std::endl;
}
