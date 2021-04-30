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

    static std::vector<std::tuple<int,int,int>> SortArray (std::vector<int> arr);

    static std::vector<int> GetSortedArray(std::vector<int> arr);

private:
    /**
    * sort the unsorted bars
    */
    static void Sort(std::vector<int>& arr, std::vector<int>& aux_arr, int start_index, int end_index
            , std::vector<std::tuple<int,int,int>>& animation);
    /**
     * Helper method to merge two sorted list
     */
    static void Merge(std::vector<int>& arr, const std::vector<int>& aux_arr, int start_index, int middle_index, int end_index
            , std::vector<std::tuple<int,int,int>>& animation);
    std::vector<int> array_;
};


#endif //FINAL_PROJECT_MERGESORT_H
} // namespace sortsimulator