#include "CImg.h"
using namespace cimg_library;

#include <cstdint>
#include <fstream>

#include "SimplexNoise/SimplexNoise.h"

/**
 * @param[in] noise [-1; 1]
 * @param[in] pColor
 * @see http://www.blitzbasic.com/codearcs/codearcs.php?code=2415
 */
void ramp(float noise, const float*& pColor)
{
    static const float DarkBlue[3]  = {   2 / 256.f,  43 / 256.f,  68 / 256.f }; // dark blue: deep water
    static const float DeepBlue[3]  = {   9 / 256.f,  62 / 256.f,  92 / 256.f }; // deep blue: water
    static const float Blue[3]      = {  17 / 256.f,  82 / 256.f, 112 / 256.f }; // blue: shallow water
    static const float LightBlue[3] = {  69 / 256.f, 108 / 256.f, 118 / 256.f }; // light blue: shore
    static const float Green[3]     = {  42 / 256.f, 102 / 256.f,  41 / 256.f }; // green: grass
    static const float LightGreen[3]= { 115 / 256.f, 128 / 256.f,  77 / 256.f }; // light green: veld
    static const float Brown[3]     = { 153 / 256.f, 143 / 256.f,  92 / 256.f }; // brown: tundra
    static const float Grey[3]      = { 179 / 256.f, 179 / 256.f, 179 / 256.f }; // grey: rocks
    static const float White[3]     = { 255 / 256.f, 255 / 256.f, 255 / 256.f }; // white: snow

    if (noise     < -0.500f)
    {
        pColor = DarkBlue;
    }
    else if(noise < -0.020f)
    {
        pColor = DeepBlue;
    }
    else if(noise < -0.000f)
    {
        pColor = Blue;
    }
    else if(noise < 0.002f)
    {
        pColor = Green;
    }
    else if(noise < 0.500f)
    {
        pColor = LightGreen;
    }
    else if(noise < 0.700f)
    {
        pColor = Brown;
    }
    else if(noise < 0.900f)
    {
        pColor = Grey;
    }
    else
    {
        pColor = White;
    }
}


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

	CImg<float> img2D(600, 600, 1, 3);   // Define a 600x600 color image with a float value per color component.
	img2D.fill(0.f);                        // Set pixel values to 0 (color : black)

    for(int row = 0; row < img2D.height(); ++row)
	{
		for(int col = 0; col < img2D.width(); ++col)
		{
            float noise = SimplexNoise::noise(col / 60.f, row / 60.f);                   // Get the noise value for the coordinate
			const float* pColor = nullptr;
            ramp(noise, pColor); // Define the color
            img2D.draw_point(col, row, pColor);
		}
	}
	img2D.display("2D noise");            // Display the image in a display window.
//  img2D.save("map2D.bmp");

	return 0;
}
