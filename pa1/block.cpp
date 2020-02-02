#include "block.h"
#include <vector>
#include <iostream>
#include "cs221util/PNG.h"
#include "cs221util/HSLAPixel.h"

using namespace std;
using namespace cs221util;

  // 2D container for pixel data
  vector<vector<HSLAPixel>> data;

  // set values in data attribute, based on a dimension x dimension square region
  //   with upper-left corner at (left, upper) in the input PNG image
  // The orientation of the pixels in the data vector must match the orientation
  //   of the pixels in the PNG.
  // PRE: upper and left (and upper + dimension, left + dimension) are valid
  //        vector indices
  void Block::Build(PNG& im, int upper, int left, int dimension) {
	  // (0,0) is upper left corner of entire image
	  
	  // Iterate through every pixel in defined square
	  for (int x = left; x <= (left + dimension); x++) {
		  vector<HSLAPixel> column;
		  for (int y = upper; y <= (upper + dimension); y++) {
			  
			  // add pixel to vector
			  HSLAPixel * pixel = im.getPixel(x, y);
			  column.push_back(*pixel);
		  }
		  // add column to image
		  data.push_back(column);
	  }

  }


  // write the pixel colour data fom data attribute into im,
  //   with upper-left corner at (left, upper)
  // PRE: upper and left (and upper + dimension, left + dimension) are valid
  //        vector indices
  void Block::Render(PNG& im, int upper, int left) const
  {
	  // Can change data array because it is private to this class
    // start at top left corner and go to width and height of dimention
	for (int width = left; width <= (left + dimension); width++) {
	  // read column from vector
	  vector<HSLAPixel> column = data.at(width);
	  
      for (int height = upper; height <= (upper + dimension); height++) {
        HSLAPixel* currPixelI = im.getPixel(width, height);
        HSLAPixel currPixelD = column.at(height);
		
		// get color from pixelD and put into color for pixelI (I don't know exactly what is supposed to happen!)
		// But i did get each pixel in image and equvanlent in vector in defined range
        //*(imageData_ + (upper - height) = currPixelD;
      }
    }
  }


  // "Reverse" the Hue and Luminance channels for each pixel in the data attribute
  //   to simulate a photo-negative effect.
  // Refer to the HSLAPixel documentation to determine an appropriate transformation
  //   for "reversing" hue and luminance.
  void Block::Negative() {



  }

  // Return the horizontal (or vertical) size of the data block's image region
  int Block::Dimension() const 
  {
    return (int)data.size();
  }
