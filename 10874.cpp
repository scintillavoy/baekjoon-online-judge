#include <iostream>
#include <array>
using namespace std;

int main() {
    int N;
    cin >> N;
    array<int, 10> answer = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    for (int i = 0; i < N; ++i) {
        array<int, 10> arr;
        for (auto &x : arr) {
            cin >> x;
        }
        if (arr == answer) {
            cout << i + 1 << '\n';
        }
    }
    return 0;
}
