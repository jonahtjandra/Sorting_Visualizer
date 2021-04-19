//
// Created by Jonah on 19/04/21.
//
#include <sort_simulation_app.h>


namespace sortsimulator {

    SortSimulationApp::SortSimulationApp() {
        ci::app::setWindowSize(kWindowSize, kWindowSize);
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
