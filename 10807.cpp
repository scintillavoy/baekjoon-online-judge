#include <iostream>
using namespace std;

int main() {
    int arr[201] = {0, };
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        ++arr[num + 100];
    }
    int v;
    cin >> v;
    cout << arr[v + 100];
    return 0;
}
