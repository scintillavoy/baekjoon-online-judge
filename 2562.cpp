#include <iostream>
using namespace std;

int main() {
    int max_num = 0, max_pos = 0;
    for (int i = 1; i <= 9; ++i) {
        int num;
        cin >> num;
        if (num > max_num) {
            max_num = num;
            max_pos = i;
        }
    }
    cout << max_num << '\n' << max_pos;
    return 0;
}
