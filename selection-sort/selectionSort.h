#ifndef CARL_SELECTION_SORT_H
#define CARL_SELECTION_SORT_H

#include <vector>
#include <utility>

namespace carl {
  class SelectionSort {
  public:
    SelectionSort(std::vector<int>* list) {
      list_ = list;
    }
    void sort() {
      selectionSort(list_->size());
    }
  private:
    void selectionSort(const size_t& size) {
      if (size <= 1) {
        return;
      }

      int max_index = 0;
      for (size_t i = 1; i < size; ++i) {
        if (list_->at(i) > list_->at(max_index)) {
          max_index = i;
        }
      }

      const int last_index = (int)size - 1;
      if (max_index != last_index) {
        std::swap(list_->at(max_index), list_->at(last_index));
      }

      selectionSort(size - 1);
    }
    std::vector<int>* list_;
  };
}

#endif // CARL_SELECTION_SORT_H
