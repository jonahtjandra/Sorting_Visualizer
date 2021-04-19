//
// Created by Jonah on 19/04/21.
//
#pragma once

#include "cinder/gl/gl.h"

using glm::vec2;

namespace sortsimulator {

/**
 * The container in which all of the gas particles are contained. This class
 * stores all of the particles and updates them on each frame of the simulation.
 */
    class Container {
    public:
        /**
         * TODO: Add more parameters to this constructor, and add documentation.
         */
        Container();

        /**
         * Displays the container walls and the current positions of the particles.
         */
        void Display() const;

        /**
         * Updates the positions and velocities of all particles (based on the rules
         * described in the assignment documentation).
         */
        void AdvanceOneFrame();

    private:
        /**
         * This variable is just for the purposes of demonstrating how to make a shape move
         * across a screen. Please remove it once you start working on your code.
         */
        int dummy_variable_ = 0;
    };

}  // namespace sortsimulator
