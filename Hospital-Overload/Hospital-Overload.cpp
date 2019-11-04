// Jacob Hardman
// Comp Sci 1
// Professor Jennifer Bailey
// 11/3/19

#include <iostream>
#include <iomanip>

using namespace std;

double CalculateCharge(double finalTotal, double inPatientCharges) {

	double medicationCharges;
	do {
		cout << "Medication charges: $";
		cin >> medicationCharges;
		if (medicationCharges < 0) { cout << "Please enter a valid number." << endl; }
	} while (medicationCharges < 0);

	double otherCharges;
	do {
		cout << "Lab fees and other service charges: $";
		cin >> otherCharges;
		if (otherCharges < 0) { cout << "Please enter a valid number." << endl; }
	} while (otherCharges < 0);

	finalTotal = inPatientCharges + medicationCharges + otherCharges;

	return finalTotal;
}

double CalculateCharge(double finalTotal) {

	double medicationCharges;
	do {
		cout << "Medication charges: $";
		cin >> medicationCharges;
		if (medicationCharges < 0) { cout << "Please enter a valid number." << endl; }
	} while (medicationCharges < 0);

	double otherCharges;
	do {
		cout << "Lab fees and other service charges: $";
		cin >> otherCharges;
		if (otherCharges < 0) { cout << "Please enter a valid number." << endl; }
	} while (otherCharges < 0);

	finalTotal = medicationCharges + otherCharges;

	return finalTotal;
}

int main()
{
	bool isRunning = true;
	string userInput;
	double finalTotal = 0.00;

	while (isRunning) {
		cout << "This program will compute patient hospital charges." << endl;

		bool inPatient = false;

		bool userConfirm = false;
		while (userConfirm == false) {
			cout << "In-Patient or Out-Patient? (I or O): ";
			cin >> userInput;

			if (userInput == "I" || userInput == "i") {
				inPatient = true;
				userConfirm = true;
			}
			else if (userInput == "O" || userInput == "o") {
				inPatient = false;
				userConfirm = true;
			}
			else {
				cout << "Please enter a valid selection." << endl;
			}
		}

		if (inPatient) {
			double daysInHospital;
			do {
				cout << "Number of days in the hospital: ";
				cin >> daysInHospital;
				if (daysInHospital < 0) { cout << "Please enter a valid number." << endl; }
			} while (daysInHospital < 0);

			double roomRate;
			do {
				cout << "Daily room rate: $";
				cin >> roomRate;
				if (roomRate < 0) { cout << "Please enter a valid number." << endl; }
			} while (roomRate < 0);

			double inPatientCharges = daysInHospital * roomRate;

			finalTotal = CalculateCharge(finalTotal, inPatientCharges);
		}
		else {
			finalTotal = CalculateCharge(finalTotal);
		}

		cout << fixed << setprecision(2) << "The total charges are: $" << finalTotal << endl;

		userConfirm = false;
		while (userConfirm == false) {
			cout << "Would you like to run the program again? (Y/N): ";
			cin >> userInput;

			if (userInput == "Y" || userInput == "y") {
				userConfirm = true;
				cout << endl;
			}
			else if (userInput == "N" || userInput == "n") {
				userConfirm = true;
				isRunning = false;
			}
			else {
				cout << "Please enter a valid selection." << endl;
			}
		}
	}
}
