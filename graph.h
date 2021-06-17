#pragma once
#include <iostream>
#include <sstream>

#include <vector>
#include <string>
#include <cmath>
#include <map>
#include "cs225/PNG.h"

#include "airport.h"
#include "airline.h"


using namespace std;
using namespace cs225;

class Graph {
    
    public:
        /**
         * constructor on small data set
         */
        Graph();

        /**
         * constructor that takes in specific input files
         * @param airportFile aiport dat file
         * @param airlineFile airline dat file
         */
        Graph(string airportFile, string airlineFile);

        /**
         * uses prim algorithm to find the shortest path
         * @param source the source airport
         * @param destination the destination airport
         * @return an ordered vector of aiport ids that represents the shortest path
         */
        vector<int> destinationPath(Airport source, Airport destination);
        
        /** 
         * Variable Getter
         * @return name
         */
        Airport nearestAirport(double lat, double lon);

        /** 
         * Variable Getter
         * @return Number of airport or node
         */
        int getAirportCount();

        /** 
         * Variable Getter
         * @return Number of airline or edge
         */
        int getAirlineCount();

        /** 
         * Variable Getter
         * @param int Airport ID
         * @return an airport based on the id
         */
        Airport * getAirport(int id);

        /** 
         * Graph Mapping 
         * @return PNG the picture
         */
        PNG mapToImage();

        /** 
         * Map Projection with Transmissibility
         * @return PNG the picture
         */
        PNG mapTrans();
        
        /** 
         * Map Path Projection 
         * @return PNG the picture
         */
        PNG mapPath(vector<int>path);

        /** 
         * Calculate the y index of an image given the latitude
         * @param PNG & Image 
         * @param Airport * the airport
         * @return y index of the image based on the airport latitude
         */
        unsigned lat_to_y(PNG & image, Airport * p);

        /** 
         * Calculate the y index of an image given the longtitude
         * @param PNG & Image 
         * @param Airport * the airport
         * @return y index of the image based on the airport longitude
         */
        unsigned long_to_x(PNG & image, Airport * p);

        /** 
         * Variable Getter
         * @return all the airport 
         */
        map<int, Airport*> getAirportMap() {
            return airportMap;
        }


    
    private:
        //airport map with airport id as key
        map<int, Airport*> airportMap;
        //list of airlines from data set
        vector<Airline*> airlines_;
        int stringtoNum(string input);
        void drawLine(PNG & png, Airport* a, Airport*b);
        /**
         * Helper functions to check string type
         * @param string x
         * @return check if string is double
         */
        bool isDouble(string x) {
            double tmp;
            stringstream ss;

            ss << x;
            ss >> tmp;

            if (ss.fail()) {
                return false;
            } else {
                return true;
            }
        }

        /**
         * Helper functions to check string type
         * @param string x
         * @return check if string is an integer
         */
        bool isInt(string x) {
            int tmp;
            stringstream ss;

            ss << x;
            ss >> tmp;

            if (ss.fail()) {
                return false;
            } else {
                return true;
            }
        }

        /**
         * Helper function to calculate weight
         * @param source
         * @param dest
         * @return the weight between two airport based on 1/number of routes
         */
        double findWeight(Airport source, Airport dest);

        /**
         * Helper function to remove duplicate int in vector
         * @param input vector with dups
         * @return vector with no duplicates
         */
        vector<int> removeDup(vector<int> input);
};      
