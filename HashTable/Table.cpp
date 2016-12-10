#include "Table.h"
#include <iostream>
#include "Hasher.h"

Table::Table() 
	: threshold(0.3f),
	  invalid("That's no good", INT_MIN)
{
	buckets.resize(10, invalid);
	size = 0;
	loadFactor = calculateLoadFactor();
}

int Table::getValue(std::string key)
{
	return buckets.at(Hasher::hash(key, buckets.size())).v;
}

std::string Table::getKey(int value)
{
	std::vector<KV>::iterator it = buckets.begin();
	while (it != buckets.end())
	{
		if (it->v == value) return it->k;
		++it;
	}
	return invalid.k;
}

bool Table::insert(std::string key, int value)
{
	if (loadFactor > threshold)
		resizeBuckets((size+1)*5);

	int destination = Hasher::hash(key, buckets.size());
	if (buckets.at(destination) != invalid)
	{
		//Do we have a legit collision??
		if (buckets.at(destination).k == key) return false;

		//implement a better solution for collisions
		resizeBuckets((size + 1) * 10);
		destination = Hasher::hash(key, buckets.size());
	}

	buckets.insert(
		buckets.erase(buckets.begin() + destination),
		KV(key, value));

	++size;
	return true;
}

int Table::remove(std::string key)
{
	std::vector<KV>::iterator it = buckets.begin();
	while (it != buckets.end())
	{
		if (it->k == key)
		{
			int value = it->v;
			it = buckets.erase(it);
			buckets.insert(it, invalid);
			--size;
			return value;
		}
		++it;
	}
	return invalid.v;
}
int Table::remove(std::string key, int value)
{
	std::vector<KV>::iterator it = buckets.begin();
	KV kv(key, value);
	while (it != buckets.end())
	{
		if (*it == kv)
		{
			it = buckets.erase(it);
			buckets.insert(it, invalid);
			--size;
			return value;
		}
		++it;
	}
	return invalid.v;
}

bool Table::contains(std::string key)
{
	int destination = Hasher::hash(key, buckets.size());
	return (buckets.at(destination) != invalid);
}

bool Table::contains(int value)
{
	return getKey(value) != invalid.k;
}

void Table::displayContents()
{
	std::vector<KV>::iterator it = buckets.begin();
	int count = 0;
	while (it != buckets.end())
	{
		std::cout << it->k << ", " << it->v << std::endl;
		if (*it != invalid)
			++count;
		++it;
	}
	std::cout << std::endl << "Size: " << size << " got: " << count << std::endl;
}

bool Table::resizeBuckets(int newSize)
{
	std::vector<KV> newBucket(newSize, invalid);
	std::vector<KV>::iterator it = buckets.begin();
	while (it != buckets.end())
	{
		if (*it != invalid)
		{
			int destination = Hasher::hash(it->k, newBucket.size());
			if (newBucket.at(destination) != invalid)
			{
				std::cout << "Conflict while resizing. We need to get huger" << std::endl;
				return resizeBuckets(newSize*1.2); // we have a conflict
			}

			newBucket.insert(
				newBucket.erase(newBucket.begin() + destination),
				KV(it->k, it->v));
		}
		++it;
	}
	buckets = newBucket;

	return true;
}

float Table::calculateLoadFactor()
{
	return (float)(size / buckets.size());
}