#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int sum = 1;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        sum += num - 1;
    }
    cout << sum;
    return 0;
}
