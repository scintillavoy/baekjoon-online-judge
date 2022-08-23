#include <iostream>
#include <string>
using namespace std;

int main() {
    while (true) {
        string num;
        cin >> num;
        if (num == "0") {
            break;
        }
        int sum;
        do {
            sum = 0;
            do {
                sum += num.back() - '0';
                num.pop_back();
            } while (!num.empty());
            num = to_string(sum);
        } while (num.size() > 1);
        cout << sum << '\n';
    }
    return 0;
}
