//
//  Mandelbrot.cpp
//
//

#include "Mandelbrot.h"
#include <iostream>
#include <complex>
#include <math.h>

namespace fractal {
    Mandelbrot::Mandelbrot(double x, double y, int iterations):  m_mu(0), m_numIterations(0), m_maxIterations(iterations) {
        std::complex<double> z = 0;
        std::complex<double> c(x, y);
    
        while(abs(z) < 2 && m_numIterations < m_maxIterations) {
            std::complex<double> ztemp = z*z + c;
            if (ztemp == z) {
                m_numIterations = m_maxIterations;
                break;
            }
            z = ztemp;
            m_numIterations++;
        }
        
        if (m_numIterations < m_maxIterations) {
            for (int i = 0; i < 3; i++) z = z*z+c;
            double nu = log(log(abs(z))/log(2)) / log(2);
            m_mu = m_numIterations+4-nu;
        }
    }
    
    double Mandelbrot::getMu() const {
        return m_mu;
    }
    
    int Mandelbrot::getIterations() const {
        return m_numIterations;
    }
    
    bool Mandelbrot::fewIterations() const {
        return m_numIterations < m_maxIterations;
    }
    
}

