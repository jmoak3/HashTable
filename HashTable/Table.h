#pragma once

#include <string>
#include <memory>

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
	std::shared_ptr<int> buckets;
};