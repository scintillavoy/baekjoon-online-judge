#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int arr[1000] = {0};
        int V;
        cin >> V;
        int maxNum = 0;
        for (int j = 0; j < V; ++j) {
            int S;
            cin >> S;
            ++arr[S - 1];
            if (arr[S - 1] > maxNum) {
                maxNum = arr[S - 1];
            }
        }
        for (int j = 0; j < 1000; ++j) {
            if (arr[j] == maxNum) {
                cout << j + 1 << '\n';
                break;
            }
        }
    }
    return 0;
}
