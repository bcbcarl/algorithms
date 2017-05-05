#ifndef CARL_BUBBLE_SORT_H
#define CARL_BUBBLE_SORT_H

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

namespace carl {
  typedef std::vector<int> Container;
  typedef Container::iterator InputIterator;

  void bubble_sort(const InputIterator& first, const InputIterator& last) {
    if (first >= last) {
      return;
    }

    auto it = first;
    while (it < std::prev(last)) {
      if (*std::next(it) < *it) {
        std::iter_swap(it, std::next(it));
      }
      std::advance(it, 1);
    }

    bubble_sort(first, std::prev(last));
  }

  void print_result(const InputIterator& first, const InputIterator& last) {
    auto it = first;
    while (it < last) {
      std::cout << *it << " ";
      std::advance(it, 1);
    }
    std::cout << std::endl;
  }
}

#endif // CARL_BUBBLE_SORT_H
