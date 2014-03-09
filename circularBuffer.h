//------------------------------------------------------------
// Copyright: Syed Shah 2014
// Contact: emaadshah@gmail.com (425) 772-0602
//
// Implement a circular buffer of size N.Allow the caller to 
// append, remove and list the contents of the buffer.
// Implement the buffer to achieve maximum performance for 
// each of the operations.The new items are appended to the 
// end and the order is retained i.e elements are placed in 
// increasing order of their insertion time.When the number 
// of elements in the list elements exceeds the defined size, 
// the older elements are overwritten.
// There are four types of commands.
// "A" n - Append the following n lines to the buffer.
// If the buffer is full they replace the older entries.
// "R" n - Remove first n elements of the buffer.These n 
// elements are the ones that were added earliest among the 
// current elements.
// "L" - List the elements of buffer in order of their inserting 
// time.
// "Q" - Quit.
// Your task is to execute commands on circular buffer.
// Input format
// First line of input contains N, the size of the buffer.
// A n - append the following n lines to the buffer.
// R n - remove first n elements of the buffer.
// L - list the buffer.
// Q - Quit.
// Constraint:
// 0 <= N <= 10000
// Number of removing elements will <= number of elements presents in circular buffer.
// Total number of commands <= 50000.
// Total number of characters in input <= 20000000.
//
// Assumptions: 
// The program assumes that all the commands in 
// the file is in uppercase. "A 2" is correct
// input, "a 2" is not.
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
		// Total number of character error
		void totalCharError();
		// File cant be opened prompt
		void fileError(const string&);
		// Display Buffer Size Error
		void bufferSizeError();
		// Appends an element to the circular buffer
		void append(const string&);
		// Removes r elements from the circular buffer
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
		// in the future, if required
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
