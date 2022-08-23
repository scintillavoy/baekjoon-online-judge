#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0, maxLv = 0;
    for (int i = 0; i < n; ++i) {
        int lv;
        cin >> lv;
        sum += lv;
        if (maxLv < lv) {
            maxLv = lv;
        }
    }
    cout << sum + maxLv * (n - 2);
    return 0;
}
