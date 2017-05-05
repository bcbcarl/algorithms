#ifndef CARL_LINEAR_SEARCH_H
#define CARL_LINEAR_SEARCH_H

#include <iostream>
#include <iterator>
#include <vector>

namespace carl {
  typedef std::vector<int> Container;
  typedef Container::const_iterator InputIterator;

  bool linear_search(
    const InputIterator& first,
    const InputIterator& last,
    const int& item
  ) {
    if (first >= last) {
      return false;
    }

    if (*first == item) {
      return true;
    }

    return linear_search(std::next(first), last, item);
  }

  void print_result(const int& item, const std::vector<int>& list) {
    auto result = carl::linear_search(list.cbegin(), list.cend(), item)
      ? "True"
      : "False";
    std::cout << "result: " << result << std::endl;
  }
}

#endif // CARL_LINEAR_SEARCH_H
