#pragma once

#include <string>

class Hasher
{
public:
	static std::hash<std::string> h;
	static int hash(std::string key, int numBuckets)
	{
		return Hasher::h(key) % numBuckets;
	}
};

std::hash<std::string> Hasher::h;
