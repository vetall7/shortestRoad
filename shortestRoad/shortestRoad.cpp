#include "Point.h"
#include "String.h"
#include "HashMap.h"
#include <stack>

#define RIGHT 0
#define LEFT 1
#define UP 2
#define DOWN 3

void FindNeighbour(Point& star, int width, int height, char** & array) {
	bool is_find = false;
	std::stack<Point> myStack;
	int counter = 0;
	int x = star.GetX();
	int y = star.GetY();
	short int last_move = -1;
	int crossroads = 0;
	while (!is_find) {
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (i == 0 && j == 0) {
					continue;
				}
				if (array[y + i][x + j] == '#') {
					crossroads++;
				}
			}
		}
		if (crossroads >= 3) {
			myQueue.push(Point(x, y));
		}
		if (x - 1 >= 0 && (array[y][x-1] == '#' || array[y][x-1] == '*') && last_move != RIGHT) {
			x = x - 1;
			last_move = LEFT;
			counter++;
		}
		else if (x + 1 <= width && (array[y][x+1] == '#' || array[y][x + 1] == '*') && last_move != LEFT) {
			x = x + 1;
			last_move = RIGHT;
			counter++;
		}
		else if (y + 1 <= height && (array[y+1][x] == '#' || array[y+1][x] == '*') && last_move != UP) {
			y = y + 1;
			last_move = DOWN;
			counter++;
		}
		else if (y - 1 >= 0 && (array[y-1][x] == '#' || array[y-1][x] == '*') && last_move != DOWN) {
			y = y - 1;
			last_move = UP;
			counter++;
		}
		if (array[y][x] == '*') {
			cout << counter << endl;
			return;
		}
	}
}

void findCities(int width, int height, char**& array, Point& star, HashMap &cities) {
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
					cities.AddCity(sity);
					FindNeighbour(star, width, height, array);
					return;
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
	char** array = new char*[height];
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
		findCities(width, height, array, star, cities);
	}

	cities.Print();

	for (int i = 0; i < height; i++) {
		delete[] array[i];
	}
	delete[] array;
}

