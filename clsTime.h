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

	bool static IsAM(short Hour)
	{
		return (Hour >= 0 && Hour <= 11);
	}

	bool IsPM(short Hour)
	{
		return (Hour >= 12 && Hour <= 23);
	}

	static bool IsHuorBeforeHour2(short Hour1, short Hour2)
	{
		return Hour1 < Hour2;
	}

	bool IsHuorBeforeHour2(short Hour)
	{
		return IsHuorBeforeHour2(_Hour, Hour);
	}

	static bool IsMinuteBeforeMinute2(short Minute1, short Minute2)
	{
		return Minute1 < Minute2;
	}

	bool IsMinuteBeforeMinute2(short Minute)
	{
		return IsMinuteBeforeMinute2(_Minute, Minute);
	}

	static bool IsSecondBeforeSecond2(short Second1, short Second2)
	{
		return Second1 < Second2;
	}

	bool IsSecondBeforeSecond2(short Second)
	{
		return IsSecondBeforeSecond2(_Second, Second);
	}

	static bool IsHuorAfterHour2(short Hour1, short Hour2)
	{
		return Hour1 > Hour2;
	}

	bool IsHuorAfterHour2(short Hour)
	{
		return IsHuorAfterHour2(_Hour, Hour);
	}

	static bool IsMinuteAfterMinute2(short Minute1, short Minute2)
	{
		return Minute1 > Minute2;
	}

	bool IsMinuteAfterMinute2(short Minute)
	{
		return IsMinuteAfterMinute2(_Minute, Minute);
	}

	static bool IsSecondAfterSecond2(short Second1, short Second2)
	{
		return Second1 > Second2;
	}

	bool IsSecondAfterSecond2(short Second)
	{
		return IsSecondAfterSecond2(_Second, Second);
	}

	static bool IsHuorEqualHour2(short Hour1, short Hour2)
	{
		return Hour1 == Hour2;
	}

	bool IsHuorEqualHour2(short Hour)
	{
		return IsHuorEqualHour2(_Hour, Hour);
	}

	static bool IsMinuteEqualMinute2(short Minute1, short Minute2)
	{
		return Minute1 == Minute2;
	}

	bool IsMinuteEqualMinute2(short Minute)
	{
		return IsMinuteEqualMinute2(_Minute, Minute);
	}

	static bool IsSecondEqualSecond2(short Second1, short Second2)
	{
		return Second1 == Second2;
	}

	bool IsSecondEqualSecond2(short Second)
	{
		return IsSecondEqualSecond2(_Second, Second);
	}

	static bool IsTimeBeforeTime2(clsTime Time1, clsTime Time2)
	{
		if (Time1.IsHuorBeforeHour2(Time2.Hour))
			return true;

		else if (Time1.IsHuorEqualHour2(Time2.Hour))
		{
			if (Time1.IsMinuteBeforeMinute2(Time2.Minute))
				return true;

			if (Time1.IsMinuteEqualMinute2(Time2.Minute))
			{
				if (Time1.IsSecondBeforeSecond2(Time2.Second))
					return true;

				else
					return false;
			}

			else
				return false;

		}

		return false;
	}

	bool IsTimeBeforeTime2(clsTime Time2)
	{
		return IsTimeBeforeTime2(*this, Time2);
	}

	static bool IsTimeAfterTime2(clsTime Time1, clsTime Time2)
	{
		if (Time1.IsHuorAfterHour2(Time2.Hour))
			return true;

		else if (Time1.IsHuorEqualHour2(Time2.Hour))
		{
			if (Time1.IsMinuteAfterMinute2(Time2.Minute))
				return true;

			if (Time1.IsMinuteEqualMinute2(Time2.Minute))
			{
				if (Time1.IsSecondAfterSecond2(Time2.Second))
					return true;

				else
					return false;
			}

			else
				return false;

		}

		return false;
	}

	bool IsTimeAfterTime2(clsTime Time2)
	{
		return IsTimeAfterTime2(*this, Time2);
	}

	static bool IsTimeEqualTime2(clsTime Time1, clsTime Time2)
	{
		return (Time1.IsHuorEqualHour2(Time2.Hour) && Time1.IsMinuteEqualMinute2(Time2.Minute) && Time1.IsSecondEqualSecond2(Time2._Second));
	}

	bool IsTimeEqualTime2(clsTime Time2)
	{
		return IsTimeEqualTime2(*this, Time2);
	}

	void Print()
	{
		Print(*this);
	}

};

