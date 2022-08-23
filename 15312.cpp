#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int stroke[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2,
                      2, 1, 2, 2, 1, 2, 2, 2, 1, 2,
                      1, 1, 1, 2, 2, 1};
    string A, B;
    cin >> A >> B;
    vector<int> vec(A.size() * 2);
    for (int i = 0; i < vec.size(); i += 2) {
        vec[i] = stroke[A[i/2] - 'A'];
        vec[i+1] = stroke[B[i/2] - 'A'];
    }
    for (int i = 0; i < vec.size() - 2; ++i) {
        for (int j = 0; j < vec.size() - i - 1; ++j) {
            vec[j] = (vec[j] + vec[j+1]) % 10;
        }
    }
    cout << vec[0] << vec[1] << '\n';
    return 0;
}
