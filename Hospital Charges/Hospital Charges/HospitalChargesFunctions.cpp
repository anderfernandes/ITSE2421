/********************************
* Student: Anderson Fernandes	*
* Class: ITSE 2421				*
* Instructor: Doug Edwards		*
*********************************/

// Hospital Charges
// This program computes and displays patient hospital charges.
// It uses a generalized function to validate all numeric data
// values, as well as a pair of overloaded functions.
#include "HospitalCharges.h"

/******************************************************
 *                     validateData                   *
 * This function is called by main to ensure that no  *
 * negative values are input                          *
 ******************************************************/
 double validateData (double input, string prompt)
 {
	 static int valCount = 0;
	 static int valError = 0;
	 /*valCount++;
	 cout << endl << valCount << " inputs validated.\n"
		  << "Press ENTER to continue...\n";
	 cin.ignore(); // to clear the \n from the previous input buffer
	 cin.get();*/

	 while (input < 0.0)
	 {
		 valError++;
		 cout << "This value cannot be less than 0. \n";
		 cout << "Please re-enter " << prompt << ": ";
		 cin  >> input;
	 }
	 if(valCount > 8)
	 {
		 cout << "\nYour validation errors are too high. "
			  << "The program will stop now and let you try again. "
			  << "press ENTER to Exit the program...\n";
		 cin.ignore();
		 cin.get();
		 exit(0);
	 }

	 return input;
	 
 }// end validateData Function

/*************************************************************
 *                        patientCharge                      *
 * This function is called by main to calculate and return   *
 * total patient charges for in-patients                     *
 *************************************************************/
double patientCharges(int days, double rate, double med, double serv)
{
	double charges = days * rate + med + serv;
	return charges;
	
}// end overload function patientCharges

/*************************************************************
 *                        patientCharge                      *
 * This function is called by main to calculate and return   *
 * total patient charges for out-patients                    *
 *************************************************************/
double patientCharges(double med, double serv)
{
	double charges = med + serv;
	return charges;
	
}// end overload function patientCharges

/*************************************************************
 *                        patientCharge                      *
 * This function is called by main to calculate and return   *
 * total patient charges for out-patients                    *
 *************************************************************/
double patientCharges(bool bInsPaid, double total, double insPay)
{
	return total - insPay;
}// end overload function patientCharges

/*************************************************************
 *                        didInsurancePay                    *
 * This function is called by main to acquire and return     *
 * true or false whether the patient's insurance paid		 *
 *************************************************************/

bool didInsurancePay()
{
	cout << "\nDid Insurance pay for part of this bill? (Y or N): ";
	char cInsYN;
	cin >> cInsYN; // Get user's response on Insurance
	cInsYN = toupper(cInsYN); //make the answer uppercase Y or N

	// Validate the insurance answer input
	while (cInsYN != 'Y' && cInsYN != 'N')
	{
		cout << "Please enter Y for yes or N for No: ";
		cin >> cInsYN; // Get user's response on Insurance
		cInsYN = toupper(cInsYN); // make the answer uppercase Y or N
	}
	// set the boolean insurance variable
	if (cInsYN == 'Y')
		return true;
	else
		return false;
}// end of function didInsurancePay

void writeFile(int d, double sV, double mD, double iN, double tC)
{
	ofstream billingStatement;
	billingStatement.open("BillingStatement.txt");
	billingStatement << "************************** \n";
	billingStatement << "Hospital Billing Statement \n";
	billingStatement << "************************** \n";
	billingStatement << "Room charges    $" << setw(8) << d*ROOM_RATE << endl;
	billingStatement << "Lab & Services  $" << setw(8) << sV << endl;
	billingStatement << "Medication      $" << setw(8) << mD << endl;
	billingStatement << "Insurance paid -$" << setw(8) << iN << endl;
	billingStatement    << "Total charges   $" << setw(8) << tC << endl;
	billingStatement << "**************************\n" << endl;
	billingStatement.close();

}