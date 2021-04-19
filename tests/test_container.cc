//
// Created by Jonah on 19/04/21.
//
#include <catch2/catch.hpp>

#include <quicksort.h>
#include <vector>

TEST_CASE("QuickSort test") {
    SECTION("Median of three test") {
        std::vector<int> arr = {2,4,1,5,9,0,3};
        std::vector<int> sorted_arr = {0,1,2,3,4,5,9};
        QuickSort quicksort = QuickSort(arr);
        REQUIRE(quicksort.GetArray() == sorted_arr);
    }
}
