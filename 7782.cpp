#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int b1, b2;
    cin >> b1 >> b2;
    bool check = false;
    while (n--) {
        int lx, ly, hx, hy;
        cin >> lx >> ly >> hx >> hy;
        if (lx <= b1 && ly <= b2 && hx >= b1 && hy >= b2) {
            check = true;
        }
    }
    cout << (check ? "Yes" : "No");
    return 0;
}
