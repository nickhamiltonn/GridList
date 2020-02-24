// File:        gridlist.cpp
// Date:        2020-01-18 00:11
// Description: Contains partial implementation of GridList class
//              CPSC 221 2019W2 PA1
//              Function bodies to be completed by yourselves
//
// ADD YOUR FUNCTION IMPLEMENTATIONS IN THIS FILE
//

#include "gridlist.h"
#include "gridlist_given.cpp"

// Creates a PNG of appropriate pixel dimensions according to the GridList's structure
//   and colours each pixel according the each GridNode's Block data.
// The fully coloured PNG is returned.
PNG GridList::Render() const
{
  printf("We inside render test\n");

  int height = 0;
  int width = 0;
  GridNode* currNode = northwest;
  PNG image(dimx * currNode->data.Dimension(), dimy * currNode->data.Dimension());

  printf("We starting render loops\n");

  for (int i = 0; i < dimy; i++) {
    for (int j = 0; j < dimx; j++) {
      currNode->data.Render(image, height, width);
      width += currNode->data.Dimension();
      if (currNode->next != NULL) {
        currNode = currNode->next;
      }
    }
    height += currNode->data.Dimension();
    width = 0;
  }

  printf("We finished render loops, about to return\n");
  return image;
}

// Allocates a new GridNode containing bdata and
//   attaches it to end of this list.
// Be careful of the special case of inserting into an empty list.
void GridList::InsertBack(const Block& bdata)
{
  GridNode* newNode = new GridNode(bdata);
  if (northwest == NULL) {
    northwest = newNode;
    southeast = newNode;
    newNode->prev = NULL;
    newNode->next = NULL;
  } else {
    southeast->next = newNode;
    newNode->prev = southeast;
    newNode->next =  NULL;
    southeast = newNode;
  }
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
  //issues with segfaulting in this function

  if (dimy == inner.dimy) {

    int middle = (dimx / 2);

    GridNode* tempBegin = northwest;
    GridNode* tempMiddle = inner.northwest;
    GridNode* tempEnd = inner.northwest;

    printf("We starting the outest loop\n");

    for (int i = 0; i < dimy; i++) {
      printf("We inside the outest loop\n");
      for (int j = 0; j < dimx; j++) {
        printf("%d\n",j);

        if (j = middle - 1) {
          printf("%d\n",j);
          tempEnd->prev = tempBegin;
          for (int x = 0; (x < (inner.dimx - 1)); x++) {
            tempEnd = tempEnd->next;
          }

          if (tempEnd->next != NULL) {
            printf("tempEnd next != NULL \n");
            tempBegin->next->prev = tempEnd;
            tempEnd = tempEnd->next;
            tempEnd->prev->next = tempBegin->next;
            tempBegin = tempBegin->next;
            tempMiddle->prev->next = tempMiddle;
            tempMiddle = tempEnd;
          } else {
              printf("TempEnd next is null\n");
              tempEnd->next = tempBegin->next;
              tempBegin = tempBegin->next;
              tempMiddle->prev->next = tempMiddle;
            }
        } else {
          printf("We moving tempBegin normally\n");

          if (tempBegin->next != NULL) {
            tempBegin = tempBegin->next;
          }
          }
        }
      }
      printf("We have finished the hard way\n");
  }
  printf("We have finished the easy way\n"); */
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
  // Not implemented
}


// PRE:  this list and otherlist have the same pixel dimensions, block dimensions, and block size
// POST: this list and otherlist are checkered with each other's nodes
//       each list's dimensions remain the same
// THIS MUST BE ACHIEVED USING POINTER REASSIGNMENTS.
// DO NOT ALLOCATE OR DELETE ANY NODES IN THIS FUNCTION.
void GridList::CheckerSwap(GridList& otherlist)
{
  // get starting node
  GridNode* node = northwest;
  GridNode* node2 = otherlist.northwest;

  // fist node is uneffected and figure out if the size is nxn or nxm
  bool makeOther = false;
  bool odd;
  if (dimx % 2 == 0) {
	odd = false;
  } else {
	odd = true;
  }

  int count = 1;

  // itterate through each eliment
  while (node != NULL) {
	if (makeOther) {
		node -> next = node2;
		node -> next -> prev = node;
	}

	// determine if next block modifcation
	if (odd || count != dimx) {
		makeOther = !makeOther;
    count++;
	} else {
		count = 1;
	}

	node = node -> next;
	node2 = node2 -> next;
  }
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
  bool odd;
  if (dimx % 2 != 0) {
	odd = true;
  } else {
	odd = false;
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
  	if (odd || count != dimx) {
  		makeNeg = !makeNeg;
      count++;
  	} else {
  		count = 1;
  	}

  	node = node -> next;
  }

}

// Deallocates any dynamic memory associated with this list
//   and re-initializes this list to an empty state
void GridList::Clear()
{
  while (northwest->next != NULL) {
    northwest->prev = NULL;
    delete northwest;
    northwest = northwest->next;
    northwest->prev->next = NULL;
  }

  northwest->prev = NULL;
  delete northwest;
  dimx = NULL;
  dimy = NULL;
  southeast = NULL;
  delete southeast;

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
