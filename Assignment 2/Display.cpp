/***********************************************************************
Filename: Display.cpp
Version: 1.0
Student Name: Wenjing Wang
Student Number: 040812907
Course Name/Number: C++ Programming CST8219
Lab Section: 303
Assignment # : Assignment 2
Assignment Name: Animation Project in C++ using
                 STL Container Classes and Overloaded Operators
Due Date: December 9, 2017 
Submission Date: December 8, 2017 
Professor's Name: Andrew Tyler
List of Source and Header Files: Display.cpp and Display.h
Purpose: A Display object holds the pixel location that it is to be
        displayed in the frame and the duration should be displayed. 
************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream> 
using namespace std;

#include "Display.h"

/************************************************
Function Name: Display
Purpose: to initialize Display object
Function In parameters: int x, int y, int duration, char* name
Function Out parameters: N/A
Version: 1.0
Student Name: Wenjing Wang
************************************************/
Display::Display(int x, int y, int duration, char* name) {
	this->pixel_x = x;
	this->pixel_y = y;
	this->duration = duration;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

/************************************************
Function Name: Display
Purpose: copy constructor to initialize another Display object.
Function In parameters: const Display& display
Function Out parameters: N/A
Version: 1.0
Student Name: Wenjing Wang
************************************************/
Display::Display(const Display& display) {
	this->pixel_x = display.pixel_x;
	this->pixel_y = display.pixel_y;
	this->duration = display.duration;
	this->name = new char[strlen(display.name) + 1];
	strcpy_s(this->name, (strlen(display.name) + 1), display.name);
}
 
/************************************************
Function Name: ~Display
Purpose: To cleanup all the memory of Display.
Function In parameters: N/A
Function Out parameters: N/A
Version: 1.0
Student Name: Wenjing Wang
************************************************/
Display::~Display() {
	delete[] name;  
}

/***********************************************
Function Name: operator<<
Purpose: overloaded << operator for displaying elements in the Display class
Function In parameters: ostream& os, Display& display
Function Out parameters: ostream& os
Version: 1.0
Student Name: Wenjing Wang
***********************************************/
ostream& operator<<(ostream& os, Display& display) {
	int tempCounter = 0;

	os << "    name = " << display.name
		<< "; pixel_x = " << display.pixel_x << "; pixel_y = " << display.pixel_y
		<< "; duration = " << display.duration << endl;

	/* to display the seconds for Display */
	os << "     Counting the seconds for this Display: ";
	for (int i = 1 ; i <= display.duration; i++) {
		os << i << ", ";  
	}
	
	return os;
}