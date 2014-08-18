#include "CImg.h"
using namespace cimg_library;

#include <cstdint>

#include "SimplexNoise/SimplexNoise.h"

int main()
{
/*
    // Integer color image (standard 2D image/file format)
    CImg<uint8_t> img(32, 4, 1, 3);     // Define a 32x4 color image with 8 bits per color component.
    img.fill(0);                        // Set pixel values to 0 (color : black)
    uint8_t purple[] = {255, 0, 255};   // Define a purple color
//  img.draw_text(10, 10, "Hello World", purple);
    img.draw_point(0, 0, purple);
    img.draw_line(2, 0, 2, 3, purple);
    img.display("hello img");           // Display the image in a display window.
//  img.save("hello.png");

    // Floating point color image (standard 3D color/texture management)
    CImg<float> imgf(32, 4, 1, 3);      // Define a 32x4 color image with 8 bits per color component.
    imgf.fill(0.f);                     // Set pixel values to 0 (color : black)
    float purplef[] = {1.f, 0.f, 1.f};  // Define a purple color
    imgf.draw_point(0, 0, purple);
    imgf.draw_line(2, 0, 2, 3, purple);
    imgf.display("hello imgf");         // Display the image in a display window.
*/

    CImg<float> img(1280, 4, 1, 3);     // Define a 1280x4 color image with a float value per color component.
    img.fill(0.f);                      // Set pixel values to 0 (color : black)
    for (int col = 0; col < img.width(); ++col)
    {
        float x     = (float)col / 60;          // Define a float coordinate associated with the column index
        float noise = SimplexNoise::noise(x);   // Get the noise value for the coordinate
        float color[] = {noise, noise, noise};  // Define the color
        img.draw_line(col, 0, col, 3, color);
    }
    img.display("1D noise");               // Display the image in a display window.

    return 0;
}
