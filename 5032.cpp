#include <iostream>
using namespace std;

int main() {
    int e, f, c;
    cin >> e >> f >> c;
    int bin = e + f, answer = 0;
    while (bin >= c) {
        answer += bin / c;
        bin = bin / c + bin % c;
    }
    cout << answer;
    return 0;
}
