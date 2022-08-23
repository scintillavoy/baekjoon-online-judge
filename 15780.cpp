#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int capacity = 0;
    for (int i = 0; i < K; ++i) {
        int num;
        cin >> num;
        capacity += ceil((double) num / 2);
    }
    cout << (capacity >= N ? "YES" : "NO");
    return 0;
}
