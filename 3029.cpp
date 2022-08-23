#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    // input
    int currTime[3], throwingTime[3], waitingTime[3] = {0};
    string a, b;
    cin >> a >> b;
    if (a == b) {
        cout << "24:00:00";
        return 0;
    }
    for (int i = 0; i < 3; ++i) {
        currTime[i] = stoi(a.substr(i * 3 , 2));
        throwingTime[i] = stoi(b.substr(i * 3, 2));
    }
    
    // compute
    for (int i = 2; i >= 0; --i) {
        waitingTime[i] += throwingTime[i] - currTime[i];
        if (waitingTime[i] < 0) {
            switch (i) {
                case 2:
                case 1:
                    waitingTime[i] += 60;
                    --waitingTime[i-1];
                    break;
                case 0:
                    waitingTime[i] += 24;
                    break;
            }
        }
    }

    // output
    cout << setfill('0');
    for (int i = 0; i < 2; ++i) {
        cout << setw(2) << waitingTime[i] << ':';
    }
    cout << setw(2) << waitingTime[2];
    return 0;
}
