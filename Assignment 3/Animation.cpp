/***************************************************************************
Filename: Animation.cpp
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
List of Source and Header Files: Animation.cpp and Animation.h
Purpose: using a forward_list class to create frames in the Animation.
*************************************************************************/
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <forward_list>
using namespace std;

#include "Display.h"
#include "SystemMemoryDisplay.h"
#include "GPUMemoryDisplay.h"
#include "Frame.h"
#include "Animation.h"

/***********************************************
Function Name: InsertFrame
Purpose: To add new Frames to Animation.
Function In parameters: N/A
Function Out parameters: N/A
Version: 1.0
Student Name: Wenjing Wang
***********************************************/
void Animation::InsertFrame() {
	vector<Display*> temp_displays;
	int counter = distance(frames.begin(), frames.end());
	int index = 0;

	string temp_fname;
	cout << "Insert a Frame in the Animation" << endl;
	cout << "Please enter the Frame filename: ";
	cin >> temp_fname;

	int temp_size;
	cout << "Entering the Frame Displays (the sets of dimensions and durations)" << endl;
	cout << "Please enter the number of Displays: ";
	cin >> temp_size;

	/* add displays elements based on the num of displays */
	for (int i = 0; i < temp_size; i++) {
		int temp_x;
		cout << "Please enter pixel x-width for Display # " << i << " pixel_x:";
		cin >> temp_x;

		int temp_y;
		cout << "Please enter pixel y-width for Display # " << i << " pixel_y:";
		cin >> temp_y;

		int temp_duration;
		cout << "Please enter the duration for this Display: ";
		cin >> temp_duration;

		char* temp_name = new char[256];
		cout << "Please enter the name for this Display: ";
		cin >> temp_name;

		int temp_type;
		do {
			cout << "Please enter the type for this display (1 = SystemMemoryDisplay, 2 = GPUMemoryDisplay): ";
			cin >> temp_type;
		} while (temp_type >= 3 || temp_type <= 0);

		 Display* display(NULL);
		/* insert into different display types */
		if (temp_type == 1) { 
			display = new SystemMemoryDisplay(temp_x, temp_y, temp_duration, temp_name);
		    temp_displays.push_back(display);
			
			cout << endl;
		}
		else if (temp_type == 2) {
			string temp_shader_name; 
			
			cout << "Please enter the file name of the associated GPU Shader: ";
			cin >> temp_shader_name;
			display = new GPUMemoryDisplay(temp_x, temp_y, temp_duration, temp_name, temp_shader_name);
			temp_displays.push_back(display);
			
			cout << endl; 
		} 

		/* release all the memory in the heap */
		delete[] temp_name; 
	}

	/* create a Frame onject */ 
	Frame frame(temp_fname, temp_displays);
	/* check if frames is empty, and push frames into it */
	if (frames.empty()) {
		cout << "This is the first Frame in the list" << endl;
		frames.push_front(frame); // dereference, get its address and add into frames 
	}
	else {
		/* add the frame in the specified position */
		if (counter > 1) {
			cout << "There are " << counter << " Frames in the list" << endl;
			do {
				cout << "Please specify the position, between 0 and " << counter - 1 << " to insert after : ";
				cin >> index;  				
			} while (index < 0 || index > counter - 1);

			/* to insert correctly after the specified index */
			forward_list<Frame>::iterator iter;
			iter = frames.begin();  
			if (index == 0) {
				iter = frames.insert_after(iter, frame);
			} else {
				forward_list<Frame>::iterator an;
				an = iter;
				++an;
				frames.insert_after(an, frame);
			} 
		} else {
			frames.push_front(frame);
			frames.reverse();
		}
	} 

	cout << endl;
}

/*************************************************
Function Name: DeleteFrames
Purpose: To delete all the frames in the Animation.
Function In parameters: N/A
Function Out parameters: N/A
Version: 1.0 
Student Name: Wenjing Wang
*************************************************/
void Animation::DeleteFrames() {
	if (frames.empty()) {
		cout << "The frame is empty" << endl;
	}
	else {
		frames.clear();
		cout << "To clear frames, now it is empty" << endl;
	}
	cout << endl;
}

/*************************************************
Function Name: operator<<
Purpose: overloaded << operator for std::ostream,
to display the Animation
Function In parameters: ostream& os, Animation& am
Function Out parameters:ostream& os
Version: 1.0
Student Name: Wenjing Wang
*************************************************/
ostream& operator<<(ostream& os, Animation& am) {
	/* iterate and display the elements in the Animation class */
	if (am.frames.empty()) {
		os << "The Animation is empty" << endl;
	}
	else {
		int counter = 0;
		os << "Animation " << am.name << endl
			<< "Run the Animation" << endl;

		forward_list<Frame>::iterator it;
		for (it = am.frames.begin(); it != am.frames.end(); it++) {
			os << "Frame #" << counter++ << ":" << *it << endl;;
		}
	}

	os << "Output finished" << endl;
	return os;
}