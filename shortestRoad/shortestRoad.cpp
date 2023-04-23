#include "Point.h"
#include "String.h"
#include "HashMap.h"
#include "Stack.h"
#include "Stack.cpp"
#include <queue>
#include "PriorityQueue.h"

String findCities(int width, int height, char**& array, Point& star);

void FindNeighbour(Point& star, int width, int height, char**& array, HashMap& cities, list<String>& cities_names) {
	bool is_find = false;
	Stack<Point> myStack(1000);
	//PriorityQueue<Point> myStack;
	//queue<Point> myStack;
	bool** visited = new bool* [height];

	for (int i = 0; i < height; i++) {
		visited[i] = new bool[width];
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			visited[i][j] = true;
		}
	}

	String main_city = findCities(width, height, array, star);
	star.DistanceIncrement();
	cities_names.push_back(main_city);
	cities.AddCity(findCities(width, height, array, star), cities_names.GetSize() - 1);
	myStack.push(star);
	while (!is_find) {
		myStack.pop();
		for (int i = -1; i <= 1; i += 2) {
			if (star.GetY() + i >= 0 && star.GetY() + i < height && array[star.GetY() + i][star.GetX()] == '#' && visited[star.GetY() + i][star.GetX()]) {
				myStack.push(Point(star.GetX(), star.GetY() + i, star.GetDistance()));
			}
			if (star.GetX() + i >= 0 && star.GetX() + i < width && array[star.GetY()][star.GetX() + i] == '#' && visited[star.GetY()][star.GetX() + i]) {
				myStack.push(Point(star.GetX() + i, star.GetY(), star.GetDistance()));
			}
			if (star.GetY() + i >= 0 && star.GetY() + i < height && array[star.GetY() + i][star.GetX()] == '*' && visited[star.GetY() + i][star.GetX()]) {
				Point temp(star.GetX(), star.GetY() + i, star.GetDistance());
				cities.AddNeighbour(main_city, findCities(width, height, array, temp), star.GetDistance());

			}
			if (star.GetX() + i >= 0 && star.GetX() + i < width && array[star.GetY()][star.GetX() + i] == '*' && visited[star.GetY()][star.GetX() + i]) {
				Point temp(star.GetX() + i, star.GetY(), star.GetDistance());
				cities.AddNeighbour(main_city, findCities(width, height, array, temp), star.GetDistance());
			}
		}
		//cout << myStack.size() << endl;
		visited[star.GetY()][star.GetX()] = false;
		if (myStack.empty()) {
			is_find = true;
		}
		else {
			star = myStack.top();
			star.DistanceIncrement();
		}
	}

	for (int i = 0; i < height; i++) {
		delete[] visited[i];
	}
	delete[] visited;
}

//void FindNeighbour(Point& star, int width, int height, char**& array, HashMap& cities, list<String>& cities_names) {
//	bool is_find = false;
//	priority_queue<Point, vector<Point>, less<Point>> myQueue;
//	int counter = 0;
//
//	bool** visited = new bool* [height];
//
//	for (int i = 0; i < height; i++) {
//		visited[i] = new bool[width];
//	}
//	for (int i = 0; i < height; i++) {
//		for (int j = 0; j < width; j++) {
//			visited[i][j] = true;
//		}
//	}
//
//	String main_city = findCities(width, height, array, star);
//	star.DistanceIncrement();
//	cities_names.push_back(main_city);
//	cities.AddCity(findCities(width, height, array, star), cities_names.GetSize() - 1);
//	myQueue.push(star);
//	if (main_city == "D") {
//		cout << "asdfasdfasdf";
//	}
//	while (!is_find) {
//		star = myQueue.top();
//		myQueue.pop();
//		for (int i = -1; i <= 1; i += 2) {
//			if (star.GetY() + i >= 0 && star.GetY() + i < height && array[star.GetY() + i][star.GetX()] == '#' && visited[star.GetY() + i][star.GetX()]) {
//				myQueue.push(Point(star.GetX(), star.GetY() + i, star.GetDistance()));
//				counter++;
//			}
//			if (star.GetX() + i >= 0 && star.GetX() + i < width && array[star.GetY()][star.GetX() + i] == '#' && visited[star.GetY()][star.GetX() + i]) {
//				myQueue.push(Point(star.GetX() + i, star.GetY(), star.GetDistance()));
//				counter++;
//			}
//			if (star.GetY() + i >= 0 && star.GetY() + i < height && array[star.GetY() + i][star.GetX()] == '*' && visited[star.GetY() + i][star.GetX()]) {
//				Point temp(star.GetX(), star.GetY() + i, star.GetDistance());
//				cities.AddNeighbour(main_city, findCities(width, height, array, temp), star.GetDistance());
//			}
//			if (star.GetX() + i >= 0 && star.GetX() + i < width && array[star.GetY()][star.GetX() + i] == '*' && visited[star.GetY()][star.GetX() + i]) {
//				Point temp(star.GetX() + i, star.GetY(), star.GetDistance());
//				cities.AddNeighbour(main_city, findCities(width, height, array, temp), star.GetDistance());
//			}
//		}
//		visited[star.GetY()][star.GetX()] = false;
//		if (myQueue.empty()) {
//			is_find = true;
//		}
//		else {
//			star.DistanceIncrement();
//		}
//	}
//
//	for (int i = 0; i < height; i++) {
//		delete[] visited[i];
//	}
//	delete[] visited;
//}


String findCities(int width, int height, char**& array, Point& star) {
	String city = "";
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i == 0 && j == 0) {
				continue;
			}
			if (star.GetX() + j >= 0 && star.GetX() + j <= width && star.GetY() + i >= 0 && star.GetY() + i <= height) {
				if (array[star.GetY() + i][star.GetX() + j] >= 'A' && array[star.GetY() + i][star.GetX() + j] <= 'Z') {
					if (j + 1 <= width && j - 1 >= 0 && array[star.GetY() + i + 1][star.GetX() + j] >= 'A' && array[star.GetY() + i + 1][star.GetX() + j] <= 'Z' && array[star.GetY() + i - 1][star.GetX() + j] >= 'A' && array[star.GetY() + i - 1][star.GetX() + j] <= 'Z') {
						continue;
					}
					int coordinate = star.GetX() + j;
					while (coordinate >= 0 && array[star.GetY() + i][ coordinate] != '.' && array[star.GetY() + i][ coordinate] != '#' && array[star.GetY() + i][coordinate] != '*') {
						coordinate--;
					}
					coordinate++;
					while (coordinate <= width-1 && array[star.GetY() + i][ coordinate] != '.' && array[star.GetY() + i][ coordinate] != '#' && array[star.GetY() + i][coordinate] != '*') {
						if (array[star.GetY() + i][coordinate] != '*') city.append(array[star.GetY() + i][coordinate]);
						coordinate++;
					}
					return city;
				}
			}
		}
	}
	return "";
}


void Dijkstra(String from, String to, int city_counter, list<String>& cities_names, HashMap& citiesMap, int mode) {
	if (to == from) {
		cout << 0 << endl;
		return;
	}
	bool is_from = false, is_to = false;
	for (String i : cities_names) {
		if (i == from) {
			is_from = true;
		}
		if (i == to) {
			is_to = true;
		}
	}
	if (!is_to || !is_from) {
		cout << "&&&&&&&&&&&&&&&&&&" << endl;
		return;
	}
	int* cities = new int[city_counter];
	int* prev = new int[city_counter]; // New array to keep track of previous city

	int index = 0;
	priority_queue<City*, vector<City*>, less<City*>> pq;
	for (String i : cities_names) {
		if (i == from) {
			cities[index] = 0;
			index++;
			continue;
		}
		cities[index] = numeric_limits<int>::max();
		index++;
	}

	pq.push(citiesMap.GetCity(from));
	while (!pq.empty()) {
		// Get the city with the smallest distance from the starting city
		City* curr = pq.top();
		pq.pop();

		// Stop searching if we've found the destination city
		if (curr->GetName() == to) {
			break;
		}

		// Update distances to neighboring cities
		for (Neighbour neighbor : *citiesMap.GetCity(curr->GetName())->GetNeighbours()) {
			int neighbor_index = citiesMap.GetCity(neighbor.GetName())->GetIndex();
			int tentative_distance = curr->GetTotalDistance() + neighbor.GetDistance();
			if (tentative_distance < cities[neighbor_index]) {
				cities[neighbor_index] = tentative_distance;
				prev[neighbor_index] = curr->GetIndex(); // Record the previous city
				pq.push(citiesMap.GetCity(neighbor.GetName()));
				citiesMap.GetCity(neighbor.GetName())->SetDistance(tentative_distance);
			}
		}
	}
	cout << cities[citiesMap.GetCity(to)->GetIndex()];

	if (mode == 1) {
		list<String> path;
		int curr_index = citiesMap.GetCity(to)->GetIndex();
		while (curr_index != citiesMap.GetCity(from)->GetIndex()) {
			path.push_back(citiesMap.GetCity(cities_names[curr_index])->GetName());
			curr_index = prev[curr_index];
		}
		path.push_back(from);

		for (int i = path.GetSize() - 2; i >= 1; i--) {
			cout << " " << path[i];
		}
	}

	cout << endl;
	// Reset distances and previous city array
	for (String i : cities_names) {
		citiesMap.GetCity(i)->DistanceToZero();
	}
	delete[] cities;
	delete[] prev;
}


int main()
{
	HashMap cities(1000);
	list<Point> stars;
	list<String> cities_names;
	int width, height;
	cin >> width >> height;
	char** array = new char* [height];
	for (int i = 0; i < height; i++) {
		array[i] = new char[width];
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> array[i][j];
			if (array[i][j] == '*') {
				stars.push_back(Point(j, i));
			}
		}
	}

	for (Point star : stars) {
		FindNeighbour(star, width, height, array, cities, cities_names);
	}

	/*for (String i : cities_names) {
		cout << i << " ";
	}
	return 0;*/

	cities.Print();

	int flights;
	cin >> flights;
	for (int i = 0; i < flights; i++) {
		char array[50], array2[50];
		int dist;
		cin >> array >> array2 >> dist;
		String main(array);
		String to_city(array2);
		cities.AddNeighbour(main, to_city, dist);
	}

	int roads;
	cin >> roads;
	for (int i = 0; i < roads; i++) {
		char array[50], array2[50];
		int mode;
		cin >> array >> array2 >> mode;
		String main(array);
		String to_city(array2);
		Dijkstra(main, to_city, stars.GetSize(), cities_names, cities, mode);
	}


	for (int i = 0; i < height; i++) {
		delete[] array[i];
	}
	delete[] array;

}
