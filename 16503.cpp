#include <iostream>
#include <algorithm>
using namespace std;

int cal(int num1, char op, int num2) {
    switch (op) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num1 / num2;
    }
}

int main() {
    int K[3], result[2];
    char O[2];
    cin >> K[0] >> O[0] >> K[1] >> O[1] >> K[2];
    result[0] = cal(cal(K[0], O[0], K[1]), O[1], K[2]);
    result[1] = cal(K[0], O[0], cal(K[1], O[1], K[2]));
    sort(result, result + 2);
    for (auto const &x : result) {
        cout << x << '\n';
    }
    return 0;
}
