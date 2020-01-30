
#include "block.h"

// set values in data attribute, based on a dimension x dimension square region
  //   with upper-left corner at (left, upper) in the input PNG image
  // The orientation of the pixels in the data vector must match the orientation
  //   of the pixels in the PNG.
  // PRE: upper and left (and upper + dimension, left + dimension) are valid
  //        vector indices
  void Build(PNG& im, int upper, int left, int dimension) {
	  
	  
  }
  
  
    // write the pixel colour data fom data attribute into im,
  //   with upper-left corner at (left, upper)
  // PRE: upper and left (and upper + dimension, left + dimension) are valid
  //        vector indices
  void Render(PNG& im, int upper, int left) const {
	  
	  
  }
  
  
    // "Reverse" the Hue and Luminance channels for each pixel in the data attribute
  //   to simulate a photo-negative effect.
  // Refer to the HSLAPixel documentation to determine an appropriate transformation
  //   for "reversing" hue and luminance.
  void Negative() {
	  
  }
  
    // Return the horizontal (or vertical) size of the data block's image region
  int  Dimension() const {
	  
  }
  
    // 2D container for pixel data
  // Be aware that a newly declared vector has a size of 0
  vector<vector<HSLAPixel>> data {
	  
  }
