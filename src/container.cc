//
// Created by Jonah on 19/04/21.
//

#include "container.h"
#include "quicksort.h"
#include "mergesort.h"
#include <utility>
#include <vector>
#include <algorithm>
#include <iostream>

namespace sortsimulator {

    using glm::vec2;

    Container::Container() {
        sorted_ = false;
    }

    void Container::ParseQuickSort() {
        sorted_ = true;
        sort_method = 2;
        animations_.clear();
        animations_ = QuickSort::SortArray(array_);
        for (int i : QuickSort::GetSortedArray(array_)) {
            std::cout << i << std::endl;
        }
    }

    void Container::ParseMergeSort() {
        sorted_ = true;
        sort_method = 3;
        animations_.clear();
        animations_ = MergeSort::SortArray(array_);
    }

    void Container::Display() const {
        ci::gl::color(ci::Color("white"));
        ci::gl::drawStrokedRect(ci::Rectf(vec2(kMarginLeft, kMarginBottom),
                                          vec2(kMarginLeft+kWidth, kMarginBottom + kHeight)));
        float bar_width = (float)(kWidth - (array_.size() + 1)*kSpacing)/array_.size();
        for (int i = 0; i < array_.size(); i++) {
            ci::gl::color(color_array_[i]);
            ci::gl::drawSolidRect(ci::Rectf(vec2((float)kMarginLeft + kSpacing + (float)i*(bar_width+kSpacing),
                                                 kMarginBottom + kHeight),
                                            vec2((float)kMarginLeft + kSpacing + (float)i*(bar_width+kSpacing) + bar_width,
                                                 (kHeight + kMarginBottom) - (kHeight
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
                //for quick sort
                if (sort_method == 2) {
                    int tmp =  array_[std::get<1>(animations_[count_])];
                    array_[std::get<1>(animations_[count_])] =  array_[std::get<2>(animations_[count_])];
                    array_[std::get<2>(animations_[count_])] = tmp;
                }
            }
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
            if (count_ > array_.size()) {
                color_array_[count_] = ci::Color("red");
                finished_ = false;
                ResetGraph();
            }
            count_++;
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


}  // namespace sortsimulator
