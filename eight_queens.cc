// 2016-10-10 
// waizungtaam@gmail.com

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> c = {0, 1, 2, 3, 4, 5, 6, 7}, d1(8), d2(8);
  do {
    for (int i = 0; i < 8; ++i) {
      d1[i] = c[i] + i;
      d2[i] = c[i] - i;
    }
    std::sort(d1.begin(), d1.end());
    std::sort(d2.begin(), d2.end());
    auto last_1 = std::unique(d1.begin(), d1.end());
    auto last_2 = std::unique(d2.begin(), d2.end());
    if (last_1 - d1.begin() == 8 && last_2 - d2.begin() == 8) {
      for (const auto& x : c) {
        std::cout << x;
      }
      std::cout << '\n';
    }
  } while (std::next_permutation(c.begin(), c.end()));
}