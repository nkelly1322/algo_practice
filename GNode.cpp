#pragma once

#include <List>
#include <Utility>
using namespace std;

template <class T, class C>
class GNode 
{
public:
	list<pair<C, GNode<T, C>* > > edgeTo;
	T value;

	GNode(T val) :value(val) {}
private:
};