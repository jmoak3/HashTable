#include "Table.h"

int Table::getValue(std::string key)
{
	return 0;
}

std::string Table::getKey(int value)
{
	return 0;
}

bool Table::resizeBuckets()
{
	return false;
}

float Table::calculateLoadFactor()
{
	return size / buckets.size();
}