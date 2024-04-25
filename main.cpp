#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>



int main()
{
	setlocale(LC_ALL, "");

	// ==> start time
	// get the current time
	auto start = std::chrono::system_clock::now();
	auto start_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(start);

	// convert time into a time structure (tm)
	std::time_t start_time = std::chrono::system_clock::to_time_t(start);
	std::tm start_tm;
	localtime_s(&start_tm, &start_time);

	// ouyput the current time in the format HH:MM:SS.mmm
	std::cout << "Start: ";
	std::cout << (start_tm.tm_hour < 10 ? "0" : "") << start_tm.tm_hour << ":";
	std::cout << (start_tm.tm_min < 10 ? "0" : "") << start_tm.tm_min << ":";
	std::cout << (start_tm.tm_sec < 10 ? "0" : "") << start_tm.tm_sec << ".";
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(start_ms.time_since_epoch()).count() % 1000 << std::endl;
	std::cout << "\n";
	// ===========
		
	
	
	// ==> payload	
	long long int l{ 1 };
	for (long long int i = 1; i < 100'000'000'000; ++i) {
		// payload
		if (l >= 10'000'000'000) {
			std::cout << i << std::endl;
			l = 1;
		}
		else ++l;
	}
	std::cout << "\n";
	// ============



	// ==> finish time
	// get the current time
	auto finish = std::chrono::system_clock::now();
	auto finish_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(finish);

	// convert time imto a time structure (tm)
	std::time_t finish_time = std::chrono::system_clock::to_time_t(finish);
	std::tm finish_tm;
	localtime_s(&finish_tm, &finish_time);

	// output the current time in the format HH:MM:SS.mmm
	std::cout << "Finish time: ";
	std::cout << (finish_tm.tm_hour < 10 ? "0" : "") << finish_tm.tm_hour << ":";
	std::cout << (finish_tm.tm_min < 10 ? "0" : "") << finish_tm.tm_min << ":";
	std::cout << (finish_tm.tm_sec < 10 ? "0" : "") << finish_tm.tm_sec << ":";
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(finish_ms.time_since_epoch()).count() % 1000 << std::endl;
	std::cout << "\n";
	// ===========



	// ==> time difference
	// calculate te difference between the times in milliseconds
    auto time_spent = finish - start;
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(time_spent);

    // calculate the number of hours, minutes, seconds and milliseconds
    auto hours = std::chrono::duration_cast<std::chrono::hours>(ms);
    ms -= hours;
    auto minutes = std::chrono::duration_cast<std::chrono::minutes>(ms);
    ms -= minutes;
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(ms);
    ms -= seconds;

    // output the time difference beetween events in the format HH:MM:SS.mmm
    std::cout << "time has passed: ";
    std::cout << std::setfill('0');		// filler for output with zeros
    std::cout << std::setw(2) << hours.count() << ":";		// two symbols for the clock
    std::cout << std::setw(2) << minutes.count() << ":";	// two symbols for minutes
    std::cout << std::setw(2) << seconds.count() << ".";	// two symbols for seconds
    std::cout << std::setw(3) << ms.count() << std::endl;	// two symbols for milliseconds
	std::cout << "\n";



    return 0;
}