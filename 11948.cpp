#include <iostream>
using namespace std;

int main() {
    int score, sum = 0, min = 100;
    for (int i = 0; i < 4; ++i) {
        cin >> score;
        sum += score;
        if (score < min) {
            min = score;
        }
    }
    sum -= min;
    min = 100;
    for (int i = 0; i < 2; ++i) {
        cin >> score;
        sum += score;
        if (score < min) {
            min = score;
        }
    }
    sum -= min;
    cout << sum;
    return 0;
}
