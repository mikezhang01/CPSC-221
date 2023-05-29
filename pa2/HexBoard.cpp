#include "HexBoard.h"

#include <iostream>

#include "queue.h"
#include "stack.h"

HexBoard::HexBoard(int radius) {
    /**
     * @todo Your code here!
     */

    this->radius = radius;

    //this->start_coord = {0, 0};

    longest_path_dist = 0;

    create_board();
    configure_cells();
}

void HexBoard::create_board() {
    /**
     * @todo Your code here!
     */

    if (radius == 1) {
        HexCell* hcell = new HexCell(0, 0);

        cells[{0, 0}] = hcell;

        return;
    }


    int cbound = radius - 1;
    int rn_def = (radius - 1) * -1;
    int rn = (radius - 1) * -1;
    //int c = 0;

    for (int r = radius -1, c=0; r>0 && c<cbound; r--, c++) {
        
            rn = rn_def;
            while (rn <= c) {

                HexCell* hcell1 = new HexCell(rn, r);
                HexCell* hcell2 = new HexCell(rn*-1, r*-1);
                

                cells[{rn, r}] = hcell1;
                cells[{rn*-1, r*-1}] = hcell2;

                rn++;
            }
        

    }
    /**

    for (int r = radius -1; r>0; r--) {

        for (int c = 0; c<r; c++) {
        
            rn = rn_def;
            while (rn <= c) {

                HexCell* hcell1 = new HexCell(rn, r);
                HexCell* hcell2 = new HexCell(rn*-1, r*-1);
                

                cells[{rn, r}] = hcell1;
                cells[{rn*-1, r*-1}] = hcell2;

                rn++;
            }
        
        }

    }
*/


    for (int r = radius-1; r >= rn_def; r--) {
        HexCell* hcell3 = new HexCell(r, 0);

        cells[{r, 0}] = hcell3;
    }

}

void HexBoard::configure_cells() {
    /**
     * @todo Your code here!
     */

    for (auto kv : cells) {               
        pair<int, int> coord = kv.first; 
        HexCell* cell = kv.second; 

        vector<pair<int, int>> nbs = get_neigh_coords(coord);

        for (pair<int, int> apair : nbs) {

            if (cells.find(apair) != cells.end()) {
                HexCell* cell2 = cells[apair];

                int side = cell->get_neighbour_side(cell2);

                cell->neighbours[side] = cell2;

            }

        }
               
    }


}

void HexBoard::generate_maze(pair<int, int> start_coord, double branch_prob) {
    /**
     * @todo Your code here!
     */

    this->start_coord = start_coord;

    map<pair<int, int>, bool> visited;
    int longest_edge = 0;

    Stack<pair<int, int>> stack1;
    visited[start_coord] = true;

    stack1.push(start_coord);

    while (stack1.isEmpty() == false) {
        pair<int, int> curr_cell = stack1.peek();

        HexCell* neigh_cell = chooseNeighbour(cells[curr_cell], visited, branch_prob);

        if (neigh_cell != nullptr) {
            cells[curr_cell]->link(neigh_cell);
            visited[{neigh_cell->q, neigh_cell->r}] = true;

            neigh_cell->path_dist_from_start = cells[curr_cell]->path_dist_from_start + 1;

            if (neigh_cell->path_dist_from_start > longest_path_dist) {
                longest_path_dist = neigh_cell->path_dist_from_start;

            } 

            if (neigh_cell->is_edge() == true) {
                if (neigh_cell->path_dist_from_start > longest_edge) {
                    longest_edge = neigh_cell->path_dist_from_start;
                    end_coord = {neigh_cell->q, neigh_cell->r};
                }
            } 

            stack1.push({neigh_cell->q, neigh_cell->r});

        } else {
            stack1.pop();
        }

    }

}

void HexBoard::solve_maze() {
    /**
     * @todo Your code here!
     */

    map<pair<int, int>, bool> visited;

    Stack<pair<int, int>> stack1;
    
    stack1.push(start_coord);

    while (stack1.isEmpty() == false) {
        pair<int, int> curr_cell = stack1.peek();
        visited[curr_cell] = true;

        if (curr_cell == end_coord) {
            break;
        }

        for (HexCell* h : cells[curr_cell]->links) {
            if (h!=nullptr && visited.find({h->q, h->r}) == visited.end()) {
                stack1.push({h->q, h->r});
                break;
            }
        }
        
        if (stack1.peek() == curr_cell) {

            int found = 0;

            while (stack1.isEmpty() == false && found == 0) {

                for (HexCell* h : cells[stack1.peek()]->links) {
                    if (h!=nullptr && visited.find({h->q, h->r}) == visited.end()) {
                        found = 1;
                    }
                }

                if (found == 0) {
                    stack1.pop();
                }

            }

        }

    }

    Stack<pair<int, int>> stack2;

    while (stack1.isEmpty() == false) {
        stack2.push(stack1.pop());
    }

    while (stack2.isEmpty() == false) {
        solution.push_back(stack2.pop());
    }


}