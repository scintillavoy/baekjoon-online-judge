#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == -1) {
            break;
        }
        int sum = 1;
        vector<int> vec1, vec2;
        for (int i = 2; i <= int(sqrt(n)); ++i) {
            if (n % i == 0) {
                sum += i + n / i;
                vec1.push_back(i);
                vec2.push_back(n / i);
            }
        }
        if (int(sqrt(n)) * int(sqrt(n)) == n) {
            sum -= int(sqrt(n));
            vec2.pop_back();
        }

        cout << n << ' ';
        if (sum == n) {
            cout << "= 1";
            for (auto it = vec1.cbegin(); it != vec1.cend(); ++it) {
                cout << " + " << *it;
            }
            for (auto it = vec2.crbegin(); it != vec2.crend(); ++it) {
                cout << " + " << *it;
            }
        } else {
            cout << "is NOT perfect.";
        }
        cout << '\n';
    }
    return 0;
}
