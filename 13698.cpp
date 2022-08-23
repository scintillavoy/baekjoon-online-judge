#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int arr[4] = {1, 0, 0, 2};
    string order;
    cin >> order;
    for (auto const &x : order) {
        switch (x) {
            case 'A':
                swap(arr[0], arr[1]);
                break;
            case 'B':
                swap(arr[0], arr[2]);
                break;
            case 'C':
                swap(arr[0], arr[3]);
                break;
            case 'D':
                swap(arr[1], arr[2]);
                break;
            case 'E':
                swap(arr[1], arr[3]);
                break;
            case 'F':
                swap(arr[2], arr[3]);
                break;
        }
    }
    cout << find(arr, arr + 4, 1) - arr + 1 << '\n';
    cout << find(arr, arr + 4, 2) - arr + 1;
    return 0;
}
