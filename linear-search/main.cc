#include <algorithm>
#include <iostream>
#include "linear_search.h"

int main() {
  const std::vector<int> list = { 17, 20, 26, 31, 44, 54, 55, 65, 77, 93 };

  for (auto item : list) {
    carl::print_result(item, list);
  }

  std::cout << "---" << std::endl;

  {
    std::vector<int> list2 = list;
    std::transform(
      list.begin(), list.end(), list2.begin(), [&list](const int& x) {
        return x + list.back();
      }
    );

    for (auto item : list2) {
      carl::print_result(item, list);
    }
  }

  return 0;
}
