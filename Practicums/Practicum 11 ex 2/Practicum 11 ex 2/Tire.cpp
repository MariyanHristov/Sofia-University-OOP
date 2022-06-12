#include <iostream>
#include "Tire.h"

std::ostream& operator<<(std::ostream& stream, const Tire& other)
{
	stream << other.id << " by " << other.manufacturer << " - " <<
		other.width << "/" << other.profile << "R" << other.diametre;
	return stream;
}