#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    // input
    int timeA[3], timeB[3], timeDiff[3] = {0};
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < 3; ++i) {
        timeA[i] = stoi(a.substr(i * 3 , 2));
        timeB[i] = stoi(b.substr(i * 3, 2));
    }

    // compute
    for (int i = 2; i >= 0; --i) {
        timeDiff[i] += timeB[i] - timeA[i];
        if (timeDiff[i] < 0) {
            switch (i) {
                case 2:
                case 1:
                    timeDiff[i] += 60;
                    --timeDiff[i-1];
                    break;
                case 0:
                    timeDiff[i] += 24;
                    break;
            }
        }
    }

    // output
    cout << setfill('0');
    for (int i = 0; i < 2; ++i) {
        cout << setw(2) << timeDiff[i] << ':';
    }
    cout << setw(2) << timeDiff[2];
    return 0;
}
