#include <iostream>

void merge(uint32_t* first, size_t first_len ,
	uint32_t* second, size_t second_len, uint32_t* result)
{
	uint32_t*q = first;
	uint32_t*p = second;
	for (size_t i = 0; i < first_len + second_len; i++ )
	{
		if (first+first_len > q && second+second_len > p)
		{
			if(*p > *q)
			{
				result[i] = *q;
				q++;
			}
			else
			{
				result[i] = *p;
				p++;
			}
			continue;
		}
		if (first+first_len <= q && second + second_len > p)
		{
			result[i] = *p;
			p++;
			continue;
		}
		if (second+second_len <= p && first + first_len >q)
		{
			result[i] = *q;
			q++;
			continue;
		}
	}
	return;
}


void out_array(uint32_t*array, size_t len)
{
	for (size_t i =0; i < len; i++)
	{
		std::cout<<array[i] << std::endl;
	}
	std::cout << std::endl;
}


void merge_sort(uint32_t* array, size_t len)
{
	if (len == 1)
	{
		return;
	}
	else
	{
		uint32_t tmp_array[len];
		for(size_t i =0; i< len; i++)
		{
			tmp_array[i] = array[i];
		}
		merge_sort(array, len/2);
		merge_sort(array + len/2 , len - len/2);
		merge(array, len/2, array + len/2, len - len/2, tmp_array );
		for(size_t i = 0; i< len; i++)
		{
			array[i] = tmp_array[i];
		}
	}
	return;
}


int main(int argc, char const *argv[])
{
	uint32_t len_a = 10;
	uint32_t* a = new uint32_t[len_a];
	for (size_t i = 0 ; i < len_a; i++)
	{
		a[i] = rand();
	}
	merge_sort(a,len_a);
	out_array(a, len_a);
	delete[] a;
	return 0;
}