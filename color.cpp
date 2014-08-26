#include "color.h"


color3f::color3f()
{
    r = 0.f;
    g = 0.f;
    b = 0.f;
}

color3f::color3f(uint8_t _r, uint8_t _g, uint8_t _b)
{
    r = _r/256.f;
    g = _g/256.f;
    b = _b/256.f;
}

color3f lerp(color3f x, color3f y, float a)
{
    color3f color;
    color.r = lerp(x.r, y.r, a);
    color.g = lerp(x.g, y.g, a);
    color.b = lerp(x.b, y.b, a);
    return color;
}

color3f lerp(color3f x, color3f y, float ax, float ay, float a)
{
    color3f color;
    color.r = lerp(x.r, y.r, ax, ay, a);
    color.g = lerp(x.g, y.g, ax, ay, a);
    color.b = lerp(x.b, y.b, ax, ay, a);
    return color;
}

/**
 * @param[in] noise [-1; 1]
 * @param[in] color
 * @see http://www.blitzbasic.com/codearcs/codearcs.php?code=2415
 */
void ramp(float noise, color3f& color)
{
    static const color3f DarkBlue   (   2,  43,  68 ); // dark blue: deep water
    static const color3f DeepBlue   (   9,  62,  92 ); // deep blue: water
    static const color3f Blue       (  17,  82, 112 ); // blue: shallow water
    static const color3f LightBlue  (  69, 108, 118 ); // light blue: shore
    static const color3f Green      (  42, 102,  41 ); // green: grass
    static const color3f LightGreen ( 115, 128,  77 ); // light green: veld
    static const color3f Brown      ( 153, 143,  92 ); // brown: tundra
    static const color3f Grey       ( 179, 179, 179 ); // grey: rocks
    static const color3f White      ( 255, 255, 255 ); // white: snow

    if (noise     < -0.500f)
    {
        color = lerp(DarkBlue, DeepBlue, -1.000f, -0.500f, noise);
    }
    else if(noise < -0.020f)
    {
        color = lerp(DeepBlue, Blue,     -0.500f, -0.020f, noise);
    }
    else if(noise < -0.000f)
    {
        color = lerp(Blue, LightBlue,    -0.020f, 0.000f, noise);
    }
    else if(noise < 0.005f)
    {
        color = lerp(LightGreen, Green,   0.000f, 0.005f, noise);
    }
    else if(noise < 0.500f)
    {
        color = lerp(Green, LightGreen,   0.005f, 0.500f, noise);
    }
    else if(noise < 0.700f)
    {
        color = lerp(LightGreen, Brown,   0.500f, 0.700f, noise);
    }
    else if(noise < 0.900f)
    {
        color = lerp(Brown, Grey,         0.700f, 0.900f, noise);
    }
    else
    {
        color = lerp(Grey, White, 0.900f, 1.000f, noise);
    }
}
