/**
 *  @filename   :   main.cpp
 *  @brief      :   4.2inch e-paper display demo
 *  @author     :   Yehui from Waveshare
 *
 *  Copyright (C) Waveshare     July 31 2017
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documnetation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to  whom the Software is
 * furished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include "epd4in2.h"
#include "epdpaint.h"
#include "imagedata.h"

#define COLORED      1
#define UNCOLORED    0

int main(void)
{
    Epd epd;
    if (epd.Init() != 0) {
        printf("e-Paper init failed\n");
        return -1;
    }

    unsigned char* frame_buffer = (unsigned char*)malloc(epd.width / 8 * epd.height);

    Paint paint(frame_buffer, epd.width, epd.height);
    paint.Clear(UNCOLORED);

    /* Draw something to the frame_buffer */
    /* For simplicity, the arguments are explicit numerical coordinates */
    paint.DrawRectangle(20, 80, 180, 280, COLORED);
    paint.DrawLine(20, 80, 180, 280, COLORED);
    paint.DrawLine(180, 80, 20, 280, COLORED);
    paint.DrawFilledRectangle(200, 80, 360, 280, COLORED);
    paint.DrawCircle(300, 160, 60, UNCOLORED);
    paint.DrawFilledCircle(90, 210, 30, COLORED);

    /*Write strings to the buffer */
    paint.DrawFilledRectangle(0, 6, 400, 30, COLORED);
    paint.DrawStringAt(100, 10, "Hello world!", &Font24, UNCOLORED);
    paint.DrawStringAt(100, 40, "e-Paper Demo", &Font24, COLORED);

    /* Display the frame_buffer */
    epd.DisplayFrame(frame_buffer);

    /* Display the image buffer */
    epd.DisplayFrame(IMAGE_BUTTERFLY);
    return 0;
}

