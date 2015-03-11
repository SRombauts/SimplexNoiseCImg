
#include <cstdint>

class color3f
{
public:
   color3f();
   color3f(uint8_t _r, uint8_t _g, uint8_t _b);

public:
   float r;
   float g;
   float b;
};

inline float lerp(float x, float y, float a)
{
    return (1 - a) * x + a * y;
}

inline float lerp(float x,  float y,
                  float ax, float ay, float a)
{
    return (ay - a)/(ay - ax) * x
         + (a - ax)/(ay - ax) * y;
}

color3f lerp(color3f x, color3f y, float a);
color3f lerp(color3f x, color3f y,
             float  ax, float  ay, float a);

/**
 * @param[in] noise [-1; 1]
 *
 * @return color
 */
color3f ramp(float noise);
