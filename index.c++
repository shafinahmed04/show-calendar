#include <iostream>
#include <iomanip>
using namespace std;

bool isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

void printCalendar(int year) {
    for (int month = 1; month <= 12; ++month) {
        cout << "\n\n" << setw(24) << setfill('-') << "\n";
        cout << setw(11) << setfill(' ') << left << "| " << right << year << " - " << setw(2) << setfill('0') << month << " |\n";
        cout << setw(24) << std::setfill('-') << "\n";
        cout << "| Sun | Mon | Tue | Wed | Thu | Fri | Sat |\n";
        cout << setw(24) << setfill('-') << "\n";

        int daysInMonth;
        if (month == 2) {
            daysInMonth = isLeapYear(year) ? 29 : 28;
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            daysInMonth = 30;
        } else {
            daysInMonth = 31;
        }

        int dayOfWeek = 0; // 0 corresponds to Sunday
        for (int day = 1; day <= daysInMonth; ++day) {
            if (dayOfWeek == 0) {
                cout << "| ";
            }
            if (day < 10) {
                cout << " ";
            }
            std::cout << day << " | ";
            if (dayOfWeek == 6) {
                cout << "\n";
                dayOfWeek = 0;
            } else {
                ++dayOfWeek;
            }
        }

        // Fill the remaining cells in the last row with spaces
        for (; dayOfWeek <= 6; ++dayOfWeek) {
            cout << "    | ";
        }

        cout << "\n\n";
    }
}

int main() {
    int year;
    cout << "Enter the year for the calendar: ";
    cin >> year;

    printCalendar(year);

    return 0;
}
