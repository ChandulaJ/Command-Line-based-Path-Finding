# DSA-Project
Shortest path

Project Proporsal
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
Project Title: Finding the shortest and quickest path in a given map

Overview

This is a console application developed so that a user can find the shortest path and the quickest path from the available routes on the given map. 
The shortest and the quickest routes will be shown to the user respective to several modes of transportation.

The internal operation of the application is planned to follow the following steps;

* Displaying the map to the user
* Defining the start and the destination points by the user
* Identifying the shortest route and the quickest route
* Displaying the shortest route and quickest route
  
The approximate traveling time and distance for the shortest and quickest paths will also be displayed.

Main data structures and algorithms that are intended to use in developing the application:

* Graphs
* Dijkstra's Algorithm
  
Scope

In this project, we consider a scenario where we have a road network of known layout and the data related to each road including the distance of the road, 
maximum speed limit, and possible methods of transportation are known. In this project, we expect to consider only two options for the mode of transportation 
which are by motorcycle and by car.

Methodology

To create this console application, the basic algorithm to be used is Dijkstra's Algorithm. This algorithm uses weighted graphs to find the shortest path between 
a set of nodes that represent different points on the map. The sum of total time spent and distance will also be calculated. Firstly, the user will be shown a map 
which will be generated on the command line interface. Then, the user should select starting and end points on the map. Next, the console will display the shortest 
routes and the quickest routes respective to the two traveling modes and also the traveling times and distances related to the corresponding routes.

Objectives

* Find the shortest route and quickest route to the destination on the given map
* Calculate the time taken to reach the destination through the shortest route and the quickest route through different modes of transportation
* Calculate the distance to the destination through the shortest route and the quickest route through different modes of transportation

Instructions
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
* Run the project
* Copy and paste all the content in the map.txt file and hit enter to input the map
* Nodes corresponding to the shortest path will be highlighted in cyan (light blue) color
* Maximum map size is 52 x 52
