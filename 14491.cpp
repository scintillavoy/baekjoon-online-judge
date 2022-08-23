#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    vector<int> vec;
    while (T > 0) {
        vec.push_back(T % 9);
        T /= 9;
    }

    for (auto it = vec.crbegin(); it != vec.crend(); ++it) {
        cout << *it;
    }
    return 0;
}
