#pragma once

class Point {
	int x, y, distance;
public:
	Point(int x, int y);
	Point(int x, int y, int distance);
	int GetX();
	int GetY();
	int GetDistance();
	Point() = default;

	void SetX(int x);
	void SetY(int y);

	void DistanceIncrement();


	bool operator<(const Point& other) const {
		return distance < other.distance;
	}
};
