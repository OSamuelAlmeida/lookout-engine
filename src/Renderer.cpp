#include "Renderer.h"

#include <CoreText/CoreText.h>

void Renderer::drawText(CGContextRef context, const std::string &text, CGFloat x, CGFloat y)
{
    CGContextSaveGState(context);

    // Convert std::string to CFStringRef
    CFStringRef stringRef = CFStringCreateWithCString(kCFAllocatorDefault, text.c_str(), kCFStringEncodingUTF8);

    // Create a font
    CTFontRef fontRef = CTFontCreateWithName(CFSTR("Helvetica"), 24, NULL);

    // Create an attributes dictionary with the font
    CFDictionaryRef attributes = CFDictionaryCreate(NULL, (const void **)&kCTFontAttributeName,
                                                    (const void **)&fontRef, 1,
                                                    &kCFTypeDictionaryKeyCallBacks,
                                                    &kCFTypeDictionaryValueCallBacks);

    // Create an attributed string
    CFAttributedStringRef attrString = CFAttributedStringCreate(NULL, stringRef, attributes);

    // Create a frame setter
    CTFramesetterRef frameSetter = CTFramesetterCreateWithAttributedString(attrString);
    CFRange range = CFRangeMake(0, CFAttributedStringGetLength(attrString));
    CGSize textSize = CTFramesetterSuggestFrameSizeWithConstraints(frameSetter, range, NULL, CGSizeMake(CGFLOAT_MAX, CGFLOAT_MAX), NULL);

    // Create a text matrix adjusted for the flipped context
    CGAffineTransform flipVertical = CGAffineTransformMake(1, 0, 0, -1, 0, textSize.height);
    CGContextSetTextMatrix(context, flipVertical);

    // Create a path for the text
    CGMutablePathRef path = CGPathCreateMutable();
    CGRect bounds = CGRectMake(x, y + 2 * textSize.height, textSize.width, textSize.height);
    CGPathAddRect(path, NULL, bounds);

    // Create a frame and draw the text
    CTFrameRef frame = CTFramesetterCreateFrame(frameSetter, CFRangeMake(0, 0), path, NULL);
    CTFrameDraw(frame, context);

    // Clean up
    CFRelease(frame);
    CFRelease(path);
    CFRelease(frameSetter);
    CFRelease(attrString);
    CFRelease(attributes);
    CFRelease(fontRef);
    CFRelease(stringRef);
    CGContextRestoreGState(context);
}
