// Time Library.cpp : This file contains the 'main' function. Program execution begins and ends there.
// PROGRAMMER : SAEED LAHMDI

#pragma warning(disable : 4996)

#include <iostream>
#include "clsTime.h"
#include <ctime>

using namespace std;

int main()
{
    clsTime Time1(5, 4, 1), Time2;

    cout << "Time 1: ";
    Time1.Print();
    
    cout << "Time 2: ";
    Time2.Print();

    cout << "\nIs Time1 Before Time2: ";
    if (Time1.IsTimeBeforeTime2(Time2))
        cout << "true.\n";
    else
        cout << "false.\n";

    cout << "Is Time1 After Time2: ";
    if (Time1.IsTimeAfterTime2(Time2))
        cout << "true.\n";
    else
        cout << "false.\n";

    cout << "Is Time1 Equal Time2: ";
    if (Time1.IsTimeEqualTime2(Time2))
        cout << "true.\n";
    else
        cout << "false.\n";

    cout << "\nLOCAL TIME: ";
    clsTime::getLocalTime().Print();

    cout << "UTC TIME: ";
    clsTime::getUTCTime().Print();

    return 0;
}
