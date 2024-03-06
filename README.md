# City Travel Project

## Overview

This project aims to provide a solution for finding the shortest travel time between cities on a rectangular map divided into squares. Each field on the map can either be empty (impassable), part of a road (passable in both directions), or a city (also passable). City names are indicated on the map, with each letter occupying one field. Travelling through one field takes one minute. Additionally, certain cities are connected by one-way air connections, with the name of a city being adjacent (by side or corner) to another city with the first or last letter of its name.

## Implementation Guidelines

- Avoided the use of standard string class and other standard library containers.
- Utilized C++ elements such as classes, references, etc.
- Implemented a custom string class.
- Emphasized code readability.
- Comments are provided where necessary but not mandatory.
- Forbidden the use of smart pointers from the standard library, but allowed implementation of a custom smart pointer class.
- Ensured memory deallocation when deleting elements of the implemented data structures.

## Input Format

The input consists of the following:
- The dimensions of the map: width (w) and height (h).
- The map description with h lines each containing w characters representing empty fields (.), roads (#), cities (*), or letters/numbers for city names.
- The number of flight connections (k).
- k lines describing the flight connections in the format source destination time.
- The number of queries (q).
- Each query appears on a separate line in the format source destination type.

## Output Format

For each query:
- Output one line with the number representing the shortest travel time between the cities.
- If the query type is one, intermediate cities (excluding the starting and ending cities) are listed in the order they were visited, separated by spaces.

## Implementation Details

- Avoided the use of standard string class and other standard library containers.
- Utilized custom classes and data structures to represent the map, cities, and flight connections.
- Algorithms such as Dijkstra's algorithm may be employed to find the shortest path between cities.

## Usage

Compile the program and run it with appropriate input files or input from the command line.

## Example

### Input:
20 20
.........GDANSK..... <br>
................... <br>
........#........... <br>
........#........... <br>
##################. <br>
#SZCZECIN.........#. <br>
#.................#. <br>
##................#. <br>
.#################. <br>
.#...WARSZAWA....... <br>
.#.................. <br>
.#############...... <br>
.#...........#...... <br>
.#..WROCLAW.##...... <br>
.#................ <br>
.####.......#KIELCE. <br>
......##.#########. <br>
.OPOLE..#.*.......#. <br>
........#.KRAKOW..#. <br>
........###########. <br>
0 <br>
3 <br>
KIELCE KRAKOW 0 <br>
KRAKOW GDANSK 0 <br>
KRAKOW GDANSK 1

**Output:**
5 <br>
40 <br>
40 KIELCE SZCZECIN <br>
