City Travel Project
Overview
This project implements a solution for finding the shortest travel time between cities on a rectangular map divided into squares. Each field on the map can be empty (impassable), part of a road (passable in both directions), or a city (passable like a road). The cities' names are given on the map, and each letter occupies one field. Moving through one field takes one minute. Additionally, selected cities are connected by one-way air connections. The name of a city will be adjacent (by side or corner) to the city with the first or last letter of the name.

Implementation Guidelines
Avoided the use of standard string class and other standard library containers.
Utilized C++ elements such as classes, references, etc.
Implemented a custom string class.
Emphasized code readability.
Comments are provided where necessary but not mandatory.
Forbidden the use of smart pointers from the standard library, but allowed implementation of a custom smart pointer class.
Ensured memory deallocation when deleting elements of the implemented data structures.
Input Format
The input consists of the following:

The dimensions of the map: width (w) and height (h).
The map description with h lines each containing w characters representing empty fields (.), roads (#), cities (*), or letters/numbers for city names.
The number of flight connections (k).
k lines describing the flight connections in the format source destination time.
The number of queries (q).
Each query appears on a separate line in the format source destination type.
