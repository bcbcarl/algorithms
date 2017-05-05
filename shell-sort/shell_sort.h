#ifndef CARL_SHELL_SORT_H
#define CARL_SHELL_SORT_H

#include <iostream>
#include <iterator>
#include <vector>
#include "../insertion-sort/insertion_sort.h"

namespace carl {
  typedef std::vector<int> Container;
  typedef Container::iterator InputIterator;

  void __gap_insertion_sort(
   const InputIterator& first,
   const InputIterator& last,
   const int& gap
  ) {
    if (gap < 1) {
      return;
    }

    insertion_sort(first, last, gap);
    __gap_insertion_sort(first, last, gap / 2);
  }

  void shell_sort(const InputIterator& first, const InputIterator& last) {
    if (first >= last) {
      return;
    }

    const int gap = std::distance(first, last) / 2;
    __gap_insertion_sort(first, last, gap);
  }
}

#endif // CARL_SHELL_SORT_H
