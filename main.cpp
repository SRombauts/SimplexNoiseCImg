#include "CImg.h"
using namespace cimg_library;

#include <iostream>
#include <cstdint>
#include <fstream>
#include <algorithm>
#include <cmath>

#include "SimplexNoise/src/SimplexNoise.h"

#include "color.h"

int main() {
    float scale     = 400.f;
    int   offset_x  = 0;
    int   offset_y  = 0;

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
        const color3f color = ramp(a); // Define the color
    }
*/
/*
    CImg<float> img2D1(1280, 720, 1, 3); // Define a 1280x720 color image with a float value per color component.
    img2D1.fill(0.f);                    // Set pixel values to 0 (color : black)

    for(int row = 0; row < img2D1.height(); ++row)
    {
        for(int col = 0; col < img2D1.width(); ++col)
        {
            float noise = SimplexNoise::noise(col / scale, row / scale);                   // Get the noise value for the coordinate
            const color3f color = ramp(noise); // Define the color
            img2D1.draw_point(col, row, (float*)&color);
        }
    }
//  img2D1.save("map2D1.bmp");
    CImgDisplay disp2D1(img2D1, "2D Simplex Perlin noise (1 octave)");
    disp2D1.move(10, 30);


    CImg<float> img2D2(1280, 720, 1, 3); // Define a 1280x720 color image with a float value per color component.
    img2D2.fill(0.f);                    // Set pixel values to 0 (color : black)

    for(int row = 0; row < img2D2.height(); ++row)
    {
        for(int col = 0; col < img2D2.width(); ++col)
        {
            // Get the noise value for the coordinate
            float noise = 0.65f * SimplexNoise::noise(1 * col / scale, 1 * row / scale);
                  noise += 0.32f * SimplexNoise::noise(2 * col / scale, 2 * row / scale);
            const color3f color = ramp(noise); // Define the color
            img2D2.draw_point(col, row, (float*)&color);
        }
    }
//  img2D2.save("map2D2.bmp");
    CImgDisplay disp2D2(img2D2, "2D Simplex Perlin noise (2 octaves)");
    disp2D2.move(10, 30);


    CImg<float> img2D3(1280, 720, 1, 3); // Define a 1280x720 color image with a float value per color component.
    img2D3.fill(0.f);                    // Set pixel values to 0 (color : black)

    for(int row = 0; row < img2D3.height(); ++row)
    {
        for(int col = 0; col < img2D3.width(); ++col)
        {
            // Get the noise value for the coordinate
            float noise = 0.57f * SimplexNoise::noise(1 * col / scale, 1 * row / scale);
                  noise += 0.27f * SimplexNoise::noise(2 * col / scale, 2 * row / scale);
                  noise += 0.15f * SimplexNoise::noise(4 * col / scale, 4 * row / scale);
            const color3f color = ramp(noise); // Define the color
            img2D3.draw_point(col, row, (float*)&color);
        }
    }
//  img2D3.save("map2D3.bmp");
    CImgDisplay disp2D3(img2D3, "2D Simplex Perlin noise (3 octaves)");
    disp2D3.move(10, 30);


    CImg<float> img2D4(1280, 720, 1, 3); // Define a 1280x720 color image with a float value per color component.
    img2D4.fill(0.f);                    // Set pixel values to 0 (color : black)

    for(int row = 0; row < img2D4.height(); ++row)
    {
        for(int col = 0; col < img2D4.width(); ++col)
        {
            // Get the noise value for the coordinate
            float noise = 0.56f * SimplexNoise::noise(1 * col / scale, 1 * row / scale);
                  noise += 0.25f * SimplexNoise::noise(2 * col / scale, 2 * row / scale);
                  noise += 0.125f * SimplexNoise::noise(4 * col / scale, 4 * row / scale);
                  noise += 0.0625f * SimplexNoise::noise(8 * col / scale, 8 * row / scale);
            const color3f color = ramp(noise); // Define the color
            img2D4.draw_point(col, row, (float*)&color);
        }
    }
//  img2D4.save("map2D4.bmp");
    CImgDisplay disp2D4(img2D4, "2D Simplex Perlin noise (4 octaves)");
    disp2D4.move(10, 30);


    CImg<float> img2D5(1280, 720, 1, 3); // Define a 1280x720 color image with a float value per color component.
    img2D5.fill(0.f);                    // Set pixel values to 0 (color : black)

    for(int row = 0; row < img2D5.height(); ++row)
    {
        for(int col = 0; col < img2D5.width(); ++col)
        {
            // Get the noise value for the coordinate
            float noise  = 0.53f * SimplexNoise::noise(1 * col / scale, 1 * row / scale);
                  noise += 0.25f * SimplexNoise::noise(2 * col / scale, 2 * row / scale);
                  noise += 0.125f * SimplexNoise::noise(4 * col / scale, 4 * row / scale);
                  noise += 0.0625f * SimplexNoise::noise(8 * col / scale, 8 * row / scale);
                  noise += 0.03125f * SimplexNoise::noise(16 * col / scale, 16 * row / scale);
            const color3f color = ramp(noise); // Define the color
            img2D5.draw_point(col, row, (float*)&color);
        }
    }
//  img2D5.save("map2D5.bmp");
    CImgDisplay disp2D5(img2D5, "2D Simplex Perlin noise (5 octaves)");
    disp2D5.move(10, 30);


    CImg<float> img2D6(1280, 720, 1, 3); // Define a 1280x720 color image with a float value per color component.
    img2D6.fill(0.f);                    // Set pixel values to 0 (color : black)

    for(int row = 0; row < img2D6.height(); ++row)
    {
        for(int col = 0; col < img2D6.width(); ++col)
        {
            // Get the noise value for the coordinate
            float noise  = 0.5f * SimplexNoise::noise(1 * col / scale, 1 * row / scale);
                  noise += 0.25f * SimplexNoise::noise(2 * col / scale, 2 * row / scale);
                  noise += 0.125f * SimplexNoise::noise(4 * col / scale, 4 * row / scale);
                  noise += 0.0625f * SimplexNoise::noise(8 * col / scale, 8 * row / scale);
                  noise += 0.03125f * SimplexNoise::noise(16 * col / scale, 16 * row / scale);
                  noise += 0.015625f * SimplexNoise::noise(32 * col / scale, 32 * row / scale);
            const color3f color = ramp(noise); // Define the color
            img2D6.draw_point(col, row, (float*)&color);
        }
    }
//  img2D6.save("map2D6.bmp");
    CImgDisplay disp2D6(img2D6, "2D Simplex Perlin noise (6 octaves)");
    disp2D6.move(10, 30);


    CImg<float> img2D7(1280, 720, 1, 3); // Define a 1280x720 color image with a float value per color component.
    img2D7.fill(0.f);                    // Set pixel values to 0 (color : black)

    for(int row = 0; row < img2D7.height(); ++row)
    {
        for(int col = 0; col < img2D7.width(); ++col)
        {
            // Get the noise value for the coordinate
            float noise  = 0.5f * SimplexNoise::noise(1 * col / scale, 1 * row / scale);
                  noise += 0.25f * SimplexNoise::noise(2 * col / scale, 2 * row / scale);
                  noise += 0.125f * SimplexNoise::noise(4 * col / scale, 4 * row / scale);
                  noise += 0.0625f * SimplexNoise::noise(8 * col / scale, 8 * row / scale);
                  noise += 0.03125f * SimplexNoise::noise(16 * col / scale, 16 * row / scale);
                  noise += 0.015625f * SimplexNoise::noise(32 * col / scale, 32 * row / scale);
                  noise += 0.0078125f * SimplexNoise::noise(64 * col / scale, 64 * row / scale);
            const color3f color = ramp(noise); // Define the color
            img2D7.draw_point(col, row, (float*)&color);
        }
    }
//  img2D7.save("map2D7.bmp");
    CImgDisplay disp2D7(img2D7, "2D Simplex Perlin noise (7 octaves)");
    disp2D7.move(10, 30);


    CImg<float> img2D8(1280, 720, 1, 3); // Define a 1280x720 color image with a float value per color component.
    img2D8.fill(0.f);                    // Set pixel values to 0 (color : black)

    for(int row = 0; row < img2D8.height(); ++row)
    {
        for(int col = 0; col < img2D8.width(); ++col)
        {
            // Get the noise value for the coordinate
            float noise  = 0.5f * SimplexNoise::noise(1 * col / scale, 1 * row / scale);
                  noise += 0.25f * SimplexNoise::noise(2 * col / scale, 2 * row / scale);
                  noise += 0.125f * SimplexNoise::noise(4 * col / scale, 4 * row / scale);
                  noise += 0.0625f * SimplexNoise::noise(8 * col / scale, 8 * row / scale);
                  noise += 0.03125f * SimplexNoise::noise(16 * col / scale, 16 * row / scale);
                  noise += 0.015625f * SimplexNoise::noise(32 * col / scale, 32 * row / scale);
                  noise += 0.0078125f * SimplexNoise::noise(64 * col / scale, 64 * row / scale);
                  noise += 0.00390625f * SimplexNoise::noise(128 * col / scale, 128 * row / scale);
                  color3f color;
            const color3f color = ramp(noise); // Define the color
            img2D8.draw_point(col, row, (float*)&color);
        }
    }
//  img2D8.save("map2D8.bmp");
    CImgDisplay disp2D8(img2D8, "2D Simplex Perlin noise (8 octaves)");
    disp2D8.move(10, 30);    
*/

    CImg<float> img(800, 480, 1, 3); // Define a 800x400 color image with a float value per color component.
    CImgDisplay disp(img, "2D Simplex Perlin noise");
    disp.move(10, 30);

    while (!disp.is_closed()) {
        const SimplexNoise simplex(1.0f/scale, 0.5f);   // Amplitude of 0.5 for the 1st octave : sum ~1.0f
        const int octaves = static_cast<int>(2 + std::log(scale)); // Estimate number of octaves needed for the current scale
        std::cout << "octaves=" << octaves << "\n";
        for (int row = 0; row < img.height(); ++row) {
            const float y = static_cast<float>(row + offset_y);
            for (int col = 0; col < img.width(); ++col) {
                const float x = static_cast<float>(col + offset_x);
                
                // Get the noise value for the coordinate
                const float noise = simplex.fractal(octaves, x, y);
                const color3f color = ramp(noise); // convert to color
                img.draw_point(col, row, (float*)&color);
            }
        }
        disp.display(img);

        disp.wait();
        if (disp.wheel()) {
            // TODO center image instead of focus on the left/up corner
            const int dx = disp.mouse_x() - disp.width() / 2;
            const int dy = disp.mouse_y() - disp.height() / 2;
            std::cout << "wheel=" << disp.wheel() << " mouse[" << disp.mouse_x() << "," << disp.mouse_y() << "]\n";
            std::cout << "scale=" << scale << " offset[" << offset_x << "," << offset_y << "]\n";
            if (disp.wheel() > 0) {
                scale *= (1.f + 0.1f*disp.wheel());
                /* TODO
                offset_x += disp.mouse_x();
                offset_y += disp.mouse_y();
                offset_x -= static_cast<int>(0.1f * scale);
                offset_y -= static_cast<int>(0.1f * scale);
                */
            }
            else {

                scale *= (1.f + 0.1f*std::min(disp.wheel(),10));
                /* TODO
                scale = 400.f;
                offset_x = 0;
                offset_y = 0;
                */
            }
            std::cout << "scale=" << scale << " offset[" << offset_x << "," << offset_y << "]\n";
            disp.set_wheel(); // Reset the wheel value to 0.
        }
        if (disp.button() & 1) { // Left button clicked.
            std::cout << "mouse[" << disp.mouse_x() << "," << disp.mouse_y() << "]\n";
            std::cout << "scale=" << scale << " offset[" << offset_x << "," << offset_y << "]\n";
        }
        if (cimg::keyESC == disp.key()) {
            disp.close();
        }
    }

    return 0;
}
