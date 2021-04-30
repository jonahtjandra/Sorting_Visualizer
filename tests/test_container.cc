//
// Created by Jonah on 19/04/21.
//
#include <catch2/catch.hpp>

#include <quicksort.h>
#include <mergesort.h>
#include <vector>

TEST_CASE("QuickSort test") {
    SECTION("Median of three test") {
        std::vector<int> arr = {2,4,1,5,9,0,3};
        std::vector<int> sorted_arr = {0,1,2,3,4,5,9};
        REQUIRE(sortsimulator::QuickSort::GetSortedArray(arr) == sorted_arr);
    }
}
TEST_CASE("MergeSort test") {
    SECTION("Merge helper") {
        std::vector<int> arr = {8,3,1,7,9,5,4,2};
        std::vector<int> sorted_arr = {1,2,3,4,5,7,8,9};
        REQUIRE(sortsimulator::MergeSort::GetSortedArray(arr) == sorted_arr);
    }
}
