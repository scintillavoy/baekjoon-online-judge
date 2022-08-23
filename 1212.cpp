#include <iostream>
#include <string>
using namespace std;

int main() {
    string in;
    cin >> in;
    char arr[8][4] = {"000", "001", "010", "011", "100", "101", "110", "111"};
    switch (in[0]) {
        case '0':
            if (in.size() == 1) {
                cout << "0";
            }
            break;
        case '1':
            cout << "1";
            break;
        case '2':
            cout << "10";
            break;
        case '3':
            cout << "11";
            break;
        default:
            cout << arr[in[0] - '0'];
            break;
    }
    for (auto it = in.cbegin() + 1; it != in.cend(); ++it) {
        cout << arr[*it - '0'];
    }
    return 0;
}
