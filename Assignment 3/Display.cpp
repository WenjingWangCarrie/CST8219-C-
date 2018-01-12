/***********************************************************************
Filename: Display.cpp
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
List of Source and Header Files: Display.cpp and Display.h
Purpose: A Display object holds the pixel location that it is to be
displayed in the frame and the duration should be displayed.
************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <string> 
#include <iostream>  
using namespace std;

#include "Display.h"
#include "GPUMemoryDisplay.h"
#include "SystemMemoryDisplay.h"

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
	strcpy(this->name, display.name);
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
	/* decide which type of MemoryDisplay class information will display */
	try {
		SystemMemoryDisplay& system = dynamic_cast<SystemMemoryDisplay&>(display);
		os << "System Memory Display" << endl;
	}
	catch (const std::bad_cast& e) {
		// ignored
	}

	try {
		GPUMemoryDisplay& gpu = dynamic_cast<GPUMemoryDisplay&>(display);
		os << "GPU Memory Display. Shader = " << gpu.GetShader() << endl;
	}
	catch (const std::bad_cast& e) {
		// ignored
	}

	os << "\tDisplay name = " << display.name
		<< "; pixel_x = " << display.pixel_x << "; pixel_y = " << display.pixel_y
		<< "; duration = " << display.duration << endl;

	/* display the seconds for Display */
	os << "\tCounting the seconds for this Display: ";
	for (int i = 1; i <= display.duration; i++) {
		os << i << ", ";
	}
	os << endl;

	/* calculate the buffer size for different derived class */
	os << "\tMemory requirements = " << display.BufferSize() << " bytes" << endl;

	return os;
}