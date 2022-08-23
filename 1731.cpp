#include <iostream>
using namespace std;

int main() {
    int N, arr[3], last;
    cin >> N;
    for (int i = 0; i < 3; ++i) {
        cin >> arr[i];
    }
    last = arr[2];
    for (int i = 3; i < N; ++i) {
        cin >> last;
    }
    if (arr[1] - arr[0] == arr[2] - arr[1]) {
        cout << last - arr[0] + arr[1];
    } else if (arr[1] / arr[0] == arr[2] / arr[1]) {
        cout << last / arr[0] * arr[1];
    }
    return 0;
}
