//
// Created by Jonah on 19/04/21.
//
#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "container.h"

namespace sortsimulator {

/**
 * An app for visualizing the behavior sorting algorithm.
 */
    class SortSimulationApp : public ci::app::App {
    public:
        SortSimulationApp();

        void draw() override;
        void update() override;

        // provided that you can see the entire UI on your screen.
        const int kWindowSize = 700;
        const int kMargin = 100;

    private:
        Container container_;
    };

}  // namespace sortsimulator
