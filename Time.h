#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <iomanip>

struct Time {
    int h;
    int m;
    int s;
};

// Reads a time from stdin as three integers (hours minutes seconds).
inline void getTime(Time &t) {
    std::cin >> t.h >> t.m >> t.s;
}

// Subtracts t1 from t2 and returns the difference as a Time.
// If t2 is earlier than t1, it is treated as on the next day (wrap around 24h).
inline Time subtract(const Time &t2, const Time &t1) {
    int seconds2 = t2.h * 3600 + t2.m * 60 + t2.s;
    int seconds1 = t1.h * 3600 + t1.m * 60 + t1.s;
    int diff = seconds2 - seconds1;
    if (diff < 0) {
        diff += 24 * 3600; // wrap to the next day
    }

    Time result;
    result.h = diff / 3600;
    diff %= 3600;
    result.m = diff / 60;
    result.s = diff % 60;
    return result;
}

// Displays the time in HH:MM:SS format.
inline void display(const Time &t) {
    std::cout << std::setw(2) << std::setfill('0') << t.h << ":"
              << std::setw(2) << std::setfill('0') << t.m << ":"
              << std::setw(2) << std::setfill('0') << t.s
              << std::setfill(' ') << std::endl;
}

#endif // TIME_H
