//
//  ZoomList.h
//  A class to be used when applying successive zoomings
//

#ifndef FractalPainter_ZoomList
#define FractalPainter_ZoomList

#include <utility>

namespace fractal {
    class ZoomList {
    private:
        double m_xCenter;
        double m_yCenter;
        double m_scale;
        int m_width;
        int m_height;
    public:
        ZoomList(int width, int height, int x, int y, double scale);
        void zoomInPixel(int x, int y, double scale);
        void zoomInPoint(double x, double y, double scale);
        std::pair<double, double> doZoom(int x, int y);
    };
}

#endif /* defined(__FractalPainter__ZoomList__) */

