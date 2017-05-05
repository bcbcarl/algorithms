#ifndef CARL_BINARY_SEARCH_H
#define CARL_BINARY_SEARCH_H

#include <iterator>
#include <vector>

namespace carl {
  class BinarySearch {
  public:
    bool found(const std::vector<int>& list, const int& item) const noexcept {
      return search(list.cbegin(), list.cend(), item);
    }
  private:
    bool search(
      const std::vector<int>::const_iterator& first,
      const std::vector<int>::const_iterator& last,
      const int& item
    ) const noexcept {
      int size = std::distance(first, last);

      if (size == 1) {
        return (*first == item);
      }

      if (size <= 0) {
        return false;
      }

      const std::vector<int>::const_iterator middle = first + size / 2;
      const int current = *middle;

      if (current == item) {
        return true;
      }

      std::vector<int>::const_iterator newFirst;
      std::vector<int>::const_iterator newLast;

      if (current > item) {
        newFirst = first;
        newLast = middle;
      } else {
        newFirst = middle + 1;
        newLast = last;
      }

      return search(newFirst, newLast, item);
    }
  };
}

#endif // CARL_BINARY_SEARCH_H
