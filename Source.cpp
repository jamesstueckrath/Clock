/*
Author: James Stueckrath
Date: September 20, 2026
Class: CS 210
Assignment: ChadaTech Clocks
*/

#include <iostream>
#include <string>

using namespace std;

// Clock variables
unsigned int hour = 0;
unsigned int minute = 0;
unsigned int second = 0;

// Format numbers as two digits
string twoDigitString(unsigned int n) {
	if (n < 10) {
		return "0" + to_string(n);
	}

	return to_string(n);
}

// Return a string containing n copies of character c
// nCharString(5,'*') returns "*****"
string nCharString(size_t n, char c) {
	return string(n, c);
}

// Format the time using the 24-hour clock format
string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
	return twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);
}

// Format the time using the 12-hour clock format
string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
	string timeOfDay;

	// Determine time of day
	if (h < 12) {
		timeOfDay = "A M";
	}
	else {
		timeOfDay = "P M";
	}

	// Convert 24-hour value to 12-hour value
	unsigned int hour12 = h % 12;

	// Midnight should return 12, not 00
	if (hour12 == 0) {
		hour12 = 12;
	}

	return twoDigitString(hour12) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " " + timeOfDay;
}

// Get current hour
unsigned int getHour() {
	return hour;
}

// Get current minute
unsigned int getMinute() {
	return minute;
}

// Get current second
unsigned int getSecond() {
	return second;
}

// Set the hour
void setHour(unsigned int h) {
	hour = h;
}

// Set the minute
void setMinute(unsigned int m) {
	minute = m;
}

// Set the second
void setSecond(unsigned int s) {
	second = s;
}

// Add one hour
void addOneHour() {
	if (getHour() < 23) {
		setHour(getHour() + 1);
	}
	else {
		setHour(0);
	}
}

// Add one minute
void addOneMinute() {
	if (getMinute() < 59) {
		setMinute(getMinute() + 1);
	}
	else {
		setMinute(0);
		addOneHour();
	}
}

// Add one second
void addOneSecond() {
	if (getSecond() < 59) {
		setSecond(getSecond() + 1);
	}
	else {
		setSecond(0);
		addOneMinute();
	}
}

// Display both clocks
void displayClocks(unsigned int h, unsigned int m, unsigned int s) {

	cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;

	cout << "*" << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << "*" << nCharString(3, ' ');

	cout << "*" << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << "*" << endl;

	cout << endl;

	cout << "*" << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(7, ' ') << "*" << nCharString(3, ' ');

	cout << "*" << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(9, ' ') << "*" << endl;

	cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
}

// Print the menu with aligned borders
void printMenu(const string strings[], unsigned int numStrings, unsigned char width) {

	// Print the top border
	cout << nCharString(width, '*') << endl;

	for (unsigned int i = 0; i < numStrings; ++i) {
		string itemNum = to_string(i + 1);

		// Calculate the spaces needed before the last '*'
		size_t usedCharacters = 6 + itemNum.length() + strings[i].length();

		size_t spacesNeeded = static_cast<size_t>(width) - usedCharacters;

		cout << "* " << itemNum << " - " << strings[i] << nCharString(spacesNeeded, ' ') << "*" << endl;

		// Add a blank line between menu choices
		if (i < numStrings - 1) {
			cout << endl;
		}
	}

	// Print the bottom border
	cout << nCharString(width, '*') << endl;
}

// Get a valid menu choice from the user
unsigned int getMenuChoice(unsigned int maxChoice) {
	unsigned int choice = 0;

	cin >> choice;

	while (choice < 1 || choice > maxChoice) {
		cin >> choice;
	}

	// return the value

	return choice;

}

// Run the main menu
void mainMenu() {
	const string menuItems[] = {
		"Add One Hour",
		"Add One Minute",
		"Add One Second",
		"Exit Program"
	};

	unsigned int choice = 0;

	while (choice != 4) {
		displayClocks(getHour(), getMinute(), getSecond());

		cout << endl;

		printMenu(menuItems, 4, 26);

		choice = getMenuChoice(4);

		if (choice == 1) {
			addOneHour();
		}
		else if (choice == 2) {
			addOneMinute();
		}
		else if (choice == 3) {
			addOneSecond();
		}

		cout << endl;
	}
}

// Main Program
int main() {
	// Enter starting time
	cout << "Enter starting hour: " << endl;
	cin >> hour;
	cout << "Enter starting minute" << endl;
	cin >> minute;
	cout << "Enter starting second" << endl;
	cin >> second;

	mainMenu();

	return 0;
}