//
// Created by Jonah on 19/04/21.
//

#include "quicksort.h"
#include <iostream>
#include <math.h>

namespace sortsimulator{

QuickSort::QuickSort() = default;

void QuickSort::MergeSort(std::vector<int> &arr) {
    //median of three method to find the first pivot value
    /*MedianOfThree(arr,0,arr.size()-1);*/
    array_ = arr;
    Sort(array_, 0, arr.size() - 1);
}


/*void QuickSort::MedianOfThree(std::vector<int>& arr, int start_index, int end_index) {
    int middle = floor(arr.size()/2);
    if (arr[0] > arr[middle]) {
        Swap(&arr[0], &arr[middle]);
    } else if (arr[middle] > arr[end_index]) {
        Swap(&arr[middle], &arr[end_index]);
        if (arr[0] > arr[middle]) {
            Swap(&arr[0], &arr[middle]);
        }
    }
    //Puts the median value in the last order, ready for partition algorithm
    Swap(&arr[middle], &arr[end_index]);
}*/

void QuickSort::Sort(std::vector<int>& arr, int start_index, int end_index) {
    if (start_index < end_index) {
        int partitioning_index = Partition(arr, start_index, end_index);
        //partition index is already at the correct index, so sort array after and before partition
        Sort(arr, start_index, partitioning_index - 1);
        Sort(arr, partitioning_index + 1, end_index);
    }
}

int QuickSort::Partition(std::vector<int>& arr, int start_index, int end_index) {
    int pivot = arr[end_index];
    //swap pivot with the last element
    //Swap(&arr[end_index],&arr[floor(arr.size()/2)]);
    //keeping in track of the right side sub-array of the original index taken from the pivot
    //the right sub-array will start at the end - 1 index because the last index is the pivot
    int left_wall = start_index - 1;
    for (int i = start_index; i <= end_index - 1; i++) {
        //animation for comparing values
        animation_.emplace_back(std::make_tuple(1,i, pivot));
        //color switch back to white
        animation_.emplace_back(std::make_tuple(0,i, i));
        if (arr[i] < pivot) {
            left_wall++;
            //color swap
            animation_.emplace_back(std::make_tuple(1,i, left_wall));
            animation_.emplace_back(std::make_tuple(0,i, left_wall));
            //animation for swapping values
            animation_.emplace_back(std::make_tuple(2,i, left_wall));
            Swap(&arr[i], &arr[left_wall]);
        } else {
            //to notify that no swapping occurred, we still need to push to signal
            animation_.emplace_back(std::make_tuple(2,0,0));
        }
    }
    //uncolor pivot
    animation_.emplace_back(std::make_tuple(0,pivot, pivot));
    //swap pivot and left wall + 1 because we want pivot between two smaller and larger array of numbers
    animation_.emplace_back(std::make_tuple(2,left_wall+1,end_index));
    Swap(&arr[left_wall+1], &arr[end_index]);
    return left_wall + 1;
}

void QuickSort::Swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

std::vector<int> QuickSort::GetArray() {
    return array_;
}

std::vector<std::tuple<int,int, int>> QuickSort::GetAnimations() {
    return animation_;
}

} // namespace sortsimulator
