/*
Name: 		Corey Lee
Assignment:	A01 resubmission

Description:	The program prompts the user to input
		the plan type they are on. Then prompts
		for the amount of GB they used. The program
		will output if the user went below or out of 
		range for their type of plan.

Input: 		char charHolder, double gbUsage

Output:		Plan type and cost the user may owe
		double planCharges, double gbUsage

Sources: 	a01 feedback, a01 google doc
*/
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

void welcome();
void totalCost_S(double planCharges, double gbUsage),
totalCost_M(double planCharges, double gbUsage),
totalCost_L(double planCharges, double gbUsage);
char planType();
double planTypeCharges(char charholder);
double planGbUse();

const int PLAN_S = 35.00;
const int PLAN_M = 50.00;
const int PLAN_L = 70.00;
const int PLAN_U = 75.00;

int main() {
	char charHolder = ' ';
	double planCharges = 0.0;
	double gbUsage = 0.0;

	welcome();
	charHolder = planType();   //returns char chosen
	planCharges = planTypeCharges(charHolder);   //returns plan cost
	gbUsage = planGbUse();

	cout << fixed << setprecision(2);
	if (planCharges == PLAN_S) {
		totalCost_S(planCharges, gbUsage);
	}
	else if (planCharges == PLAN_M) {
		totalCost_M(planCharges, gbUsage);
	}
	else if (planCharges == PLAN_L) {
		totalCost_L(planCharges, gbUsage);
	}
	else {
		cout << "Plan charges: $" << planCharges << endl;
		cout << "Total cost: $" << PLAN_U << endl;
	}
	cout << "Would you like to run the program again?" << endl;
	cin.clear();
	cin.ignore(100, '\n');
	cin.get(charHolder);
	while (!(toupper(charHolder) == 'Y' || toupper(charHolder) == 'N')) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid input, Please try again." << endl;
		cout << "Would you like to run the program again?" << endl;
		cin.get(charHolder);
	}
	switch (charHolder) {
		case 'y':
		case 'Y':
			cin.clear();
			cin.ignore(100, '\n');
			main();
			break;
		case 'n':
		case 'N':
			cout << "Thank you for choosing Mint Mobile" << endl;
			break;
	}
	return 0;
}
void welcome() {
	cout << "***** Welcomoe to Mint Mobile ***** \n" << endl;
	cout << "Let's calculate your monthly bill! \n" << endl;
	cout << "S: 2GB $35/mo* \n" << endl;
	cout << "M: 4GB $50/mo* \n" << endl;
	cout << "L: 8GB $70/mo* \n" << endl;
	cout << "U: Unlimited $75/mo* \n" << endl;
	cout << "*Overage charges $15 per GB \n" << endl;
	cout << "Which plan are you on: " << endl;
}
char planType() {
	char option = ' ';
	cin.get(option);
	cin.ignore(100, '\n');
	cin.clear();
	while (!(toupper(option) == 'S' ||
		toupper(option) == 'M' ||
		toupper(option) == 'L' ||
		toupper(option) == 'U')) {
			cout << "Invalid answer" << endl;
			cout << "Which plan are you on: " << endl;
			cin.get(option);
			cin.ignore(100, '\n');
			cin.clear();
	}
	return option;
}
double planTypeCharges(char charHolder) {
	switch (charHolder) {
		case 's':
		case 'S':
			return PLAN_S;
			break;
		case 'm':
		case 'M':
			return PLAN_M;
			break;
		case 'l':
		case 'L':
			return PLAN_L;
			break;
		case 'u':
		case 'U':
			return PLAN_U;
			break;
	}
}
double planGbUse() {
	double gbUse = 0.0;
	cout << "How many GB did you use last month?" << endl;
	cin >> gbUse;
	while (gbUse < 0 || !cin) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid answer" << endl;
		cout << "How many GB did you use last month?" << endl;
		cin >> gbUse;
	}
	return gbUse;
}
void totalCost_S(double planCharges, double gbUsage) {
	double total = 0.0;
	if (gbUsage <= 2.00) {
		cout << "Plan charges: $" << planCharges << endl;
		cout << "Total charges: $" << planCharges << endl;
	}
	else if (gbUsage > 2.00) {
		gbUsage = (ceil(gbUsage) - 2.00) * 15.00;
		total = PLAN_S + gbUsage;
		cout << "Plan charges: $" << planCharges << endl;
		cout << "Overage charges: $" << gbUsage << endl;
		cout << "Total charges: $" << total << endl;
		if (total > 75.00) {
		cout << "Save $" <<  total - 75.00 << " by switching to unlimited!" << endl;
		}
	}
}
void totalCost_M(double planCharges, double gbUsage) {
	double total = 0.0;
	if (gbUsage <= 4.00) {
		cout << "Plan charges: $" << planCharges << endl;
		cout << "Total charges: $" << planCharges << endl;
	}
	else if (gbUsage > 4.00) {
		gbUsage = (ceil(gbUsage) - 4.00) * 15.00;
		total = PLAN_M + gbUsage;
		cout << "Plan charges: $" << planCharges << endl;
		cout << "Overage Charges: $" << gbUsage << endl;
		cout << "Total charges: $" << total << endl;
		if (total > 75.00) {
			cout << "Save $" << total - 75.00 << " by switching to unlimited!" << endl;
		}
	}
}
void totalCost_L(double planCharges, double gbUsage) {
	double total = 0.0;
	if (gbUsage <= 8.00) {
		cout << "Plan charges: $" << planCharges << endl;
		cout << "Total charges: $" << planCharges << endl;
	}
	else if (gbUsage > 8.00) {
		gbUsage = (ceil(gbUsage) - 8.00) * 15.00;
		total = PLAN_L + gbUsage;
		cout << "Plan charges: $" << planCharges << endl;
		cout << "Overage charges: $" << gbUsage << endl;
		cout << "Total charges: $" << total << endl;
		if (total > 75.00) {
			cout << "Save $" << total - 75.00 << " by switching to unlimited!" << endl;
		}
	}
}
