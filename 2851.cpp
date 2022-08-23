#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int sum = 0;
    for (int i = 0; i < 10; ++i) {
        int score;
        cin >> score;
        if (abs(sum - 100) < abs(sum + score - 100)) {
            for (int j = i + 1; j < 10; ++j) {
                cin >> score;
            }
            cout << sum;
            return 0;
        }
        sum += score;
    }
    cout << sum;
    return 0;
}
