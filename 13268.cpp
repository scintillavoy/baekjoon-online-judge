#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    N %= 100;
    int loop = 1;
    while (N >= loop * 10) {
        N -= loop * 10;
        ++loop;
    }
    int answer = 0;
    while (N > 0 && answer < loop) {
        N -= 5;
        ++answer;
    }
    N -= 4;
    while (N > 0) {
        N -= 5;
        --answer;
    }
    cout << answer;
    return 0;
}
