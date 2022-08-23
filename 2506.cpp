#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int sum = 0, curr = 0;
    for (int i = 0; i < N; ++i) {
        int check;
        cin >> check;
        if (check) {
            sum += ++curr;
        } else {
            curr = 0;
        }
    }
    cout << sum;
    return 0;
}
