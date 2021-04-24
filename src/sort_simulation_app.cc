//
// Created by Jonah on 19/04/21.
//
#include <sort_simulation_app.h>
#include <random>

namespace sortsimulator {

    SortSimulationApp::SortSimulationApp() {
        ci::app::setWindowSize(kWindowSize, kWindowSize);
        GenerateNewArray();
    }

    void SortSimulationApp::GenerateNewArray() {
        std::vector<int> array;
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> distribution(1,100);
        for(int i = 0; i < 100; i++) {
            int a = distribution(mt);
            array.push_back(a);
        }
        container_.SetArray(array);
        container_.Display();
        std::cout << "pressed";
    }

    void SortSimulationApp::draw() {
        ci::Color background_color("black");
        ci::gl::clear(background_color);
        ci::gl::drawStringCentered("Sorting Algorithm Visualizer",vec2(kWindowSize/2, kTitleTopMargin),ci::Color("white"));
        ci::gl::drawStringCentered("Generate New Array",vec2(kLeftMargin * 2, kWindowSize - kTitleTopMargin),ci::Color("white"));
        ci::gl::drawStringCentered("Selection Sort",vec2(kLeftMargin * 5, kWindowSize - kTitleTopMargin),ci::Color("white"));
        ci::gl::drawStringCentered("Bubble Sort",vec2(kLeftMargin * 7.5, kWindowSize - kTitleTopMargin),ci::Color("white"));
        ci::gl::drawStringCentered("Quick Sort",vec2(kLeftMargin * 10, kWindowSize - kTitleTopMargin),ci::Color("white"));
        ci::gl::drawStringCentered("Merge Sort",vec2(kLeftMargin * 12.5, kWindowSize - kTitleTopMargin),ci::Color("white"));
        container_.Display();
    }

    void SortSimulationApp::update() {
        container_.AdvanceOneFrame();
    }

    void SortSimulationApp::mouseDown(ci::app::MouseEvent event) {
        vec2 clickPos = event.getPos();
        //if clicked on generate new array
        if ((float)(kWindowSize - kTitleTopMargin) - 10 < clickPos.y && clickPos.y < (float)kWindowSize - kTitleTopMargin + 10) {
            if ((float)kLeftMargin * 2 - kLeftMargin < clickPos.x && clickPos.x < (float)kLeftMargin * 2 + kLeftMargin) {
                GenerateNewArray();
            }
            if ((float)kLeftMargin * 5 - kLeftMargin < clickPos.x && clickPos.x < (float)kLeftMargin * 5 + kLeftMargin) {
                std::cout<< "Selection Sort";
            }
            if ((float)kLeftMargin * 7.5 - kLeftMargin < clickPos.x && clickPos.x < (float)kLeftMargin * 7.5 + kLeftMargin) {
                std::cout<< "Bubble Sort";
            }
            if ((float)kLeftMargin * 10 - kLeftMargin < clickPos.x && clickPos.x < (float)kLeftMargin * 10 + kLeftMargin) {
                std::cout<< "Quick Sort";
            }
            if ((float)kLeftMargin * 12.5 - kLeftMargin < clickPos.x && clickPos.x < (float)kLeftMargin * 12.5 + kLeftMargin) {
                std::cout<< "Merge Sort";
            }
        }
    }

}  // namespace sortsimulator
