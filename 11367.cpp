#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string name;
        int grade;
        cin >> name >> grade;
        cout << name << ' ';
        if (grade >= 90) {
            cout << 'A';
        } else if (grade >= 80) {
            cout << 'B';
        } else if (grade >= 70) {
            cout << 'C';
        } else if (grade >= 60) {
            cout << 'D';
        } else {
            cout << 'F';
        }
        if (grade >= 60 && (grade % 10 >= 7 || grade == 100)) {
            cout << '+';
        }
        cout << '\n';
    }
    return 0;
}
