cmake_minimum_required (VERSION 2.6)
project (CImgTest)

add_executable (CImgTest main.cpp CImg.h)
if (UNIX)
    target_link_libraries (CImgTest X11 pthread)
endif (UNIX)