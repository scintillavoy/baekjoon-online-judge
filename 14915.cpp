#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    if (m == 0) {
        cout << 0;
    } else {
        vector<char> vec;
        while (m > 0) {
            if (m % n < 10) {
                vec.push_back('0' + m % n);
            } else {
                vec.push_back('A' + m % n - 10);
            }
            m /= n;
        }
        
        for (auto it = vec.crbegin(); it != vec.crend(); ++it) {
            cout << *it;
        }
    }
    return 0;
}
