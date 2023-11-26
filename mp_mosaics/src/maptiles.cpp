/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>

#include "maptiles.h"

using namespace std;


Point<3> convertToXYZ(LUVAPixel pixel) {
    return Point<3>( pixel.l, pixel.u, pixel.v );
}


MosaicCanvas* mapTiles(SourceImage const& sourceImage,
                       vector<TileImage>& tileImages)
{
    MosaicCanvas* resultCanvas = new MosaicCanvas(sourceImage.getRows(), sourceImage.getColumns());

    vector<LUVAPixel> tileColors;
    for (size_t i = 0; i < tileImages.size(); i++) {
        tileColors.push_back(tileImages[i].getAverageColor());
    }
    
    for (int row = 0; row < sourceImage.getRows(); row++) {
        for (int col = 0; col < sourceImage.getColumns(); col++) {
            LUVAPixel pixelColor = sourceImage.getRegionColor(row, col);
            
            int bestTileIndex = 0;
            double bestDistance = getDistance(tileColors[0], pixelColor);
            for (size_t i = 1; i < tileImages.size(); i++) {
                double distance = getDistance(tileColors[i], pixelColor);
                if (distance < bestDistance) {
                    bestTileIndex = i;
                    bestDistance = distance;
                }
            }
            
            resultCanvas->setTile(row, col, &tileImages[bestTileIndex]);
        }
    }
    
    return resultCanvas;
}

double getDistance(LUVAPixel color1, LUVAPixel color2)
{
    double deltaL = color1.l - color2.l;
    double deltaU = color1.u - color2.u;
    double deltaV = color1.v - color2.v;
    return sqrt(deltaL * deltaL + deltaU * deltaU + deltaV * deltaV);
}