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
    QuickSort();

    /**
     * entry point for the sorting algorithm
     * @param arr the array of integers
     * @return the animation sequence
     */
    static std::vector<std::tuple<int,int,int>> SortArray(std::vector<int> arr);

    static std::vector<int> GetSortedArray(std::vector<int> arr);


private:

    /**
     * The main sorting algorithm. This is where the divide and conquer happens through recursion
     * @param arr the array to be sorted
     * @param start_index the start index of array
     * @param end_index the end index of array
     * @param animation the animation sequence
     */
    //first is for indicating whether a swap(2) or color(1) or uncolor(0). Second and third are for indexes being compared.
    static void Sort(std::vector<int>& arr, int start_index, int end_index
                                                     , std::vector<std::tuple<int,int,int>>& animation);

    /**
     * The partition method used to establish a pivot for partition and sort the sub arrays accordingly
     * @param arr the array to be sorted
     * @param start_index the start index of said array
     * @param end_index the end index of said array
     * @param animation the animation sequence
     * @return a partition index used for the divide and conquer
     */
    static int Partition(std::vector<int>& arr, int start_index, int end_index, std::vector<std::tuple<int,int,int>>& animation);

    /**
     * private helper to swap to integers
     * @param a first integer
     * @param b second integer
     */
    static void Swap(int* a, int* b);
};

} // namespace sortsimulator

#endif //FINAL_PROJECT_QUICKSORT_H
