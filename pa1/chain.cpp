#include "chain.h"
#include <cmath>
#include <iostream>


// PA1 functions

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain() {
  /* your code here */
  clear();
}

/**
 * Inserts a new node after the node pointed to by p in the
 * chain (so p->next is the new node) and returns a pointer to
 * the newly created node.
 * If p is NULL, inserts a new head node to the chain.
 * This function **SHOULD** create a new Node and increase length_.
 *
 * @param p = The new node should be pointed to by p->next.
 *            If p is NULL, the new node becomes the head of the chain.
 * @param ndata = The data to be inserted.
 */
Chain::Node * Chain::insertAfter(Node * p, const Block &ndata) {
  /* your code here */

  Node* newnode = new Node(ndata);

  if (p == NULL) {

    head_ = newnode;
    length_ = length_ + 1;
    return head_;

  } else {

    Node* temp = p;

    if (temp->next == NULL) {
      temp->next = newnode;
      newnode->prev = temp;
    } else {
      newnode->next = temp->next;
      temp->next->prev = newnode;
      temp->next = newnode;
      newnode->prev = temp;
    }

    length_ = length_ + 1;
    temp = temp->next;
    return temp;

  }

  //return nullptr;
}

/**
 * Swaps the position in the chain of the two nodes pointed to
 * by p and q.
 * If p or q is NULL or p==q, do nothing.
 * Change the chain's head pointer if necessary.
 */
void Chain::swap(Node *p, Node *q) {
  /* your code here */

  if (p == NULL || q == NULL || p == q) {
    return;
  }

  Node* prevp = p->prev;
  Node* currp = p;
  Node* nextp = p->next;
  Node* prevq = q->prev;
  Node* currq = q;
  Node* nextq = q->next;

  if (prevp == NULL) {
     head_= q;

      if (nextq == NULL && nextp != q) {
        currp->next = nextq;
        currp->prev = prevq;
        prevq->next = currp;
        currq->prev = prevp;
        currq->next = nextp;
        nextp->prev = currq;
      } else if (nextq == NULL) {
        currp->next = nextq;
        currp->prev = currq;
        currq->prev = prevp;
        currq->next = currp;     
      } else if (nextp == q) {
        currp->next = nextq;
        nextq->prev = currp;
        currp->prev = currq;
        currq->prev = prevp;
        currq->next = currp;
      } else {
        currp->next = nextq;
        nextq->prev = currp;
        currp->prev = prevq;
        prevq->next = currp;
        currq->prev = prevp;
        currq->next = nextp;
        nextp->prev = currq;
      }
  } else if (nextq == NULL) {
    if (prevq == p) {
        currp->next = nextq;
        currp->prev = currq;
        currq->prev = prevp;
        prevp->next = currq;
        currq->next = currp;
    } else {
        currp->next = nextq;
        currp->prev = prevq;
        prevq->next = currp;
        currq->prev = prevp;
        prevp->next = currq;
        currq->next = nextp;
        nextp->prev = currq;
    }
  } else if (prevq == NULL) {
      head_= p;

      if (nextp == NULL && nextq != p) {
        currp->next = nextq;
        nextq->prev = currp;
        currp->prev = prevq;
        currq->prev = prevp;
        prevp->next = currq;
        currq->next = nextp;
      } else if (nextp == NULL) {
        currp->next = currq;
        currp->prev = prevq;
        currq->prev = currp;
        currq->next = nextp;     
      } else if (nextq == p) {
        currp->next = currq;
        currp->prev = prevq;
        currq->prev = currp;
        currq->next = nextp;
        nextp->prev = currq;
      } else {
        currp->next = nextq;
        nextq->prev = currp;
        currp->prev = prevq;
        currq->prev = prevp;
        prevp->next = currq;
        currq->next = nextp;
        nextp->prev = currq;
      }
  } else if (nextp == NULL) {
      if (prevp == q) {
        currp->next = currq;
        currp->prev = prevq;
        prevq->next = currp;
        currq->prev = currp;
        currq->next = nextp;
      } else {
        currp->next = nextq;
        nextq->prev = currp;
        currp->prev = prevq;
        prevq->next = currp;
        currq->prev = prevp;
        prevp->next = currq;
        currq->next = nextp;
      }
  } else if (nextp == q) {
        currp->next = nextq;
        nextq->prev = currp;
        currp->prev = currq;
        currq->prev = prevp;
        prevp->next = currq;
        currq->next = currp;
  } else if (nextq == p) {
        currp->next = currq;
        currp->prev = prevq;
        prevq->next = currp;
        currq->prev = currp;
        currq->next = nextp;
        nextp->prev = currq;
  } else {
        currp->next = nextq;
        nextq->prev = currp;
        currp->prev = prevq;
        prevq->next = currp;
        currq->prev = prevp;
        prevp->next = currq;
        currq->next = nextp;
        nextp->prev = currq;
  }

}

/**
 * Destroys all dynamically allocated memory associated with the
 * current Chain class.
 */
void Chain::clear() {
  /* your code here */

  if (head_ == NULL) {
    return;
  }

  if (head_->next == NULL) {
    delete head_;
    head_ = NULL;
  }
  else {

    Node* temp = head_;

    while (temp->next != NULL) {
      temp = temp->next;
      delete temp->prev;
    }

    delete temp;
    head_ = NULL;

  }

}

/**
 * Makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */
void Chain::copy(Chain const &other) {
  /* your code here */

  if (other.length_ == 0) {
    return;
  }
  
  length_ = other.length_;

  Node* othertemp = other.head_;
  Node* newhead = new Node(othertemp->data);
  head_ = newhead;

  Node* temp = head_;
  othertemp = othertemp->next;

  while (othertemp != NULL) {
    Node* newnode = new Node(othertemp->data);

    temp->next = newnode;
    newnode->prev = temp;

    othertemp = othertemp->next;
    temp = temp->next;

  }

}

/* Modifies the current chain:
 * 1) Find the node with the first (leftmost) block in the unscrambled
 *    image and move it to the head of the chain.
 *	This block is the one whose closest match (to the left) is the
 *	largest.  That is, the distance (using distanceTo) to this block
 *	is big for all other blocks.
 *	For each block B, find the distanceTo B from every other block
 *	and take the minimum of these distances as B's "value".
 *	Choose the block B with the maximum value over all blocks and
 *	swap its node to the head of the chain.
 *
 * 2) Starting with the (just found) first block B, find the node with
 *    the block that is the closest match to follow B (to the right)
 *    among the remaining blocks, move (swap) it to follow B's node,
 *    then repeat to unscramble the chain/image.
 */
void Chain::unscramble() {
  /* your code here */

  Node* temp = head_;
  Node* first = head_;
  double maxvalue = 0.0;
  //1
  
  while (temp != NULL) {

    double value = 10000000.0;
    Node* curr = head_;

    while (curr != NULL) {

      double dist = curr->data.distanceTo(temp->data);
      if (curr != temp) {
        if (dist < value) {
          value = dist;
        }
      }

      curr = curr->next;
    }

    if (value > maxvalue) {
      maxvalue = value;
      first = temp;
    }

    temp = temp->next;
  }

  //Node* headref = head_;
  swap(head_, first);

  //2

  if (first->next == NULL) {
    return;
  }

  while (first->next->next != NULL) {
    Node* curr2 = first->next;
    Node* second = first->next;
    double minvalue = 1000000000.0;

    while (curr2 != NULL) {
      
      double dist2 = first->data.distanceTo(curr2->data);
      if (dist2 < minvalue) {
        minvalue = dist2;
        second = curr2;
      }
      curr2 = curr2->next;

    }

    swap(first->next, second);

    first = first->next;

  }

}
