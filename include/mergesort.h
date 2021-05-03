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
    explicit MergeSort();

    /**
     * Entry point for sorting the array
     * @param arr the array to be sorted
     * @return an vector of tuple with three elements representing the animation
     */
    static std::vector<std::tuple<int,int,int>> SortArray (std::vector<int> arr);

    /**
     * Method use for testing
     * @param arr the unsorted array
     * @return the sorted array
     */
    static std::vector<int> GetSortedArray(std::vector<int> arr);

private:
    /**
     * main sorting method for sorting the unsorted bars
     * divide and conquer occurs here recursively
     * @param arr the unsorted array
     * @param aux_arr auxiliary array used for sorting the array in place in the original array
     * @param start_index start index of the array
     * @param end_index end index of the array
     * @param animation vector of tuples representing the animation sequence
     */
    static void Sort(std::vector<int>& arr, std::vector<int>& aux_arr, int start_index, int end_index
            , std::vector<std::tuple<int,int,int>>& animation);
    /**
     * Helper method to merge two list
     * @param arr the array with both sub-lists
     * @param aux_arr the auxiliary array to merge list in place
     * @param start_index the start index of the first array
     * @param middle_index the start index of the second array hence the end index of first array
     * @param end_index the end index of the second array
     * @param animation vector of tuples representing the animation sequence
     */
    static void Merge(std::vector<int>& arr, const std::vector<int>& aux_arr, int start_index, int middle_index, int end_index
            , std::vector<std::tuple<int,int,int>>& animation);
};


#endif //FINAL_PROJECT_MERGESORT_H
} // namespace sortsimulator