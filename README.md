# CS 225 Final Project

## Team Members: Xin Yi Huang, Tommy Kimura, Run Zhong Li, Taige Zhang

### Motivation

- We are trying to simulate the spread of an unknown virus through airlines. We will use the [OpenFlights database](openflights.org/data.html) to map the airports and airlines onto a World map image. Given an origin Airport and a destination Airport, we will use BFS traversal and Prim's algorithm to find the path for the virus to reach from the origin airport to the destination airport. Each edge between the airports represents an airline, and the techniques we used allow us to discover the number of airports the virus has infected. On top of that, we would also like to map the transmissibility of the virus by coloring airports closer to the origin (point A) with a darker shade of red while the ones further away with the color green.

#### Video Presentation Link

- [Video](https://www.youtube.com/watch?v=r6t7QcIH4PY&t=4s)

### Project outline

#### Data

- You can find two full datasets in the data folder `data/`
  - `airports.dat`
  - `routes.dat`
- We also provide smaller datasets in the folder `tests/tdata`
  - We provide 7 datasets
  - `test_bfs_small_l.dat`
    - This is the smallest airline dataset that contains 2 airline data used for a small BFS test
  - `test_bfs_small_p.dat`
    - This is the smallest airport dataset that contains 3 airport data used for a small BFS test
  - `test_const_airline.dat`
    - This is a small airline dataset that contains 39 airline data used for simple testings like Map projection or Prim's algorithm
  - `test_const_airport.dat`
    - This is a small airport dataset that contains 79 airport data used for simple testings like Map projection or Prim's algorithm
  - `test_large_airline.dat`
    - This is a large airline dataset that contains 67663 airline data used for simple testings like Map projection or Prim's algorithm
  - `test_large_airport.dat`
    - This is a large airport dataset that contains 2000 airport data used for simple testings like Map projection or Prim's algorithm
  - `test_medium_airport.dat`
    - This is a medium airport dataset that contains 466 airport data used for simple testings like Map projection or Prim's algorithm

- Credits
  - Openflights

#### Commands

- We wrote a Makefile so that anyone could run our program with simple lines
- **IF THERE IS A LINKING ISSUE, PLEASE TRY `MAKE CLEAN` FIRST**
- For **testing**
  - `make test`
  - `./test`
- For **main**
  - `make`
  - `./finalproj argv[1] argv[2] argv[3] argv[4]`
    - `argv[1]` is a string input that represents the airport data directory, e.g `"tests/tdata/test_bfs_small_l.dat"`
    - `argv[2]` is a string input that represents the airline data directory, e.g `"tests/tdata/test_bfs_small_p.dat"`
    - `argv[3]` is an integer input that represents the origin airport ID, e.g `3384`
    - `argv[4]` is an integer input that represents the destination airport ID, e.g `3383`
  - Example: `./finalproj "tests/tdata/test_bfs_small_l.dat" "tests/tdata/test_bfs_small_p.dat" 3384 3383`
- Clean the directory with `make clean`

#### Files

- Please read comments in the header files for specfic information regarding each method
- **`main.cpp`**
  - Our main file, you can run it with `make` (see above)
- **data folder**
  - Contains two datasets `airports.dat` and `routes.dat` for grader's convenience
- **graph class**
  - `graph.cpp` `graph.h`
  - Has our major functions such as map projection and prim's algorithm
  - Has a custom constructor that takes in airport and airline file directories as inputs
  - includes readFromFile
- **`airport.h`**
  - A separate class that represents an airport, or a node, mainly used in graph class for most of the algorithms.
- **`airline.h`**
  - A separate class that represents an airline, or an edge, mainly used in graph class for Map projection.
- **GridTraversal & BFS classes**
  - `GridTraversal.cpp` `GridTraversal.h` `BFS.cpp` `BFS.h`
  - Classes mainly for graph traversal
  - includes graph class
- **tests folder**
  - `tests.cpp`
  - Contains test data and test file
- **readFromFile**
  - `readFromFile.cpp` `readFromFile.hpp`
  - Has functions that allow us to read data from the .dat file
  - used in graph class
- **`Makefile`**
  - Our Makefile
- **.objs and cs225 folder**
  - `cs225` folder has PNG class and HSLAPixel class used for Map projection
  - `.objs` folder has all the files for execution
- **`world_map.png`**
  - The original image that we will project our nodes onto
- **results folder**
  - Contains our `results.md` documentation and some image sources. Our test cases would also output the image to the folder `test_images` under this directory.
- **weekly_development_log**
  - Contains our `development.md` documentation
- **`project_proposal.md`**
  - Our project proposal file

#### Outputs

- We are running datasets that contains more than 10000 data, and our program would traverse through these airports and airlines, so it will inevitably take a few moments.
- **Tests**
  - Some of our test cases will generate image files in the `results/test_images` directory
  - There will also be a few printed statements
  
  ``` c++
  ID: 2990
  ID: 2965
  ID: 2966
  ID: 2968
  ID: 2948
  ID: 2975
  ID: 2962
  ID: 2972
  Not Found
  ```
- **Main**
  - Our main program will generate at most three image files depending on the validity of the inputs.
  - These image files are called `map_graph.png`, `map_path.png`, `map_trans_graph.png`
  - If these files are missing, it means there is an invalid input, the starting airport is not valid, or there is no path between airport A and airport B in our dataset.

#### Tests

- We have classified our tests into four different types
- For more information regarding each type of test case, please read our `results.md`
  - graph_default
    - 3 tests that test graph default and custom constructor
    - Checks methods `getAirportCount()` and `getAirlineCount()`
  - bfs
    - 4 tests that test BFS traversal
    - Tests `++it`, `begin()`, `end()`, `enhanced for loop`, simple full BFS test
  - prim
    - 4 tests that test Prim's algorithm
    - Test find simple path, test path projection to image `mapped_const_path.png`
  - map_proj
    - 5 tests that test Map projection
    - Test small and large dataset simple projection
      - Image output: `mapped_small.png`, `mapped_large.png`
    - Test small, medium airport, and large dataset transimissibility projection
      - Image output: `mapped_small_trans.png`, `mapped_med_trans.png`, `mapped_large_trans.png`
      - These test cases also retest BFS traversal, since it requires a full run of BFS traversal to mark the heights before the projection
- You can test specific type with `make test && ./test [typename]`
