//
//  ColorRange.h
//  A class with a colour scale. Uses a csv file with a list of colours
//

#ifndef FractalPainter_ColorRange
#define FractalPainter_ColorRange

#include "RGB.h"
#include <vector>

namespace fractal {
    class ColorRange {
    private:
        std::vector<RGB> m_colorVec;
    public:
        ColorRange();
        ~ColorRange();
        RGB getColor(double d);
    };
}

#endif /* defined(__FractalPainter__ColorRange__) */

