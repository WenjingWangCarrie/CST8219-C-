/***************************************************************
Filename: Animation.cpp
Version: 1.0
Student Name: Wenjing Wang
Student Number: 040812907
Course Name/Number: C++ Programming CST8219
Lab Section: 303
Assignment # : Assignment 1
Assignment Name: Animation Project in C++
Due Date: November 25, 2017
Submission Date: November 24, 2017
Professor's Name: Andrew Tyler
List of Source and Header Files: Animation.cpp and Animation.h
Purpose: To write the application that holds the data of an
         animation application using a forward list in dynamic
		 memory for its data. It can be insert,
         display and delete the Frames in the Animation.
*************************************************************/

#include "Frame.h"
#include "Animation.h"
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

/*****************************************
Function Name: Animation
Purpose: To initialize the variables in the struct Animation.
Function In parameters: N/A
Function Out parameters: N/A
Version: 1.0
Student Name: Wenjing Wang
*****************************************/
Animation::Animation() {
	frames = nullptr;
}

/*****************************************
Function Name: InsertFrame
Purpose: To add a new Frame to Animation at a specified position.
Function In parameters: N/A
Function Out parameters: N/A
Version: 1.0
Student Name: Wenjing Wang
*****************************************/
void Animation::InsertFrame() {
	char fname[100];
	
	Frame *iterator;
	iterator = new Frame;
	int size = strlen(fname) + 1; // get the length of fileName
	iterator->GetfileName() = new char[size]; // to allocate memory for fileName

	cout << "Insert a Frame in the Animation\n" << endl;
	cout << "Please enter the Frame filename: ";
	cin >> fname; // catch user entered fname
	strcpy(iterator->GetfileName(), fname); // copy user entered fname into fileName

	Frame *current;
	current = frames; // make the current pointer points to the Animation
	int counter;
	int index;

	if (frames == nullptr) // if list is empty, insert into the first position
	{
		cout << "This is the first Frame in the list" << endl;
		iterator->GetpNext() = frames;
		frames = iterator;
		return;
	}
	else // there are nodes in the list, to insert at user specified position
	{
		counter = 0;
		current = frames;
		while (current != nullptr) // calculate the length of the list
		{
			current = current->GetpNext();
			counter++;
		}
		current = frames;

		cout << "There is " << counter << " Frame(s) in the list.  Please specify the position(<= " << counter << ") to insert at: ";
		cin >> index;

		if (index == 0) // go to the first poisition of list
		{
			iterator->GetpNext() = frames;
			frames = iterator;
			return;
		}

		int counts = 0;
		current = frames;
		Frame *prev;
		while (counts < index) {
			
			prev = current; // reassign the location of frame
			current = current->GetpNext();
			counts++;
		}

		prev->GetpNext() = iterator; // reassign the location of frame
		iterator->GetpNext() = current;
		return;
	}
}

/*****************************************
Function Name: DeleteFrames
Purpose: To delete all the frames in the Animation.
Function In parameters: N/A
Function Out parameters: N/A
Version: 1.0
Student Name: Wenjing Wang
*****************************************/
void Animation::DeleteFrames() {
	if (frames != nullptr) {
		delete this->frames;
		frames = nullptr;
		cout << "Delete all the Frames from the Animation" << endl;
	}
}

/*****************************************
Function Name: RunFrames
Purpose: To display all the frames in the Animation to show the 
         list of Frame details one after another at 1 second intervals.
Function In parameters: N/A
Function Out parameters: N/A
Version: 1.0
Student Name: Wenjing Wang
*****************************************/
void Animation::RunFrames() {
	int counter = 0;
	time_t startsec, oldsec, newsec;
	Frame* iterator = frames;
	
	if (frames == 0) {
		cout << "No frames in the animation" << endl;
		return; 
	}

	cout << "Run the Animation" << endl;
	startsec = oldsec = time(nullptr);

	while (iterator)
	{
		newsec = time(nullptr);
		if (newsec > oldsec)
		{
			cout << "Frame #" << counter++ << ", time = " << newsec - startsec << "sec" << endl;
			cout << "Image file name = " << iterator->GetfileName() << endl;
			iterator = iterator->GetpNext();
			oldsec = newsec;
		}
	}
}

/*****************************************
Function Name: ~Animation
Purpose: To cleanup all the frames in the memory of struct Animation.
Function In parameters: N/A
Function Out parameters: N/A
Version: 1.0
Student Name: Wenjing Wang
*****************************************/
Animation::~Animation() {
	DeleteFrames();
}