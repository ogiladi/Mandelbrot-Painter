//
//  BitMap.h
//  Set pixels in a picture with a given width and height
//

#ifndef FractalPainter_BitMap
#define FractalPainter_BitMap

#include <string>
#include <vector>
#include <cstdint>

namespace fractal {
    class BitMap {
    private:
        int m_width;
        int m_height;
        std::unique_ptr<uint8_t[]> m_pPixels;
    public:
        BitMap(int width, int height);
        ~BitMap();
        bool write(std::string filename);
        void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
    };
}

#endif /* defined(__FractalPainter__BitMap__) */
