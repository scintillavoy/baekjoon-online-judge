#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    static bool compare(const Student &a, const Student &b);
    string name;
    int day = 0;
    int month = 0;
    int year = 0;
};

bool Student::compare(const Student &a, const Student &b) {
    if (a.year != b.year) {
        return a.year < b.year;
    } else if (a.month != b.month) {
        return a.month < b.month;
    } else {
        return a.day < b.day;
    }
}

int main() {
    int n;
    cin >> n;
    Student oldest, youngest;
    cin >> oldest.name >> oldest.day >> oldest.month >> oldest.year;
    youngest = oldest;
    for (int i = 1; i < n; ++i) {
        Student in;
        cin >> in.name >> in.day >> in.month >> in.year;
        if (Student::compare(in, oldest)) {
            oldest = in;
        }
        if (Student::compare(youngest, in)) {
            youngest = in;
        }
    }
    cout << youngest.name << '\n' << oldest.name;
    return 0;
}
