//
// Created by Jonah on 19/04/21.
//
#pragma once

#include "cinder/gl/gl.h"

using glm::vec2;

namespace sortsimulator {

/**
 * The container in which all of the sorting algorithm graphs are stored
 */
    class Container {
    public:
        /**
         * Default Constructor for the container of the bar graph.
         */
        Container(int height, int width, int left_margin, int bottom_margin);

        /**
         * Do quicksort animation
         */
        void ParseQuickSort();

        /**
         * Do mergesort animation
         */
        void ParseMergeSort();

        /**
         * Do bubblesort animation
         */
        void ParseBubbleSort();

        /**
         * Do selectionsort animation
         */
        void ParseSelectionSort();

        /**
         * Setter for array
         */
        void SetArray(const std::vector<int>& arr);

        /**
         * Displays the bar graph.
         */
        void Display() const;

        /**
         * Updates the height and positions of bars. Also updates the current pointer of the algorithm
         */
        void AdvanceOneFrame();

        void ResetGraph();

        void Reset();

        void SpeedUp();

        void SpeedDown();

        bool GetState() const;

        void SetState(bool state);

        void SetTitle(std::string title);

    private:
        int height_ = 400;
        int width_ = 600;
        int margin_left_ = 50;
        int margin_bottom_ = 150;
        int spacing_ = 2;
        std::string title_;
        /**
         * Array of numbers
         */
        std::vector<int> array_;
        std::vector<ci::Color> color_array_;
        //the array of size 2 is for the two index values of the one we want to swap or color
        std::vector<std::tuple<int,int,int>> animations_;
        int count_ = 0;
        bool sorted_ = false;
        bool finished_ = false;
        //0=bubble sort, 1=selection sort, 2=quicksort, 3=mergesort
        int sort_method;
        unsigned int kDelay = 0;
        bool state_;
    };

}  // namespace sortsimulator
