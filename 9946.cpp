#include <iostream>
#include <string>
using namespace std;

int main() {
    string A, B;
    for (int i = 1; cin >> A >> B; ++i) {
        if (A == "END" && B == "END") {
            break;
        }
        int arr[26] = {0};
        for (auto const &x : A) {
            ++arr[x - 'a'];
        }
        for (auto const &x : B) {
            --arr[x - 'a'];
        }
        bool check = true;
        for (auto const &x : arr) {
            if (x != 0) {
                check = false;
                break;
            }
        }
        cout << "Case " << i << ": " << (check ? "same" : "different") << '\n';
    }
    return 0;
}
