#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>

//+------------------------------------------------------------------+
//|                         class Chronometr                         |
//| auxiliary class, to determine the speed of implementation of     |
//| training programs.                                               |
//|                                      Copyright 2024, Mars37 Ltd. |
//|                                       markin.sergey.37@yandex.ru |
//+------------------------------------------------------------------+
class Chronometr
{
public:
	Chronometr() : started(false) {};
	// method locks the start
	void TimeStart()
	{
		started = true;
		// get the current time
		start_time = std::chrono::steady_clock::now();
		auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		// structure for storing locale time
		std::tm start_tm;
		// get the locale time
		localtime_s(&start_tm, &now);

		// get milliseconds
		std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(
			start_time.time_since_epoch()
			);

		// output the start time in the format HH:MM:SS.mmm
		std::cout << "Start_time: ";
		// format and display hours, minutes and seconds
		std::cout << std::put_time(&start_tm, "%H:%M:%S");
		// output milliseconds
		std::cout << "." << std::setw(3) << std::setfill('0') << ms.count() % 1000 << "\n\n";
	}
	// method to end the time countdown
	void TimeFinish()
	{
		// if timing is started
		if (started) {
			// get the current time
			auto finish_time = std::chrono::steady_clock::now();
			auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
			// structure for storing locale time
			std::tm finish_tm;
			// get the locale time
			localtime_s(&finish_tm, &now);

			// get milliseconds
			std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(
				finish_time.time_since_epoch()
			);

			// output the finish time in the format HH:MM:SS.mmm
			std::cout << "Finish time: ";
			// format and display hours, minutesand seconds
			std::cout << std::put_time(&finish_tm, "%H:%M:%S");
			std::cout << "." << std::setw(3) << std::setfill('0') << ms.count() % 1000 << std::endl;
		}
		else {
			// if the time countdown has not started, 
			// display an error message
			std::cout << "Timer has not started.\n";
		}
	}

private:
	bool started;
	std::chrono::time_point<std::chrono::steady_clock> start_time;
};


int main() {
	Chronometr timer;
	timer.TimeStart();



	// ==> payload	
	long long int l{ 0 };
	for (long long int i = 1; i < 100'000'000'001; ++i) {
	    // payload
		++l;
	    if (l >= 10'000'000'000) {
	        std::cout << i << std::endl;
	        l = 0;
	    }
	}
	std::cout << "\n";
	// ============



	timer.TimeFinish();



	return 0;
}