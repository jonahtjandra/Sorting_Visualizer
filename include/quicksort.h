//
// Created by Jonah on 19/04/21.
//

#ifndef FINAL_PROJECT_QUICKSORT_H
#define FINAL_PROJECT_QUICKSORT_H
#include <vector>


class QuickSort {
public:
    /**
     * constructor for the MergeSort class
     */
    explicit QuickSort(std::vector<int> arr);

    std::vector<int> GetArray();


private:
    /**
     * Helper method to find the pivot using median of three
     */
    void MedianOfThree(std::vector<int>& arr);
    /**
     * Actual sorting algorithm
     */
    void Sort(std::vector<int> arr, int start_index, int end_index);

    /**
     * to partition
     */
    void Partition(std::vector<int> arr, int start_index, int end_index);
    /**
     * private helper to swap to integers
     * @param a first integer
     * @param b second integer
     */
    void Swap(int* a, int* b);
    //index of the first looping pointer
    //int first_pointer_;
    //index of the second looping pointer
    //int second_pointer_;
    std::vector<int> array_;
    //std::vector<std::vector<std::vector<int>>> animation_;
};


#endif //FINAL_PROJECT_QUICKSORT_H
