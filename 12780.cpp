#include <iostream>
#include <string>
using namespace std;

int main() {
    string H, N;
    cin >> H >> N;
    int cnt = 0;
    for (int i = 0; (i = H.find(N, i)) != string::npos; ++cnt, ++i);
    cout << cnt;
    return 0;
}
