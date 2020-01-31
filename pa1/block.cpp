#include "block.h"
#include <vector>
#include <iostream>
#include "cs221util/PNG.h"
#include "cs221util/HSLAPixel.h"

using namespace std;
using namespace cs221util;

// set values in data attribute, based on a dimension x dimension square region
  //   with upper-left corner at (left, upper) in the input PNG image
  // The orientation of the pixels in the data vector must match the orientation
  //   of the pixels in the PNG.
  // PRE: upper and left (and upper + dimension, left + dimension) are valid
  //        vector indices
  void Build(PNG& im, int upper, int left, int dimension) {
	  // (0,0) is upper left corner of entire image
	  
	  // Iterate through every pixel in defined square
	  for (int x = left; x < (left + dimension); x++) {
		  vector<HSLAPixel> column;
		  for (int y = upper; y < (upper + dimension); y++) {
			  // add pixel to vector
			  HSLAPixel * pixel = im::getPixel(x, y);
			  column.push_back(pixel);
		  }
		  // add column to image
		  data.push_back(column);
	  }

  }


    // write the pixel colour data fom data attribute into im,
  //   with upper-left corner at (left, upper)
  // PRE: upper and left (and upper + dimension, left + dimension) are valid
  //        vector indices
  //am I able to just change imageDataArray cause its private?

  void Render(PNG& im, int upper, int left) const {
    //see if this condition for for loop makes sense
    //ask the fuckn boys for this one
    //ye
    for (int height = 0; height < Block.Dimension(); height++) {
      for (int width = 0; width < Block.Dimension(); width++) {
        HSLAPixel* currPixel = getPixel(upper + height, left + width);
        *currPixel = data[height][width];
        //*(imageData_ + (upper - height) = data[height][width];
      }
    }
  }


    // "Reverse" the Hue and Luminance channels for each pixel in the data attribute
  //   to simulate a photo-negative effect.
  // Refer to the HSLAPixel documentation to determine an appropriate transformation
  //   for "reversing" hue and luminance.
  void Negative() {



  }

    // Return the horizontal (or vertical) size of the data block's image region
  int  Dimension() const {
    return data.size();
  }

    // 2D container for pixel data
  // Be aware that a newly declared vector has a size of 0
  vector<vector<HSLAPixel>> data {

  }
