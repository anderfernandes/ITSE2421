/********************************
* Student: Anderson Fernandes	*
* Class: ITSE 2421				*
* Instructor: Doug Edwards		*
*********************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;

// Function prototypes
double validateData (double, string);
double patientCharges(int, double, double, double);  // In-patient
double patientCharges(double, double);			   	 // Out-patient
double patientCharges(bool, double, double);			   	 // Out-patient
bool didInsurancePay();
void writeFile(int, double, double, double, double); // Write to file

// Constants
const double ROOM_RATE = 150.0; // Daily Room Rate