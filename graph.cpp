#include "graph.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include "readFromFile.hpp"


using namespace std;
using namespace cs225;


// Default constructor that creates a graph based on small_data and small_route
Graph::Graph() {
    //initialize airport info
    vector<string> data_vec = manipulate_string(file_to_string("data/small_data_20.dat"));
    vector<vector<string>> airport_data(data_vec.size());
    for(size_t i = 0; i < data_vec.size(); i++) {
        // Check if it is empty string
        if(data_vec[i] == "") {
            cout << i << endl;
        } else {
            airport_data[i] = manipulate_string(data_vec[i], ",");
        }
    }

    for(auto airport : airport_data) {
        if(airport[0] == "\\N" || airport[1] == "\\N" || airport[2] == "\\N" || airport[3] == "\\N" || airport[4] == "\\N" || !isInt(airport[0]) || !isDouble(airport[3]) || ! isDouble(airport[4])) {
            continue;
        } else {
            Airport * newAirport = new Airport(stoi(airport[0]), airport[1], airport[2], stod(airport[3]), stod(airport[4]));
            airportMap[newAirport->getId()] = newAirport;
        }
    }


    //initialize airline info
    vector<string> route_vec = manipulate_string(file_to_string("data/small_route.dat"));
    vector<vector<string>> route_data(route_vec.size());
    for(size_t i = 0; i < route_data.size(); i++) {
        // Check if it is empty string
        if(route_vec[i] == "") {
            cout << i << endl;
        } else {
            route_data[i] = manipulate_route(route_vec[i], ",");
        }
    }
    for(auto airline : route_data) {
        if(airline[0] == "\\N" || airline[1] == "\\N" || airline[2] == "\\N" || airline[3] == "\\N" || airline[4] == "\\N" || airline[5] == "\\N" || !isInt(airline[1]) || !isInt(airline[3]) || !isInt(airline[5])) {
            continue;
        } else {
            Airline * newAirline = new Airline(airline[0], stoi(airline[1]), airline[2], stoi(airline[3]), airline[4], stoi(airline[5]));
            airlines_.push_back(newAirline);

            // add an destination airport to the source airport under destination
            map<int, Airport*>::iterator it = airportMap.find(newAirline->getSourceId());
            if (airportMap.end() != it) {
                airportMap[newAirline->getSourceId()]->addAirline(newAirline->getDestinationId());
            }
        }
    }
}

Graph::Graph(string airportFile, string airlineFile) {
    //initialize airport info
    vector<string> data_vec = manipulate_string(file_to_string(airportFile));
    vector<vector<string>> airport_data(data_vec.size());
    for(size_t i = 0; i < data_vec.size(); i++) {
        // Check if it is empty string
        if(data_vec[i] == "") {
            cout << i << endl;
        } else {
            airport_data[i] = manipulate_string(data_vec[i], ",");
        }
    }
    for(auto airport : airport_data) {
        if(airport[0] == "\\N" || airport[1] == "\\N" || airport[2] == "\\N" || airport[3] == "\\N" || airport[4] == "\\N" || !isInt(airport[0]) || !isDouble(airport[3]) || ! isDouble(airport[4])){
            continue;
        } else {
            Airport * newAirport = new Airport(stoi(airport[0]), airport[1], airport[2], stod(airport[3]), stod(airport[4]));
            airportMap[newAirport->getId()] = newAirport;
        }
    }

    //initialize airline info

    vector<string> route_vec = manipulate_string(file_to_string(airlineFile));
    vector<vector<string>> route_data(route_vec.size());
    for(size_t i = 0; i < route_data.size(); i++) {
        // Check if it is empty string
        if(route_vec[i] == "") {
            cout << i << endl;
        } else {
            route_data[i] = manipulate_route(route_vec[i], ",");
        }
    }

    for(auto airline : route_data) {
        if(airline[0] == "\\N" || airline[1] == "\\N" || airline[2] == "\\N" || airline[3] == "\\N" || airline[4] == "\\N" || airline[5] == "\\N" || !isInt(airline[1]) || !isInt(airline[3]) || !isInt(airline[5])) {
            continue;
        } else {
            Airline * newAirline = new Airline(airline[0], stoi(airline[1]), airline[2], stoi(airline[3]), airline[4], stoi(airline[5]));
            airlines_.push_back(newAirline);

            // add an destination airport to the source airport under destination

            map<int, Airport*>::iterator it = airportMap.find(newAirline->getSourceId());
            if (airportMap.end() != it) {
                airportMap[newAirline->getSourceId()]->addAirline(newAirline->getDestinationId());
            }
        }
    }
}

int Graph::getAirlineCount() {
    map<int, Airport*>::iterator it;
    int count = 0;
    for(it = airportMap.begin(); it != airportMap.end(); ++it) {
        count += (it->second)->getAirlineCount();
    }
    return count;
}

int Graph::getAirportCount() {
    return airportMap.size();
}

Airport * Graph::getAirport(int id) {
    return airportMap[id];
}

PNG Graph:: mapToImage() {
    PNG image;
    image.readFromFile("world_map.png");
    
    vector<Airline *>::iterator airline_it = airlines_.begin();
    for(; airline_it!=airlines_.end(); ++airline_it) {
        // Source airport
        int a_id = (*airline_it)->getSourceId();
        // Destination airport
        int b_id = (*airline_it)->getDestinationId();
        // Check if two airports exist in our graph
        if(airportMap.find(a_id)!=airportMap.end() && airportMap.find(b_id) != airportMap.end()) {
            drawLine(image, airportMap.find(a_id)->second, airportMap.find(b_id)->second);
        }
    }

    map<int, Airport*>::iterator it = airportMap.begin();
    for(; it!= airportMap.end(); ++it) {
        unsigned y = lat_to_y(image, it->second);
        unsigned x = long_to_x(image, it->second);
        // draw the vertex
        for(unsigned i = x; i < x+4; i++) {
            for(unsigned j = y; j < y+4; j++) {
                if(i < image.width() && j < image.height()) {
                    HSLAPixel & p = image.getPixel(i, j);
                    p.h = 136;
                    p.s = 1;
                    p.l = 0.5;
                    p.a = 1;
                }
            }
        }
    }
    return image;
}

PNG Graph::mapTrans() {
    PNG image;
    image.readFromFile("world_map.png");
    vector<Airline *>::iterator airline_it = airlines_.begin();
    for(; airline_it!=airlines_.end(); ++airline_it) {
        // Source airport
        int a_id = (*airline_it)->getSourceId();
        // Destination airport
        int b_id = (*airline_it)->getDestinationId();
        // Check if two airports exist in our graph
        if(airportMap.find(a_id)!=airportMap.end() && airportMap.find(b_id) != airportMap.end()) {
            drawLine(image, airportMap.find(a_id)->second, airportMap.find(b_id)->second);
        }
    }
    map<int, Airport*>::iterator it = airportMap.begin();
    for(; it!= airportMap.end(); ++it) {
        if(!it->second)
            continue;
        unsigned y = lat_to_y(image, it->second);
        unsigned x = long_to_x(image, it->second);
        // draw the vertex
        for(unsigned i = x; i < x+4; i++) {
            for(unsigned j = y; j < y+4; j++) {
                if(i < image.width() && j < image.height()) {
                    HSLAPixel & p = image.getPixel(i, j);
                    if(it->second->getHeight() > -1) {
                        double new_h = 0 + 10 * it->second->getHeight();
                        if(new_h > 136) {
                            new_h = 136;
                        }
                        p.h = new_h;
                    } else {
                        p.h = 136;
                    }
                    p.s = 1;
                    p.l = 0.5;
                    p.a = 1;
                }
            }
        }
    }
    return image;
}

PNG Graph::mapPath(vector<int> path) {
    PNG image;
    image.readFromFile("world_map.png");
    if(path.empty()) {
        cout << "Path is empty!" << endl;
        return image;
    }
    for(unsigned pi = 0; pi < path.size()-1; pi++) {
        Airport * a = getAirport(path[pi]);
        Airport * b = getAirport(path[pi+1]);
        drawLine(image, a, b);
        unsigned y = lat_to_y(image, a);
        unsigned x = long_to_x(image, a);
        // draw the vertex
        for(unsigned i = x; i < x+4; i++) {
            for(unsigned j = y; j < y+4; j++) {
                if(i < image.width() && j < image.height()) {
                    HSLAPixel & p = image.getPixel(i, j);
                    if(pi == 0) {
                        p.h = 0;
                    } else {p.h = 60;}
                    p.s = 1;
                    p.l = 0.5;
                    p.a = 1;
                }
            }
        }
        y = lat_to_y(image, b);
        x = long_to_x(image, b);
        // draw the vertex
        for(unsigned i = x; i < x+4; i++) {
            for(unsigned j = y; j < y+4; j++) {
                if(i < image.width() && j < image.height()) {
                    HSLAPixel & p = image.getPixel(i, j);
                    if(pi == path.size()-2) {
                        p.h = 136;
                    } else {
                        p.h = 60;
                    }
                    p.s = 1;
                    p.l = 0.5;
                    p.a = 1;
                }
            }
        }
    }
    return image;
}

unsigned Graph::lat_to_y(PNG & image, Airport * p) {
    if(!p) {
        return 0;
    }
    double latitude = p->getLatitude();
    latitude = (latitude * 0.97+1) / 90;
    unsigned y = image.height()/2 - latitude * image.height()/2;
    return y;
}

unsigned Graph::long_to_x(PNG & image, Airport * p) {
    if(!p) {
        return 0;
    }
    double longtitude = p->getLongitude();
    longtitude = (longtitude * 0.888-4.8) / 180;
    unsigned x = image.width()/2 + longtitude * image.width()/2;
    return x;
}

void Graph::drawLine(PNG & png, Airport * a, Airport * b) {
    if(!a || !b) {
        return;
    }
    unsigned x1 = long_to_x(png, a);
    unsigned y1 = lat_to_y(png, a);
    unsigned x2 = long_to_x(png, b);
    unsigned y2 = lat_to_y(png, b);
    if(x1>=x2) {
        x1 = x2;
        y1 = y2;
        x2 = long_to_x(png, a);
        y2 = lat_to_y(png, a);
    }
    if(x2 - x1 == 0) {
        if(y2>y1) {
            for(unsigned i = y1; i < y2; i++) {
                if(i < png.width() && i < png.height()) {
                    HSLAPixel & p = png.getPixel(x1, i);
                    p.h = 216;
                    p.s = 1;
                    p.l = 0.5;
                    p.a = 1;
                }
            }
        } else {
            for(unsigned i = y2; i < y1; i++) {
                if(i < png.width() && i < png.height()) {
                    HSLAPixel & p = png.getPixel(x1, i);
                    p.h = 216;
                    p.s = 1;
                    p.l = 0.5;
                    p.a = 1;
                }
            }
        }
        return;
    }
    double slope = ((double)y2 - (double)y1) / ((double)x2 - (double)x1);
    double ycord = y1+slope;
    for(unsigned i = x1; i < x2; i++) {
        if(i < png.width() && (unsigned int)ycord < png.height()) {
            HSLAPixel & p = png.getPixel(i, (unsigned int)ycord);
            p.h = 216;
            p.s = 1;
            p.l = 0.5;
            p.a = 1;
            ycord+=slope;
        }
    }
}

vector<int> Graph::destinationPath(Airport source, Airport destination) {
    vector<int> toReturn; //vector with path ids
    toReturn.push_back(source.getId());
    vector<int> vertices;
    vertices.push_back(source.getId());
    int curr = source.getId();
    map<int, pair<double, int>> weightMap; //map with id as key, weight as value
    map<int, int> reverseMap; //map with airport id as key, its previous airport id as value;
    // As long as we did not reach destionation as a min weight
    for(int i = 0; i < source.getAirlineCount(); i++) {
        if(source.getDestination(i) == destination.getId()) {
            vector<int> x = {source.getId(), destination.getId()};
            return x;
        }
    }
    int count = 0;
    while (curr != destination.getId()) {  
        vector<int> nonDup_Dest = removeDup(airportMap[curr]->getDestVector());
        // Add all of current aiport's destination into the map
        for (int id : nonDup_Dest) {
            // Exclude returning flights
            if (find(vertices.begin(), vertices.end(), id) == vertices.end()) { // When the destionation id does not exisit in toReturn
                if(airportMap[curr] && airportMap[id]) {
                    pair<int, int> edge(findWeight(*airportMap[curr], *airportMap[id]), curr);
                    weightMap[id] = edge;
                }
            }
        }
        int min_id = curr;
        double min_weight = __DBL_MAX__;
        int edge_count = 0;
        while (find(vertices.begin(), vertices.end(), min_id) != vertices.end()) { // When the min weight destionation id does not exisit in toReturn
            for (auto it = weightMap.begin(); it != weightMap.end(); it++) {
                if (it->second.first < min_weight) {
                    min_id = it->first;
                    min_weight = it->second.first;
                }
            }

            if (find(vertices.begin(), vertices.end(), min_id) != vertices.end()) { // Remove the destination if it is present in toReturn and reset
                weightMap.erase(min_id);
                min_id = source.getId();
                min_weight = __DBL_MAX__;
            }
            edge_count++;
            if(edge_count>68000) {
                break;
            }
        }
        // update reverse map and weight map
        vertices.push_back(min_id);
        reverseMap[min_id] = weightMap[min_id].second;
        curr = min_id;
        weightMap.erase(min_id);
        count++;
        if(count > getAirportCount() || count > 3000) {
            cout << "Not Found" << endl;
            return vector<int>();
        }
    }
    // Construct a reverse path from destination to source
    stack<int> tempPath;
    int position = destination.getId();
    while (position != source.getId()) {
        tempPath.push(position);
        position = reverseMap[position];
    }
    // Update toReturn with proper ordering
    while (!tempPath.empty()) {
        toReturn.push_back(tempPath.top());
        tempPath.pop();
    }

    return toReturn; // temp for testing
}

double Graph::findWeight(Airport source, Airport dest) {
    int count = 0;
    //loop through the destination vector to find number of times dest id appears.
    for (int i = 0; i < source.getAirlineCount(); i++) {
        if (source.getDestination(i) == dest.getId()) count++;
    }

    return 1/count;
}

vector<int> Graph::removeDup(vector<int> input) {
    //create a new vector with same elements
    vector<int> toReturn;
    for (size_t i = 0; i < input.size(); i++) {
        toReturn.push_back(input[i]);
    }

    //remove duplicates
    sort(toReturn.begin(), toReturn.end());
    toReturn.erase(unique(toReturn.begin(), toReturn.end()), toReturn.end());

    return toReturn;
}
