#include <iostream>
#include <fstream>
#include <vector>
#include <string>


#include "readFromFile.hpp"
#include "graph.h"
#include "BFS.h"
#include "cs225/catch/catch.hpp"


using namespace std;

int main(int argc, const char * argv[]) {

    // Header section
    cout << endl << endl;
    for(int i = 0; i < 10; i++) {cout << "*\t";}
    for(int i = 0; i < 5; i++) {cout << "\n*"; if(i==1) cout << "\tCS 225 Final Project"; if(i==2) cout << "\ttaige2-xinyih8-tkimura4-rl17";};
    for(int i = 0; i < 9; i++) {cout << "\t*";} cout << endl << endl;


    // Check input validity
    // Check if there are four inputs
    if(argc < 4) {
        cout << "Invalid input! \nPlease make sure you have four inputs: airport_datafile, airline_datafile, Airport A ID, Airport B ID!" << endl;
        return 0;
    }
    string airport_file = argv[1];
    string airline_file = argv[2];
    int a_id = atoi(argv[3]);
    int b_id = atoi(argv[4]);

    ifstream ifile;
    ifile.open(airport_file);
    if(ifile) {
        ifile.close();
    } else {
        cout<< airport_file << " does not exist, please check your directory!"<< endl;
        return 0;
    }
    ifile.open(airline_file);
    if(ifile) {
        ifile.close();
    } else {
        cout << airline_file << " does not exist, please check your directory!"<< endl;
        return 0;
    }
    if(a_id == 0 || a_id > 14110) {
        cout << "Invalid Airport A ID!" << endl;
        return 0;
    }
    if(b_id == 0 || b_id > 14110) {
        cout << "Invalid Airport B ID!" << endl;
        return 0;
    }
    cout << "Valid inputs!" << endl;
    cout << "Airport Dataset is: " << airport_file << endl;
    cout << "Route/Airline Dataset is: " << airline_file << endl;
    cout << endl;


    cout << "Creating Graph..." << endl;
    Graph graph(airport_file, airline_file);
    PNG graph_image = graph.mapToImage();
    graph_image.writeToFile("map_graph.png");
    cout << "Graph created!" << endl;
    cout << "You can view the graph projection in 'map_graph.png'!" << endl << endl;

    cout << "Running Prim's algorithm..." << endl;
    vector <int> path;
    Airport * a = graph.getAirport(a_id);
    Airport * b = graph.getAirport(b_id);
    if(a && b) {
        cout << "Origin: " << a->getName() << endl;
        cout << "Destination: " << b->getName() << endl;
        path = graph.destinationPath(*a, *b);
    }
    if(path.empty()) {
        cout << "Virus will not reach airport B!" << endl;
    } else {
        cout << "The path of the virus is: " << endl;
        for(unsigned i = 0; i < path.size(); i++) {
            cout << (i+1) << ": " << graph.getAirport(path[i])->getName() << " "<< graph.getAirport(path[i])->getId() << endl;
        }
        PNG path_img = graph.mapPath(path);
        path_img.writeToFile("map_path.png");
        cout << "You can view the projected path in 'map_path.png'!" << endl << endl;
    }
    cout << endl << endl;

    Airport * airport_a = graph.getAirport(a_id);
    
    cout << "Initializing BFS..." << endl;
    BFS bfs(airport_a, graph);

    // Check if starting airport is valid
    if(!bfs.valid()) {
        cout << "End" << endl << endl;
        return 0;
    }
    cout << "BFS initialized!" << endl << endl;
    cout << "Traversing the graph to mark transmissibility..." << endl;
    for(auto it:bfs) {

    }
    PNG graph_trans_image = graph.mapTrans();
    graph_trans_image.writeToFile("map_trans_graph.png");
    cout << "Traversal Done, you can now view the graph projection with transmissibility in 'map_trans_graph.png'!" << endl << endl;
    return argc;
}