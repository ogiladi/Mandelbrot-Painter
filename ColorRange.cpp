//
//  ColorRange.cpp
//
//

#include "ColorRange.h"
#include <fstream>
#include <iostream>

namespace fractal {
    ColorRange::ColorRange() {
        std::ifstream infile("listcolors.csv");
        double pixels;
        double red = 0;
        double green = 0;
        double blue = 0;
        int i = 0;
        
        while (infile >> pixels) {
            if (i%3 == 0) red = pixels;
            else if (i%3 == 1) green = pixels;
            else {
                blue = pixels;
                m_colorVec.push_back(RGB(red, green , blue));
            }
            i++;
        }
    }
    
    ColorRange::~ColorRange() {}
    
    RGB ColorRange::getColor(double d) {
        int numColors = (int) m_colorVec.size();
//        std::cout << numColors;
        int bottom = ((int)(d*numColors)) % numColors;
        int top = ((int)(d*numColors)+1) % numColors;
        RGB first = m_colorVec[bottom];
        RGB second = m_colorVec[top];
        double fracPart = d*numColors - (int)(d*numColors);
        RGB currentColor = interpolate(first, second, fracPart);
        return currentColor;
    }
}
