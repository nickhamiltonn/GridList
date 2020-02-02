// File:        gridlist.cpp
// Date:        2020-01-18 00:11
// Description: Contains partial implementation of GridList class
//              CPSC 221 2019W2 PA1
//              Function bodies to be completed by yourselves
//
// ADD YOUR FUNCTION IMPLEMENTATIONS IN THIS FILE
//

//Swag
//Nicks Swag

#include "gridlist.h"
#include "gridlist_given.cpp"

// Creates a PNG of appropriate pixel dimensions according to the GridList's structure
//   and colours each pixel according the each GridNode's Block data.
// The fully coloured PNG is returned.
PNG GridList::Render() const
{
  PNG image;
  // enter your code here
  return image;
}

// Allocates a new GridNode containing bdata and
//   attaches it to end of this list.
// Be careful of the special case of inserting into an empty list.
void GridList::InsertBack(const Block& bdata)
{
  // enter your code here
}

// if this list has an odd number of column blocks, then the right side will have more blocks
// PRE:  this list and inner are not the same physical list
//       this list must have at least two column blocks
//       inner list must have at least one column block
//       inner list must have the same vertical resolution, vertical block dimension, and block size
// POST: this list has nodes of the entire inner list in between the left and right halves of this list
//         and inner list becomes empty
//       otherwise both lists are not modified
// THIS MUST BE ACHIEVED USING POINTER REASSIGNMENTS.
// DO NOT ALLOCATE OR DELETE ANY NODES IN THIS FUNCTION.
void GridList::Sandwich_H(GridList& inner)
{
  // enter your code here
}

// inner list must have the same horizontal resolution, horizontal block dimension, and block size
// if this list has an odd number of row blocks, then the bottom side will have more blocks
// PRE:  this list and inner are not the same physical list
//       this list must have at least two row blocks
//       inner list must have at least one row block
//       inner list must have same horizontal resolution, horizontal block dimension, and block size
// POST: this list has nodes of the entire inner list in between the upper and lower halves of this list
//         and inner list becomes empty
//       otherwise both lists are not modified
// THIS MUST BE ACHIEVED USING POINTER REASSIGNMENTS.
// DO NOT ALLOCATE OR DELETE ANY NODES IN THIS FUNCTION.
void GridList::Sandwich_V(GridList& inner)
{
  // enter your code here
}


// PRE:  this list and otherlist have the same pixel dimensions, block dimensions, and block size
// POST: this list and otherlist are checkered with each other's nodes
//       each list's dimensions remain the same
// THIS MUST BE ACHIEVED USING POINTER REASSIGNMENTS.
// DO NOT ALLOCATE OR DELETE ANY NODES IN THIS FUNCTION.
void GridList::CheckerSwap(GridList& otherlist)
{
  // enter your code here
}

// POST: this list has the negative effect applied selectively to GridNodes to form
//         a checkerboard pattern.
//       The northwest block is normal (does not have the negative effect applied).
// Ensure that the checkering looks correct for both odd and even horizontal block dimensions
void GridList::CheckerN()
{
  // get starting node
  GridNode* node = northwest;
  
  // fist node is uneffected and figure out if the size is nxn or nxm
  bool makeNeg = false;
  bool square;
  if (dimx == dimy) {
	square = true;
  } else {
	square = false;
  }
  
  int count = 1;
  
  // itterate through each eliment
  while (node != NULL) {
	if (makeNeg) {
		Block negBlock = node -> data;
		negBlock.Negative();
		node -> data = negBlock;
	}
	
	// determine if next block modifcation
	if (square || count != dimx) {
		makeNeg = !makeNeg;
	} else {
		count = 1;
	}
	
	count++;
	node = node -> next;
  }
 
}

// Deallocates any dynamic memory associated with this list
//   and re-initializes this list to an empty state
void GridList::Clear()
{
  // enter your code here
  //still need to check if there even is something to start
  //also need to change size, north and south pointers to null. 

  while (northwest->next != NULL) {
    northwest->prev = NULL;
    delete northwest;
    northwest = northwest->next;
    northwest->prev->next = NULL;
  }

  northwest->prev = NULL;
  delete northwest;



}

// Allocates new nodes into this list as copies of all nodes from otherlist
void GridList::Copy(const GridList& otherlist)
{
  // keep reference to start
  GridNode* node = northwest;
  
  // empty current list
  Clear();
  
  // fills up with new array on nodes
  GridNode* nodeC = otherlist.northwest;
  northwest = nodeC; // make northwest of GridList be first GridNode of other list
  while (nodeC != NULL) {
	  InsertBack(nodeC -> data);
	  nodeC = nodeC -> next;
  }
  
  // make northwest of GridList be first GridNode of other list
  southeast = nodeC; 
  
  dimx = otherlist.dimx;
  dimy = otherlist.dimy;
}

// IMPLEMENT ANY PRIVATE FUNCTIONS YOU HAVE ADDED BELOW
//
//
