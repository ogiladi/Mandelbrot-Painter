//
//  ZoomList.cpp
//
//

#include "ZoomList.h"

namespace fractal {
    ZoomList::ZoomList(int width, int height, int x, int y, double scale) : m_width(width), m_height(height) {
        m_xCenter += x - m_width/2;
        m_yCenter -= y - m_height/2;
        m_scale = scale;
    }
    
    void ZoomList::zoomInPixel(int x, int y, double scale) {
        m_xCenter += (x - m_width/2) * m_scale;
        m_yCenter -= (y - m_height/2) * m_scale;
        m_scale /= scale;
    }
    
    void ZoomList::zoomInPoint(double x, double y, double scale) {
        m_xCenter = x;
        m_yCenter = y;
        m_scale /= scale;
    }
    
    std::pair<double, double> ZoomList::doZoom(int x, int y) {
        double xFractal = (x-m_width/2)*m_scale + m_xCenter;
        double yFractal = (y-m_height/2)*m_scale + m_yCenter;
        return std::pair<double, double>(xFractal, yFractal);
    }
    
}

