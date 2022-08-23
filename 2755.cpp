#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    double sum = 0;
    int sumOfCredits = 0;
    while (N--) {
        int credit;
        string name, grade;
        cin >> name >> credit >> grade;
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
        sum += credit * grade2;
        sumOfCredits += credit;
    }

    cout.precision(2);
    cout << fixed << floor(sum / sumOfCredits * pow(10, 2) + 0.5) / pow(10, 2);
    return 0;
}
