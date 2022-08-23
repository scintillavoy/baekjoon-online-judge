#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    int score = 0;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        score += abs(num);
    }
    cout << score * 2;
    return 0;
}
