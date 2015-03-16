cmake_minimum_required (VERSION 2.6)
project (CImgTest)

if (NOT MSVC)
    add_definitions (-std=c++0x)  # -std=c++11
endif ()

add_executable (CImgTest
 main.cpp
 color.cpp
 color.h
 img.cpp
 img.h
 CImg.h
 SimplexNoise/src/SimplexNoise.cpp
 SimplexNoise/src/SimplexNoise.h
)
source_group(src FILES main.cpp color.cpp color.h img.cpp img.h)
source_group(cimg FILES CImg.h)
source_group(noise SimplexNoise/src/SimplexNoise.*)


if (UNIX)
    target_link_libraries (CImgTest X11 pthread)
endif (UNIX)
