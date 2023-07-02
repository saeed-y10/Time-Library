// Time Library.cpp : This file contains the 'main' function. Program execution begins and ends there.
// PROGRAMMER : SAEED LAHMDI
#pragma warning(disable : 4996)

#include <iostream>
#include "clsTime.h"
#include <ctime>

using namespace std;

int main()
{
    cout << "Local Time:";

    // get and print local time
    clsTime::getLocalTime().Print();

    cout << "UTC Time: ";
    
    // get and print UTC time
    clsTime::getUTCtime().Print();

    return 0;
}
