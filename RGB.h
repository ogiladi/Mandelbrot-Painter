//
//  RGB.h
//  A class for representing coloursin RGB form
//

#ifndef FractalPainter_RGB
#define FractalPainter_RGB

namespace fractal {
    struct RGB {
        double m_r;
        double m_g;
        double m_b;
        RGB();
        RGB(double r, double g, double b);        
    };
    
    RGB interpolate(const RGB &, const RGB &, double);
}

#endif /* defined(__FractalPainter__RGB__) */

