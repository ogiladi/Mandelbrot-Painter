//
//  main.cpp
//
//

#include <iostream>
#include "MandelbrotCreator.h"

using namespace fractal;

int main() {
    MandelbrotCreator mc(800, 500, 1000);
    mc.zoomInPoint(-0.7435669, 0.1314023, 1344.9);
    mc.drawInFile("test.bmp");
    std::cout << "Done\n";

    return 0;
}
