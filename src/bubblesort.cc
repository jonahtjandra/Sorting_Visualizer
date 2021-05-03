//
// Created by Jonah on 01/05/21.
//

#include <vector>
#include "bubblesort.h"

namespace sortsimulator{

BubbleSort::BubbleSort() {

}

std::vector<std::tuple<int,int,int>> BubbleSort::SortArray(std::vector<int> arr) {
    std::vector<std::tuple<int,int,int>> animation;
    std::vector<int> array = arr;
    Sort(array, animation);
    return animation;
}

void BubbleSort::Swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

std::vector<int> BubbleSort::GetSortedArray(std::vector<int> arr) {
    std::vector<std::tuple<int,int,int>> animation;
    Sort(arr, animation);
    return arr;
}

void BubbleSort::Sort(std::vector<int>& arr, std::vector<std::tuple<int,int,int>>& animation) {
    for (int i = 0; i < arr.size()-1; i++) {
        for (int j = 0; j < arr.size()-1-i; j++) {
            //animation for comparing values
            animation.emplace_back(std::make_tuple(1,j, j+1));
            //color switch back to white
            animation.emplace_back(std::make_tuple(0,j, j+1));
            if (arr[j] > arr[j+1]) {
                //color swap
                animation.emplace_back(std::make_tuple(3,j, j+1));
                //animation for swapping values
                animation.emplace_back(std::make_tuple(2,j, j+1));
                //uncolor
                animation.emplace_back(std::make_tuple(0,j, j+1));
                Swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

} // namespace sortsimulator
