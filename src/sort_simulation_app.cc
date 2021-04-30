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
        std::uniform_int_distribution<int> distribution(1,kNumberOfBars);
        for(int i = 0; i < kNumberOfBars; i++) {
            int a = distribution(mt);
            array.push_back(a);
            std::cout<<a<<std::endl;
        }
        container_.SetArray(array);
    }

    void SortSimulationApp::draw() {
        ci::Color background_color("black");
        ci::gl::clear(background_color);
        ci::gl::drawStringCentered("Sorting Algorithm Visualizer",vec2(kWindowSize/2, kTitleTopMargin),ci::Color("white"));
        if (!sorted_) {
            ci::gl::drawStringCentered("Generate New Array",vec2(kLeftMargin * 2, kWindowSize - kTitleTopMargin),ci::Color("white"));
            ci::gl::drawStringCentered("Selection Sort",vec2(kLeftMargin * 5, kWindowSize - kTitleTopMargin),ci::Color("white"));
            ci::gl::drawStringCentered("Bubble Sort",vec2(kLeftMargin * 7.5, kWindowSize - kTitleTopMargin),ci::Color("white"));
            ci::gl::drawStringCentered("Quick Sort",vec2(kLeftMargin * 10, kWindowSize - kTitleTopMargin),ci::Color("white"));
            ci::gl::drawStringCentered("Merge Sort",vec2(kLeftMargin * 12.5, kWindowSize - kTitleTopMargin),ci::Color("white"));
        }
        container_.Display();
    }

    void SortSimulationApp::update() {
        container_.AdvanceOneFrame();
    }

    void SortSimulationApp::mouseDown(ci::app::MouseEvent event) {
        vec2 clickPos = event.getPos();
        //if clicked on generate new array
        if (!sorted_) {
            if ((float)(kWindowSize - kTitleTopMargin) - 10 < clickPos.y && clickPos.y < (float)kWindowSize - kTitleTopMargin + 10) {
                if ((float)kLeftMargin * 2 - kLeftMargin < clickPos.x && clickPos.x < (float)kLeftMargin * 2 + kLeftMargin) {
                    std::cout<< "Generate New Array";
                    GenerateNewArray();
                }
                if ((float)kLeftMargin * 5 - kLeftMargin < clickPos.x && clickPos.x < (float)kLeftMargin * 5 + kLeftMargin) {
                    std::cout<< "Selection Sort";
                }
                if ((float)kLeftMargin * 7.5 - kLeftMargin < clickPos.x && clickPos.x < (float)kLeftMargin * 7.5 + kLeftMargin) {
                    std::cout<< "Bubble Sort";
                }
                if ((float)kLeftMargin * 10 - kLeftMargin < clickPos.x && clickPos.x < (float)kLeftMargin * 10 + kLeftMargin) {
                    //quick sort
                    std::cout<< "Quick Sort";
                    container_.ParseQuickSort();
                }
                if ((float)kLeftMargin * 12.5 - kLeftMargin < clickPos.x && clickPos.x < (float)kLeftMargin * 12.5 + kLeftMargin) {
                    //merge sort
                    std::cout<< "Merge Sort";
                    container_.ParseMergeSort();
                }
            }
        }
    }

    void SortSimulationApp::keyDown(ci::app::KeyEvent event) {
        if (event.getChar() == 's') {
            container_.SpeedDown();
        }
        if (event.getChar() == 'w') {
           container_.SpeedUp();
        }
    }

}  // namespace sortsimulator
