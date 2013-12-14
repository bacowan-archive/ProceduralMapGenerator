#include "Elevation.hh"

Elevation::Elevation(int height)
{
	mHeight = height;
}

Elevation::~Elevation()
{
}

void Elevation::setHeight( int height )
{
	mHeight = height;
}

int Elevation::getHeight()
{
	return mHeight;
}
