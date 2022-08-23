#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    int sum = 0;
    while (getline(cin, S, ',')) {
        sum += stoi(S);
    }
    cout << sum;
    return 0;
}
