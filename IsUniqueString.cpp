#include "IsUniqueString.h"
#include <string>
using namespace std;

bool isUniqueString(string str)
{
	if (str.length() < 2)
	{
		return true;
	}
	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] == str[i-1])
		{
			return false;
		}
	}
	return true;
}


void quickSort(string& str, int l, int r)
{
	if (r-l+1 < 2)
	{
		return;
	}
	int rpiv = (rand() % (r - l + 1)) + l;
	char pivot = str[rpiv];
	int i = l;
	int j = l;
	swap(str, r, rpiv);
	//if something is less than the pivot
	//swap it with the next leftmost spot
	//where j finishes is the pos after the last lesser element
	//put the pivot there as everything after is greater than the pivot
	for (int i = l; i < r; i++)
	{
		if (str[i] < pivot)
		{
			swap(str, i, j);
			j++;
		}
	}
	swap(str, j, r);
	//quicksort on either side of the pivot, as pivot is in final position
	quickSort(str, l, j -1);
	quickSort(str, j+1, r);
}

void swap(string &str, int i, int j)
{
	char tmp = str[i];
	str[i] = str[j];
	str[j] = tmp;
}