#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int arr[10] = {0};
    string num;
    cin >> num;
    for (auto const &x : num) {
        ++arr[x - '0'];
    }
    arr[6] = (arr[6] + arr[9]) / 2 + (arr[6] + arr[9]) % 2;
    cout << *max_element(arr, arr + 9);
    return 0;
}
