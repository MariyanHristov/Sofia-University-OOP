#pragma once

template <typename T>
class Vector
{
private:
	T* variable;
	size_t size;

public:
	Vector() = default;
	Vector(const Vector<T>& other);

};
