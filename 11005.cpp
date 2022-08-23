#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, B;
    cin >> N >> B;

    vector<char> vec;
    while (N > 0) {
        if (N % B < 10) {
            vec.push_back('0' + N % B);
        } else {
            vec.push_back('A' + N % B - 10);
        }
        N /= B;
    }
    
    for (auto it = vec.crbegin(); it != vec.crend(); ++it) {
        cout << *it;
    }
    return 0;
}
