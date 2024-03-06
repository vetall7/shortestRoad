<!DOCTYPE html>
<html lang="en">
<body>

    <h1>Rectangular Map Project</h1>
    
    <h2>Description</h2>
    <p>
        A rectangular map divided into squares is given. Each field on the map can be empty (impassable), be part of a road (passable in both directions), or be a city (passable like a road). The name of each city is given on the map, and each letter occupies one field (the field with the letter is impassable). Moving through one field takes one minute. We can only move between fields adjacent by sides. Additionally, selected cities are connected by one-way air connections. The name of a city will be adjacent (by side or corner) to the city with the first or last letter of the name. The name will be unambiguously assigned to the city. There will be no number or letter before or after the name of the city (if there is such a field).
    </p>

    <h2>Implementation Notes</h2>
    <ul>
        <li>Standard string class and other standard library containers cannot be used.</li>
        <li>You can use C++ elements such as classes, references, etc.</li>
        <li>One can implement their own string class.</li>
        <li>Code readability is important, and comments (which are of course allowed) do not necessarily ensure it.</li>
        <li>Smart pointers from the standard library are forbidden, but you can still implement your own smart pointer class.</li>
        <li>Please remember to free memory when deleting elements of the implemented data structures.</li>
    </ul>

    <h2>Input Format</h2>
    <p>
        The first line of input will contain the dimensions of the map: width (w) and height (h). The next h lines (each containing w characters) will describe the map. Each character in the description is a dot (.) representing an empty field, a cross (#) representing a road, an asterisk (*) representing a city, or a letter or number that is part of the city name. The next line will contain a single integer k - the number of flight connections. The next k lines will describe the connections in the format source destination time, where source is the name of the starting city, destination is the name of the destination city, and time is the flight time in minutes. The next line will contain a single integer q - the number of queries. Each query will appear on a separate line and will have the format source destination type. This is a query for the shortest travel time from the source city to the destination city. If the type is zero, the query is only for the time. If the type is one, the route should also be provided.
    </p>

    <h2>Output Format</h2>
    <p>
        For each query, output one line. At the beginning of the line should be the number representing the shortest travel time between the cities. If the query has a type of one, all intermediate cities (excluding the starting and ending cities) should also be listed in the order they were visited, separated by spaces.
    </p>

</body>
</html>
