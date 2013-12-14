#ifndef __ELEVATION__HH__
#define __ELEVATION__HH__

using namespace std;

class Elevation {
private:
	int mHeight;
public:
	Elevation(int);
	~Elevation();
	void setHeight( int );
	int getHeight();
};

#endif
