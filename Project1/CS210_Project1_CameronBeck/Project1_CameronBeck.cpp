#include "Project1_CameronBeck.h"
#include <string>
#include <iostream>
/*
Name: Cameron Beck
Date: 5/25/2025
Purpose: Create a C++ program designing a both a 12-Hour and 24-Hour clock from user input.
*/

using namespace std;


static void displayMenu() {
	//Prints all of the choices from the menu to the terminal for the user to see
	string starLine = "***********************";

	cout << starLine << endl;
	cout << "* 1 - Add One Hour    *" << endl;
	cout << "* 2 - Add One Minute  *" << endl;
	cout << "* 3 - Add One Second  *" << endl;
	cout << "* 4 - Exit Program    *" << endl;
	cout << starLine << endl;
}

static void display12HR(int hr, int min, int sec) {
	string amOrPM = "AM"; // AM by default unless otherwise
	//Both star spaces were made so the clock can fit in between the two in the middle.
	string leftStarSpace = "*     ";
	string rightStarSpace = "      *";
	char zeroChar = '0';//In case either argument is 0. That will be added before the single digit

	int rem24 = hr % 24;

	//If the hour input greater than 12, then that number is subtracted by 12 for thr PM output
	int amOrPMdif = hr - 12;

	//If the hour is 24, it's then resetted to 0 for midnight
	if (rem24 == 0) {
		hr = 0;
		amOrPM = "AM";
	}

	/*Below are the multiple if-else statements in order to determine the following:
	* - If the hour is greater than, equal to, or below 12.
	* - If hours, minutes and/or seconds is below 10 so we can input the '0'
	*   char before the number.
	*/

	if (hr == 0) {//Since Hour is 0, it would be midnight thus AM.
		if ((min < 10) && (sec >= 10)) {
			cout << leftStarSpace << 12 << ":" << zeroChar << min << ":" << sec << amOrPM << rightStarSpace << endl;
		}
		else if ((min >= 10) && (sec < 10)) {
			cout << leftStarSpace << 12 << ":" << min << ":" << zeroChar << sec << amOrPM << rightStarSpace << endl;
		}
		else if ((min < 10) && (sec < 10)) {
			cout << leftStarSpace << 12 << ":" << zeroChar << min << ":" << zeroChar << sec << amOrPM << rightStarSpace << endl;
		}
		else {
			cout << leftStarSpace << 12 << ":" << min << ":" << sec << amOrPM << rightStarSpace << endl;
		}
	}
	else if ((hr > 0) && (hr < 10)) {//Hour is between 1 and 9
		if ((min < 10) && (sec >= 10)) {
			cout << leftStarSpace << zeroChar << hr << ":" << zeroChar << min << ":" << sec << amOrPM << rightStarSpace << endl;
		}
		else if ((min >= 10) && (sec < 10)) {
			cout << leftStarSpace << zeroChar << hr << ":" << min << ":" << zeroChar << sec << amOrPM << rightStarSpace << endl;
		}
		else if ((min < 10) && (sec < 10)) {
			cout << leftStarSpace << zeroChar << hr << ":" << zeroChar << min << ":" << zeroChar << sec << amOrPM << rightStarSpace << endl;
		}
		else {
			cout << leftStarSpace << zeroChar << hr << ":" << min << ":" << sec << amOrPM << rightStarSpace << endl;
		}

	}
	else if (((hr == 10) || (hr == 11))) {//Hour is either 10 or 11 for AM (22 or 23 for PM)
		if (amOrPM == "AM") {

			if ((min < 10) && (sec >= 10)) {
				cout << leftStarSpace << hr << ":" << zeroChar << min << ":" << sec << amOrPM << rightStarSpace << endl;
			}
			else if ((min >= 10) && (sec < 10)) {
				cout << leftStarSpace << hr << ":" << min << ":" << zeroChar << sec << amOrPM << rightStarSpace << endl;
			}
			else if ((min < 10) && (sec < 10)) {
				cout << leftStarSpace << hr << ":" << zeroChar << min << ":" << zeroChar << sec << amOrPM << rightStarSpace << endl;
			}
			else {
				cout << leftStarSpace << hr << ":" << min << ":" << sec << amOrPM << rightStarSpace << endl;
			}
		}

	}

	else if ((hr == 12)) {//Hour is greater than 12 and less than or equal to 23
		amOrPM = "PM";

		if ((min < 10) && (sec >= 10)) {
			cout << leftStarSpace << 12 << ":" << zeroChar << min << ":" << sec << amOrPM << rightStarSpace << endl;
		}
		else if ((min >= 10) && (sec < 10)) {
			cout << leftStarSpace << 12 << ":" << min << ":" << zeroChar << sec << amOrPM << rightStarSpace << endl;
		}
		else if ((min < 10) && (sec < 10)) {
			cout << leftStarSpace << 12 << ":" << zeroChar << min << ":" << zeroChar << sec << amOrPM << rightStarSpace << endl;
		}
		else {
			cout << leftStarSpace << 12 << ":" << min << ":" << sec << amOrPM << rightStarSpace << endl;
		}
	}
	else if ((hr > 12) && (hr <= 21)) {//Hour is greater than 12 and less than or equal to 21
		int rem = hr % 12;
		amOrPM = "PM";
		if ((min < 10) && (sec >= 10)) {
			cout << leftStarSpace << zeroChar << rem << ":" << zeroChar << min << ":" << sec << amOrPM << rightStarSpace << endl;
		}
		else if ((min >= 10) && (sec < 10)) {
			cout << leftStarSpace << zeroChar << rem << ":" << min << ":" << zeroChar << sec << amOrPM << rightStarSpace << endl;
		}
		else if ((min < 10) && (sec < 10)) {
			cout << leftStarSpace << zeroChar << rem << ":" << zeroChar << min << ":" << zeroChar << sec << amOrPM << rightStarSpace << endl;
		}
		else {
			cout << leftStarSpace << zeroChar << rem << ":" << min << ":" << sec << amOrPM << rightStarSpace << endl;
		}
	}
	else {//Hour is 22 or 23 (In 12-Hour Clock standards its 10PM or 11PM)
		amOrPM = "PM";
		if ((min < 10) && (sec >= 10)) {
			cout << leftStarSpace << amOrPMdif << ":" << zeroChar << min << ":" << sec << amOrPM << rightStarSpace << endl;
		}
		else if ((min >= 10) && (sec < 10)) {
			cout << leftStarSpace << amOrPMdif << ":" << min << ":" << zeroChar << sec << amOrPM << rightStarSpace << endl;
		}
		else if ((min < 10) && (sec < 10)) {
			cout << leftStarSpace << amOrPMdif << ":" << zeroChar << min << ":" << zeroChar << sec << amOrPM << rightStarSpace << endl;
		}
		else {
			cout << leftStarSpace << amOrPMdif << ":" << min << ":" << sec << amOrPM << rightStarSpace << endl;
		}
	}



}

static void display24HR(int hr, int min, int sec) {
	//Both star spaces were made so the clock can fit in between the two in the middle.
	string leftStarSpace = "*      ";
	string rightStarSpace = "       *";
	char zeroChar = '0';//In case if hour, minute, or second is below 10 so it can be printed before the number

	//If hour is 24, the variable is resetted to 0.
	int rem24 = hr % 24;
	if (rem24 == 0) {
		hr = 0;
	}
	/*Same rules apply for the if-else statement from the display12HR() funciton but this time, it's 24-Hours, not 12.
	* So therefore AM and PM is not applied here.

	*/
	if ((hr >= 0) && (hr < 10)) {//Hour is between 0 - 10
		if ((min < 10) && (sec < 10)) {
			cout << leftStarSpace << zeroChar << hr << ":" << zeroChar << min << ":" << zeroChar << sec << rightStarSpace << endl;
		}
		else if ((min >= 10) && (sec < 10)) {
			cout << leftStarSpace << zeroChar << hr << ":" << min << ":" << zeroChar << sec << rightStarSpace << endl;
		}
		else if ((min < 10) && (sec >= 10)) {
			cout << leftStarSpace << zeroChar << hr << ":" << zeroChar << min << ":" << sec << rightStarSpace << endl;
		}
		else {
			cout << leftStarSpace << zeroChar << hr << ":" << min << ":" << sec << rightStarSpace << endl;
		}
	}
	else if ((hr >= 10) && (hr <= 23)) { //Hour is bewteen 10 - 23
		if ((min < 10) && (sec < 10)) {
			cout << leftStarSpace << hr << ":" << zeroChar << min << ":" << zeroChar << sec << rightStarSpace << endl;
		}
		else if ((min >= 10) && (sec < 10)) {
			cout << leftStarSpace << hr << ":" << min << ":" << zeroChar << sec << rightStarSpace << endl;
		}
		else if ((min < 10) && (sec >= 10)) {
			cout << leftStarSpace << hr << ":" << zeroChar << min << ":" << sec << rightStarSpace << endl;
		}
		else {
			cout << leftStarSpace << hr << ":" << min << ":" << sec << rightStarSpace << endl;
		}
	}
	else {
		if ((min < 10) && (sec < 10)) {
			cout << leftStarSpace << hr % 12 << ":" << zeroChar << min << ":" << zeroChar << sec << rightStarSpace << endl;
		}
		else if ((min >= 10) && (sec < 10)) {
			cout << leftStarSpace << hr % 12 << ":" << min << ":" << zeroChar << sec << rightStarSpace << endl;
		}
		else if ((min < 10) && (sec >= 10)) {
			cout << leftStarSpace << hr % 12 << ":" << zeroChar << min << ":" << sec << rightStarSpace << endl;
		}
		else {
			cout << leftStarSpace << hr % 12 << ":" << min << ":" << sec << rightStarSpace << endl;
		}
	}

}

static void displayTime(int hr, int min, int sec) {
	/*For this function, I organized the output with the stars just
	*how the example layed out. However I had to call two functions within this function
	*to organize the two functions' output as neatly as possible.
	*/
	string starLine = "***********************";
	string hour12 = "*    12-Hour Clock    *"; //4 to 5 stars space
	string hour24 = "*    24-Hour Clock    *";

	//Displays 12-hour clock
	cout << starLine << endl;
	cout << hour12 << endl;
	display12HR(hr, min, sec);
	cout << starLine << endl << endl;

	//Displays 24-hour clock
	cout << starLine << endl;
	cout << hour24 << endl;
	display24HR(hr, min, sec);
	cout << starLine << endl << endl;
}

int main() {
	//Hours, minutes, and seconds declared as int awaiting user input.
	int hours;
	int minutes;
	int seconds;
	int menuOption = 0; //Declared it 0 for the while to iterate

	//Gathering user input
	cout << "Enter the current time: (Hour/Minute/Second)" << endl;
	cout << "Enter Hour(s): " << endl;
	cin >> hours;
	cout << "Enter Minute(s): " << endl;
	cin >> minutes;
	cout << "Enter Second(s): " << endl;
	cin >> seconds;

	//Displays user initial input
	displayTime(hours, minutes, seconds);


	while (menuOption != 4) {
		/*During the course of the while loop, if the user adds a number to either time that
		*goes over the limit, the modulo divider will reset the variables back to 0.
		*/
		if (hours > 23) {
			hours %= 24;
		}
		if (minutes > 59) {
			minutes %= 60;
		}
		if (seconds > 59) {
			seconds %= 60;
		}

		//Displays the option to the user in every loop
		displayMenu();

		//The user inputs a choice whether to add hours, minutes, seconds, or just exit the program.
		cin >> menuOption;

		if (menuOption == 1) {
			hours += 1;
		}
		if (menuOption == 2) {
			minutes += 1;
		}
		if (menuOption == 3) {
			seconds += 1;
		}

		//Displays time, both the 12-Hour and 24-Hour clock
		displayTime(hours, minutes, seconds);
	}

	//This informs the user the program is done!
	cout << "Program terminated!" << endl;
	return 0;
}