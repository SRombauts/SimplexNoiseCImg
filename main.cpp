#include "CImg.h"
using namespace cimg_library;

#include <iostream>
#include <sstream>
#include <cstdint>
#include <algorithm>
#include <cmath>
#include <chrono> // NOLINT(build/c++11)

#include "SimplexNoise/src/SimplexNoise.h"

#include "color.h"

/// Time measure using C++11 std::chrono
class Measure {
public:
    /// Start a time measure
    void start() {
        // std::chrono::steady_clock would be more stable, but does not exist in Travis CI GCC 4.6
        mStartTime = std::chrono::high_resolution_clock::now();
    }
    /// Get time elapsed since first time measure
    double get() {
        auto diffTime = (std::chrono::high_resolution_clock::now() - mStartTime);
        return std::chrono::duration<double, std::milli>(diffTime).count();
    }

private:
    std::chrono::high_resolution_clock::time_point   mStartTime; ///< Store the first time measure
};


int main() {
    float scale     = 400.f;
	float offset_x	= 0.0f;
    float offset_y  = 0.0f;
    float offset_z  = 0.0f;
    int last_mouse_x = 0;
    int last_mouse_y = 0;
    float lacunarity = 2.0f;
    float persistance = 0.5f;

    CImg<float> img(800, 480, 1, 3); // Define a 800x400 color image with a float value per color component.
    CImgDisplay disp(img, "2D Simplex Perlin noise");
    disp.move(10, 30);

    while (!disp.is_closed()) {
        Measure measure;
        measure.start();
        const SimplexNoise simplex(1.0f/scale, 0.5f, lacunarity, persistance);   // Amplitude of 0.5 for the 1st octave : sum ~1.0f
        const int octaves = static_cast<int>(2 + std::log(scale)); // Estimate number of octaves needed for the current scale
		std::ostringstream title;
		title << "2D Simplex Perlin noise (" << octaves << " octaves)";
		disp.set_title(title.str().c_str());
        for (int row = 0; row < img.height(); ++row) {
			const float y = static_cast<float>(row - img.height()/2 + offset_y*scale);
            for (int col = 0; col < img.width(); ++col) {
				const float x = static_cast<float>(col - img.width()/2 + offset_x*scale);
                
                // TODO(SRombauts): Add some height offset for more realistic results (use a basic noise for this)
                // TODO(SRombauts): Generate "biomes", ie smooth geographic variation in frequency & amplitude 
                // TODO(SRombauts): Add 'erosion' with simple smoothing like exponential
                // Get the noise value for the coordinate
                const float noise = simplex.fractal(octaves, x, y) + offset_z;
                const color3f color = ramp(noise); // convert to color
                img.draw_point(col, row, (float*)&color);
            }
        }
        disp.display(img);
        const double diff_ms = measure.get();
        std::cout << std::fixed << diff_ms << "ms\n";

        disp.wait();
        if (disp.wheel()) {
            std::cout << "wheel=" << disp.wheel() << " mouse[" << disp.mouse_x() << "," << disp.mouse_y() << "]\n";
            std::cout << "scale=" << scale << " offset[" << offset_x << "," << offset_y << "]\n";
            if (disp.wheel() > 0) {
                scale *= (1.f + 0.1f*disp.wheel());
                /* TODO(SRombauts): add offset based on mouse position
                offset_x -= static_cast<int>(0.1f * scale);
                offset_y -= static_cast<int>(0.1f * scale);
                */
            }
            else {
				scale *= (1.f + 0.090909090909f*std::min(disp.wheel(), 10));
            }
            std::cout << "scale=" << scale << " offset[" << offset_x << "," << offset_y << "]\n";
            disp.set_wheel(); // Reset the wheel value to 0.
        }
        if (disp.button() & 1) { // Left button clicked.
            // drag window with mouse drag
            std::cout << "mouse[" << disp.mouse_x() << "," << disp.mouse_y() << "]\n";
            if ((last_mouse_x != 0) || (last_mouse_y != 0)) {
                offset_x -= (disp.mouse_x() - last_mouse_x);
                offset_y -= (disp.mouse_y() - last_mouse_y);
            }
            last_mouse_x = disp.mouse_x();
            last_mouse_y = disp.mouse_y();
        }
        else {
            last_mouse_x = 0;
            last_mouse_y = 0;
        }
        switch (disp.key()) {
		// Offset X
        case cimg::keyQ:
			offset_x -= 100.f/scale;
			break;
		case cimg::keyD:
			offset_x += 100.f/scale;
			break;
        // Offset Y
        case cimg::keyZ:
			offset_y -= 100.f/scale;
			break;
		case cimg::keyS:
			offset_y += 100.f/scale;
			break;
        // Zoom
        case cimg::keyA:
			scale *= 0.833333333333333f;
			break;
		case cimg::keyE:
			scale *= 1.2f;
			break;
        // Lacunarity
        case cimg::keyL:
            lacunarity += 0.1f;
            break;
        case cimg::keyM:
            lacunarity -= 0.1f;
            break;
        // Persistence
        case cimg::keyP:
            persistance += 0.05f;
            break;
        case cimg::keyO:
            persistance -= 0.05f;
            break;
        // Vertical offset
        case cimg::keyI:
            offset_z += 0.05f;
            break;
        case cimg::keyK:
            offset_z -= 0.05f;
            break;
        // Quit
        case cimg::keyESC:
            disp.close();
			break;
		}
        std::cout << "scale=" << scale << " offset[" << offset_x << "," << offset_y << "]\n";
        std::cout << "lacunarity=" << lacunarity << " persistance=" << persistance << "\n";
    }

    return 0;
}
