#include "Point.h"
#include "String.h"
#include "HashMap.h"
#include "Stack.h"
#include "Stack.cpp"


String findCities(int width, int height, char**& array, Point& star);

void FindNeighbour(Point& star, int width, int height, char** & array, HashMap& cities) {
	bool is_find = false;
	Stack<Point> myStack(100);
	int counter = 0;

	bool** visited = new bool*[height];

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
	cities.AddCity(findCities(width, height, array, star));

	myStack.push(star);
	while (!is_find) {
		myStack.pop();
		for (int i = -1; i <= 1; i+=2) {
			if (star.GetY() + i >= 0 && star.GetY() + i < height && array[star.GetY() + i][star.GetX()] == '#' && visited[star.GetY() + i][star.GetX()]) {
				myStack.push(Point(star.GetX(), star.GetY()+i, star.GetDistance()));
				counter++;
			}
			if (star.GetX() + i >= 0 && star.GetX() + i < width && array[star.GetY()][star.GetX()+i] == '#' && visited[star.GetY()][star.GetX()+i]) {
				myStack.push(Point(star.GetX()+i, star.GetY(), star.GetDistance()));
				counter++;
			}
			if (star.GetY() + i >= 0 && star.GetY() + i < height && array[star.GetY() + i][star.GetX()] == '*' && visited[star.GetY() + i][star.GetX()]) {
				Point temp(star.GetX(), star.GetY() + i, star.GetDistance());
				cities.AddNeighbour(main_city, findCities(width, height, array, temp), star.GetDistance());
			}
			if (star.GetX() + i >= 0 && star.GetX() + i < width && array[star.GetY()][star.GetX()+i] == '*' && visited[star.GetY()][star.GetX()+i]) {
				Point temp(star.GetX()+i, star.GetY(), star.GetDistance());
				cities.AddNeighbour(main_city, findCities(width, height, array, temp), star.GetDistance());
			}
		}
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


String findCities(int width, int height, char**& array, Point& star) {
	String sity = "";
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
					while (coordinate >= 0 && array[star.GetY() + i][ coordinate] != '.' && array[star.GetY() + i][ coordinate] != '#') {
						coordinate--;
					}
					coordinate++;
					while (coordinate <= width && array[star.GetY() + i][ coordinate] != '.' && array[star.GetY() + i][ coordinate] != '#') {
						sity.append(array[star.GetY() + i][ coordinate]);
						coordinate++;
					}
					return sity;
				}
			}
		}
	}
}

int main()
{
	HashMap cities(1000);
	list<Point> stars;
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
		FindNeighbour(star, width, height, array, cities);
	}

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

	cities.Print();

	for (int i = 0; i < height; i++) {
		delete[] array[i];
	}
	delete[] array;

}
