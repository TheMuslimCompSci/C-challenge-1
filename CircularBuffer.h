#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

// NB: Do not add any extra #include statements to this file
#include "SimpleVector.h"
#include <iostream>

/** TODO: complete the definition of the class CircularBuffer here
 *
 * Its constructor should take the size of the buffer as an argument
 *
 * It needs to have the functions:
 * - count() which returns how many things are in the buffer
 * - full() which returns true iff the buffer is full
 * - add() which takes an element and adds it to the buffer (you can assume the buffer is not full)
 * - remove() which removes the next element from the buffer (you can assume the buffer is not empty)
 */
class CircularBuffer 
{
	private:
	//size of the array
	int capacity;
	//front index of the circular queue
	int f;
	//rear index of the circular queue
	int r;
	//simple vector
	SimpleVector<char> bufferArray;
public:
	CircularBuffer(int sizeOfArray) : bufferArray(sizeOfArray), capacity(sizeOfArray), f(0),r(0)
	{
		
	}
	//returns number of elementrs currently in the vector
	int count()
	{
		return ((r - f + capacity) % capacity);
	}
	//returns true if vector is full
	bool full()
	{
		if (((r - f + capacity) % capacity) >= capacity)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	//adds char in the vector, increments rear index
	void add(char toAdd)
	{
		bufferArray[r] = toAdd;
		r = ((r + 1) % capacity);
	}
	//removes char in the vector in first in first out manner, increments front index
	char remove()
	{
		char toReturn = bufferArray[f];
		bufferArray[f] = '\0';
		f = ((f + 1) % capacity);
		return toReturn;

	}
};


// don't write any code below this line

#endif
