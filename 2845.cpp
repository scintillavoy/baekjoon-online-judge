#include <iostream>
using namespace std;

int main() {
    int L, P, input;
    cin >> L >> P;
    int participant_num = L * P;
    for (int i = 0; i < 5; ++i) {
        cin >> input;
        cout << input - participant_num << ' ';
    }
    return 0;
}
