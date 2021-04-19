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
         * Displays the bar graph.
         */
        void Display() const;

        /**
         * Updates the height and positions of bars. Also updates the current pointer of the algorithm
         */
        void AdvanceOneFrame();

    private:
        /**
         * dummy
         */
        int dummy_variable_ = 0;
    };

}  // namespace sortsimulator
