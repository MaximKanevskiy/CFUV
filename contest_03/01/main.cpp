#include <iostream>
#include <algorithm>

int main()
{
	size_t size1, size2;
	std::cin >> size1;
	int* array1 = new int[size1];

	for (int i = 0; i < size1; i++)
	{
		std::cin >> array1[i];
	}

	std::cin >> size2;
	int* array2 = new int[size2] ;

	for (int i = 0; i < size2; i++)
	{
		std::cin >> array2[i];
	}

	int final_size = size1 + size2;
	int* whole_array = new int[size1 + size2];

	std::copy(array1, array1 + size1, whole_array);
	std::copy(array2, array2 + size2, whole_array + size1);

	std::sort(whole_array, whole_array + final_size);

	for (int i = 0; i < final_size; i++) 
	{
		std::cout << whole_array[i] << " ";
	}

	delete[] array1, array2, whole_array;
}
