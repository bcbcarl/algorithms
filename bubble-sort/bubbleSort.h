#ifndef CARL_BUBBLE_SORT_H
#define CARL_BUBBLE_SORT_H

#include <vector>
#include <utility>

namespace carl {
  class BubbleSort {
  public:
    BubbleSort(std::vector<int>* list) {
      list_ = list;
    }
    void sort() {
      bubbleSort(list_->size());
    }
  private:
    void bubbleSort(const size_t& size) {
      if (size <= 1) {
        return;
      }

      for (size_t i = 0; i < size - 1; ++i) {
        if (list_->at(i) > list_->at(i + 1)) {
          std::swap(list_->at(i), list_->at(i + 1));
        }
      }

      bubbleSort(size - 1);
    }
    std::vector<int>* list_;
  };
}

#endif // CARL_BUBBLE_SORT_H
