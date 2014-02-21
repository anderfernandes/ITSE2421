/********************************
* Student: Anderson Fernandes	*
* Class: ITSE 2421				*
* Instructor: Doug Edwards		*
*********************************/

#include "HospitalCharges.h"

int main()
{
	char patientType;             // I=in-patient, O=out-patient
	int  days;                    // Number of days of hospital stay
	double medication,            // Total medication charges
		   services,              // Total for tests and other services
		   totalCharges;          // Total of all charges

	// Input and validate patient type
	cout << "This program will compute patient hospital charges.\n\n";
	cout << "Enter I for in-patient or O for out-patient: ";
	cin  >> patientType;
	patientType = toupper(patientType); // Make I or O uppercase

	while (patientType != 'I' && patientType != 'O') 
	{
		cout << "Please enter I or O: ";
		cin  >> patientType;
		patientType = toupper(patientType);
  	} 
	cout << endl;

	// Input and validate data relevant to in-patients
	if (patientType == 'I') 
  	{
		cout << "\nNumber of days in the hospital: ";
     	cin  >> days;
		days = static_cast<int>(validateData(days, "days in hospital"));
		
		cout << "\nDaily room rate: $";
	}
   
	// Input and validate data relevant to all patients
	cout << "\nLab fees and other service charges: $";
	cin  >> services;
	services = validateData(services, "lab fees and other service charges");

	cout << "\nMedication charges: $";
	cin  >> medication;

	// Ask if insurance paid any part of the bill
	bool bInsurancePaid = didInsurancePay();

	// Get the insurance paid amount & validate input
	double insurance = 0.0;
	if (bInsurancePaid)
	{
		cout << "\nInsurance paid this amount: $";
		cin >> insurance;
		insurance = validateData(insurance, "insurance paid");
	}

	medication = validateData(medication, "medication charges");

  	// Call correct patientCharges function to return total charges
	if (patientType == 'I')
		totalCharges = patientCharges(days, ROOM_RATE, medication, services);
	else
		totalCharges = patientCharges(medication, services);

	// call correct patientcharges function to subtract insurance payment
	totalCharges = patientCharges(bInsurancePaid, totalCharges, insurance);

	// Display the billing statment
	cout << fixed << showpoint << setprecision(2) << endl << endl;
	cout << "************************** \n";
	cout << "Hospital Billing Statement \n";
	cout << "************************** \n";
	if (patientType == 'I')
		cout << "Room charges    $" << setw(8) << days*ROOM_RATE << endl;
	if (services > 0.0)
		cout << "Lab & Services  $" << setw(8) << services << endl;
	if (medication > 0.0)
		cout << "Medication      $" << setw(8) << medication << endl;
	if (bInsurancePaid)
		cout << "Insurance paid -$" << setw(8) << insurance << endl;
	cout    << "Total charges   $" << setw(8) << totalCharges << endl;
	cout << "**************************\n";
  
	writeFile(days, services, medication, insurance, totalCharges);

	return 0;
}// end main function