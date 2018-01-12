/****************************************************************
Filename: Frame.cpp
Version: 1.0
Student Name: Wenjing Wang
Student Number: 040812907
Course Name/Number: C++ Programming CST8219
Lab Section: 303
Assignment # : Assignment 3
Assignment Name: Animation Project in C++ using Polymorphic Inheritance and RTTI
Due Date: January 6, 2018
Submission Date: January 05, 2018
Professor's Name: Andrew Tyler
List of Source and Header Files: Frame.cpp and Frame.h
Purpose: to create frames that includes Display vector.
*****************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "Display.h"
#include "SystemMemoryDisplay.h"
#include "GPUMemoryDisplay.h"
#include "Frame.h" 

/************************************************
Function Name: Frame
Purpose: copy constructor to initialize another Frame object.
Function In parameters: const Frame& frame
Function Out parameters: N/A
Version: 1.0
Student Name: Wenjing Wang
************************************************/
Frame::Frame(const Frame& frame) {
	fileName = frame.fileName;
	
	for (vector<Display*>::const_iterator it = frame.displays.begin(); it != frame.displays.end(); it++) {
		if (SystemMemoryDisplay *system = dynamic_cast<SystemMemoryDisplay*>(*it)) {
			displays.push_back(new SystemMemoryDisplay(*system));
		}
		else if (GPUMemoryDisplay *gpu = dynamic_cast<GPUMemoryDisplay*> (*it)) {
			displays.push_back(new GPUMemoryDisplay(*gpu));
		}
	} 
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
	vector<Display*>::iterator it;

	/* iterator and display the elements in the Frame class */
	os << "\tfileName = " << frame.fileName << endl;

	for (it = frame.displays.begin(); it != frame.displays.end(); it++) {
		os << "\tDisplay #" << counter++ << ": " << **it << endl;
	}

	return os;
}