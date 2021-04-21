//
// Created by Jonah on 19/04/21.
//

#include <iostream>
#include "mergesort.h"

MergeSort::MergeSort(std::vector<int> arr) {
    array_ = arr;
    array_ = Sort(array_);
}

std::vector<int> MergeSort::Sort(std::vector<int> arr) {
    if (arr.size() <= 1) {
        return arr;
    }
    //splitting array into two
    int mid = arr.size()/2;
    std::vector<int> arr_a;
    std::vector<int> arr_b;
    for (int i = 0; i < mid; i++) {
        arr_a.push_back(arr[i]);
    }
    for (int i = mid; i < arr.size(); i++) {
        arr_b.push_back(arr[i]);
    }

    arr_a = Sort(arr_a);
    arr_b = Sort(arr_b);
    return Merge(arr_a,arr_b);
}

std::vector<int> MergeSort::Merge(std::vector<int> arr_a, std::vector<int> arr_b) {
    std::vector<int> merged_arr;
    //when both arrays are not empty
    while(arr_a.size() != 0 && arr_b.size() != 0) {
        //checking which array head is smaller
        if (arr_a[0] > arr_b[0]) {
            merged_arr.push_back(arr_b[0]);
            arr_b.erase(arr_b.cbegin());
        } else {
            merged_arr.push_back(arr_a[0]);
            arr_a.erase(arr_a.cbegin());
        }
    }
    //At this point one of the array is empty
    //emptying out arr_a to merged array
    while(arr_a.size() != 0) {
        merged_arr.push_back(arr_a[0]);
        arr_a.erase(arr_a.cbegin());
    }
    //emptying out arr_b to merged array
    while(arr_b.size() != 0) {
        merged_arr.push_back(arr_b[0]);
        arr_b.erase(arr_b.cbegin());
    }
    return merged_arr;
}

std::vector<int> MergeSort::GetArray() {
    return array_;
}

