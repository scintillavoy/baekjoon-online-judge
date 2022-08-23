#include <iostream>
#include <string>
using namespace std;

int main() {
    bool flag = false;
    for (int i = 0; i < 5; ++i) {
        string codeName;
        cin >> codeName;
        if (codeName.find("FBI") != string::npos) {
            cout << i + 1 << ' ';
            flag = true;
        }
    }
    if (!flag) {
        cout << "HE GOT AWAY!";
    }
    return 0;
}
