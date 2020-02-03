#include "block.h"
#include <vector>
#include <iostream>
#include "cs221util/PNG.h"
#include "cs221util/HSLAPixel.h"

using namespace std;
using namespace cs221util;

	int size;

  // set values in data attribute, based on a dimension x dimension square region
  //   with upper-left corner at (left, upper) in the input PNG image
  // The orientation of the pixels in the data vector must match the orientation
  //   of the pixels in the PNG.
  // PRE: upper and left (and upper + dimension, left + dimension) are valid
  //        vector indices
  void Block::Build(PNG& im, int upper, int left, int dimension) {
	  // (0,0) is upper left corner of entire image
	  size = 0;
	  
	  // Iterate through every pixel in defined square
	  for (int x = 0; x < (left + dimension); x++) {
		  vector<HSLAPixel> column;
		  if (x >= left) {
			for (int y = 0; y < (upper + dimension); y++) {
			  
			  // add pixel to vector
			  HSLAPixel * pixel = new HSLAPixel();
			  
			  if (y >= upper) {
				pixel = im.getPixel(x, y);  
			  }
			  
			  column.push_back(*pixel);
		    }
			size++;	
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
	  printf("Im in!");
	int dimension = size;
	
	printf("powp pow");
	for (int width = left; width < (left + dimension); width++) {
	  // read column from vector
	  vector<HSLAPixel> column = data.at(width);
	  printf("peep");
      for (int height = upper; height < (upper + dimension); height++) {
        HSLAPixel* currPixelI = im.getPixel(width, height);
        HSLAPixel currPixelD = column.at(height);
		
		// give png pixel from vector
		*currPixelI = currPixelD;
        //*(imageData_ + (upper - height) = currPixelD;
      }
    }
	printf("done here");
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
    return size;
  }
