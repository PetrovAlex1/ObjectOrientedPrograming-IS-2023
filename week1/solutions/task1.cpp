#include <iostream>

int* createArr(size_t size)
{
	int* arr = new int[size];
	return arr;
}

void inputArr(int* arr,const size_t& size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

int countSameNums(const int* arr1, const int* arr2, const size_t& size1, const size_t& size2)
{
	int count = 0;
	for (size_t i = 0; i < size1; i++)
	{
		for (size_t j = 0; j < size2; j++)
		{
			if (arr1[i] == arr2[j])
				++count;
		}
	}
	return count;
}

int* sameNums(const int* arr1, const int* arr2, const size_t& size1, const size_t& size2)
{
	int size = countSameNums(arr1, arr2, size1, size2);
	
	if (size == 0)
		return nullptr;
	int* result = new int[size];
	int index = 0;
	for (size_t i = 0; i < size1; i++)
	{
		for (size_t j = 0; j < size2; j++)
		{
			if (arr1[i] == arr2[j])
			{
				result[index] = arr1[i];
				index += 1;
			}
		}
	}
	return result;
}

void outputArr(const int* arr, const size_t& size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}

int main()
{
	int n, m;
	std::cin >> n >> m;
	int* arr1 = createArr(n);
	inputArr(arr1, n);
	int* arr2 = createArr(m);
	inputArr(arr2, m);
	int* result = sameNums(arr1, arr2, n, m);
	outputArr(result, countSameNums(arr1, arr2, n, m));
	delete[] arr1;
	delete[] arr2;
	delete[] result;
}