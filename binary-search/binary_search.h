#ifndef CARL_BINARY_SEARCH_H
#define CARL_BINARY_SEARCH_H

#include <iostream>
#include <iterator>
#include <vector>

namespace carl {
  typedef std::vector<int> Container;
  typedef Container::const_iterator InputIterator;

  bool binary_search(
    const InputIterator& first,
    const InputIterator& last,
    const int& item
  ) {
    if (first >= last) {
      return false;
    }

    const int size = std::distance(first, last);
    const InputIterator middle = first + (size / 2);
    const int current = *middle;

    if (current == item) {
      return true;
    }

    InputIterator newFirst;
    InputIterator newLast;

    if (current > item) {
      newFirst = first;
      newLast = middle;
    } else {
      newFirst = std::next(middle);
      newLast = last;
    }

    return binary_search(newFirst, newLast, item);
  }

  void print_result(const int& item, const std::vector<int>& list) {
    auto result = carl::binary_search(list.cbegin(), list.cend(), item)
      ? "True"
      : "False";
    std::cout << "result: " << result << std::endl;
  }
}

#endif // CARL_BINARY_SEARCH_H
