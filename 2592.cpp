#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int sum = 0;
    int count[99] = {0};
    for (int i = 0; i < 10; ++i) {
        int num;
        cin >> num;
        sum += num;
        ++count[num / 10 - 1];
    }
    cout << sum / 10 << '\n';
    cout << (max_element(count, count + 99) - count + 1) * 10;
    return 0;
}
