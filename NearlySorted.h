#ifndef NEARLYSORTED_H
#define NEARLYSORTED_H


#include <vector>
using std::vector;

/** @brief Class that describes how to sort a nearly-sorted vector */
class HowToSort {
protected:
    
    /** @brief The index of the first element to use */
    int firstElement;
    
    /** @brief The index of the second element to use */
    int secondElement;
    
    /** @brief If true, firstElement and secondElement should be swapped; if false, the range of elements should be reversed */
    bool swapThem;
    
public:
    
    /** @brief Default constructor.
     * 
     * This assumes that we can't sort the vector by swapping/reversing a range -- it sets both elements
     * to have an index -1.
     */
    HowToSort() 
      : firstElement(-1),
        secondElement(-1),
        swapThem(false) {
    }
    
    /** @brief The actual constructor: use this to define how to sort a nearly-sorted vector
     * 
     * @param firstElementIn   The first element to use
     * @param secondElementIn  The second element to use
     * @param swapThemIn       If true, swap firstElementIn and secondElementIn; if false, reverse the range of elements
     */
    HowToSort(const int firstElementIn, const int secondElementIn,
              const bool swapThemIn)
      : firstElement(firstElementIn),
        secondElement(secondElementIn),
        swapThem(swapThemIn) {
    }
    
    /** @brief Returns false if no way to sort the vector could be found (i.e. if firstElement == -1) */
    bool canBeMadeSorted() const {
        return (firstElement != -1);
    }
    
    /** @brief Accessor function -- get the first element to use */
    int getFirstElement() const {
        return firstElement;
    }

    /** @brief Accessor function -- get the second element to use */
    int getSecondElement() const {
        return secondElement;
    }

    /** @brief If true, the element indices denote a swap.  If false, they denote a range reversal. */
    bool isASwap() const {
        return swapThem;
    }
    
};

// TODO your code goes here:

//checks if the vector is sorted, returns true if it is
bool checkSort(vector<int> A)
{
	bool sorted = true;
	for (int i = 0; i <= A.size() - 2; i++)
	{
		if (A[i] > A[i + 1])
		{
			sorted = false;
		}
	}
	return sorted;
}

HowToSort nearlySorted(vector<int> toCheck)
{

	//checks if the vector is already sorted
	if (toCheck.size() == 1 || checkSort(toCheck) == true)
	{
		return HowToSort(0, 0, true);
	}
	
	//finding first item out of order from the left in the vector
	int i = 0;
	while (i < toCheck.size() - 1 && toCheck[i] < toCheck[i + 1])
	{
		i += 1;
	}
	int firstoooleft = i;
	//finding first item out of order from the right in the vector
	int j = toCheck.size() - 1;
	while (j > 0 && toCheck[j - 1] < toCheck[j])
	{
		j -= 1;
	}
	int firstoooright = j;

	if (firstoooleft == firstoooright)
	{
		return HowToSort();
	}

	int l = firstoooleft;
	int r = firstoooright;
	//counting number of swaps
	int swaps = 0;
	//swwaping elements in vector if needed and counting the number of swaps done
	//similar to in-place quick sort
	while (r - 1 > 0 && l<r)
	{
		if (toCheck[l] > toCheck[r])
		{
			std::swap(toCheck[r], toCheck[l]);
			swaps = swaps + 1;
		}
		r -= 1;
		l += 1;

	}
	//check if its sorted
	bool isItSorted = checkSort(toCheck);
	if (isItSorted == true)
	{
		//we did a swap
		if (swaps == 1)
		{
			return HowToSort(firstoooleft, firstoooright, true);
		}
		//if we did more than 1 swap, we check if it was a range swap
		else if (swaps == (firstoooright - firstoooleft + 1)/2)
		{
			return HowToSort(firstoooleft, firstoooright, false);
		}
	}
	//not sorted, return object with no constructor
	else
	{
		return HowToSort();
	}

}
// Don't write any code below this line

#endif
