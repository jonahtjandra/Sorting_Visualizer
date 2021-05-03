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

    static std::vector<std::tuple<int,int,int>> SortArray(std::vector<int> arr);

    static std::vector<int> GetSortedArray(std::vector<int> arr);


private:

    /**
     * Actual sorting algorithm
     */
    //first is for indicating whether a swap(2) or color(1) or uncolor(0). Second and third are for indexes being compared.
    static void Sort(std::vector<int>& arr, int start_index, int end_index
                                                     , std::vector<std::tuple<int,int,int>>& animation);

    /**
     * to partition
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
