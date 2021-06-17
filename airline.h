#pragma once
#include <iostream>
#include <sstream>

#include <vector>
#include <string>
#include <cmath>
#include <map>

using namespace std;

class Airline {
    public:
        Airline() {}

        Airline(string name, int id, string source, int sourceId, string destination, int destinationId): name_(name), id_(id), source_(source), sourceId_(sourceId), destination_(destination), destinationId_(destinationId){};

        string getName() {
            return name_;
        }

        int getId() {
            return id_;
        }

        string getSource() {
            return source_;
        }

        int getSourceId() {
            return sourceId_;
        }

        string getDestination() {
            return destination_;
        }

        int getDestinationId() {
            return destinationId_;
        }


    private:
        string name_;
        int id_;
        string source_;
        int sourceId_;
        string destination_;
        int destinationId_;
        

};