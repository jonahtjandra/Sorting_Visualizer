//
// Created by Jonah on 19/04/21.
//
#include "sort_simulation_app.h"

using sortsimulator::SortSimulationApp;

void prepareSettings(SortSimulationApp::Settings* settings) {
    settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(SortSimulationApp, ci::app::RendererGl, prepareSettings);

