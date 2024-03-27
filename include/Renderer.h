#pragma once

#include <CoreGraphics/CoreGraphics.h>
#include <string>

class Renderer
{
public:
    void drawText(CGContextRef context, const std::string &text, CGFloat x, CGFloat y);
};