#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cin >> input;
    int time = 0;
    int arr[26] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, \
                   9, 9, 9, 10, 10, 10, 10};
    for (auto const &x : input) {
        time += arr[x - 'A'];
    }
    cout << time;
    return 0;
}
