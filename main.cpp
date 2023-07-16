// Time Library.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Programmed : Saeed Lahmdi

#pragma warning(disable : 4996)

#include <iostream>
#include "clsTime.h"
#include <ctime>
#include "clsUtil.h"

using namespace std;

int main()
{
    
    clsTime Time("12:30:59", ":");

    cout << "\nOBJECT TIME: ";
    Time.Print();

    cout << "LOCAL TIME : ";
    clsTime::getLocalTime().Print();

    cout << "UTC TIME   : ";
    clsTime::getUTCTime().Print();

    return 0;
}
