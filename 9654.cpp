#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void print(const string &a, const string &b, const string &c, const string &d) {
    cout << left;
    cout << setw(15) << a << setw(15) << b;
    cout << setw(11) << c << setw(10) << d << '\n';
}

int main() {
    print("SHIP NAME", "CLASS", "DEPLOYMENT", "IN SERVICE");
    print("N2 Bomber", "Heavy Fighter", "Limited", "21");
    print("J-Type 327", "Light Combat", "Unlimited", "1");
    print("NX Cruiser", "Medium Fighter", "Limited", "18");
    print("N1 Starfighter", "Medium Fighter", "Unlimited", "25");
    print("Royal Cruiser", "Light Combat", "Limited", "4");
    return 0;
}
