#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> vec(10, -1);
    int cnt = 0;
    while (N--) {
        int num, loc;
        cin >> num >> loc;
        if (vec[num - 1] != loc) {
            if (vec[num - 1] != -1) {
                ++cnt;
            }
            vec[num - 1] = loc;
        }
    }
    cout << cnt;
    return 0;
}
