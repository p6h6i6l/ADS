#include <iostream>

int32_t BinSearch(int32_t* array, int32_t left, int32_t right, int32_t key, int32_t fail)
{
	while ( left < right)
	{
		int32_t pivot = (left+right)/2;
		if (key < array[pivot])
		{
			right = pivot;
			continue;
		}
		if (array[pivot] < key)
		{
			left = pivot +1;
			continue;
		}
		else
		{
			return pivot;
		}
	}
	return fail;
}

int main(int argc, char const *argv[])
{
	int32_t a[5];
	for (size_t i = 0; i < 5; i++)
	{
		a[i] = i;
	}
	std::cout << BinSearch(a, 0, 4, 0, 228);
	return 0;
}