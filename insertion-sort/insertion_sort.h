#ifndef CARL_INSERTION_SORT_H
#define CARL_INSERTION_SORT_H

#include <iostream>
#include <iterator>
#include <vector>

namespace carl {
  typedef std::vector<int> Container;
  typedef Container::iterator InputIterator;

  void __insert(
    const InputIterator& first,
    const InputIterator& last,
    const int& gap
  ) {
    if (std::next(first, gap) >= last) {
      return;
    }

    auto temp_it = std::prev(last);
    auto prev_it = std::prev(temp_it, gap);

    const int temp = *temp_it;
    while (first <= prev_it) {
      const int prev = *prev_it;
      if (prev <= temp) {
        break;
      }
      *temp_it = prev;
      std::advance(temp_it, -gap);
      std::advance(prev_it, -gap);
    }
    *temp_it = temp;
  }

  void __insertion_sort(
    const InputIterator& first,
    const InputIterator& last,
    const int& gap
  ) {
    auto it = std::next(first, gap + 1);
    while (it <= last) {
      __insert(first, it, gap);
      std::advance(it, gap);
    }
  }

  void insertion_sort(
    const InputIterator& first,
    const InputIterator& last,
    const int& gap = 1
  ) {
    for (int i = 0; i < gap; ++i) {
      __insertion_sort(std::next(first, i), last, gap);
    }
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

#endif // CARL_INSERTION_SORT_H
