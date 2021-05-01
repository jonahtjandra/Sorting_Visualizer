//
// Created by Jonah on 01/05/21.
//

#include <vector>
#include "selectionsort.h"

namespace sortsimulator {

    SelectionSort::SelectionSort() {

    }

    std::vector<std::tuple<int,int,int>> SelectionSort::SortArray(std::vector<int> arr) {
        std::vector<std::tuple<int,int,int>> animation;
        for (int i = 0; i < arr.size()-1; i++) {
            int min = i;
            for (int j = i+1; j < arr.size(); j++) {
                //animation for comparing values
                animation.emplace_back(std::make_tuple(1,j, min));
                //color switch back to white
                animation.emplace_back(std::make_tuple(0,j, min));
                if (arr[j] < arr[min]) {
                    min = j;
                }
            }
            //color swap
            animation.emplace_back(std::make_tuple(1,i, min));
            animation.emplace_back(std::make_tuple(0,i, min));
            //animation for swapping values
            animation.emplace_back(std::make_tuple(2,i, min));
            Swap(&arr[i],&arr[min]);
        }
        return animation;

    }

    void SelectionSort::Swap(int* a, int* b) {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }

    std::vector<int> SelectionSort::GetSortedArray(std::vector<int> arr) {
        SortArray(arr);
        return arr;
    }
}