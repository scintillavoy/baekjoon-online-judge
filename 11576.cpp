#include <iostream>
#include <vector>
using namespace std;

int main() {
    int A, B, m;
    cin >> A >> B >> m;

    int numA = 0;
    while (m--) {
        int num;
        cin >> num;
        numA *= A;
        numA += num;
    }

    vector<int> vec;
    while (numA > 0) {
        vec.push_back(numA % B);
        numA /= B;
    }

    for (auto it = vec.crbegin(); it != vec.crend(); ++it) {
        cout << *it << ' ';
    }
    return 0;
}
