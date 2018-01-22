//******************************************************************************
// $Id: payroll.cpp,v 1.1 2017/12/09 dgkimsp Exp $
//
// Payroll program
// This program computes each employee's wages and
// the total company payroll
//
//******************************************************************************

#include <iostream>
#include <fstream>		// For file I/O

void CalcPay(float, float, float&);

const float MAX_HOURS = 40.0;	// Maximum normal work hours
const float OVERTIME = 1.5;	// overtime pay rate factor

int main()
{
	float payRate;		// Employee's pay rate
	float hours;		// hours worked
	float wages;		// Wages earend
	float total;		// Total company payroll
	int empNum;		// Employee ID number
	ofstream payFile;	// Company payroll file

	payFile.open("payfile.dat");		// Open the output file
	total = 0.0;				// Initialize total

	cout << "Enter employee number: ";	// Prompt
	cin >> empNum;				// Read employee ID no.
	while (empNum != 0)
	{
		cout << "Enter pay rate: ";	// Prompt
		cin >> payRate;			// Read hourly pay rate
		cout << "Enter hours worked: ";	// Prompt
		cin >> hours;			// Read hours worked
		CalcPay(payRate, hours, wages);	// Compute wages
		total = total + wages;		// Add wages to total
		payFile << empNum << payRate
			<< hours << wages;	// Put results into file
		cout << "Enter employee number: "; // Prompt
		cin >> empNum;			// Read ID number
	}
	cout << "Total payroll is "		// Print total payroll
		<< total << endl;			//   on screen
	return 0;					// Indicate successful
}							// completion

void CalcPay( /* in */ float payRate,		// Employee's pay rate
	/* in */ float hours,			// Hours worked
	/* out */ float& wages )		// Wages earned
{
	// CalcPay computes wages from the employee's pay rate
	// and the hours worked, taking overtime into account
	if (hours > MAX_HOURS)			// Is there overtime?
		wages = (MAX_HOURS * payRate) +		// Yes
			(hours - MAX_HOURS) * payRate * OVERTIME;
	else
		wages = hours * payRate;	// No
}
