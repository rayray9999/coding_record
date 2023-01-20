// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<algorithm>
#include <cmath>
using namespace std;
int main()
{
    float a, b, x[4], y[4], len[4];
    int ans;
    for (int i = 1; i <= 3; i++)
    {
        cout << "Input the ";
        if (i == 1)
        {
            cout << "first ";
        }
        else if (i == 2)
        {
            cout << "second ";
        }
        else
        {
            cout << "third";
        }
        cout << "point in R^2 space x,y= ";
        cin >> x[i] >> y[i];
    }
    if (abs((x[1] - x[2]) / (y[1] - y[2])) == abs((x[1] - x[3]) / (y[1] - y[3])) || abs((x[1] - x[2]) / (y[1] - y[2])) == abs((x[2] - x[3]) / (y[2] - y[3])))
    {
        cout << "These three point cannot form a triangle." << endl;
    }
    else if (abs((x[3] - x[2]) / (y[3] - y[2])) == abs((x[1] - x[3]) / (y[1] - y[3])))
    {
        cout << "These three point cannot form a triangle." << endl;
    }
    else if (x[1] - x[2] == 0 && (y[1] - y[2]) == 0)
    {
        cout << "These three point cannot form a triangle." << endl;
    }
    else if (x[1] - x[3] == 0 && (y[1] - y[3]) == 0)
    {
        cout << "These three point cannot form a triangle." << endl;
    }
    else if ((x[2] - x[3]) == 0 && (y[2] - y[3]) == 0)
    {
        cout << "These three point cannot form a triangle." << endl;
    }
    else
    {
        len[1] = (x[1] - x[2])*(x[1] - x[2]) + (y[1] - y[2])*(y[1] - y[2]);
        len[2]= (x[1] - x[3])*(x[1] - x[3]) + (y[1] - y[3])*(y[1] - y[3]);
        len[3]= (x[3] - x[2])*(x[3] - x[2]) + (y[3] - y[2])*(y[3] - y[2]);
        if (len[2] < len[1])swap(len[1], len[2]);
        if (len[2] > len[3])swap(len[3], len[2]);
        if (len[2] < len[1])swap(len[1], len[2]);
        
        
        cout << "These three point form ";
        if ((len[3] - len[2] - len[1])==0)
        {
            cout << "a right ";
        }
        else if ((len[1] + len[2]) > len[3])
        {
            cout << "an acute ";
        }
        else
        {
            cout << "an obtuse ";
        }
        cout << "triangle." << endl;
    }
    return 0;
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
