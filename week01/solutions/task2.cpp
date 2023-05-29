#include <iostream>

bool checkAritmeticProgression(const int first, const int second, const int diff)
{
	return second - first == diff;// operator precedence help us
}

bool checkGeometricProgression(const int first, const int second, const double ratio)
{
	return first * ratio == second;
}

void aritmeticProgressionFilter(double* arr, const int n, double* aritmeticProg, const int aritmeticProgCount, const double diff)
{
	aritmeticProg[1] = arr[0];
	arr[0] = INT_MAX;//set to be INT_MAX for marking it like removed element from the array
	aritmeticProg[2] = arr[1];
	int lastElement = (int)arr[1];
	arr[1] = INT_MAX;//set to be INT_MAX for marking it like removed element from the array
	int j = 3;

	for (size_t i = 2; i < n; i++)
	{
		if (checkAritmeticProgression(lastElement, arr[i], diff))
		{
			aritmeticProg[j] = arr[i];
			lastElement = arr[i];
			arr[i] = INT_MAX;
			j++;
		}
	}
}

void geometricProgressionFilter(double* arr, const int n, double*& geometricProg, const int geometricProgCount)
{
	int lastElement = INT_MAX;
	bool foundRatio = false;
	int j = 1;

	for (size_t i = 2; i < n; i++)
	{
		if (arr[i] != INT_MAX)
		{
			geometricProg[j] = arr[i];
			j++;
		}
	}

	if (geometricProgCount != 1)
	{
		double ratio = geometricProg[2] / geometricProg[1];
		int lastElement = geometricProg[1];

		for (size_t i = 2; i < geometricProgCount; i++)
		{
			if (!checkGeometricProgression(lastElement, geometricProg[i], ratio))
			{
				delete[] geometricProg;
				geometricProg = nullptr;
				return;
			}
		}
	}
}

void filter(double* arr, const int n, double*& aritmeticProg, double*& geometricProg)
{
	double diff = arr[1] - arr[0];
	int aritmeticProgCount = 2;
	int geometricProgCount = 0;
	int lastAritmeticProgElement = arr[1];

	for (size_t i = 2; i < n; i++)
	{
		if (checkAritmeticProgression(lastAritmeticProgElement, arr[i], diff))
		{
			lastAritmeticProgElement = arr[i];
			aritmeticProgCount++;
		}
	}

	aritmeticProg = new double[aritmeticProgCount + 1];// one element more for the size of the array
	aritmeticProg[0] = aritmeticProgCount;
	aritmeticProgressionFilter(arr, n, aritmeticProg, aritmeticProgCount, diff);//filters the elements from arr, which make aritmetic progression

	if (n - aritmeticProgCount > 0)
	{
		geometricProgCount = n - aritmeticProgCount;
		geometricProg = new double[geometricProgCount + 1];
		geometricProg[0] = geometricProgCount;
		geometricProgressionFilter(arr, n, geometricProg, geometricProgCount);
	}
}

int main()
{
	int n;
	std::cin >> n;
	double* arr = new double[n];

	for (size_t i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}

	double* aritmeticProg = nullptr;
	double* geometricProg = nullptr;

	filter(arr, n, aritmeticProg, geometricProg);

	int aritmeticCount = aritmeticProg[0];
	std::cout << "Aritmetic progression: \n";

	for (size_t i = 1; i <= aritmeticCount; i++)
	{
		std::cout << aritmeticProg[i] << " ";
	}

	if (geometricProg)
	{
		int geometricCount = geometricProg[0];
		std::cout << "\nGeometric progression: \n";

		for (size_t i = 1; i <= geometricCount; i++)
		{
			std::cout << geometricProg[i] << " ";
		}

		delete[] geometricProg;
	}
	else
	{
		std::cout << "\nThere is no geometric progression!\n";
	}

	delete[] arr;
	delete[] aritmeticProg;
	return 0;
}