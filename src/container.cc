//
// Created by Jonah on 19/04/21.
//

#include "container.h"

namespace sortsimulator {

    using glm::vec2;

    Container::Container() {

    }


    void Container::Display() const {
        ci::gl::color(ci::Color("white"));
        ci::gl::drawStrokedRect(ci::Rectf(vec2(kMarginLeft, kMarginBottom),
                                          vec2(kMarginLeft+kWidth, kMarginBottom + kHeight)));
        float bar_width = (float)(kWidth - (array_.size() + 1)*kSpacing)/array_.size();
        for (int i = 0; i < array_.size(); i++) {
            ci::gl::color(ci::Color("white"));
            ci::gl::drawSolidRect(ci::Rectf(vec2(kMarginLeft + kSpacing + i*(bar_width+kSpacing), kMarginBottom + kHeight),
                                            vec2(kMarginLeft + kSpacing + i*(bar_width+kSpacing) + bar_width,
                                                 (kHeight + kMarginBottom) - (kHeight / array_.size() * array_[i]))));
        }
    }

    void Container::AdvanceOneFrame() {
    }

    void Container::SetArray(std::vector<int>& arr) {
        array_ = arr;
    }

}  // namespace sortsimulator
