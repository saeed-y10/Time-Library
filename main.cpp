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
    // it's important to use this method fist thing in the main function before any this
    // to change time seed in every run.
    clsUtil::Srand();

    cout << "\nLOCAL TIME: ";
    clsTime::getLocalTime().Print();

    cout << "UTC TIME: ";
    clsTime::getUTCTime().Print();

    return 0;
}
