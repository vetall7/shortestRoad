#pragma once

class Point {
	int x, y;
public:
	Point(int x, int y);
	int GetX();
	int GetY();
	Point() = default;

	void SetX(int x);
	void SetY(int y);
};