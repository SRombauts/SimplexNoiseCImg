#include "CImg.h"
using namespace cimg_library;

#include "img.h"

#include <iostream>
#include <algorithm>

/// Pimpl of CImg to reduce compile time
class ImgImpl {
public:
    ImgImpl() :
        img(1024, 600, 1, 3), // Define a 800x400 color image with a float value per color component.
        disp(img, "2D Simplex Perlin noise", 0)
    {
        disp.move(10, 30);
    }

    CImg<float> img;
    CImgDisplay disp;
};

/// Encapsulation of CImg to reduce compile time
Img::Img() :
    mImgImpl(*(new ImgImpl())) {
}

bool Img::is_closed() const {
    return mImgImpl.disp.is_closed();
}


void Img::set_title(const char* title) {
    mImgImpl.disp.set_title(title);
}

void Img::draw_point(int col, int row, float* color) {
    mImgImpl.img.draw_point(col, row, color);
}

void Img::display() {
    mImgImpl.disp.display(mImgImpl.img);
}

void Img::user(float& scale, float& offset_x, float& offset_y, float& offset_z, float& lacunarity, float& persistance) {
    int last_mouse_x = 0;
    int last_mouse_y = 0;

    mImgImpl.disp.wait();
    if (mImgImpl.disp.wheel()) {
        std::cout << "wheel=" << mImgImpl.disp.wheel() << " mouse[" << mImgImpl.disp.mouse_x() << "," << mImgImpl.disp.mouse_y() << "]\n";
        std::cout << "scale=" << scale << " offset[" << offset_x << "," << offset_y << "]\n";
        if (mImgImpl.disp.wheel() > 0) {
            scale *= (1.f + 0.1f*mImgImpl.disp.wheel());
            /* TODO(SRombauts): add offset based on mouse position
            offset_x -= static_cast<int>(0.1f * scale);
            offset_y -= static_cast<int>(0.1f * scale);
            */
        }
        else {
            scale *= (1.f + 0.090909090909f*std::min(mImgImpl.disp.wheel(), 10));
        }
        std::cout << "scale=" << scale << " offset[" << offset_x << "," << offset_y << "]\n";
        mImgImpl.disp.set_wheel(); // Reset the wheel value to 0.
    }
    if (mImgImpl.disp.button() & 1) { // Left button clicked.
        // drag window with mouse drag
        std::cout << "mouse[" << mImgImpl.disp.mouse_x() << "," << mImgImpl.disp.mouse_y() << "]\n";
        if ((last_mouse_x != 0) || (last_mouse_y != 0)) {
            offset_x -= (mImgImpl.disp.mouse_x() - last_mouse_x);
            offset_y -= (mImgImpl.disp.mouse_y() - last_mouse_y);
        }
        last_mouse_x = mImgImpl.disp.mouse_x();
        last_mouse_y = mImgImpl.disp.mouse_y();
    }
    else {
        last_mouse_x = 0;
        last_mouse_y = 0;
    }
    switch (mImgImpl.disp.key()) {
    // Offset X
    case cimg::keyQ:
    case cimg::keyARROWLEFT:
        offset_x -= 100.f/scale;
        break;
    case cimg::keyD:
    case cimg::keyARROWRIGHT:
        offset_x += 100.f/scale;
        break;
    // Offset Y
    case cimg::keyZ:
    case cimg::keyARROWUP:
        offset_y -= 100.f/scale;
        break;
    case cimg::keyS:
    case cimg::keyARROWDOWN:
        offset_y += 100.f/scale;
        break;
    // Zoom
    case cimg::keyA:
    case cimg::keyPAGEUP:
        scale *= 0.833333333333333f;
        break;
    case cimg::keyE:
    case cimg::keyPAGEDOWN:
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
        mImgImpl.disp.close();
        break;
    }
    std::cout << "scale=" << scale << " offset[" << offset_x << "," << offset_y << "]\n";
    std::cout << "lacunarity=" << lacunarity << " persistance=" << persistance << "\n";
}

int Img::height() const {
    return mImgImpl.img.height();
}

int Img::width() const {
    return mImgImpl.img.width();
}


