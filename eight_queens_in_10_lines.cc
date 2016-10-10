#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  std::vector<int> c = {0, 1, 2, 3, 4, 5, 6, 7}, d1(8), d2(8);
  do {
    for (int i = 0; i < 8; d1[i] = c[i] + i, d2[i] = c[i] - i, ++i, std::sort(d1.begin(), d1.begin() + i), std::sort(d2.begin(), d2.begin() + i)) {}
    if (std::unique(d1.begin(), d1.end()) - d1.begin() == 8 && std::unique(d2.begin(), d2.end()) - d2.begin() == 8) std::cout << c[0] << c[1] << c[2] << c[3] << c[4] << c[5] << c[6] << c[7] << '\n';
  } while (std::next_permutation(c.begin(), c.end()));
}