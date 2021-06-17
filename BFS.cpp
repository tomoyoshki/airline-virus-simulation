#include <iterator>
#include <cmath>
#include <list>
#include <queue>
#include <vector>

#include "airport.h"
#include "GridTraversal.h"
#include "BFS.h"

using namespace std;

BFS::BFS(Airport * start, Graph graph) {
    if(start) { // If the starting point is a valid Airport
        start_ = start;
        graph_ = graph;
        valid_ = true;
    } else {    // If the starting point is invalid
        start_ = nullptr;
        current_ = nullptr;
        valid_ = false;
        cout << "Invalid Starting Airport!" << endl;
    }
}


GridTraversal::Iterator BFS::begin() {
    // Set all the nodes in the graph to be not visited
    // Set all the height to be -1 except for the origin point
    if(start_) {
        map<int, Airport*> air_map = graph_.getAirportMap();
        map<int, Airport*>::iterator it = air_map.begin();
        while(it!=air_map.end()) {
            if(!it->second) {
                break;
            }
            it->second->unvisit();
            it->second->setHeight(-1);
            ++it;
        }
        
        // Visit the start airport 
        airport_.push(start_);
        current_ = start_;
        start_->visit();
        start_->setHeight(0);
    }
    return GridTraversal::Iterator(this, start_, graph_);
}

GridTraversal::Iterator BFS::end() {
    return GridTraversal::Iterator();
}

void BFS::add(Airport * airport) {

    // set this airport visited
    airport->visit();

    // add all the neighbors 
    for(int i = 0; i < airport->getAirlineCount(); i++) {
        int destinationId = airport->getDestination(i);
        if(graph_.getAirport(destinationId)) {
            airport_.push(graph_.getAirport(destinationId));

            // Set the height of the destination airport to be the current airport + 1
            if(graph_.getAirport(destinationId)->getHeight() == -1) {
                graph_.getAirport(destinationId)->setHeight(airport->getHeight()+1);
            }
        }
    }

    Airport * temp = airport_.front();

    // While the airport_ queue is not empty and the temp airport is not visited
    while(!airport_.empty() && temp->visitStatus()) {
        airport_.pop();
        temp = airport_.front();
    }
    // set current airport we are at = temp
    current_ = temp;
}

Airport * BFS::pop() {
    Airport * output = airport_.front();
    airport_.pop();
    return output;
}

Airport * BFS::peek() const {
    return current_;
}

bool BFS::empty() const {
    return airport_.empty();
}