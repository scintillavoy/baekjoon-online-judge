#include <iostream>
using namespace std;

int main() {
    int arr[30] = {0};
    for (int i = 0; i < 28; ++i) {
        int num;
        cin >> num;
        ++arr[num - 1];
    }
    for (int i = 0; i < 30; ++i) {
        if (arr[i] == 0) {
            cout << i + 1 << '\n';
        }
    }
    return 0;
}
