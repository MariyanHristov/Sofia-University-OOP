#include <iostream>
#include "Engine.h"

std::ostream& operator<<(std::ostream& stream, const Engine& other)
{
	stream << other.id << " by " << other.manufacturer << " - " <<
		other.description << " - " << other.horsePower << "hp";

	return stream;
}
