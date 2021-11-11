/*
* Zachary Meisner
* 11/11/2021
* Chada Tech Clock for CS210
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <conio.h>





using namespace std;

// gets local time and outputs it to initial display for user
// turns off error 4996 due to a deprecated variable localtime

time_t ttime = time(0);
#pragma warning (disable : 4996)
tm* local_time = localtime(&ttime);
int hour = local_time->tm_hour;
int minute = local_time->tm_min;
int second = local_time->tm_sec;

// AM PM string declaration
string merediem;

// Logic for 12 hour clock subtracts a value of 12 for accurate time
int clock12() {
	int hour12 = hour;
	if (hour > 12) {
		hour12 = hour - 12;
	}
	return hour12;
}

// Logic for 24 hour clock functional timekeeping so each variable adds at designated points in time
// Merediem in use here to tell AM/PM between morning and night times based off of alotted variable

void clock24() {
	if (second > 59) {
		second = 0;
		minute += 1;
	}
	if (minute > 59) {
		minute = 0;
		hour += 1;
	}
	if (hour > 24) {
		hour = 0;
		minute = 0;
		second = 0;
	}
	if (hour <= 11) {
		merediem = "A M";
	}
	else {
		merediem = "P M";
	}
}

// formats the time to transform variables on the clock into a string for display
// 00 does not print out for single numbers and this allows 00 to print out for 09 to 01

string format(int time) {
	string format = "0";
	if (time >= 0 && time <= 9) {
		format.append(to_string(time));
	}
	else {
		format = to_string(time);
	}
	return format;
}

// displays both clocks and ASCII art for the menu calls both clock functions defined above to keep time relevant
// implements formatting for the clock time

void display() {
	

	clock24();

	int hour_12;
	hour_12 = clock12();

	string fHour12;
	string fHour24;
	string min;
	string sec;

	fHour24 = format(hour);
	fHour12 = format(hour_12);
	min = format(minute);
	sec = format(second);


	
	cout << "\n\n\n";
	cout << setw(72) << "CHADA TECH CLOCKS\n" << endl;
	cout << setw(60) << string(26, '*') << setw(30) << string(26, '*') << endl;
	cout << setw(60) << "*      12-Hour Clock     *" << setw(30) << "*      24-Hour Clock     *" << endl;
	cout << setw(41) << "*      " << fHour12 << ":" << min << ":" << sec << " " << merediem << "      *" << setw(11) << "*      " << fHour24 << ":" << min << ":" << sec << "          *" << endl;
	cout << setw(60) << string(26, '*') << setw(30) << string(26, '*') << endl;


	cout << setw(75) << string(26, '*') << endl;
	cout << setw(75) << "*   1 - Add One Hour     *" << endl;
	cout << setw(75) << "*   2 - Add One Minute   *" << endl;
	cout << setw(75) << "*   3 - Add One Second   *" << endl;
	cout << setw(75) << "*   4 - Exit             *" << endl;
	cout << setw(75) << string(26, '*') << endl;

}

// main function uses switch case for user to allow functionality of adding time to the clock
// clears the screen and shows display of current time, clears and shows updated time for each case scenario
// kbhit allows the user to manipulate the program while the clock is ticking


int main() {
	int choice = 0;
	int flag = 0;
	while (choice != 4) {
		while (!kbhit() && flag == 0) {
			system("cls");
			display();
			second++;
			Sleep(898.269);
			main();
		}
	cin >> choice;

		switch (choice) {
		case 1:
			hour = hour + 1;
			minute = minute - 1;
			second = second - 1;

		case 2:
			minute = minute + 1;
			second = second - 1;

		case 3:
			second = second + 1;
		
		}
		
	}
	
	cout << "Thanks for using Chada Tech Clock!" << endl;
	
	exit(0);
}

