#include "block.h"
#include <cmath>
#include <iostream>

int Block::height() const {
  /* your code here */

  if (data.size() == 0) {
    return 0;
  }

  return data[0].size();

}

int Block::width() const {
  /* your code here */

  return data.size();

}

void Block::render(PNG &im, int x) const {
  /* your code here */

  for (int l=x; l < x+width(); l++) {
    for (int y=0; y < height(); y++) {

      *(im.getPixel(l,y)) = data[l-x][y];

    }
  }

}

void Block::build(PNG &im, int x, int width) {
  /* your code here */

  for (int l=x; l < x+width; l++) {
    vector<HSLAPixel> v;
    for (unsigned int y=0; y<im.height(); y++) {
      HSLAPixel* pixel = im.getPixel(l,y);
      v.push_back(*pixel);
    }

    data.push_back(v);

  }




}
