#pragma once

template<typename T, typename U>

class Pair
{
private:
	T variable1;
	U variable2;

public:

	Pair() = default;

	Pair(const T& var1, const U& var2)
	{
		variable1 = var1;
		variable2 = var2;
	}

	void setVariable1(const T& variable1)
	{
		this->variable1 = variable1;
	}

	void setVariable2(const U& variable2)
	{
		this->variable2 = variable2;
	}

	const T& getVariable1() const
	{
		return variable1;
	}

	const U& getVariable2() const
	{
		return variable2;
	}

	bool operator==(const Pair& other) const
	{
		return *this == other;
	}

	bool operator!=(const Pair& other) const
	{
		return !(*this == other);
	}
};
