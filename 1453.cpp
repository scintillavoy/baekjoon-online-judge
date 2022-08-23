#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int arr[100] = {0};
    int rejected = 0;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        if (arr[num - 1] == 0) {
            ++arr[num - 1];
        } else {
            ++rejected;
        }
    }
    cout << rejected;
    return 0;
}
