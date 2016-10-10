// 2016-10-10 
// waizungtaam@gmail.com

// Note: This is a exhaustive solution to the Eight Queen Problem
//       which has bad performance.

#include <cstddef>
#include <algorithm>
#include <iostream>
#include <vector>

void solve(std::size_t n) {
  std::vector<std::size_t> cols(n), diag_1(n), diag_2(n);
  std::iota(cols.begin(), cols.end(), 0);
  std::size_t num_solutions = 0;
  do {
    for (std::size_t i = 0; i < n; ++i) {
      diag_1[i] = cols[i] + i;
      diag_2[i] = cols[i] - i;
    }
    std::sort(diag_1.begin(), diag_1.end());
    std::sort(diag_2.begin(), diag_2.end());
    auto last_1 = std::unique(diag_1.begin(), diag_1.end());
    auto last_2 = std::unique(diag_2.begin(), diag_2.end());
    if (last_1 - diag_1.begin() == n && last_2 - diag_2.begin() == n) {
      ++num_solutions;
      std::cout << num_solutions << "\t[ ";
      for (const auto& x : cols) {
        std::cout << x << ' ';
      }
      std::cout << "]\n";
    }
  } while (std::next_permutation(cols.begin(), cols.end()));
}

int main() {
  solve(9);
}