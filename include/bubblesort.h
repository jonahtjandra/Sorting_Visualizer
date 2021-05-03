//
// Created by Jonah on 01/05/21.
//

#ifndef FINAL_PROJECT_BUBBLESORT_H
#define FINAL_PROJECT_BUBBLESORT_H

namespace sortsimulator {
class BubbleSort {
    public:
        /**
         * default constructor
         */
        BubbleSort();

        /**
         * Entry point for sorting the array
         * @param arr the unsorted array
         * @return the sorted array
         */
        static std::vector<std::tuple<int,int,int>> SortArray(std::vector<int> arr);

        /**
         * the main sort method
         * @param arr the unsorted array
         * @param animation the animation sequence
         */
        static void Sort(std::vector<int>& arr, std::vector<std::tuple<int,int,int>>& animation);

        /**
         * Method for testing
         * @param arr the unsorted array
         * @return the sorted array
         */
        static std::vector<int> GetSortedArray(std::vector<int> arr);

    private:
        /**
        * private helper to swap to integers
        * @param a first integer
        * @param b second integer
        */
        static void Swap(int* a, int* b);


};
} // namespace sortsimulator



#endif //FINAL_PROJECT_BUBBLESORT_H
