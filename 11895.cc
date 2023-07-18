#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);

  int min_num = 1000000;
  int num_xor = 0;
  int sum = 0;
  while (n--) {
    int num;
    cin >> num;
    if (num < min_num) {
      min_num = num;
    }
    num_xor ^= num;
    sum += num;
  }

  cout << (num_xor != 0 ? 0 : sum - min_num);
  return 0;
}
