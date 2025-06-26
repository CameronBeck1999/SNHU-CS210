/*
Name: Cameron Beck
Date: 6/5/2025
CS-210
Project 2 Airgead Banking
*/

#include "Project2.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <stdexcept>
using namespace std;

class Bank
{
public:
	//Mutators
	void SetInvestmentAmount(double t_initialAmount);
	void SetMonthlyDeposit(double t_monthlyDeposit);
	void SetAnnualInterest(double t_annualInterest);
	void SetYears(double t_years);
	//Accessors
	double GetInvestmentAmount() const;
	double GetMonthlyDeposit() const;
	int GetAnnualInterest() const;
	int GetYears() const;
	//Prints out the DataInput menu with all of the user's inputs
	void Print() const;
	//Calculating Functions
	void BalanceWithoutMonthlyDeposit(double t_initialAmount, int t_annualInterest, int t_years);
	void BalanceWithMonthlyDeposit(double t_initialAmount, int t_annualInterest, int t_years, double t_monthlyDeposit);
	void ClosingBalance(double t_initialAmount, int t_annualInterest, int t_years, double t_monthlyDeposit);
private:
	//user Inital private values
	double m_investmentAmount;
	double m_monthlyDeposit;
	double m_annualInterest;
	double m_years;
};

void Bank::SetInvestmentAmount(double t_initialAmount) {
	m_investmentAmount = t_initialAmount;
}

void Bank::SetMonthlyDeposit(double t_deposit) {
	m_monthlyDeposit = t_deposit;
}

void Bank::SetAnnualInterest(double t_interest) {
	m_annualInterest = t_interest;
}

void Bank::SetYears(double t_years) {
	m_years = t_years;
}

double Bank::GetInvestmentAmount() const {
	return m_investmentAmount;
}

double Bank::GetMonthlyDeposit() const {
	return m_monthlyDeposit;
}

int Bank::GetAnnualInterest() const {
	return m_annualInterest;
}

int Bank::GetYears() const {
	return m_years;
}

void Bank::Print() const {
	//Prints all of the user's input afterwards
	cout << endl;
	cout << "********************************" << endl;
	cout << "********** Data Input **********" << endl;
	cout << "Initial Investment Amount: $" << fixed << setprecision(2) << m_investmentAmount << endl;
	cout << "Monthly Deposit: $" << fixed << setprecision(2) << m_monthlyDeposit << endl;
	cout << "Annual Interest: %" << fixed << setprecision(0) << m_annualInterest << endl;
	cout << "Number of years: " << fixed << setprecision(0) << m_years << endl;
	cout << "Press any key to continue..." << endl;
}

void Bank::BalanceWithoutMonthlyDeposit(double t_initialAmount, int t_annualInterest, int t_years) {
	//Initially starts out with the input inital amount
	double m_totalAmount = t_initialAmount;
	double m_interestAmount;

	cout << "\tBalance and Interest Without Additional Monthly Deposits  " << endl;
	cout << "===========================================================================" << endl;
	cout << " Year\t\t   Year End Balance\t\t Year End Earned Interest " << endl;
	cout << "---------------------------------------------------------------------------" << endl;

	for (int i = 1; i <= t_years; i++) {
		//Calculations for the balance and interests each year
		m_interestAmount = m_totalAmount * (t_annualInterest / 100.0);
		m_totalAmount = m_totalAmount + m_interestAmount;

		//Prints out all of the calculation for each year.
		cout << "    " << i << "\t\t\t $" << fixed << setprecision(2) << m_totalAmount << "\t\t\t\t\t $" << fixed << setprecision(2) << m_interestAmount << endl;

	}
	cout << endl;
}

void Bank::BalanceWithMonthlyDeposit(double t_initialAmount, int t_annualInterest, int t_years, double t_monthlyDeposit) {
	//Initially starts out with the input inital amount
	double m_totalAmount = t_initialAmount;
	double m_interestAmount;

	cout << "\t Balance and Interest With Additional Monthly Deposits  " << endl;
	cout << "===========================================================================" << endl;
	cout << " Year\t\t   Year End Balance\t\t Year End Earned Interest " << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	for (int i = 1; i <= t_years; i++) {//Year

		double m_yearlyInterest = 0; //Every year the yearly interest resets to 0

		for (int j = 1; j <= 12; j++) {//Month

			//Calculations for the total amount in 1 year
			m_interestAmount = (m_totalAmount + t_monthlyDeposit) * ((t_annualInterest / 100.00) / 12.00);
			m_yearlyInterest += m_interestAmount;
			m_totalAmount = m_totalAmount + t_monthlyDeposit + m_interestAmount;
			
		}
		//prints a line with all of the information from the calculation every year
		cout << "    " << i << "\t\t\t $" << fixed << setprecision(2) << m_totalAmount << "\t\t\t\t $" << fixed << setprecision(2) << m_yearlyInterest << endl;

	}
	cout << endl;
}

void Bank::ClosingBalance(double t_initialAmount, int t_annualInterest, int t_years, double t_monthlyDeposit) {
	/*This function calculates the closing balance based on the opening balance,
	* monthly deposit, the sum of the first two variables, the interest, and lastly
	* the closing balance based on the sum of the total of the opening balance and monthly deposit
	* plus the interest. (From Step 4 from the directions)
	*/
	
	int m_month = t_years * 12;
	double m_openingAmount = t_initialAmount;
	double m_totalAmount = 0.0;
	double m_closingAmount = 0.0;
	cout << "=======================================================================================================================" << endl;
	cout << "Month\t Opening Amount\t Deposited Amount    $Total\t $Interest\t Closing Balance" << endl;
	cout << "=======================================================================================================================" << endl;

	for (int i = 1; i <= m_month; i++) {
		//Calculations to determine the closing amount.
		m_totalAmount = m_openingAmount + t_monthlyDeposit;
		double m_interestAmount = (m_openingAmount + t_monthlyDeposit) * ((t_annualInterest / 100.0) / 12.0);
		m_closingAmount = (m_totalAmount + m_interestAmount);

		//This displays all of the values for the month based on the calculations from above.
		cout << i << "\t     $" << m_openingAmount << "\t     $" << t_monthlyDeposit << "\t     $" << m_totalAmount;
		cout << "\t     $" << m_interestAmount << "\t     $" << m_closingAmount << endl;

		//The opening amount is the closing amount from the previous month and shall
		//be carried to the next loop.
		m_openingAmount = m_closingAmount;
	}
}


static double DoubleInputValidation() {
	//This function checks if the input is valid
	double input;

	while (true) {
		if (cin >> input) {//Valid input, so the loop breaks returning the valid input
			break;
		}
		else {//Invalid, so the message will display prompting another input from the user
			cout << "Invalid input! Value must be a number, try again!";
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}
	return input;

}

static int IntegerInputValidation() {
	//This function checks if the input is valid
	int input;

	while (true) {
		if (cin >> input) {//Valid input, so the loop breaks returning the valid input
			break;
		}
		else {//Invalid, so the message will display prompting another input from the user
			cout << "Invalid input! Value must be a number, try again!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}
	return input;

}

int main() {
	/*Bank is a separate class that focuses on the user's
	* inputs. It comest with accessors, mutators, and a print statement
	* that prints the following message below but with all of the user's inputs
	* filling in the blanks.
	*/
	Bank user{};

	//Setting up necessary values for the main function
	double m_investment;
	double m_deposit;
	int m_interest;
	int m_years;
	char key = 'a';

	while (key != 'q') {//As long as the user char input isn't 'q', the loop continues.
		try {
			cout << "********************************" << endl;
			cout << "********** Data Input **********" << endl;
			cin.clear();

			//Gathering input from user
			//All inputs are transferred and stored to the Bank class
			cout << "Initial Investment Amount: $";
			m_investment = DoubleInputValidation();
			user.SetInvestmentAmount(m_investment);
			if (m_investment < 0) {
				throw runtime_error("Invalid input! Value cannot be negative.");
			}


			cout << "Monthly Deposit: $";
			m_deposit = DoubleInputValidation();
			if (m_deposit < 0) {
				throw runtime_error("Invalid input! Value cannot be negative.");
			}
			user.SetMonthlyDeposit(m_deposit);

			cout << "Annual Interest: %";
			m_interest = IntegerInputValidation();
			if (m_interest < 0) {
				throw runtime_error("Invalid input! Value cannot be negative.");
			}
			user.SetAnnualInterest(m_interest);

			cout << "Number of years: ";
			m_years = IntegerInputValidation();
			if (m_years <= 0) {
				throw runtime_error("Invalid input! Value must be 1 or greater.");
			}
			user.SetYears(m_years);

			//Displays everything the user has inputted thus far
			user.Print();

			//key input is when the prompt tells the user to press any key to continue.
			cin >> key;
			//If-statement for "Press any key to continue..." so long it's not NULL
			if (key != NULL) {

				//Prints out all three reports
				user.BalanceWithoutMonthlyDeposit(user.GetInvestmentAmount(), user.GetAnnualInterest(), user.GetYears());
				user.BalanceWithMonthlyDeposit(user.GetInvestmentAmount(), user.GetAnnualInterest(), user.GetYears(), user.GetMonthlyDeposit());
				user.ClosingBalance(user.GetInvestmentAmount(), user.GetAnnualInterest(), user.GetYears(), user.GetMonthlyDeposit());
			}


		}
		catch (runtime_error& e) {//Catches the input error if less than 0.
			cout << e.what() << endl;
		}
		//After everything has been accounted for, with the printing of the users
		//banking information, the user will be asked to either hit 'q' to exit
		//or hit another key to start over from the beginning.
		cout << "Enter 'q' to quit or any other key to continue... ";
		cin >> key;
		cin.clear();
		cin.ignore(10000, '\n');
	}

	return 0;
}
