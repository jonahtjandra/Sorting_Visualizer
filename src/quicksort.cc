//
// Created by Jonah on 19/04/21.
//

#include "quicksort.h"
#include <iostream>
#include <math.h>

QuickSort::QuickSort(std::vector<int> arr) {
    //median of three method to find the first pivot value
    array_ = arr;
    MedianOfThree(array_);
    //Sort(arr, 0, arr.size());
}

void QuickSort::MedianOfThree(std::vector<int>& arr) {
    std::cout << "median";
    int middle = floor(arr.size()/2);
    int last = arr.size()-1;
    if (arr[0] > arr[middle]) {
        Swap(&arr[0], &arr[middle]);
    } else if (arr[middle] > arr[last]) {
        Swap(&arr[middle], &arr[last]);
        if (arr[0] > arr[middle]) {
            Swap(&arr[0], &arr[middle]);
        }
    }
}

void QuickSort::Partition(std::vector<int> arr, int start_index, int end_index) {

}

void QuickSort::Swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void QuickSort::Sort(std::vector<int> arr, int start_index, int end_index) {
}

std::vector<int> QuickSort::GetArray() {
    return array_;
}
