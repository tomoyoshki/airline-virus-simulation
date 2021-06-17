#pragma once

#include <iostream>
#include <sstream>

#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <iterator>
#include <queue>

/** 
 * Airport class
 */
using namespace std;
class Airport {
    public:
        // Default Constructor
        Airport();

        /** 
         * Custom Constructor
         * @param id Airport ID
         * @param name  Airport Name
         * @param city City the airport is located in 
         * @param latitude  Latitude of the airport
         * @param longtitude Longtitude of the airport
         */
        Airport(int id, string name, string city, double latitude, double longitude): id_(id), name_(name), city_(city), latitude_(latitude), longitude_(longitude){
            visited = false;
            height_ = -1;
        };
        
        /** 
         * Variable Getter
         * @return id
         */
        int getId() {
            return id_;
        }

        /** 
         * Variable Getter
         * @return name
         */
        string getName() {
            return name_;
        }

        /** 
         * Variable Getter
         * @return Number of airline from this airport
         */
        int getAirlineCount() {
            return destination.size();
        }
        
        /** 
         * Variable Getter
         * @return Latitude
         */
        double getLatitude() {
            return latitude_;
        }

        /** 
         * Variable Getter
         * @return Longitude
         */
        double getLongitude() {
            return longitude_;
        }

        /** 
         * Check if two airports are the same
         * @param Airport
         * @return True if they are the same, false if not
         */
        bool operator== (Airport other) const {
            return (other.getId() == id_);
        };

        /** 
         * Add an airline to the vector
         * @param int id
         */
        void addAirline(int destination_id) {
                destination.push_back(destination_id);
        }

        /** 
         * Get destination
         * @param   int index 
         * @return int destination airport's ID
         */
        int getDestination(int index) {
            return destination[index];
        }

        /**
         * Get entire list of destination
         */
        vector<int> getDestVector() {
            return destination;
        }
        
        /** 
         * Set the airport to not visitied
         */
        void unvisit() {
            visited = false;
        }

        /** 
         * Set the airport to be visited
         */
        void visit() {
            visited = true;
        }

        /** 
         * Variable Getter
         * @return visit
         */
        bool visitStatus() {
            return visited;
        }

        /** 
         * Variable Getter
         * @return height
         */
        int getHeight() {
            return height_;
        }

        /** 
         * Variable Setter
         * @param int height 
         * set height
         */
        void setHeight(int height) {
            height_ = height;
        }
    private:
        int id_;
        string name_;
        string city_;
        double latitude_;
        double longitude_;
        vector<int> destination;
        bool visited;
        int height_;
};
