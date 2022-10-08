#include "Rectangle.h"
#include "CommonHeader.h"

Rectangle::Rectangle(int pWidth, int pHeight)
{
	cout << "\n\nRectangle created";
	width = pWidth;
	height = pHeight;
}

Rectangle::Rectangle(Rectangle& copyRect)
{
	this->width = copyRect.width;
	this->height = copyRect.height;
	cout << "Copy constructor called" << endl;
}

int Rectangle::getWidth()
{
	return width;
}

int Rectangle::getHeight()
{
	return height;
}

int Rectangle::getArea()
{
	return height*width;
}

Rectangle& Rectangle::whoIsBigger(Rectangle& pRect)
{
	if (this->getArea() < pRect.getArea() ){
		return pRect;
	}
	return *this;
}

Rectangle::~Rectangle()
{
	cout << "\nDestroying rectangle";
}
