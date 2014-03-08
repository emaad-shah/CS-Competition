#include "CircularBuffer.h"

// Reads the given file name from the string
// Initialize head, tail and count 
CB::CB(const string &fileName)
{
	bool success = readFile(fileName);
	if (success)
	{
		head = 0;
		tail = 0;
		count = 0;
	}
}

// Read file and perform append, remove and list operation
bool CB::readFile(const string &fileName)
{
	string line;
	int commands;
	int numLines;
	ifstream file;
	file.open(fileName);
	// Check for error
	if (!file)
		fileError(fileName);
	else
	{
		// First line of the file contains the queue size
		file >> size;
		if (size > bufferSize || size < 0)
		{
			constraints();
			return false;
		}
		else
		{
			// Allocate memory for circular buffer
			c = new Node[size];
			// Keeps tracks of total commands
			commands = 0;
			while (!file.eof() && commands <= totalCommands)
			{
				getline(file,line);
				// Append to the circular buffer
				if (line[0] == 'A' && line[1] == ' ' && isdigit(line[2]))
				{
					// Num of lines to append
					numLines = line[2] - '0';
					while (numLines-- != 0)
					{
						getline(file, line);
						if (line.length() <= totalChar)
							append(line);
					}
					commands++;
				}
				// Remove from the circular buffer
				if (line[0] == 'R' && line[1] == ' ' && isdigit(line[2]))
				{
					// Num of elements to remove
					numLines = line[2] - '0';
					remove(numLines);
					commands++;
				}
				// List all the elements in the buffer
				if (line.length() == 1 && line[0] == 'L')
				{
					list();
					commands++;
				}
				// Quit
				if (line.length() == 1 && line[0] == 'Q')
					break;
			}
		}
	}
	file.close();
	return true;
}

// Deconstructor
CB::~CB()
{
	// Deallocate the memory
	delete [] c;
}

// Specification not met
void CB::constraints()
{
	cerr << "Constraints not met. Please check specification" << endl;
}

// File cant be opened prompt
void CB::fileError(const string & file)
{
	cerr << "Could not open " << file << endl;
}

// Appends an element to the circular queue
void CB::append(const string & a)
{
	// Reset head and tail to first index if
	// List is empty
	if (isEmpty())
		head = tail = 0;
	if (tail == size)
		tail = 0;
	if (head == size)
		head = 0;
	
	// Check if buffer needs to be overwritten
	// Eventualy head and tail will point
	// to the same index
	if (!c[tail].word.empty())
		head++;

	c[tail++].word = a;
	// Keep track of the count but do not
	// keep in to consideration wrapping
	if (count < size)
		count++;
}

// Removes r elements from the circular queue
void CB::remove(int r)
{
	if (isEmpty())
		return;
	// Can only remove items that really exists
	if (r > count)
		r = count;
	while (r-- > 0)
	{
		// If the circular buffer has 
		// been wrapped around, the head
		// and tail will point to the same 
		// index
		if (head == size)
			head = 0;
		c[head++].word = "";
		count--;
	}

}

// Display current elements in the circular buffer
void CB::list()
{
	cout << endl << "Printing items in the circular buffer" << endl;
	cout << "Head: " << head << " Tail: " << tail << endl;
	cout << endl;
	for (int i = head; i < size; i++)
		cout << c[i].word << setw(10);
	for (int i = 0; i < head; i++)
		cout << setw(10) << c[i].word << setw(10);
	cout << endl;
}

// Check if the ciricular buffer is full
bool CB::isFull()
{
	return count == size;
}

// Check if the ciricular buffer is empty
bool CB::isEmpty()
{
	return count == 0;
}

int main(void)
{
	// Test Case 1
	CB test1("circularFile.txt");
	cout << endl << "****End of Test 1****" << endl;
	// Test Case 2
	CB test2("circularFile2.txt");
	cout << endl << "****End of Test 2****" << endl;
	system("pause");
	return 0;
}
