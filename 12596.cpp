#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int G;
        cin >> G;
        vector<int> code(G);
        for (auto &x : code) {
            cin >> x;
        }
        sort(code.begin(), code.end());
        cout << "Case #" << i << ": ";
        int j;
        for (j = 0; j+1 < code.size() && code[j] == code[j+1]; j += 2);
        cout << code[j] << '\n';
    }
    return 0;
}
