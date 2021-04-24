//
// Created by Jonah on 19/04/21.
//

#ifndef FINAL_PROJECT_QUICKSORT_H
#define FINAL_PROJECT_QUICKSORT_H
#include <vector>

namespace sortsimulator{
class QuickSort {
public:
    /**
     * constructor for the MergeSort class
     */
    QuickSort(std::vector<int>& arr);

    std::vector<int> GetArray();

    std::vector<int[2]> GetAnimations();


private:
    /**
     * Helper method to find the pivot using median of three
     */
    void MedianOfThree(std::vector<int>& arr, int start_index, int end_index);

    /**
     * Actual sorting algorithm
     */
    void Sort(std::vector<int>& arr, int start_index, int end_index);

    /**
     * to partition
     */
    int Partition(std::vector<int>& arr, int start_index, int end_index);

    /**
     * private helper to swap to integers
     * @param a first integer
     * @param b second integer
     */
    void Swap(int* a, int* b);
    std::vector<int> array_;
    //optimize to be two arrays with comparisons and swaps
    //so we don't need to loop through the entire array each step of the animation
    std::vector<int[2]> animation_;
};

} // namespace sortsimulator

#endif //FINAL_PROJECT_QUICKSORT_H
