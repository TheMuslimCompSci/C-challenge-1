#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <ostream>
#include <cmath>
using std::ostream;
using namespace std;
// TODO: your code  goes here

class Item
{

private:
	double latitude;
	double longitude;
	string ID;
	int time;
public:
	Item(double lat, double lon, string id, int ti) : latitude(lat), longitude(lon), ID(id), time(ti)
	{
	
	}

	 double getLatitude() const
	{
		return latitude;

	}
	 double getLongitude() const
	{
		return longitude;
	}
	 string getID() const
	{
		return ID;
	}
	  int getTime() const
	{
		return time;
	}
	//returns distance from the item provided in parameter to the current item
	  double distanceTo(Item anotherItem)
	  {
		  //constants
		  const double pi = 3.14159265358979323846;
		  const double radiusOfEarth = 6373000;
		  //degree to rad
		  double latToRad1 = ((pi / 180)*latitude);
		  double longToRad1 = ((pi / 180)*longitude);
		  double latToRad2 = ((pi / 180)*anotherItem.latitude);
		  double longToRad2 = ((pi / 180)*anotherItem.longitude);
		  //actual calculations
		  double dlon = longToRad2 - longToRad1;
		  double dlat = latToRad2 - latToRad1;
		  double a = pow((sin(dlat / 2)), 2) + cos(latToRad1) * cos(latToRad2) * pow((sin(dlon / 2)), 2);
		  double c = 2 * atan2(sqrt(a), sqrt(1 - a));
		  double distance = radiusOfEarth * c;
		  
		  return distance;
	  }
};
//custom operator to print out the item details
ostream & operator<<(ostream & o, const Item & i) 
{
	o << "{" << i.getLatitude() << ", " << i.getLongitude() << ", \"" << i.getID() << "\", " << i.getTime() << "}";
	return o;
}



// don't write any code below this line

#endif
