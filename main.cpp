#include "CImg.h"
using namespace cimg_library;

#include <cstdint>
#include <fstream>

#include "SimplexNoise/SimplexNoise.h"

#include "color.h"

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
    CImg<float> imgf(32, 4, 1, 3);      // Define a 32x4 color image with a float value per color component.
    imgf.fill(0.f);                     // Set pixel values to 0 (color : black)
    float purplef[] = {1.f, 0.f, 1.f};  // Define a purple color
    imgf.draw_point(0, 0, purple);
    imgf.draw_line(2, 0, 2, 3, purple);
    imgf.display("hello imgf");         // Display the image in a display window.
*/

/*
    CImg<float> img1D(1280, 4*8, 1, 3);   // Define a 1280x32 color image with a float value per color component.
    img1D.fill(0.f);                      // Set pixel values to 0 (color : black)

    for (int row = 0; row < 8; ++row)
    {
        for (int col = 0; col < img1D.width(); ++col)
        {
            float x     = (float)(col + (row * img1D.width())) / 60;    // Define a float coordinate associated with the column index
            float noise = SimplexNoise::noise(x);                       // Get the noise value for the coordinate
            float color[] = { noise, noise, noise };                    // Define the color
            img1D.draw_line(col, 0 + (row * 4), col, 3 + (row * 4), color);
        }
    }
    img1D.display("1D noise");            // Display the image in a display window.
//  img1D.save("map1D.bmp");
*/

/*
    for(float a = -1.000f; a <= 1.000f; a += 0.1f)
    {
        color3f color;
        ramp(a, color); // Define the color
    }
*/

    CImg<float> img2D(600, 600, 1, 3); // Define a 600x600 color image with a float value per color component.
    img2D.fill(0.f);                   // Set pixel values to 0 (color : black)

    for(int row = 0; row < img2D.height(); ++row)
    {
        for(int col = 0; col < img2D.width(); ++col)
        {
            float noise = SimplexNoise::noise(col / 180.f, row / 180.f);                   // Get the noise value for the coordinate
            color3f color;
            ramp(noise, color); // Define the color
            img2D.draw_point(col, row, (float*)&color);
        }
    }
    img2D.display("2D noise");            // Display the image in a display window.
//  img2D.save("map2D.bmp");

    return 0;
}
