/***************
* Clocks        
* CS-210
* Project one
* Stormey Trayter
****************/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
void clearscreen() {
	//function to "clear screen" using newlines
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl <<
	endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << 
	endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

}
void displayTime(int hour12, int min, int sec, string ampm, int hour24) {
	//function to  display times side by side, setw sets each int to two char, setfill sets filler char as "0"
	cout << "**************************     **************************\n";
	cout << "*    12 - Hour Clock     *     *    24 - Hour Clock     *\n*       ";
	cout << setw(2) << setfill('0') << hour12 << ":";
	cout << setw(2) << setfill('0') << min << ":";
	cout << setw(2) << setfill('0') << sec << " " << ampm << "      *     *        ";
	cout << setw(2) << setfill('0') << hour24 << ":";
	cout << setw(2) << setfill('0') << min << ":";
	cout << setw(2) << setfill('0') << sec << "        * \n";
	cout << "**************************     **************************\n";
}
void displayMenu() {
	//function to display menu 
	cout << "**************************\n";
	cout << "* 1 - Add One Hour       * \n";
	cout << "* 2 - Add One Minute     * \n";
	cout << "* 3 - Add One Second     * \n";
	cout << "* 4 - Exit Program       * \n";
	cout << "**************************\n";
}
void displayExit() {
	//function to display an exit message
	cout << "**************************\n";
	cout << "*       Good Bye         * \n";
	cout << "**************************\n";
}

int main(){
	// initailize varibles
	int hour24 = 0;
	int hour12 = 12;
	int min = 0;
	int sec = 0;
	int hourCount = 0;
	int minCount = 0;
	int secCount = 0;
	string ampm = "AM";
	int userOption = 0;

	while (userOption != 4){
		// this loop will run until option 4 is selected, then will dispaly exit message
		while (userOption != 0) {
			//this loop checks for options 1,2 & 3 then displays new clocks, all options rest userOption to 0 to allow new input
			if (userOption == 1) {
				//this if function adds one hour. The nested if functions control the 12 and 24 hour formatting. 
				hourCount++;
				userOption = 0;
				if (hourCount == 1) {
					hour12 = 1;
					hour24++;
					break;
				}
				if (hourCount <= 11) {
					ampm = "AM";
					hour12++;
					hour24++;
					break;
				}
				if (hourCount == 12) {
					ampm = "PM";
					hour12 = 12;
					hour24++;
					break;
				}
				if (hourCount == 13) {
					ampm = "PM";
					hour12 = 1;
					hour24++;
					break;
				}
				if (hourCount == 24) {
					hour12 = 12;
					ampm = "AM";
					hour24 = 0;
					hourCount = 0;
					break;
				}
					else {
					hour12++;
					hour24++;
					break;
				}
			}
			if (userOption == 2) {
				//this if function adds one minute. The nested if functions control the minute formatting.
				minCount++;
				userOption = 0;
				if (minCount <= 59) {
					min++;
					break;
				}
				//resets min to 0 after 59
				if (minCount == 60) {
					min = 0;
					minCount = 0;
					break;
				}
			}
			if (userOption == 3) {
				//this if function adds one second. The nested if functions control the second formatting.
				secCount++;
				userOption = 0;
				if (secCount <= 59) {
					sec++;
				}
				//resets sec to 0 after 59
				if (secCount == 60) {
					sec = 0;
					secCount = 0;
				}
				}
		} // clear screen and display clocks/menu
		clearscreen();
		displayTime(hour12, min, sec, ampm, hour24);
		displayMenu();
		cin >> userOption;
		
	}
	clearscreen();
	displayExit();
	}
