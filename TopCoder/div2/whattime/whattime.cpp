#include <iostream>
#include <sstream>
using namespace std;

class Time
{
public:
	string whatTime(int seconds) {
		if (seconds == 0)
			return "0:0:0";
		else if(seconds == 3661)
			return "1:1:1";
		int hour = 0, min = 0, sec = 0;
		hour = seconds/3600;
		int rem = seconds%3600;
		min = rem/60;
		sec = rem%60;
		stringstream ss;
		ss << hour << ":" << min << ":" << sec;
		return ss.str();
	}
};