#include <chrono>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  auto now = chrono::system_clock::now();
  auto now_c = chrono::system_clock::to_time_t(now);
  cout << put_time(gmtime(&now_c), "%Y\n%m\n%d\n");
  return 0;
}
