/***************************************************************************
Filename: Animation.cpp
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
List of Source and Header Files: Animation.cpp and Animation.h
Purpose: using a forward_list class to create frames in the Animation.
*************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <forward_list>
using namespace std;

#include "Display.h"
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
	vector<Display> temp_displays;
	string temp_fname;
	int counter = distance(frames.begin(), frames.end());
	int index = 0;

	cout << "Insert a Frame in the Animation" << endl;
	cout << "Please enter the Frame filename: ";
	cin >> temp_fname; 

	int temp_size;
	cout << "Entering the Frame Displays (the sets of dimensions and durations)" << endl;
	cout << "Please enter the number of Displays : ";
	cin >> temp_size; 
	cout << endl;

	/* to add displays elements based on the num of displays */
	for (int i = 0; i < temp_size; i++)
	{
		int temp_x;
		int temp_y;
		int temp_duration;
		char* temp_name = new char[256];

		cout << "Please enter pixel x for Display # " << i << " pixel_x:";
		cin >> temp_x;

		cout << "Please enter pixel y for Display # " << i << " pixel_y:";
		cin >> temp_y;

		cout << "Please enter the duration sec for this Display: ";
		cin >> temp_duration;

		cout << "Please enter the name for this Display: ";
		cin >> temp_name;

		temp_displays.push_back(Display(temp_x, temp_y, temp_duration, temp_name));
	}

	/* to check if frames is empty, and push frames into it */
	if (frames.empty()) 
	{
		cout << "This is the first Frame in the list" << endl;
		frames.push_front(Frame(temp_fname, temp_displays));
	}
	else {	 
		/* to add the frames in the specified position */
		if (counter > 1) { 
			cout << "There are " << counter << " Frames in the list" << endl;
			do {
				cout << "Please specify the position, between 0 and " << counter - 1 << " to insert after : ";
				cin >> index; 
				frames.insert_after(frames.begin(), Frame(temp_fname, temp_displays));
			} while (index < 0 || index > counter - 1);
		}
		else {
			frames.push_front(Frame(temp_fname, temp_displays));
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
	/* to check if frames is empty or not */
	if (frames.empty()) {
		cout << "The frame is empty" << endl;
	}
	else {
		frames.clear();
		cout << "To clear Frames, now it is empty" << endl;
	}

	cout << endl;
}

/*************************************************
Function Name: Animation::operator[]
Purpose: Overloaded [] operator to return the frame 
         at specified position 
Function In parameters: unsigned int x
Function Out parameters: Frame*
Version: 1.0
Student Name: Wenjing Wang
*************************************************/
Frame& Animation::operator[](unsigned int x) {
	unsigned int counter = 0; 
	forward_list<Frame>::iterator i;

	/* to iterate the frames to get the specified index */
	for (i = frames.begin(); i != frames.end(); i++) {
		if (x == counter++) {
			break;
		}
	}
	return *i;
 }

/*************************************************
Function Name: operator+=
Purpose: to add animations together 
Function In parameters: Frame& frame
Function Out parameters: N/A
Version: 1.0
Student Name: Wenjing Wang
*************************************************/
void Animation::operator+=(Frame& frame) {
	Frame tempFrame(frame);
	frames.push_front(tempFrame); 
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
	/* to iterate and display the elements in the Animation class*/
	if (am.frames.empty()) {
		os << "The Animation is empty" << endl;
	}
	else {
		int tempCounter = 0;
		os << "Animation " << am.name << endl
			<< "Run the Animation" << endl;

		forward_list<Frame>::iterator i;
		for (i = am.frames.begin(); i != am.frames.end(); i++) {
			os << "Frame #" << tempCounter++ << ":" << endl
			   << *i;
		}
		os << endl;	
	}

	os << "Output finished" << endl;
	return os;
}