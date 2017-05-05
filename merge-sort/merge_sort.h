#ifndef CARL_MERGE_SORT_H
#define CARL_MERGE_SORT_H

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

namespace carl {
  typedef std::vector<int> Container;
  typedef Container::iterator InputIterator;
  typedef InputIterator OutputIterator;

  void merge(
    const InputIterator& first1,
    const InputIterator& last1,
    const InputIterator& first2,
    const InputIterator& last2,
    const OutputIterator& result
  ) {
    Container list(std::distance(first1, last1) + std::distance(first2, last2));
    std::merge(first1, last1, first2, last2, list.begin());
    std::copy(list.cbegin(), list.cend(), result);
  }

  void merge_sort(const InputIterator& first, const InputIterator& last) {
    if (std::next(first) >= last) {
      return;
    }

    const int size = std::distance(first, last);
    const InputIterator middle = first + (size / 2);

    merge_sort(first, middle);
    merge_sort(middle, last);
    merge(first, middle, middle, last, first);
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

#endif // CARL_MERGE_SORT_H
