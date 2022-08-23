#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int main() {
    auto now = time(nullptr);
    cout << put_time(gmtime(&now), "%Y\n%m\n%d\n");
    return 0;
}
