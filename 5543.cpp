#include <iostream>
using namespace std;

int main() {
    int hamburger = 2000, drink = 2000;
    for (int i = 0; i < 3; ++i) {
        int price;
        cin >> price;
        if (price < hamburger) {
            hamburger = price;
        }
    }
    for (int i = 0; i < 2; ++i) {
        int price;
        cin >> price;
        if (price < drink) {
            drink = price;
        }
    }
    cout << hamburger + drink - 50;
    return 0;    
}
