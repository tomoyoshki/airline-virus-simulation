#include "../cs225/catch/catch.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../readFromFile.hpp"
#include "../graph.h"
#include "../BFS.h"


using namespace std;


TEST_CASE("Create default graph small", "[graph_default]")
{
    Graph graph_small;
    REQUIRE(20 >= graph_small.getAirportCount());
    REQUIRE(39 >= graph_small.getAirlineCount());
}

TEST_CASE("Create graph small", "[graph_default]")
{
    string adata = "tests/tdata/test_const_airport.dat";
    string rdata = "tests/tdata/test_const_airline.dat";
    Graph graph_small(adata, rdata);
    REQUIRE(79 >= graph_small.getAirportCount());
    REQUIRE(39 >= graph_small.getAirlineCount());
}

TEST_CASE("Create graph large", "[graph_default]")
{
    string adata = "tests/tdata/test_large_airport.dat";
    string rdata = "tests/tdata/test_large_airline.dat";
    Graph graph_small(adata, rdata);
    REQUIRE(2000 >= graph_small.getAirportCount());
    REQUIRE(67663 >= graph_small.getAirlineCount());
}


TEST_CASE("BFS Test Begin", "[bfs]") {
    string adata = "tests/tdata/test_const_airport.dat";
    string rdata = "tests/tdata/test_const_airline.dat";
    Graph graph_small(adata, rdata);
    Airport * start = graph_small.getAirport(2931);
    BFS bfs(start, graph_small);
    REQUIRE( *(bfs.begin()) == start );
}

TEST_CASE("BFS Test Increment Once", "[bfs]") {
    string adata = "tests/tdata/test_bfs_small_p.dat";
    string rdata = "tests/tdata/test_bfs_small_l.dat";
    Graph graph_small(adata, rdata);
    Airport * start = graph_small.getAirport(3384);
    BFS bfs(start, graph_small);
    BFS::Iterator it = bfs.begin();
    Airport * dest = graph_small.getAirport(3370);
    ++it;
    REQUIRE( (*it) == dest );
}

TEST_CASE("BFS Test Increment Twice", "[bfs]") {
    string adata = "tests/tdata/test_bfs_small_p.dat";
    string rdata = "tests/tdata/test_bfs_small_l.dat";
    Graph graph_small(adata, rdata);
    Airport * start = graph_small.getAirport(3384);
    BFS bfs(start, graph_small);
    BFS::Iterator it = bfs.begin();
    Airport * dest = graph_small.getAirport(3383);
    ++it;
    ++it;
    REQUIRE( (*it) == dest );
}

TEST_CASE("BFS Test", "[bfs]") {
    string adata = "tests/tdata/test_const_airport.dat";
    string rdata = "tests/tdata/test_const_airline.dat";
    Graph graph_small(adata, rdata);
    Airport * start = graph_small.getAirport(2990);
    BFS bfs(start, graph_small);
    BFS::Iterator it = bfs.begin();
    while(it!=bfs.end()) {
        cout << "ID: " <<  (*it)->getId() << endl;
        ++it;
    }
}

TEST_CASE("Map to image small", "[map_proj]")
{
    string adata = "tests/tdata/test_const_airport.dat";
    string rdata = "tests/tdata/test_const_airline.dat";
    Graph graph_small(adata, rdata);
    PNG image = graph_small.mapToImage();
    image.writeToFile("./results/test_images/mapped_small.png");
}

TEST_CASE("Map to image big", "[map_proj]")
{
    string adata = "tests/tdata/test_large_airport.dat";
    string rdata = "tests/tdata/test_large_airline.dat";
    Graph graph_small(adata, rdata);
    PNG image = graph_small.mapToImage();
    image.writeToFile("./results/test_images/mapped_large.png");
}

TEST_CASE("Map to image small trans", "[map_proj]")
{
    string adata = "tests/tdata/test_const_airport.dat";
    string rdata = "tests/tdata/test_const_airline.dat";
    Graph graph_small(adata, rdata);
    Airport * start = graph_small.getAirport(2990);
    BFS bfs(start, graph_small);
    for(auto at:bfs) {

    }
    PNG image = graph_small.mapTrans();
    image.writeToFile("./results/test_images/mapped_small_trans.png");
}

TEST_CASE("Map to image med trans", "[map_proj]")
{
    string adata = "tests/tdata/test_medium_airport.dat";
    string rdata = "tests/tdata/test_large_airline.dat";
    Graph graph_small(adata, rdata);
    Airport * start = graph_small.getAirport(160);
    BFS bfs(start, graph_small);
    for(auto at:bfs) {
    }
    PNG image = graph_small.mapTrans();
    image.writeToFile("./results/test_images/mapped_med_trans.png");
}

TEST_CASE("Map to image big trans", "[map_proj]")
{
    string adata = "tests/tdata/test_large_airport.dat";
    string rdata = "tests/tdata/test_large_airline.dat";
    Graph graph_small(adata, rdata);
    Airport * start = graph_small.getAirport(2048);
    BFS bfs(start, graph_small);
    for(auto at:bfs) {
    }
    PNG image = graph_small.mapTrans();
    image.writeToFile("./results/test_images/mapped_large_trans.png");
}

TEST_CASE("Prim test small", "[prim]") {
    string adata = "tests/tdata/test_const_airport.dat";
    string rdata = "tests/tdata/test_const_airline.dat";
    Graph graph(adata, rdata);
    int startId = 2965;
    int destId = 2966;
    vector<int> path = {2965, 2990, 2966};
    Airport a = *(graph.getAirport(startId));
    Airport b = *(graph.getAirport(destId));
    vector<int> pp = graph.destinationPath(a, b);
    REQUIRE( (path == pp));
}

TEST_CASE("Prim test medium", "[prim]") {
    string adata = "tests/tdata/test_medium_airport.dat";
    string rdata = "tests/tdata/test_large_airline.dat";
    Graph graph(adata, rdata);
    int startId = 3364;
    int destId = 150;
    Airport a = *(graph.getAirport(startId));
    Airport b = *(graph.getAirport(destId));
    vector<int> pp = graph.destinationPath(a, b);
    REQUIRE (vector<int>() == pp);
}

TEST_CASE("Prim test large", "[prim]") {
    string adata = "tests/tdata/airports.dat";
    string rdata = "tests/tdata/routes.dat";
    Graph graph(adata, rdata);
    int startId = 3494;
    int destId = 3364;
    Airport a = *(graph.getAirport(startId));
    Airport b = *(graph.getAirport(destId));
    vector<int> pp = {3494, 3364};
    REQUIRE((pp == graph.destinationPath(a, b)));
}

TEST_CASE("Prim test large mapping", "[prim]") {
    string adata = "tests/tdata/airports.dat";
    string rdata = "tests/tdata/routes.dat";
    Graph graph(adata, rdata);
    int startId = 3494;
    int destId = 3364;
    Airport a = *(graph.getAirport(startId));
    Airport b = *(graph.getAirport(destId));
    PNG image = graph.mapPath(graph.destinationPath(a, b));
    image.writeToFile("./results/test_images/mapped_path.png");
}

