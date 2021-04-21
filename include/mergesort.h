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
    explicit MergeSort(std::vector<int> arr);

    /**
     * sort the unsorted bars
     */
    std::vector<int> Sort(std::vector<int> arr);
    /**
     * Helper method to merge two sorted list
     */
    std::vector<int> Merge(std::vector<int> arr_a, std::vector<int> arr_b);

    std::vector<int> GetArray();

private:

    std::vector<int> array_;
    std::vector<std::vector<int>> animation_;

};


#endif //FINAL_PROJECT_MERGESORT_H
