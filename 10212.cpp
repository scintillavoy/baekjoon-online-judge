#include <iostream>
#include <random>
using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 1);
    cout << (dis(gen) ? "Yonsei" : "Korea");
    return 0;
}
