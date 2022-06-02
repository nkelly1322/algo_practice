// CTCI Problems.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "IsUniqueString.h"
#include <string>
#include <list>
#include "LL_Rem_Dup.h"
#include "SingleLL.cpp"
#include "minstack.cpp"

int main()
{
    string pause;
    /*
    string str = "aijfqe";
    quickSort(str, 0, str.length()-1);
    */
    /*
    list<string> test = { "aa","aa","cc","cc","asdf","cc", "aa"};
    remDups(test);
    for (auto it : test)
    {
        std::cout << it << ":";
    }
    //std::cout << str;
    */
    MinStack<int> ms;
    ms.push(3);
    ms.push(2);
    ms.push(5);
    ms.push(7);
    ms.push(3);
    ms.push(8);
    ms.push(3);
    ms.push(2);
    ms.push(0);
    ms.push(1);
    ms.push(1);

    std::cout << ms.minimum() << endl;

    ms.pop();
    ms.pop();
    ms.pop();

    std::cout << ms.minimum() << endl;

    ms.pop();

    std::cout << ms.minimum() << endl;

    std::cin >> pause;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
