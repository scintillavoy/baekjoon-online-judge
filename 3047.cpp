#include <iostream>
#include <cstdio>
#include <limits>
#include <algorithm>
using namespace std;

int main() {
    int arr[3];
    for (int i = 0; i < 3; ++i) {
        cin >> arr[i];
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    sort(arr, arr + 3);
    for (int i = 0; i < 3; ++i) {
        switch (getc(stdin)) {
            case 'A':
                cout << arr[0] << ' ';
                break;
            case 'B':
                cout << arr[1] << ' ';
                break;
            case 'C':
                cout << arr[2] << ' ';
                break;
        }
    }
    return 0;
}
