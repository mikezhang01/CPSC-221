#include "HexCell.h"

#include <cmath>

HexCell::HexCell(int Q, int R) {
    /**
     * @todo Your code here!
     */
    q = Q;
    r = R;
    path_dist_from_start = 0;

    for (int i = 0; i < 6; i++) {
        neighbours[i] = nullptr;
        links[i] = nullptr;
    }

}

void HexCell::link(HexCell* cell) {
    /**
     * @todo Your code here!
     */

    if (cell == nullptr || distance(cell) != 1) {
        return;
    }
    int side = get_neighbour_side(cell);

    links[side] = cell;

    int side2 = cell->get_neighbour_side(this);
    cell->links[side2] = this;

}

int HexCell::get_neighbour_side(const HexCell* cell) const {
    /**
     * @todo Your code here! You will need to replace the following line.
     */

    if (cell->q == q) {
        if (cell->r > r) {
            return 3;
        } else {
            return 0;
        }
    } else if (cell->r == r) {
        if (cell->q > q) {
            return 2;
        } else {
            return 5;
        }
    } else {
        if (cell->q > q) {
            return 1;
        } else {
            return 4;
        }
    }

}

bool HexCell::is_linked(const HexCell* cell) const {
    /**
     * @todo Your code here! You will need to replace the following line.
     */

    if (distance(cell) != 1) {
        return false;
    } 

    int side = get_neighbour_side(cell);

    if (links[side] == cell) {
        return true;
    }
    return false;
}

int HexCell::distance(const HexCell* cell) const {
    /**
     * @todo Your code here! You will need to replace the following line.
     */

    if (cell == nullptr) {
        return -1;
    }
    
    int qdiff = cell->q - q;
    int rdiff = cell->r - r;
    int qr = qdiff + rdiff;

    int dist;

    if (abs(qdiff) >= abs(rdiff) && abs(qdiff) >= abs(qr)) {
        dist = abs(qdiff);
    } else if (abs(rdiff) >= abs(qdiff) && abs(rdiff) >= abs(qr)) {
        dist = abs(rdiff);
    } else if (abs(qr) >= abs(rdiff) && abs(qr) >= abs(qdiff)) {
        dist = abs(qr);
    }

    //int dist = std::max(abs(qdiff), abs(rdiff), abs(qr));


    return dist;

}

bool HexCell::is_edge() const {
    /**
     * @todo Your code here! You will need to replace the following line.
     */

    for (int i = 0; i < 6; i++) {
        if (neighbours[i] == nullptr) {
            return true;
        }
    }
    return false;
}