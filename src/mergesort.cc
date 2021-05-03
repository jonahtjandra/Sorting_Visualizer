//
// Created by Jonah on 19/04/21.
//

#include <iostream>
#include "mergesort.h"
#include <cmath>
namespace sortsimulator {
MergeSort::MergeSort(std::vector<int> arr) {
    array_ = arr;
}

std::vector<std::tuple<int, int, int>> MergeSort::SortArray(std::vector<int> arr) {
    std::vector<std::tuple<int,int,int>> animation;
    std::vector<int> array = arr;
    Sort(array, arr, 0, arr.size() - 1,animation);
    return animation;
}

void MergeSort::Sort(std::vector<int>& arr, std::vector<int>& aux_arr, int start_index, int end_index
                     , std::vector<std::tuple<int,int,int>>& animation) {
    if (end_index == start_index) {
        return;
    }
    //splitting array into two
    int mid = floor((start_index + end_index)/2);
    Sort(aux_arr,arr, start_index, mid, animation);
    Sort(aux_arr,arr, mid+1, end_index, animation);
    Merge(arr,aux_arr, start_index, mid, end_index, animation);
}

void MergeSort::Merge(std::vector<int>& arr, const std::vector<int>& aux_arr, int start_index, int middle_index
                      , int end_index, std::vector<std::tuple<int,int,int>>& animation) {
    //pointer in the original array
    int i = start_index;
    //pointer in the auxiliary array
    int j = start_index;
    //start of second array
    int k = middle_index + 1;
    //when both arrays are not empty
    while(j <= middle_index && k <= end_index) {
        //animation for comparing values
        animation.emplace_back(std::make_tuple(1,j,k));
        //color switch back to white
        animation.emplace_back(std::make_tuple(0,j,k));
        //checking which array head is smaller
        if (aux_arr[j] <= aux_arr[k]) {
            //animation for color swap
            animation.emplace_back(std::make_tuple(3,i,j));
            //swap
            animation.emplace_back(std::make_tuple(2,i,aux_arr[j]));
            //color switch back to white
            animation.emplace_back(std::make_tuple(0,i,j));
            arr[i++] = aux_arr[j++];
        } else {
            //animation for color swap
            animation.emplace_back(std::make_tuple(3,i,k));
            //swap
            animation.emplace_back(std::make_tuple(2,i,aux_arr[k]));
            //color switch back to white
            animation.emplace_back(std::make_tuple(0,i,k));
            arr[i++] = aux_arr[k++];
        }
    }
    //At this point one of the array is empty
    //emptying out arr1 to merged array
    while(j <= middle_index) {
        //animation for color swap
        animation.emplace_back(std::make_tuple(3,i,j));
        //color for swap
        animation.emplace_back(std::make_tuple(2,i,aux_arr[j]));
        //color switch back to white
        animation.emplace_back(std::make_tuple(0,i,j));
        arr[i++] = aux_arr[j++];
    }

    //emptying out arr2 to merged array
    while(k <= end_index) {
        //animation for color swap
        animation.emplace_back(std::make_tuple(3,i,k));
        //color for swap
        animation.emplace_back(std::make_tuple(2,i,aux_arr[k]));
        //color switch back to white
        animation.emplace_back(std::make_tuple(0,i,k));
        arr[i++] = aux_arr[k++];
    }
}

std::vector<int> MergeSort::GetSortedArray(std::vector<int> arr) {
    std::vector<std::tuple<int,int,int>> animation;
    std::vector<int> array = arr;
    Sort(array, arr, 0, arr.size() - 1,animation);
    return array;
}

} //namespace sortsimulator


