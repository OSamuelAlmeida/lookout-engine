cmake_minimum_required(VERSION 3.10)
project(LookoutWebRenderer)

set(CMAKE_CXX_STANDARD 17)

find_library(CORE_FOUNDATION CoreFoundation)
find_library(CORE_GRAPHICS CoreGraphics)
find_library(CORE_TEXT CoreText)
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

add_library(LookoutWebRenderer SHARED
    src/HtmlParser.cpp
    src/Renderer.cpp
)

target_link_libraries(LookoutWebRenderer ${CORE_FOUNDATION} ${CORE_GRAPHICS} ${CORE_TEXT})