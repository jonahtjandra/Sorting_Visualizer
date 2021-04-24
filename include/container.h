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
         * Constructor for the container of the bar graph.
         */
        Container();

        /**
         * Setter for array
         */
        void SetArray(std::vector<int> arr);

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
        const size_t kMargin = 150;
        const size_t kSpacing = 2;
        /**
         * Array of numbers
         */
        std::vector<int> array_;
    };

}  // namespace sortsimulator
