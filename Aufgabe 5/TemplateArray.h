#pragma once
#include <iostream>
#include <sstream>

template<class item_type>

class TemplateArray
{
public:
	TemplateArray();
	TemplateArray(int arrSize);
	~TemplateArray();

	item_type get(int index);
	void set(int index, item_type value);
	void resize(int newSize);
	int getSize();
	void print();
	std::string m_name; //needed for Testklasse

private:
	int arrSize;
	item_type* arrPtr;
	item_type* m_resize(item_type* buffArray, int size);

};

template<class item_type>
inline TemplateArray<item_type>::TemplateArray()
{
}

template<class item_type>
inline TemplateArray<item_type>::TemplateArray(int asize)
{
	arrSize = asize;
	arrPtr = new item_type[arrSize];

	for (int x = 0; x < arrSize; x++)
	{
		arrPtr[x] = 0;
	}
}

template<class item_type>
inline TemplateArray<item_type>::~TemplateArray()
{
	delete[] arrPtr;
}

template<class item_type>
inline item_type TemplateArray<item_type>::get(int index)
{
	return arrPtr[index];
}

template<class item_type>
inline void TemplateArray<item_type>::set(int index, item_type value)
{
	arrPtr[index] = value;
}

template<class item_type>
inline void TemplateArray<item_type>::resize(int newSize)
{
	item_type* bufferArray;
	int buffSize = arrSize; //otherwise else if statement will always be called if we make the array smaller
	bool arrResize = true;
	bool validChoice = false;
	std::string inputBuff;
	char chInput;
	bufferArray = new item_type[newSize]; //we need to initalize a new array to copy the content to
	do
	{
		if (newSize < arrSize)
		{
			if (arrPtr[newSize] != 0) //failsafe in case new size smaller than old size, we don't want to accidentally lose data
			{
				std::cout << "The array is not empty, are you sure you want to resize?" << std::endl;
				while (validChoice == false)
				{
					std::cin >> inputBuff;
					std::stringstream(inputBuff) >> chInput;
					switch (chInput)
					{
					case 'y': arrPtr = m_resize(bufferArray, newSize);//resize array to smaller size, arrPtr is now bufferArray
						arrSize = newSize;
						validChoice = true;
						break;
					case 'n': arrResize = false; validChoice = true; break;
					default: std::cout << "This is not a valid choice. Please choose valid option (y/n)." << std::endl;
						break;
					}
				}
			}
		}
		else if (buffSize == newSize) // no need to copy array content in new array, if old array already has the same size
		{
			std::cout << "The array already has the size " << arrSize << std::endl;
			arrResize = false;
		}
		else
		{
			arrPtr = m_resize(bufferArray, newSize);
			for (int z = arrSize; z < newSize; z++)
			{
				arrPtr[z] = 0; //fill extra space with zeros
			}
			arrSize = newSize;
			arrResize = false; //exit
		}


	} while (arrResize == true);

}

template<class item_type>
inline int TemplateArray<item_type>::getSize()
{
	return arrSize;
}

template<class item_type>
inline void TemplateArray<item_type>::print()
{
	std::cout << "\nCurrent Array: " << std::endl;
	for (int x = 0; x < arrSize; x++)
	{
		std::cout << arrPtr[x] << " ";
	}
}

template<class item_type>
inline item_type* TemplateArray<item_type>::m_resize(item_type* bufferArray, int newSize)
{
	for (int z = 0; z < newSize; z++)
	{
		bufferArray[z] = arrPtr[z];
	}
	return bufferArray;
}
