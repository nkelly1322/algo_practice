#pragma once

#include "GNode.cpp"
#include <Vector>
#include <Utility>
#include <iostream>
using namespace std;

template <class T>
class BinarySearchTree
{
public:
	GNode<T, char>* root;
	
	BinarySearchTree(vector<T> input)
	{
		//complete binary tree has 2^h - 1 nodes in total
		root = Shoot(input, 0, input.size()-1);
	}

	GNode<T, char>* Shoot(vector<T> input, int l, int r)
	{
		int local_root = ceil((r - l) / 2) + l;
		GNode<T, char>* node = new GNode<T, char>(input[local_root]);
		if(l < local_root)
		{
			node->edgeTo.push_back(pair<char, GNode<T, char>*>('l', Shoot(input, l, local_root - 1)));
		}
		if (r > local_root)
		{
			node->edgeTo.push_back(pair<char, GNode<T, char>*>('r', Shoot(input, local_root + 1, r)));
		}
		return node;
	}
	
	int getHeight()
	{
		GNode<T, char>* node = root;
		int height = 1;
		if (node == nullptr)
		{
			return 0;
		}
		while (!(node->edgeTo.empty()))
		{
			node = node->edgeTo.front().second;
			height++;
		}
		return height + 2;
	}

	void inOrder()
	{
		vector<list<T>> tree;
		for (int i = 0; i < getHeight(); i++)
		{
			//tree deconstructor should delete these p sure...
			tree.push_back(list<T>());
		}
		if ((root->edgeTo.size()) > 0 && 
			(root->edgeTo.front().first == 'l'))
		{
			inOrder(root->edgeTo.front().second, tree, 1);
		}
		cout << root->value << " ";
		tree[0].push_back(root->value);
		if ((root->edgeTo.size()) > 0 &&
			(root->edgeTo.back().first == 'r'))
		{
			inOrder(root->edgeTo.back().second, tree, 1);
		}
		cout << endl;
		for (auto l : tree)
		{
			for (auto n : l)
			{
				cout << n << " ";
			}
			cout << endl;
		}
	}
private:
	void inOrder(GNode<T, char>* node, vector<list<T>>& tree, int level)
	{
		if ((node->edgeTo.size()) > 0 &&
			(node->edgeTo.front().first == 'l'))
		{
			inOrder(node->edgeTo.front().second, tree, level + 1);
		}
		cout << node->value << " ";
		tree[level].push_back(node->value);
		if ((node->edgeTo.size()) > 0 &&
			(node->edgeTo.back().first == 'r'))
		{
			inOrder(node->edgeTo.back().second, tree, level + 1);
		}
	}
};