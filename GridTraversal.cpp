#include <iterator>
#include <cmath>

#include "airport.h"
#include "GridTraversal.h"


using namespace std;

/**
 * Default iterator constructor.
 */
GridTraversal::Iterator::Iterator() : traversal_(NULL) {
}

GridTraversal::Iterator::Iterator(GridTraversal * traversal, Airport * start, Graph graph) {
    if(start) {
        traversal_ = traversal;
        start_ = start;
        graph_ = graph;
        current_ = start_;
        current_ = traversal_->peek();
    } else {
        traversal_ = NULL;
    }
}

GridTraversal::Iterator & GridTraversal::Iterator::operator++() {
    // while traversal is not empty we continue to add
    if(!traversal_->empty()) {
        traversal_->add(current_);
        current_ = traversal_->peek();
    }
    return *this;
}

Airport * GridTraversal::Iterator::operator*() {
    return current_;
}

bool GridTraversal::Iterator::operator!=(const GridTraversal::Iterator &other) {

    bool thisEmpty = false; 
    bool otherEmpty = false;
    if (traversal_ == NULL) { 
        thisEmpty = true;
    }
    if (other.traversal_ == NULL) { 
        otherEmpty = true;
    }

    if (!thisEmpty)  {
        thisEmpty = traversal_->empty();
    }
    if (!otherEmpty) {
        otherEmpty = other.traversal_->empty(); 
    }
    if (thisEmpty && otherEmpty) 
        return false; // both empty then the traversal_s are equal, return false
    else if ((!thisEmpty)&&(!otherEmpty)) {
        return !(traversal_->peek() == other.traversal_->peek()); //both not empty then compare the traversals
    }
    else {
        return true;
    }
}
