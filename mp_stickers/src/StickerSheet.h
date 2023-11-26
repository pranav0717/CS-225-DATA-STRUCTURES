/**
 * @file StickerSheet.h
 * Contains your declaration of the interface for the StickerSheet class.
 */
#pragma once
#include "cs225/PNG.h"
#include <vector>
#include <iostream>
#include "Image.h"
using namespace std;

class StickerSheet
{
    public:
    StickerSheet(const Image &picture, unsigned max);
    StickerSheet(const StickerSheet &other);
    ~StickerSheet();
    const StickerSheet & operator=(const StickerSheet &other);
    void changeMaxStickers(unsigned max);
    int addSticker(Image &sticker, int x, int y);
    int layers()const;
    int setStickerAtLayer (Image &sticker, unsigned layer, int x, int y);
    bool translate(unsigned index, int x, int y);
    void removeSticker(unsigned index);
    Image *getSticker(unsigned index) const;
    Image render() const;
    void copy(const StickerSheet &other);
    
    private: 
    vector <Image*> stickerss;
    vector <int>  x_location;
    vector <int> y_location;

    Image picbase;
    unsigned limit;

};

