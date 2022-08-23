#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        string N;
        cin >> N;
        string N_rev = N;
        reverse(N_rev.begin(), N_rev.end());
        string sum = to_string(stoi(N) + stoi(N_rev));
        bool isPalindrome = true;
        for (int i = 0; i < sum.size() / 2; ++i) {
            if (sum[i] != sum[sum.size() - 1 - i]) {
                isPalindrome = false;
                break;
            }
        }
        cout << (isPalindrome ? "YES" : "NO") << '\n';
    }
    return 0;
}
