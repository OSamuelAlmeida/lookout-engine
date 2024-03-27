#include "Renderer.h"

void Renderer::drawText(CGContextRef context, const std::string &text, CGFloat x, CGFloat y)
{
    CGContextSaveGState(context);

    CFStringRef stringRef = CFStringCreateWithCString(kCFAllocatorDefault, text.c_str(), kCFStringEncodingUTF8);

    CGContextSelectFont(context, "Helvetica", 24, kCGEncodingMacRoman);
    CGContextSetTextDrawingMode(context, kCGTextFill);
    CGContextSetRGBFillColor(context, 0, 0, 0, 1);

    CGContextShowTextAtPoint(context, x, y, CFStringGetCStringPtr(stringRef, kCFStringEncodingUTF8), strlen(CFStringGetCStringPtr(stringRef, kCFStringEncodingUTF8)));

    CFRelease(stringRef);
    CGContextRestoreGState(context);
}
