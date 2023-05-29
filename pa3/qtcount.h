#ifndef _QTCOUNT_H_
#define _QTCOUNT_H_

#include <cmath>
#include <utility>

#include "cs221util/PNG.h"
#include "cs221util/RGBAPixel.h"
#include "quadtree.h"

using namespace std;
using namespace cs221util;

class qtcount : public quadtree {
public:
    qtcount(PNG& im) : quadtree(im) {}

private:
    bool prunable(Node* node, const int tol) const;
    bool phelper(Node* node, const int tol, RGBAPixel a) const;
};

#endif
