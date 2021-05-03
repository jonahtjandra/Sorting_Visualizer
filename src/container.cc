//
// Created by Jonah on 19/04/21.
//

#include "container.h"
#include "quicksort.h"
#include "mergesort.h"
#include <utility>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <bubblesort.h>
#include <selectionsort.h>

namespace sortsimulator {

    using glm::vec2;

    Container::Container(int height, int width, int margin_left, int margin_bottom) {
        sorted_ = false;
        height_ = height;
        width_ = width;
        margin_left_ = margin_left;
        margin_bottom_ = margin_bottom;
        state_ = false;
    }

    void Container::ParseQuickSort() {
        sorted_ = true;
        sort_method = 2;
        animations_.clear();
        std::vector<int> arr = array_;
        animations_ = QuickSort::SortArray(arr);

    }

    void Container::ParseMergeSort() {
        sorted_ = true;
        sort_method = 3;
        animations_.clear();
        animations_ = MergeSort::SortArray(array_);
    }

    void Container::ParseBubbleSort() {
        sorted_ = true;
        sort_method = 0;
        animations_.clear();
        animations_ = BubbleSort::SortArray(array_);
    }

    void Container::ParseSelectionSort() {
        sorted_ = true;
        sort_method = 1;
        animations_.clear();
        animations_ = SelectionSort::SortArray(array_);
    }

    void Container::Display() const {
        ci::gl::drawStringCentered(title_,vec2((width_/2)+margin_left_, margin_bottom_ - spacing_*5)
                                   ,ci::Color("white"));
        ci::gl::color(ci::Color("white"));
        ci::gl::drawStrokedRect(ci::Rectf(vec2(margin_left_, margin_bottom_),
                                          vec2(margin_left_ + width_, margin_bottom_ + height_)));
        float bar_width = (float)(width_ - (array_.size() + 1) * spacing_) / array_.size();
        for (int i = 0; i < array_.size(); i++) {
            ci::gl::color(color_array_[i]);
            ci::gl::drawSolidRect(ci::Rectf(vec2((float)margin_left_ + spacing_ + (float)i * (bar_width + spacing_),
                                                 margin_bottom_ + height_),
                                            vec2((float)margin_left_ + spacing_ + (float)i * (bar_width + spacing_) + bar_width,
                                                 (height_ + margin_bottom_) - (height_
                                                                               / array_.size() * array_[i]))));
        }
    }

    void Container::AdvanceOneFrame() {
        if (sorted_) {
            //comparisons color
            if (std::get<0>(animations_[count_]) == 1) {
                color_array_[std::get<1>(animations_[count_])] = ci::Color("red");
                color_array_[std::get<2>(animations_[count_])] = ci::Color("blue");
            }
            //uncolor
            if (std::get<0>(animations_[count_]) == 0) {
                color_array_[std::get<1>(animations_[count_])] = ci::Color("white");
                color_array_[std::get<2>(animations_[count_])] = ci::Color("white");
            }
            //swap
            if (std::get<0>(animations_[count_]) == 2) {
                //for merge sort
                if (sort_method == 3) {
                    array_[std::get<1>(animations_[count_])] = std::get<2>(animations_[count_]);
                }
                //for quick sort, bubble sort, and selection sort
                if (sort_method == 2 || sort_method == 1 || sort_method == 0) {
                    int tmp =  array_[std::get<1>(animations_[count_])];
                    array_[std::get<1>(animations_[count_])] =  array_[std::get<2>(animations_[count_])];
                    array_[std::get<2>(animations_[count_])] = tmp;
                }
            }
            //color indicating swaps
            if (std::get<0>(animations_[count_]) == 3) {
                color_array_[std::get<1>(animations_[count_])] = ci::Color("green");
                color_array_[std::get<2>(animations_[count_])] = ci::Color("green");
            }
            usleep(kDelay);
            Display();
            count_++;
            //sorting has finished
            if (count_ >= animations_.size()) {
                sorted_ = false;
                finished_ = true;
                count_ = 0;
            }
        }
        //ending sequence
        if (finished_) {
            color_array_[count_] = ci::Color("red");
            count_++;
            if (count_ > array_.size()) {
                color_array_[count_] = ci::Color("red");
                finished_ = false;
                ResetGraph();
                count_ = 0;
                state_ = true;
            }
        }
    }
    void Container::SetArray(const std::vector<int>& arr) {
        Reset();
        array_ = arr;
        for (int i = 0; i < array_.size(); i++) {
            color_array_.emplace_back("white");
        }
    }

    void Container::ResetGraph() {
        for (ci::Color& color : color_array_) {
            color = ci::Color("white");
        }
    }

    void Container::Reset() {
        animations_.clear();
        array_.clear();
        color_array_.clear();
    }

    void Container::SpeedUp() {
        if (kDelay >= 30000) {
            kDelay = kDelay - 30000;
        }
    }

    void Container::SpeedDown() {
        kDelay = 150000;
    }

    bool Container::GetState() const {
        return state_;
    }

    void Container::SetState(bool state) {
        state_ = state;

    }

    void Container::SetTitle(std::string title) {
        title_ = std::move(title);
    }


}  // namespace sortsimulator
