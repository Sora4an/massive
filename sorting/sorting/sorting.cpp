#include <iostream>
using namespace std;
//1
void bubbleSort(int array[], int listLength)
{
	while (listLength--)
	{
		bool swapped = false;

		for (int i = 0; i < listLength; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array[i], array[i + 1]);
				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}
}
//2
void insertionSort(int array2[], int listLength)
{
	for (int i = 1; i < listLength; i++)
	{
		int j = i - 1; //previous element
		while (j >= 0 && array2[j] > array2[j + 1]) //compare previous and next element, if the next one element is bigger than the previous, then
		{
			swap(array2[j], array2[j + 1]); //swap them
			j--;
		}
	}
}


int main()
{
	int array[7] = { 6, 23, 0, 45, 78, 13, 8 };
	
	//1
	cout << "1.Puzirkovaya sortirovka" << endl;

	cout << "Initial array " << endl;
      for (int i = 0; i < 7; i++)
		cout << array[i] << '\t';
	cout << endl;

	bubbleSort(array, 7);

	cout << "Sorted array " << endl;

	for (int i = 0; i < 7; i++)

		cout << array[i] << '\t';
	cout << endl;

	//2 
	int array2[16] = { 6, 23, 0, 45, 78, 13, 8, 64, 239, 87, 9, 5, 76, 22, 34, 10};

	cout << "2.Sortirovka vstavkami " << endl;

	cout << "Initial array "  << endl;
	for (int i = 0; i < 16; i++)
		cout << array2[i] << '\t';
	cout << endl;

	insertionSort(array2, 16);

	cout << "Sorted array " << endl;

	for (int i = 0; i < 16; i++)

		cout << array2[i] << '\t';
	cout << endl;
	return 0;
}