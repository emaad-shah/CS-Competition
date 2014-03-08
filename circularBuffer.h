//------------------------------------------------------------
// Copyright: Syed Shah 2014
// Implementation of Circular Buffer
// Assumptions: The program assumes that all the commands in 
//              the file is in uppercase. "A 2" is correct
//				input, "a 2" is not.
//------------------------------------------------------------
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>

#ifndef CB_H
#define CB_H

using namespace std;

class CB
{
	public:
		// Reads the given file name from the string
		// Initialize head, tail and count 
		CB(const string&);
		// Deconstructor
		~CB();
		// Read file and perform append, remove and list operation
		bool readFile(const string&);
		// File cant be opened prompt
		void fileError(const string&);
		// Specification not met
		void constraints();
		// Appends an element to the circular queue
		void append(const string&);
		// Removes r elements from the circular queue
		void remove(int);
		// Display current elements in the circular buffer
		void list();
		// Check if the ciricular buffer is full
		bool isFull();
		// Check if the ciricular buffer is empty
		bool isEmpty();

	private:
		// Struct used rather than array
		// for other information to be added
		// if required
		struct Node
		{
			string word;
		};
		struct Node * c;

		// Max size of the buffer
		const int bufferSize = 10000;
		// Total number of possible commands
		const int totalCommands = 50000;
		// Largest possible size of the string
		unsigned const int totalChar = 20000000;
		// Size of the buffer
		int size;
		// Total current elements in the buffer
		int count;
		// Keep track of the elements
		int head;
		int tail;
		
};

#endif
