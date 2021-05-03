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
        void mouseDown(ci::app::MouseEvent event) override;
        void keyDown(ci::app::KeyEvent event) override;

    private:
        void RunAll();
        const int kWindowSize = 700;
        const int kTitleTopMargin = 50;
        const int kLeftMargin = 50;
        const int kNumberOfBars = 20;
        bool simulate_all_ = false;
        std::vector<int> GenerateNewArray() const;
        Container container_ = Container(400, 600, 50, 150);
        // 0 = mergesort, 1 = quicksort, 2 = bubblesort, 3 = selectionsort
        std::vector<std::tuple<Container, int>> container_list_ = {std::make_tuple(Container(200, 300, 40, 140), 0)
                , std::make_tuple(Container(200, 300, 360, 140), 1),
                std::make_tuple(Container(200, 300, 40, 360), 2), std::make_tuple(Container(200, 300, 360, 360), 3)};
        //true if array simulation is currently being sorted
        bool sorted_ = false;

    };

}  // namespace sortsimulator
