#pragma once

#include <string>
#include <vector>

class Table
{
public:
	Table() {}
	~Table() {}

	int getValue(std::string key);
	std::string getKey(int value);

private:
	bool resizeBuckets();
	float calculateLoadFactor();
	float loadFactor;
	int size;
	std::vector<int> buckets;
};