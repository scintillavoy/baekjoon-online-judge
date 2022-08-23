#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string num;
        cin >> num;
        int cnt;
        for (cnt = 0; num != "6174"; ++cnt) {
            sort(num.begin(), num.end(), greater<char>());
            int maxNum = stoi(num);
            reverse(num.begin(), num.end());
            int minNum = stoi(num);
            num = to_string(maxNum - minNum);
            if (num.size() == 3) {
                num.push_back('0');
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
