//
// Created by Jonah on 01/05/21.
//

#ifndef FINAL_PROJECT_BUBBLESORT_H
#define FINAL_PROJECT_BUBBLESORT_H

namespace sortsimulator {
class BubbleSort {
    public:
        BubbleSort();

        static std::vector<std::tuple<int,int,int>> SortArray(std::vector<int> arr);

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
