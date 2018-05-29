//
//  main.cpp
//
//

#include <iostream>
#include "MandelbrotCreator.h"

using namespace fractal;

int main() {
    MandelbrotCreator mc(800, 600, 1000);
    mc.zoomInPoint(-0.743643135, .131825963, 210350);
    mc.drawInFile("test.bmp");
    std::cout << "Done\n";

    return 0;
}
