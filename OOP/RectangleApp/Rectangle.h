#pragma once
class Rectangle
{
private:
	int width;
	int height;
public:
	Rectangle(int pWidth, int pHeight);
	Rectangle(Rectangle &copyRect);
	int getWidth();
	int getHeight();
	int getArea();
	Rectangle& whoIsBigger(Rectangle& pRect);
	~Rectangle();
};

