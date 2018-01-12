/****************************************************************
Filename: Frame.cpp
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
List of Source and Header Files: Frame.cpp and Frame.h
Purpose: to create frames that includes Display vector.
*****************************************************************/
#include <iostream>
#include <vector>
#include <string> 
using namespace std;

#include "Display.h"
#include "Frame.h"
/***********************************************
Function Name: operator+
Purpose: to iterate Display elements in two parts of Frames
Function In parameters: Frame& frame
Function Out parameters: frame
Version: 1.0
Student Name: Wenjing Wang
***********************************************/
Frame Frame::operator+(Frame& frame) {
	vector<Display> newDisplay;
	int counter = 0;
	
	vector<Display>::iterator i;
	/* to iterate the first part of the frames */
	for (i = displays.begin(); i != displays.end(); i++)
		newDisplay.push_back(Display(frame.displays.at(counter++)));
	
	/* to iterate the second part of the frames */
	counter = 0;
	for (i = frame.displays.begin(); i != frame.displays.end(); i++)
		newDisplay.push_back(Display(frame.displays.at(counter++)));

	/* to concate the frames together */
	Frame newFrame(fileName + "_" + frame.fileName, newDisplay);  

	return newFrame;
}

/***********************************************
Function Name: operator<<
Purpose: overloaded << operator to display
         information in the Frame class
Function In parameters: ostream& os, Frame& frame
Function Out parameters: ostream& os
Version: 1.0
Student Name: Wenjing Wang
***********************************************/
ostream& operator<<(ostream& os, Frame& frame) {
	int counter = 0;
	vector<Display>::iterator i;

	/* to iterator and display the elements in the Frame class */
	os << "     fileName = " << frame.fileName << endl;
	for (i = frame.displays.begin(); i != frame.displays.end(); i++) 
		   os << "     Display #" << counter++ << ":" << *i << endl;
	
	return os;
}
 