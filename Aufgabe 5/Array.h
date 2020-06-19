#pragma once
class Array
{
public:
	Array();
	Array(int asize);
	~Array();

	int get(int index);
	void set(int index, int value);
	void resize(int asize);
	int getsize();
	void print();

private:
	int arrSize;
	int* arrPtr; 
	int* m_resize(int* bufferArray, int newSize);

};

