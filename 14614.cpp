#include <iostream>
#include <string>
using namespace std;

int main() {
    int A, B;
    string C;
    cin >> A >> B >> C;
    cout << ((C.back()-'0') % 2 ? A ^ B : A) << '\n';
    return 0;
}
