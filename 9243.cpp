#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < a.size(); ++i) {
        if ((N % 2 == 0 && a[i] != b[i]) || (N % 2 == 1 && a[i] == b[i])) {
            cout << "Deletion failed";
            return 0;
        }
    }
    cout << "Deletion succeeded";
    return 0;
}
