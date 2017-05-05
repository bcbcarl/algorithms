#include <iostream>
#include <algorithm>
#include "binarySearch.h"

void printResult(const int& item, const std::vector<int>& list);

int main() {
  const std::vector<int> list = { 17, 20, 26, 31, 44, 54, 55, 65, 77, 93 };

  for (auto item : list) {
    printResult(item, list);
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
      printResult(item, list);
    }
  }

  return 0;
}

void printResult(const int& item, const std::vector<int>& list) {
  carl::BinarySearch bs;
  auto result = bs.found(list, item) ? "True" : "False";
  std::cout << "result: " << result << std::endl;
}
