//
// Created by Jonah on 19/04/21.
//

#include <iostream>
#include "mergesort.h"
#include <cmath>

MergeSort::MergeSort(std::vector<int> arr) {
    array_ = arr;
    Sort(array_, arr, 0, arr.size() - 1);
}

void MergeSort::Sort(std::vector<int>& arr, std::vector<int>& aux_arr, int start_index, int end_index) {
    if (end_index == start_index) {
        return;
    }
    //splitting array into two
    int mid = floor((start_index + end_index)/2);
    Sort(aux_arr,arr, start_index, mid);
    Sort(aux_arr,arr, mid+1, end_index);
    Merge(arr,aux_arr, start_index, mid, end_index);
}

void MergeSort::Merge(std::vector<int>& arr, const std::vector<int>& aux_arr, int start_index, int middle_index, int end_index) {
    //pointer in the original array
    int i = start_index;
    //pointer in the auxiliary array
    int j = start_index;
    //start of second array
    int k = middle_index + 1;
    //when both arrays are not empty
    while(j <= middle_index && k <= end_index) {
        //checking which array head is smaller
        if (aux_arr[j] <= aux_arr[k]) {
            arr[i++] = aux_arr[j++];
        } else {
            arr[i++] = aux_arr[k++];
        }
    }
    //At this point one of the array is empty
    //emptying out arr1 to merged array
    while(j <= middle_index) {
        arr[i++] = aux_arr[j++];
    }
    //emptying out arr2 to merged array
    while(k <= end_index) {
        arr[i++] = aux_arr[k++];
    }
}

std::vector<int> MergeSort::GetArray() {
    return array_;
}


