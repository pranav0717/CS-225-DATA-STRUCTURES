#include "Image.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <algorithm>
#include <iostream>

using cs225::PNG;
using cs225::HSLAPixel;
using namespace std;

void Image :: lighten () 
{ 
    for(unsigned i= 0; i< width(); i++)
    {
        for(unsigned j = 0; j< height(); j++)
        {
            HSLAPixel & pix = getPixel(i, j);
            if (pix.l+ 0.1 > 1) 
            pix.l = 1.0;
            else
            pix.l  += 0.1;

        }
    }
}

void Image :: lighten (double amount) 
{ 
    for(unsigned i= 0; i< width(); i++)
    {
        for(unsigned j=0; j< height(); j++)
        {
            HSLAPixel & pix = getPixel(i, j);
            if (pix.l + amount > 1) 
            pix.l = 1.0;
            else
            pix.l  += amount;
        }
    } 
}

void Image :: darken () 
{ 
    for(unsigned i= 0; i< width(); i++)
    {
        for(unsigned j=0; j< height(); j++)
        {
            HSLAPixel & pix = getPixel(i, j);
            if (pix.l - 0.1 < 0) 
            pix.l = 0;
            else
            pix.l  -= 0.1;
        }
    } 
}


void Image :: darken (double amount) 
{ 
    for(unsigned i= 0; i< width(); i++)
    {
        for(unsigned j=0; j< height(); j++)
        {
            HSLAPixel & pix = getPixel(i, j);
            if (pix.l - amount  < 0) 
            pix.l = 0;
            else
            pix.l  -= amount;
        }
    } 
}

void Image :: saturate () 
{ 
    for(unsigned i= 0; i< width(); i++)
    {
        for(unsigned j=0; j< height(); j++)
        {
            HSLAPixel & pix = getPixel(i, j);
            if (pix.s + 0.1 > 1) 
            pix.s = 1.0;
            else
            pix.s  += 0.1;
        }
    } 
}

void Image :: saturate (double amount) 
{ 
    for(unsigned i= 0; i< width(); i++)
    {
        for(unsigned j=0; j< height(); j++)
        {
            HSLAPixel & pix = getPixel(i, j);
            if (pix.s + amount > 1) 
            pix.s = 1.0;
            else
            pix.s  += amount;
        }
    } 
}

void Image :: desaturate () 
{ 
    for(unsigned i= 0; i< width(); i++)
    {
        for(unsigned j=0; j< height(); j++)
        {
            HSLAPixel & pix = getPixel(i, j);
            if (pix.s - 0.1 < 0) 
            pix.s = 0;
            else
            pix.s  += 0.1;
        }
    } 
}

void Image :: desaturate (double amount) 
{ 
    for(unsigned i= 0; i< width(); i++)
    {
        for(unsigned j=0; j< height(); j++)
        {
            HSLAPixel & pix = getPixel(i, j);
            if (pix.s - amount < 0) 
            pix.s = 0;
            else
            pix.s  -= amount;
        }
    } 
}

void Image :: grayscale () 
{ 
    for(unsigned i= 0; i< width(); i++)
    {
        for(unsigned j=0; j< height(); j++)
        {
            HSLAPixel & pix = getPixel(i, j);
            pix.s = 0.0;
        }
    }
}

void Image :: rotateColor (double degrees)
{
    for(unsigned i= 0; i< width(); i++)
    {
        for(unsigned j=0; j< height(); j++)
        {
            HSLAPixel & pix = getPixel(i, j);
            pix.h += degrees;
            if(pix.h > 360.0)
            pix.h -= 360.0;
            if(pix.h < 0.0)
            pix.h += 360.0;

        }
    }
}

void  Image :: illinify ()
{
    for(unsigned i= 0; i< width(); i++)
    {
        for(unsigned j=0; j< height(); j++)
        {
            HSLAPixel & pix = getPixel(i, j);
            if(pix.h <= 293.5 && pix.h >= 113.5)
            pix.h = 216;
            else
            pix.h = 11;

        }
    }   
}


void Image :: scale (double factor) 
{
     if (factor == 1.0) 
    return;
         Image backup = Image(*this);
         unsigned newImageWidth = width() * factor;
         unsigned newImageHeight = height() * factor;
         resize(newImageWidth, newImageHeight);

    // Iterate through each pixel in the new image
    for (unsigned x = 0; x < newImageWidth; x++) 
    {
        for (unsigned y = 0; y < newImageHeight; y++) 
        {
            HSLAPixel & newPixel = getPixel(x, y);
            HSLAPixel & oldPixel = backup.getPixel(x / factor, y / factor);
            newPixel = oldPixel;
        }
    }
}


void  Image :: scale (unsigned w, unsigned h)
{
    double new_factor_w = (1.0*w)/width(); //typecast 
    double new_factor_h = (h*1.0)/height(); //typecast
    double factor = min(new_factor_w,new_factor_h);
    scale(factor);
}