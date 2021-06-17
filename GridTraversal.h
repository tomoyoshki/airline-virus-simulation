#pragma once

#include <iterator>
#include <queue>
#include <vector>

#include "airport.h"
#include "graph.h"

using namespace std;

class GridTraversal {
    public:
        class Iterator : iterator<forward_iterator_tag, Airport> {
            public:
                Iterator();
                Iterator(GridTraversal * traversal, Airport *start, Graph graph);

                Iterator & operator++();
                Airport * operator*();
                bool operator!=(const Iterator &other);
            private:
                GridTraversal * traversal_;
                Airport * start_;
                Airport * current_;
                vector<bool> visited;
                Graph graph_;
        };
        /**
         * The begining of an iterator
         */
        virtual Iterator begin() = 0;

        /**
         * The end of an iterator
         */
        virtual Iterator end() = 0;

        /**
         * Add new point to the traversal
         */
        virtual void add(Airport * t) = 0;

        /**
         * Remove and return the next point of the traversal
         */
        virtual Airport * pop() = 0;

        /**
         * Return but not remove the next point of the traversal
         */
        virtual Airport * peek() const = 0;

        /**
         * To see if the traversal has no points left
         */
        virtual bool empty() const = 0;
};