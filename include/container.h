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
        Container();

        /**
         * Constructor for the container of the bar graph.
         */
        Container(std::vector<int[2]>);

        /**
         * Set sort animation
         */
        void ParseQuickSort();

        /**
         * Setter for array
         */
        void SetArray(std::vector<int>& arr);

        /**
         * Displays the bar graph.
         */
        void Display() const;

        /**
         * Updates the height and positions of bars. Also updates the current pointer of the algorithm
         */
        void AdvanceOneFrame();

    private:
        const int kHeight = 400;
        const int kWidth = 600;
        const size_t kMarginLeft = 50;
        const size_t kMarginBottom = 150;
        const size_t kSpacing = 2;
        /**
         * Array of numbers
         */
        std::vector<int> array_;
        //the array of size 2 is for the two index values of the one we want to swap or color
        std::vector<int[2]> animations_;
        int animation_count_;
        bool sorted_;
    };

}  // namespace sortsimulator
