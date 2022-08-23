#include <iostream>
#include <string>
using namespace std;

int main() {
    string grade;
    cin >> grade;
    double grade2 = 0;
    switch (grade[0]) {
        case 'A':
            grade2 += 4.0;
            break;
        case 'B':
            grade2 += 3.0;
            break;
        case 'C':
            grade2 += 2.0;
            break;
        case 'D':
            grade2 += 1.0;
            break;
    }
    switch (grade[1]) {
        case '+':
            grade2 += 0.3;
            break;
        case '-':
            grade2 -= 0.3;
            break;
    }
    cout.precision(1);
    cout << fixed << showpoint << grade2;
    return 0;
}
