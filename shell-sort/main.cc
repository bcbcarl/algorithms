#include <iostream>
#include <vector>
#include "shell_sort.h"

int main() {
  std::vector<int> list = { 54, 26, 93, 17, 77, 31, 44, 55, 20 };

  std::cout << "Before: ";
  carl::print_result(list.begin(), list.end());

  std::cout << "After : ";
  carl::shell_sort(list.begin(), list.end());
  carl::print_result(list.begin(), list.end());

  return 0;
}
