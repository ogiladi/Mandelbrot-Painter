//
//  BitMapFileHeader.h
//
//
#ifndef FractalPainter_BitMapFileHeader_h
#define FractalPainter_BitMapFileHeader_h

#include <cstdint>
#pragma pack(2)

namespace fractal {
    
    struct BitMapFileHeader {
        char header[2]{'B', 'M'};
        int32_t fileSize;
        int32_t reserved{0};
        int32_t dataOffSet;
    };
}

#endif

