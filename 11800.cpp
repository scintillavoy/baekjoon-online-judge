#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main() {
    string singleName[6] = {"Yakk", "Doh", "Seh", "Ghar", "Bang", "Sheesh"};
    string pairName[6] = {"Habb Yakk", "Dobara", "Dousa",
                            "Dorgy", "Dabash", "Dosh"};
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int a, b;
        cin >> a >> b;
        cout << "Case " << i << ": ";
        if (a < b) {
            swap(a, b);
        }
        if (a == b) {
            cout << pairName[a-1];
        } else if (a == 6 && b == 5) {
            cout << "Sheesh Beesh";
        } else {
            cout << singleName[a-1] << ' ' << singleName[b-1];
        }
        cout << '\n';
    }
    return 0;
}
