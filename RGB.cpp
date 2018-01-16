//
//  RGB.cpp
//
//

#include "RGB.h"

namespace  fractal {
    RGB::RGB() : m_r(0), m_g(0), m_b(0) {}
    RGB::RGB(double r, double g, double b) : m_r(r), m_g(g), m_b(b) {}
    
    RGB interpolate(const RGB & first, const RGB & second, double weight) {
        double red = first.m_r*(1-weight) + second.m_r*weight;
        double green = first.m_g*(1-weight) + second.m_g*weight;
        double blue = first.m_b*(1-weight) + second.m_b*weight;
        return RGB(red, green, blue);
    }
}
