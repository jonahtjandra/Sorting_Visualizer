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
         * Entry point for every new frame
         */
        void AdvanceOneFrame();

        /**
         * Resets the graph
         */
        void ResetGraph();

        /**
         * Resets instance variables
         */
        void Reset();

        /**
         * Speed up the simulation
         */
        void SpeedUp();

        /**
         * Slow down the simulation
         */
        void SpeedDown();

        /**
         * Getter for state of current simulation. This is used for simultaneous simulations
         * @return
         */
        bool GetState() const;

        /**
         * Setter for state
         * @param state boolean representation of the state
         */
        void SetState(bool state);

        /**
         * Setter for title. Used in simultaneous simulations
         * @param title
         */
        void SetTitle(std::string title);

    private:
        int height_ = 400;
        int width_ = 600;
        int margin_left_ = 50;
        int margin_bottom_ = 150;
        int spacing_ = 2;
        std::string title_;
        // vector of integers to be sorted
        std::vector<int> array_;
        // vector of color array representing the color of each bar
        std::vector<ci::Color> color_array_;
        // the array of size 2 is for the two index values of the one we want to swap or color
        std::vector<std::tuple<int,int,int>> animations_;
        // counter for displaying animation sequence
        int count_ = 0;
        // used to handle animation sequence
        bool sorted_ = false;
        // used to handle animation sequence
        bool finished_ = false;
        // 0=bubble sort, 1=selection sort, 2=quicksort, 3=mergesort
        int sort_method;
        // used for handling simulation speed
        unsigned int kDelay = 0;
        // used for establishing state of simulation. true = simultaneous, false = single
        bool state_;
    };

}  // namespace sortsimulator
