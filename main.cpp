#include "CImg.h"
using namespace cimg_library;

int main() {
   CImg<unsigned char> img(10, 10, 1, 3);  // Define a 640x400 color image with 8 bits per color component.
   img.fill(0);                            // Set pixel values to 0 (color : black)
   unsigned char purple[] = {255, 0, 255};         // Define a purple color
// img.draw_text(10, 10, "Hello World", purple);   // Draw a purple "Hello world" at coordinates (100,100).
   img.draw_point(0, 0, purple);
   img.draw_line(1, 0, 1, 9, purple);
   img.display("hello");             // Display the image in a display window.
// img.save("hello.png");

   return 0;
}
