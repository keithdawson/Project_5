//This is the Heap program by Blake Mizzell

#include <vector>
#include "MyDynA.cpp"
using namespace std;

class Heap
{
private:
	void BubbleDown(int index);
	void BubbleUp(int index);
	void minHeapify();
	void maxHeapify();
	MyDynamicArray dynA;
public:
	Heap(int a[], int, string);
	Heap(int a[], int);
	Heap();

	void insert(int newValue);
	int extract();
	void out();
};


Heap::Heap(int* array, int length)
{
	for (int i = 0; i < length; i++) dynA.add(array[i]);
	minHeapify();
}

Heap::Heap(int* array, int length, string s)
{
	std::string str(s);
	if (str.compare("max")){
		for(int i = 0; i < length; ++i)
		{
			dynA.add(array[i]);
		}
		maxHeapify();
	}
	else {
		for(int i = 0; i < length; ++i)
		{
			dynA.add(array[i]);
		}
		minHeapify();
	}
}

Heap::Heap()
{
}

void Heap::minHeapify()
{
	int length = dynA.length();
	for(int i=length-1; i>=0; --i)
	{
		BubbleDown(i);
	}
}

void Heap::maxHeapify()
{
	int length = dynA.length();
	for(int i=length-1; i>=0; --i)
	{
		BubbleUp(i);
	}
}

void Heap::BubbleDown(int index)
{
	int length = dynA.length();
	int leftChildIndex = 2*index + 1;
	int rightChildIndex = 2*index + 2;

	if(leftChildIndex >= length)
		return; //index is a leaf

	int minIndex = index;

	if(dynA[index] > dynA[leftChildIndex])
	{
		minIndex = leftChildIndex;
	}

	if((rightChildIndex < length) && (dynA[minIndex] > dynA[rightChildIndex]))
	{
		minIndex = rightChildIndex;
	}

	if(minIndex != index)
	{
		//need to swap
		int temp = dynA[index];
		dynA[index] = dynA[minIndex];
		dynA[minIndex] = temp;
		BubbleDown(minIndex);
	}
}

void Heap::BubbleUp(int index)
{
	if(index == 0)
		return;

	int parentIndex = (index-1)/2;

	if(dynA[parentIndex] > dynA[index])
	{
		int temp = dynA[parentIndex];
		dynA[parentIndex] = dynA[index];
		dynA[index] = temp;
		BubbleUp(parentIndex);
	}
}

void Heap::insert(int newValue)
{
	int length = dynA.length();
	dynA[length] = newValue;

	BubbleUp(length);
}

void Heap::out(){
	for (int i=0; i < dynA.length(); i++) {
		cout<<dynA[i];
	}
}