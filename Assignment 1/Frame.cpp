/************************************************
Filename: Frame.cpp
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
List of Source and Header Files: Frame.cpp and Frame.h
Purpose: to initialize and cleanup all the variables
         in the struct Frame. 
*************************************************/

#include "Frame.h"
using namespace std;

/*****************************************
Function Name: Frame
Purpose: To initialize the variables in the struct Frame.
Function In parameters: N/A
Function Out parameters: N/A
Version: 1.0
Student Name: Wenjing Wang
*****************************************/
Frame::Frame() {
	fileName = nullptr;
	pNext = nullptr;
}

/*****************************************
Function Name: ~Frame
Purpose: To cleanup the variables in the struct Frame.
Function In parameters: N/A
Function Out parameters: N/A
Version: 1.0
Student Name: Wenjing Wang
*****************************************/
Frame::~Frame() {
	delete this->fileName;
	delete this->pNext;
}