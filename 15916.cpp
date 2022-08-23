#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<unsigned long long> vec(n);
    for (auto &x : vec) {
        cin >> x;
    }
    unsigned long long k;
    cin >> k;

    if (vec[0] == k) {
        cout << "T";
        return 0;
    }
    bool prev = (vec[0] > k ? true : false), curr;
    for (int i = 1; i < vec.size(); ++i) {
        curr = vec[i] > k * (i + 1);
        if (prev != curr || vec[i] == k * (i + 1)) {
            cout << "T";
            return 0;
        }
        prev = curr;
    }
    cout << "F";
    return 0;
}
