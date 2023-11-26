#include "cs225/PNG.h"
#include "StickerSheet.h"
#include "Image.h"
 
 StickerSheet::StickerSheet (const Image &picture, unsigned max)
{
      picbase = Image(picture); 
      limit = max;  
      for(unsigned i = 0; i<max; i++)
      {
        stickerss.push_back(NULL);
        x_location.push_back(0);
        y_location.push_back(0);
      }
}

StickerSheet::~StickerSheet()
{
    return;
}

StickerSheet::StickerSheet(const StickerSheet &other)
{
    copy(other);
}

const StickerSheet & StickerSheet::operator=(const StickerSheet &other)
{
if(this != &other)
{  
    stickerss.clear();
    x_location.clear();
    y_location.clear();
    copy(other);
}
return *this;
}

void StickerSheet::copy(const StickerSheet &other)
{
    limit = other.limit;
    x_location = other.x_location;
    y_location = other.y_location;
    stickerss = other.stickerss;
    picbase = other.picbase;
}


void StickerSheet::changeMaxStickers(unsigned max)
{
   if(max == 0)
    {
    stickerss.clear();
    x_location.clear();
    y_location.clear();
    }
    if(max >= stickerss.size())
    {
        limit = max;
    }
    else
    {
        stickerss.erase(stickerss.begin()+max, stickerss.end());
        x_location.erase(x_location.begin()+max, x_location.end());
        y_location.erase(y_location.begin()+max, y_location.end());
    }
    
}

int StickerSheet:: addSticker(Image &sticker, int x, int y)
{
    for(size_t i=0; i< stickerss.size(); i++)
    {
     if(stickerss.at(i) == NULL)
     {
        // cout<< i<< endl; 
        stickerss.at(i) = (&sticker);
        x_location.at(i) = x;
        y_location.at(i) = y;
        return i;
     }
    }
    stickerss.push_back(&sticker);
    x_location.push_back(x);
    y_location.push_back(y);
    limit++;
    return limit-1;
}

int StickerSheet:: layers() const
{
        return limit;
}
int StickerSheet::setStickerAtLayer (Image &sticker, unsigned layer, int x, int y)
{
        if(layer >= limit)
        {
            return -1;
        }
        else if(layer < 0)
        {
            return -1;
        }
        else
        {
            stickerss.at(layer) = &sticker;
            x_location.at(layer) = x;
            y_location.at(layer) = y;
        }
        return layer;
}

 bool StickerSheet:: translate(unsigned index, int x, int y)
{
     if (index >= stickerss.size() || index <0 || stickerss.at(index)== NULL)
     {
            return false ; 
     } 
     else 
    {
            x_location.at(index) = x;
            y_location.at(index) = y;
            return true; 
    }
} 


void StickerSheet:: removeSticker(unsigned index)
{
    if(index < 0 || index >= limit)
    {
        return;
    }
   stickerss.at(index) = NULL;
   
}

 Image StickerSheet::render() const
 {
  if(stickerss.size() == 0)
  {
    return picbase;
  }
  Image newcanvas = picbase;
  int min_x=0;
  int min_y=0;
  int max_x= picbase.width();
  int max_y= picbase.height();

    for(unsigned i=0; i< stickerss.size(); i++)
    {
        if(stickerss.at(i)!= NULL)
        {
           
            if(y_location.at(i)<min_y)
            {
                min_y=y_location.at(i);
                
            }
            if(x_location.at(i)<min_x)
            {
                min_x=x_location.at(i);
            }
            if(x_location.at(i)+(int)(stickerss.at(i)->width()) > max_x)
            {
                max_x= x_location.at(i)+(int)(stickerss.at(i)->width());
            }
            if(y_location.at(i)+(int)(stickerss.at(i)->height())> max_y)
            {
                max_y= y_location.at(i)+(int)(stickerss.at(i)->height());
            }

        }
    
    } 
    unsigned n_width =(unsigned) ((int) max_x - min_x); 
    unsigned n_height = (unsigned) ((int) max_y - min_y);
   
    Image blank_img(n_width, n_height);


    for(unsigned i=0; i< picbase.width(); i++)
    {
        for(unsigned j=0; j< picbase.height(); j++)
        {
            blank_img.getPixel(i+std::abs(min_x) , j+std::abs(min_y))= picbase.getPixel(i,j);
        }
    }


  for(unsigned i=0; i< stickerss.size(); i++ )
  {
    if(stickerss.at(i) != NULL)
    {
    for(unsigned x=0; x< stickerss.at(i)->width(); x++ )
    {
    for(unsigned y=0; y< stickerss.at(i)->height(); y++ )
    {
        if(stickerss.at(i)->getPixel(x,y).a != 0)
        {
            blank_img.getPixel(x_location.at(i)+x-min_x, y_location.at(i)+y-min_y) = stickerss.at(i)->getPixel(x,y);
        }
    }
    }
    }
  }
    return blank_img;
 }

Image * StickerSheet::getSticker (unsigned index) const
{
if( index < 0 || index >= stickerss.size() || stickerss.at(index)==NULL)
{
    return NULL;
}
return stickerss.at(index);
}
