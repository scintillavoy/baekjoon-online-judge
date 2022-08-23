#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    int N;
    cin >> N;
    double min7[8];
    for (int i = 0; i < 7; ++i) {
        cin >> min7[i];
    }
    N -= 7;
    while (N--) {
        cin >> min7[7];
        swap(min7[7], min7[max_element(min7, min7 + 8) - min7]);
    }
    sort(min7, min7 + 8);
    cout.precision(3);
    cout << fixed;
    for (int i = 0; i < 7; ++i) {
        cout << min7[i] << '\n';
    }
    return 0;
}
