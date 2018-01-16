//
//  MandelbrotCreator.cpp
//
//

#include <string>
#include "MandelbrotCreator.h"
#include "Mandelbrot.h"
#include "RGB.h"

namespace fractal {
    
    MandelbrotCreator::MandelbrotCreator(int width, int height, int iterations) : m_iterations(iterations), m_width(width), m_height(height), m_bitmap(width, height), m_zoomList(width, height, width/2, height/2, 4.0/width), m_pixelIter(std::vector<int>(width*height)), m_muIter(std::vector<double>(width*height)) {}
    
    MandelbrotCreator::~MandelbrotCreator() {}
    
    void MandelbrotCreator::buildArrays() {
        for (int y = 0; y < m_height; y++) {
            for (int x = 0; x < m_width; x++) {
                std::pair<double, double> coors = m_zoomList.doZoom(x, y);
                Mandelbrot c(coors.first, coors.second, m_iterations);
                m_pixelIter[y*m_width+x] = c.getIterations();
                m_muIter[y*m_width+x] = c.getMu();
            }
        }
    }
    
    void MandelbrotCreator::drawFractal() {
        for (int y = 0; y < m_height; y++) {
            for (int x = 0; x < m_width; x++) {
                uint8_t red = 0;
                uint8_t green = 0;
                uint8_t blue = 0;
                if (m_pixelIter[y*m_width+x] < m_iterations) {
                    double mu = m_muIter[y*m_width+x];
                    RGB currentColor = m_colorTable.getColor(10*mu/(m_iterations+3));
                    red = currentColor.m_r;
                    green = currentColor.m_g;
                    blue = currentColor.m_b;
                }
                m_bitmap.setPixel(x, y, red, green, blue);
            }
        }
    }

    void MandelbrotCreator::zoomInPixel(int x, int y, double scale) {
        m_zoomList.zoomInPixel(x, y, scale);
    }
    
    void MandelbrotCreator::zoomInPoint(double x, double y, double scale) {
        m_zoomList.zoomInPoint(x, y, scale);
    }
    
    void MandelbrotCreator::drawInFile(std::string filename) {
        buildArrays();
        drawFractal();
        m_bitmap.write(filename);
    }
}

