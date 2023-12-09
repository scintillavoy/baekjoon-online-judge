#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  while (true) {
    int nx, ny;
    double w;
    cin >> nx >> ny >> w;
    if (nx == 0 && ny == 0 && w == 0.0) {
      break;
    }
    vector<double> xi(nx);
    for (int i = 0; i < nx; ++i) {
      cin >> xi[i];
    }
    sort(xi.begin(), xi.end());
    vector<double> yi(ny);
    for (int i = 0; i < ny; ++i) {
      cin >> yi[i];
    }
    sort(yi.begin(), yi.end());
    bool ok = true;
    double last = -w / 2;
    for (int i = 0; i < nx; ++i) {
      if (xi[i] - last > w) {
        ok = false;
        break;
      }
      last = xi[i];
    }
    if (75.0 - last > w / 2) {
      ok = false;
    }
    last = -w / 2;
    for (int i = 0; i < ny; ++i) {
      if (yi[i] - last > w) {
        ok = false;
        break;
      }
      last = yi[i];
    }
    if (100.0 - last > w / 2) {
      ok = false;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}
