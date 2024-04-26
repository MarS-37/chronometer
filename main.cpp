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
        // that's milliseconds
        std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(
            start_time.time_since_epoch()
        );
        // output the start time in the format HH:MM:SS.mmm
        std::cout << "Start_time: ";
        // format and display hours, minutes and seconds
        std::cout << std::put_time(&start_tm, "%H:%M:%S");
        // output milliseconds
        std::cout << "." << std::setw(3) << std::setfill('0') << ms.count() % 1000 << std::endl;
    }

private:
    bool started;
    std::chrono::time_point<std::chrono::steady_clock> start_time;
};


int main() {
    Chronometr timer;
    timer.TimeStart();


    
    //// ==> payload	
    //long long int l{ 1 };
    //for (long long int i = 1; i < 20'000'000'000; ++i) {
    //    // payload
    //    if (l >= 10'000'000'000) {
    //        std::cout << i << std::endl;
    //        l = 1;
    //    }
    //    else ++l;
    //}
    //std::cout << "\n";
    //// ============




    return 0;
}