//
//  Mandelbrot.h
//  Computes the trajectory after a number of iterations,
//  as well as the mu coefficient (for smooth colouring)
//

#ifndef FractalPainter_Mandelbrot
#define FractalPainter_Mandelbrot

namespace fractal {
    class Mandelbrot {
    private:
        double m_mu;
        int m_numIterations;
        int m_maxIterations;
    public:
        Mandelbrot(double x, double y, int iterations);
        double getMu() const;
        int getIterations() const;
        bool fewIterations() const;
    };
}

#endif /* defined(__FractalPainter__Mandelbrot__) */

