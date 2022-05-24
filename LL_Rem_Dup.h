#pragma once
#include <list>
#include <unordered_set>
using namespace std;

template <class T>
void remDups(list<T>& my_list)
{
	unordered_set<T> hash;
	typename list<T>::iterator it;
	typename list<T>::iterator dup;

	for (it = my_list.begin(); it != my_list.end();)
	{
		/*
		* Try to insert value into hash table
		* The second parameter of the return pair is true if insert successful
		* If unable to insert, element already found, therefore, delete
		*/
		if (!((hash.insert(*it)).second))
		{
			dup = it;
			it++;
			my_list.erase(dup);
		}
		else
		{
			it++;
		}
	}
	return;
}