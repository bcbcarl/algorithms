#ifndef CARL_INSERTION_SORT_H
#define CARL_INSERTION_SORT_H

#include <iterator>
#include <vector>

namespace carl {
  typedef std::vector<int>::iterator RandomAccessIterator;

  class InsertionSort {
  public:
    InsertionSort(std::vector<int>* list) {
      if (list->size() <= 1) {
        return;
      }

      for (size_t i = 2; i <= list->size(); ++i) {
        insert(list->begin(), list->begin() + i);
      }
    }

  private:
    void insert(
      const RandomAccessIterator& first,
      const RandomAccessIterator& last
    ) {
      if (std::distance(first, last) <= 1) {
        return;
      }

      typedef std::reverse_iterator<RandomAccessIterator> ReverseIterator;
      const ReverseIterator rbegin(last);
      const ReverseIterator rend(first);
      const int target = *rbegin;

      if (target >= *std::next(rbegin)) {
        return;
      }

      ReverseIterator it;
      for (it = rbegin; it != rend; ++it) {
        if (target >= *std::next(it)) {
          break;
        }
        *it = *std::next(it);
      }
      *it = target;
    }
  };
}

#endif // CARL_INSERTION_SORT_H
