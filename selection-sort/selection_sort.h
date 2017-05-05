#ifndef CARL_SELECTION_SORT_H
#define CARL_SELECTION_SORT_H

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

namespace carl {
  typedef std::vector<int> Container;
  typedef Container::iterator InputIterator;

  void selection_sort(const InputIterator& first, const InputIterator& last) {
    if (first >= last) {
      return;
    }

    auto max_it = first;
    auto it = std::next(first);
    while (it < last) {
      if (*max_it < *it) {
        max_it = it;
      }
      std::advance(it, 1);
    }

    if (max_it != std::prev(last)) {
      std::iter_swap(max_it, std::prev(last));
    }

    selection_sort(first, std::prev(last));
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

#endif // CARL_SELECTION_SORT_H
