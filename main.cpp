#include <iostream>
#include <sstream>
#include <cstdint>
#include <algorithm>
#include <cmath>
#include <chrono> // NOLINT(build/c++11)

#include "SimplexNoise/src/SimplexNoise.h"

#include "color.h"
#include "img.h"

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
    float offset_x  = 0.0f;
    float offset_y  = 0.0f;
    float offset_z  = 0.0f;
    float lacunarity = 2.0f;
    float persistance = 0.5f;
/*
    float lacunarity = 1.55f;
    float persistance = 0.65f;
*/    
    // TODO NOCOMMIT :
    float min;
    float max;

    Img img;

    while (!img.is_closed()) {
        Measure measure;
        measure.start();
        const SimplexNoise simplex(1.0f/scale, 0.5f, lacunarity, persistance);   // Amplitude of 0.5 for the 1st octave : sum ~1.0f
        const int octaves = static_cast<int>(2 + std::log(scale)); // Estimate number of octaves needed for the current scale
        std::ostringstream title;
        title << "2D Simplex Perlin noise (" << octaves << " octaves)";
        img.set_title(title.str().c_str());
        for (int row = 0; row < img.height(); ++row) {
            const float y = static_cast<float>(row - img.height()/2 + offset_y*scale);
            for (int col = 0; col < img.width(); ++col) {
                const float x = static_cast<float>(col - img.width()/2 + offset_x*scale);
                
                // TODO(SRombauts): Generate "biomes", ie smooth geographic variation in frequency & amplitude 
                // TODO(SRombauts): Add 'erosion' with simple smoothing like exponential
            //  const float biome = SimplexNoise::noise(x, y);
            //  const float noise = 0.5f * biome + 0.5f * simplex.fractal(octaves, x, y) + offset_z;
                // Get the noise value for the coordinate
                const float noise = simplex.fractal(octaves, x, y) + offset_z;
                min = std::min(min, noise);
                max = std::min(max, noise);
                const color3f color = ramp(noise); // convert to color
                img.draw_point(col, row, (float*)&color);
            }
        }
        img.display();
        const double diff_ms = measure.get();
        std::cout << std::fixed << diff_ms << "ms - ";
        std::cout << "minmax[" << min << "," << max << "]\n";

        img.user(scale, offset_x, offset_y, offset_z, lacunarity, persistance);
    }

    return 0;
}
