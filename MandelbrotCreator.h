//
//  MandelbrotCreator.h
//  A class that sets the colour for each pixel. Has a method for zooming in
//

#ifndef FractalPainter_MandelbrotCreator
#define FractalPainter_MandelbrotCreator

#include <vector>
#include "Bitmap.h"
#include "ZoomList.h"
#include "ColorRange.h"

namespace fractal {
    class MandelbrotCreator {
    private:
        int m_iterations;
        int m_width;
        int m_height;
        ColorRange m_colorTable;
        BitMap m_bitmap;
        ZoomList m_zoomList;
        std::vector<int> m_pixelIter;
        std::vector<double> m_muIter;
        void buildArrays();
        void drawFractal();
    public:
        MandelbrotCreator(int width, int height, int iterations);
        ~MandelbrotCreator();
        void zoomInPixel(int x, int y, double scale);
        void zoomInPoint(double x, double y, double scale);
        void drawInFile(std::string filename);
    };
}

#endif /* defined(__FractalPainter__MandelbrotCreator__) */

