//
// Created by Jonah on 19/04/21.
//
#include <sort_simulation_app.h>
#include <random>

namespace sortsimulator {

    SortSimulationApp::SortSimulationApp() {
        ci::app::setWindowSize(kWindowSize, kWindowSize);
        container_.SetArray(GenerateNewArray());
    }

    std::vector<int> SortSimulationApp::GenerateNewArray() const {
        std::vector<int> array;
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> distribution(1,kNumberOfBars);
        for(int i = 0; i < kNumberOfBars; i++) {
            int a = distribution(mt);
            array.push_back(a);
        }
        return array;
    }

    void SortSimulationApp::draw() {
        ci::Color background_color("black");
        ci::gl::clear(background_color);
        ci::gl::drawStringCentered("Sorting Algorithm Visualizer",vec2(kWindowSize/2, kTitleTopMargin),ci::Color("white"));
        if (!simulate_all_) {
            if (!sorted_) {
                ci::gl::drawStringCentered("Generate New Array",vec2(kLeftMargin * 2, kWindowSize - kTitleTopMargin),ci::Color("white"));
                ci::gl::drawStringCentered("Selection Sort",vec2(kLeftMargin * 4.5, kWindowSize - kTitleTopMargin),ci::Color("white"));
                ci::gl::drawStringCentered("Bubble Sort",vec2(kLeftMargin * 6.5, kWindowSize - kTitleTopMargin),ci::Color("white"));
                ci::gl::drawStringCentered("Quick Sort",vec2(kLeftMargin * 8.5, kWindowSize - kTitleTopMargin),ci::Color("white"));
                ci::gl::drawStringCentered("Merge Sort",vec2(kLeftMargin * 10.5, kWindowSize - kTitleTopMargin),ci::Color("white"));
                ci::gl::drawStringCentered("Simulate All", vec2(kLeftMargin * 12.5, kWindowSize - kTitleTopMargin),ci::Color("white"));
            }
            container_.Display();
        } else {
            for (std::tuple<Container, int>& container : container_list_) {
                std::get<0>(container).Display();
            }
            int count = 0;
            for (std::tuple<Container, int>& container : container_list_) {
                if (std::get<0>(container).GetState()) {
                    count++;
                }
            }
            if (count == container_list_.size()) {
                std::cout << "simulation finish";
                simulate_all_ = false;
                for (std::tuple<Container, int>& container : container_list_) {
                    std::get<0>(container).SetState(false);
                }
            }
        }
    }

    void SortSimulationApp::update() {
        if (!simulate_all_) {
            container_.AdvanceOneFrame();
        } else {
            for (std::tuple<Container, int>& container : container_list_) {
                std::get<0>(container).AdvanceOneFrame();
            }
        }
    }

    void SortSimulationApp::mouseDown(ci::app::MouseEvent event) {
        vec2 clickPos = event.getPos();
        //if clicked on generate new array
        if (!sorted_) {
            if ((float)(kWindowSize - kTitleTopMargin) - 10 < clickPos.y && clickPos.y < (float)kWindowSize - kTitleTopMargin + 10) {
                if ((float)kLeftMargin * 2 - kLeftMargin < clickPos.x && clickPos.x < (float)kLeftMargin * 2 + kLeftMargin) {
                    std::cout<< "Generate New Array";
                    container_.SetArray(GenerateNewArray());
                }
                if ((float)kLeftMargin * 4.5 - kLeftMargin < clickPos.x && clickPos.x < (float)kLeftMargin * 4.5 + kLeftMargin) {
                    std::cout<< "Selection Sort";
                    container_.ParseSelectionSort();
                }
                if ((float)kLeftMargin * 6.5 - kLeftMargin < clickPos.x && clickPos.x < (float)kLeftMargin * 6.5 + kLeftMargin) {
                    std::cout<< "Bubble Sort";
                    container_.ParseBubbleSort();
                }
                if ((float)kLeftMargin * 8.5 - kLeftMargin < clickPos.x && clickPos.x < (float)kLeftMargin * 8.5 + kLeftMargin) {
                    //quick sort
                    std::cout<< "Quick Sort";
                    container_.ParseQuickSort();
                }
                if ((float)kLeftMargin * 10.5 - kLeftMargin < clickPos.x && clickPos.x < (float)kLeftMargin * 10.5 + kLeftMargin) {
                    //merge sort
                    std::cout<< "Merge Sort";
                    container_.ParseMergeSort();
                }
                if ((float)kLeftMargin * 12.5 - kLeftMargin < clickPos.x && clickPos.x < (float)kLeftMargin * 12.5 + kLeftMargin) {
                    //simulate simultaneously
                    std::cout<< "Simulating all";
                    simulate_all_ = true;
                    RunAll();
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
        if (event.getChar() == 'c') {
            simulate_all_ = true;
            RunAll();
        }
    }

    void SortSimulationApp::RunAll() {
        std::vector<int> array = GenerateNewArray();
        for (std::tuple<Container, int>& container : container_list_) {
            std::get<0>(container).SetArray(array);
            if (std::get<1>(container) == 0) {
                std::get<0>(container).ParseMergeSort();
                std::get<0>(container).SetTitle("Merge Sort");
            }
            if (std::get<1>(container) == 1) {
                std::get<0>(container).ParseQuickSort();
                std::get<0>(container).SetTitle("Quick Sort");
            }
            if (std::get<1>(container) == 2) {
                std::get<0>(container).ParseBubbleSort();
                std::get<0>(container).SetTitle("Bubble Sort");
            }
            if (std::get<1>(container) == 3) {
                std::get<0>(container).ParseSelectionSort();
                std::get<0>(container).SetTitle("Selection Sort");
            }
        }
    }

}  // namespace sortsimulator
