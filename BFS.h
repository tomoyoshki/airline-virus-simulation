#pragma once

#include <iterator>
#include <cmath>
#include <list>
#include <queue>

#include "airport.h"
#include "GridTraversal.h"

using namespace std;

/**
 * A breadth-first ImageTraversal.
 * Derived from base class GridTraversal
 */

class BFS : public GridTraversal {
    public:
        /** 
         * Custom Constructor
         * @param Airport * starting airprot
         * @param Graph the graph
         */
        BFS(Airport * start, Graph graph);

        /**
         * The begining of an iterator
         */
        GridTraversal::Iterator begin();

        /**
         * The end of an iterator
         */
        GridTraversal::Iterator end();

        /**
         * Add new airport to the traversal
         */
        void add(Airport * airport);

        /**
         * Remove and return the next airport of the traversal
         */
        Airport * pop();

        /**
         * Return but not remove the next airport of the traversal
         */
        Airport * peek() const;

        /**
         * To see if the traversal has no airports left
         */
        bool empty() const;

        /**
         * Get if starting point is valid
         */
        bool valid() const {
            return valid_;
        }
    private:
        Graph graph_;
        Airport * start_;
        Airport * current_;
        queue<Airport*> airport_;
        bool valid_;
};