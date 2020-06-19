#include "Array.h"
#include <iostream> //for cout and endl
#include <sstream>

Array::Array()
{
}

Array::Array(int asize)
{
	arrSize = asize;
	arrPtr = new int[arrSize];

	for (int x = 0; x < arrSize; x++)
	{
		arrPtr[x] = 0;
	}
}

Array::~Array()
{
	delete[] arrPtr;
}

int Array::get(int index)
{
	return arrPtr[index];
}

void Array::set(int index, int value)
{
	arrPtr[index] = value;
}

void Array::resize(int asize)
{
	int* bufferArray;
	int buffSize = arrSize; //otherwise else if statement will always be called if we make the array smaller
	bool arrResize = true;
	bool validChoice = false;
	std::string inputBuff;
	char chInput;
	bufferArray = new int[asize]; //we need to initalize a new array to copy the content to
	
	do
	{
		if (asize < arrSize) 
		{
			if (arrPtr[asize] != 0) //failsafe in case new size smaller than old size, we don't want to accidentally lose data
			{
				std::cout << "The array is not empty, are you sure you want to resize?" << std::endl; 
				while (validChoice == false)
				{
					std::cin >> inputBuff;
					std::stringstream(inputBuff) >> chInput;
					switch (chInput)
					{
					case 'y': arrPtr = m_resize(bufferArray, asize);//resize array to smaller size, arrPtr is now bufferArray
						arrSize = asize;
						validChoice = true;
						break;
					case 'n': arrResize = false; validChoice = true; break;
					default: std::cout << "This is not a valid choice. Please choose valid option (y/n)." << std::endl;
						break;
					}
				}
			}
		}
		else if (buffSize == asize) // no need to copy array content in new array, if old array already has the same size
		{
			std::cout << "The array already has the size " << arrSize << std::endl;
			arrResize = false;
		}
		else
		{
			arrPtr = m_resize(bufferArray, asize);
			for (int z = arrSize; z < asize; z++)
			{
				arrPtr[z] = 0; //fill extra space with zeros
			}
			arrSize = asize;
			arrResize = false; //exit
		}


	} while (arrResize == true);

}

int Array::getsize()
{
	return arrSize;
}

void Array::print()
{
	std::cout << "Current Array: " << std::endl;
	for (int x = 0; x < arrSize; x++)
	{
		std::cout << arrPtr[x] << " ";
	}
}

int* Array::m_resize(int* bufferArray, int newSize) //function now reusable, safes a bit of code
{
	for (int z = 0; z < newSize; z++)
	{
		bufferArray[z] = arrPtr[z];
	}
	return bufferArray;
}

