#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

class clsTime
{
private:

	short _Hour;
	short _Minute;
	short _Second;

public:

	clsTime()
	{
		time_t t = time(0);
		tm* Time = localtime(&t);

		_Hour = Time->tm_hour;
		_Minute = Time->tm_min;
		_Second = Time->tm_sec;
	}

	clsTime(short Hour, short Minute, short Second)
	{
		time_t t = time(0);
		tm* Time = localtime(&t);

		if (Hour < 0 || Hour > 23)
			Hour = Time->tm_hour;

		if (Minute < 0 || Minute > 59)
			Minute = Time->tm_min;

		if (Second < 0 || Second > 59)
			Second = Time->tm_sec;

		_Hour = Hour;
		_Minute = Minute;
		_Second = Second;
	}

	static short HourTo12HoursSystem(short Hour)
	{
		if (Hour == 0)
			return 12;

		else if (Hour >= 1 && Hour <= 12)
			return Hour;

		else if (Hour >= 13 && Hour <= 23)
			return Hour - 12;

		return HourTo12HoursSystem(getSystemHour());
	}

	static short getSystemHour()
	{
		time_t t = time(0);
		tm* Time = localtime(&t);

		return Time->tm_hour;
	}

	static short getSystemMinute()
	{
		time_t t = time(0);
		tm* Time = localtime(&t);

		return Time->tm_min;
	}

	static short getSystemSecond()
	{
		time_t t = time(0);
		tm* Time = localtime(&t);

		return Time->tm_sec;
	}

	static clsTime getSystemTime()
	{
		time_t t = time(0);
		tm* Time = localtime(&t);

		return clsTime(Time->tm_hour, Time->tm_min, Time->tm_sec);
	}

	void setHour(short Hour)
	{
		if (Hour < 0 || Hour > 23)
			_Hour = getSystemHour();

		else
			_Hour = Hour;
	}

	short getHour()
	{
		return _Hour;
	}
	__declspec(property(get = getHour, put = setHour))short Hour;

	void setMinute(short Minute)
	{
		if (Minute < 0 || Minute > 59)
			_Minute = getSystemMinute();

		else
			_Minute = Minute;
	}

	short getMinute()
	{
		return _Minute;
	}
	__declspec(property(get = getMinute, put = setMinute))short Minute;

	void setSecond(short Second)
	{
		if (Second < 0 || Second > 59)
			_Second = getSystemSecond();

		else
			_Second = Second;
	}

	short getSecond()
	{
		return _Second;
	}
	__declspec(property(get = getSecond, put = setSecond))short Second;

	static int DurationInMinutes(short Hours, short Minutes, short Seconds)
	{
		int TotalMinutes = 0;

		TotalMinutes += (Hours * 60);
		TotalMinutes += Minutes;
		TotalMinutes += (Seconds / 60);

		return TotalMinutes;
	}

	static int DurationInMinutes(clsTime Time)
	{
		return DurationInMinutes(Time.Hour, Time.Minute, Time.Second);
	}

	static int DurationInSeconds(short Hours, short Minutes, short Seconds)
	{
		int TotalSeconds = 0;

		TotalSeconds += (Hours * 60 * 60);
		TotalSeconds += (Minutes * 60);
		TotalSeconds += Seconds;

		return TotalSeconds;
	}
	
	static int DurationInSeconds(clsTime Time)
	{
		return DurationInSeconds(Time.Hour, Time.Minute, Time.Second);
	}

	static void Print(clsTime Time)
	{
		cout << setw(2) << setfill('0') << Time.getHour() << ":";
		cout << setw(2) << setfill('0') << Time.getMinute() << ":";
		cout << setw(2) << setfill('0') << Time.getSecond() << endl;
	}

	static short DaylightSavingsHours()
	{
		time_t t = time(0); // to get time now 
		tm* now = localtime(&t);

		return now->tm_isdst;
	}

	static clsTime getLocalTime()
	{
		return getSystemTime();
	}

	static clsTime getUTCtime()
	{
		time_t now = time(0);
		tm* Time = gmtime(&now);

		return clsTime(Time->tm_hour, Time->tm_min, Time->tm_sec);
	}

	/*static void TimeZone()
	{
	}*/

	void Print()
	{
		Print(*this);
	}

};

