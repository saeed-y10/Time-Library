// Time Library.cpp : This file contains the 'main' function. Program execution begins and ends there.
// PROGRAMMER : SAEED LAHMDI

#pragma warning(disable : 4996)

#include <iostream>
#include "clsTime.h"
#include <ctime>

using namespace std;

int main()
{
    cout << "Local Time: ";
    clsTime::getLocalTime().Print(); // get and print local time

    cout << "UTC Time: ";
    clsTime::getUTCtime().Print(); // get and print UTC time

    return 0;
}
