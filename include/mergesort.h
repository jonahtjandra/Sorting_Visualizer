//
// Created by Jonah on 19/04/21.
//

#ifndef FINAL_PROJECT_MERGESORT_H
#define FINAL_PROJECT_MERGESORT_H
#include <vector>

class MergeSort {
public:
    /**
     * constructor for the MergeSort class
     */
    explicit MergeSort(std::vector<int> bars);

    /**
     * sort the unsorted bars
     */
    void Sort(std::vector<int>& arr);

    /**
     * Merge two sorted list
     */
    void Merge(std::vector<int>& arr_a, std::vector<int>& arr_b);

private:
    std::vector<int> bars_;
    std::vector<std::vector<int>> animation_;

};


#endif //FINAL_PROJECT_MERGESORT_H
