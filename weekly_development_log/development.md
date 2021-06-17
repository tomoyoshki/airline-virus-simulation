# Development  

## taige2-xinyih8-tkimura4-rl17

### Week 1 (April 15th - April 22nd)

During the weekly meeting on April 15th, we decided to finish individual MP Mazes first so we could focus on this final project together. After finishing MP Mazes on Tuesday, we began with creating initial set up files such as `Makefile` and `catch/`. We then worked on data processing. We first downloaded the airport data from OpenFlights and separated it into three sets of data: `data/small_data_20.dat`, `data/medium_data_200.dat`, `data/large_data_2000.dat`. Then, we looked through StackOverflow and created a few functions that turn lines of data into vector of strings. These functions are in `readFromFile.cpp`. Lastly, we used these functions in `main.cpp` for simple testings, and the output can be found under the `processed_data` directory. Beside data processing, we started building our graph class. For this graph, we have completed a struct called Airport, which will contain Airport information. A constructor `Graph()` is also implemented, which will read data from a file and then create airport nodes. We have not implemented the edges (airlines) between the nodes(airports) yet, and this will be one of our major goal next week. 

#### Goals (April 15th)

- Set up the initial coding files
- Start processing data from OpenFlight
- Determine the data structure and write corresponding components
  - Graphs
  - Nodes
  - Edges
- Convert array format into graph format and create simple tests
- Finish MP Mazes

#### Accomplishments (April 22nd)

- MP Mazes
- Process OpenFlight data  
  - Airport information in a string vector
  - Output to processed_data/ directory with the original data filename
- A class for the graph
- A struct in the graph class that represents the airport node
- Initial coding files including Makefile and Catch

#### Going further

- Turn data into a graph
- Design edges in the graph
- BFS Traversal and Prim's 
- Create some simple test cases
- Documentation

#### Comments

- We decided to finish MP Mazes first so we could concentrate on the final project this week

### Week 2 (April 23th - April 30th)

During this week, we fist continued on the work of data processing to convert the array format into graph format, which includes fixing default constructor `Graph()`, adding custom constructor `Graph(string airportFile, string airlineFile)`, and adding some functions. We have completed a class called Airline, which is the edge to connect two airports(nodes). And we also turned the struct called Airport in the Graph class into a separate class, which contains Airport information. Besides, three test cases are written in `tests.cpp` to verify the graph created. Finally, BFS iterator is also completed. In the next week, we will focus on implementing Prim’s algorithm.

#### Goals (April 23rd)

- convert array format into graph format and pass simple tests
- write BFS iterator and verify with tests
- write Prim’s and verify with tests

#### Accomplishments (April 30th)

- further on graph class
  - default constructor 
  - custom constructor
  - some functions
- a class called Airline
- a class called Airport
- BFS traversal
- some test cases

#### Going further

- Prim’s algorithm

#### Comments

### Week 3 (May 1st - May 8th)

During the weekly meeting on May 2ed, we planned to finish Prim’s algorithm, which aims to find the shortest path between starting airport and destination airport, and project our found shortest path (subgraph) onto a world map. To implement these goals, we wrote two functions in `graph.cpp`, which are named as `mapToImage()` and `drawLine()`. Besides, two test cases called `"map to image small"` and `"map to image big"` were written on `tests.cpp` to verify graph projection. The output image can be found on `mapped_large.png`. Then, on the second group meeting during this week, we decided to start working on final report and final presentation and record our video in next meeting. Prim's algorithm will be implemented next week.

#### Goals (May 1st)

- Prim's algorithm
- Map to World Map image
- Start final reports
- Add more test cases

#### Accomplishments (May 8th) 
- Map to World Map image
  - mapToImage()
  - drawLine()
- some test cases

#### Going further

- final report
- final presentation
- Prim's algorithm

#### Comments

- nothing really

### Week 4 (May 9th - May 12th)

During the weekly meeting on May 9th, we decided to mainly focus on making the video for our final presentation and writing the result document as our final report. We also finished implementing Prims' algorithm, and wrote corresponding test cases for it. Furthermore, we finished building our main executable, and anyone can just run our program with ./finalproj with their own selections of inputs. Bseides the coding part, we finished making the recordings and successfully uploaded the video to YouTube. In addition, we also finished our report and readMe file for the grader to view. We were able to finish these assignments on May 12th, which is before the deadline. We used many pictures as supplementation to explain the result of our project, making this report appealing and easy to understand. Our video is made with efforts to illustrate the project. It explains the algorithm well and presents various images and outputs.

#### Goals (May 8th)

- final report
- final presentation
- Prim's algorithm

#### Accomplishments (May 15th)

- final report
- final presentation
- Prim's algorithm
- More test cases
- Main

#### Going further

- nothing

#### Comments

- We are done!
