#include <iostream>
#include <vector>
#include "bubbleSort.h"

void printResult(const std::vector<int>& list);

int main() {
  std::vector<int> list = { 54, 26, 93, 17, 77, 31, 44, 55, 20 };

  std::cout << "Before: ";
  printResult(list);

  std::cout << "After : ";
  carl::BubbleSort bs(&list);
  bs.sort();
  printResult(list);

  return 0;
}

void printResult(const std::vector<int>& list) {
  for (auto i : list) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}
