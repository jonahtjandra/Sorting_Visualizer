//
// Created by Jonah on 19/04/21.
//

#ifndef FINAL_PROJECT_MERGESORT_H
#define FINAL_PROJECT_MERGESORT_H
#include <vector>

namespace sortsimulator {

class MergeSort {
public:
    /**
     * constructor for the MergeSort class
     */
    explicit MergeSort(std::vector<int> arr);

    /**
     * sort the unsorted bars
     */
    void Sort(std::vector<int>& arr, std::vector<int>& aux_arr, int start_index, int end_index);
    /**
     * Helper method to merge two sorted list
     */
    void Merge(std::vector<int>& arr, const std::vector<int>& aux_arr, int start_index, int middle_index, int end_index);

    std::vector<int> GetArray();

private:
    std::vector<int> array_;
    std::vector<std::vector<int>> animation_;

};


#endif //FINAL_PROJECT_MERGESORT_H
} // namespace sortsimulator