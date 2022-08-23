#include <iostream>
using namespace std;

int main() {
    int S1, S2;
    cin >> S1 >> S2;
    bool sampleTest = true, systemTest = true;
    while (S1--) {
        int a, b;
        cin >> a >> b;
        if (a != b) {
            sampleTest = false;
        }
    }
    while (S2--) {
        int a, b;
        cin >> a >> b;
        if (a != b) {
            systemTest = false;
        }
    }
    if (sampleTest) {
        if (systemTest) {
            cout << "Accepted";
        } else {
            cout << "Why Wrong!!!";
        }
    } else {
        cout << "Wrong Answer";
    }
    return 0;
}
