//
// Created by Jonah on 19/04/21.
//
#include <sort_simulation_app.h>
#include <random>

namespace sortsimulator {

    SortSimulationApp::SortSimulationApp() {
        ci::app::setWindowSize(kWindowSize, kWindowSize);
        std::vector<int> array;
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(1,100);
        for(int i = 0; i < 100; i++) {
            int a = distribution(generator);
            array.push_back(a);
        }
        container_.SetArray(array);
    }

    void SortSimulationApp::draw() {
        ci::Color background_color("black");
        ci::gl::clear(background_color);

        container_.Display();
    }

    void SortSimulationApp::update() {
        container_.AdvanceOneFrame();
    }

}  // namespace sortsimulator
