// Time Library.cpp : This file contains the 'main' function. Program execution begins and ends there.
// PROGRAMMER : SAEED LAHMDI

#pragma warning(disable : 4996)

#include <iostream>
#include "clsTime.h"
#include <ctime>

using namespace std;

int main()
{
    clsTime Time1(1, 5, 1), Time2(1, 5, 1);

    cout << "Time 1: ";
    Time1.Print();
    
    cout << "Time 2: ";
    Time2.Print();

    cout << "Is Time1 Before Time2: " << Time1.IsTimeBeforeTime2(Time2) << endl;
    cout << "Is Time1 After Time2: " << Time1.IsTimeAfterTime2(Time2) << endl;
    cout << "Is Time1 Equal Time2: " << Time1.IsTimeEqualTime2(Time2) << endl;

    return 0;
}
