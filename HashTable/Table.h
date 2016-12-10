#pragma once

#include <string>
#include <vector>

//INT_MIN is invalid state for value
//"That's no good" is invalid state for key
class KV
{
public:
	KV(std::string key, int value) :k(key), v(value) {}
	~KV() {}
public:
	std::string k;
	int v;
	bool operator==(const KV& kv) const
	{
		return (kv.k == k && kv.v == v);
	}
	bool operator!=(const KV& kv) const
	{
		return (kv.k != k || kv.v != v);
	}
};

class Table
{
public:
	Table();
	~Table() {}

	int getValue(std::string key);
	std::string getKey(int value);
	bool insert(std::string key, int value);
	int remove(std::string key);
	int remove(std::string key, int value);
	bool contains(std::string key);
	bool contains(int value);

	void displayContents();

private:
	bool resizeBuckets(int newSize);
	float calculateLoadFactor();

	const KV invalid;
	float loadFactor;
	const float threshold;
	int size;
	std::vector<KV> buckets;
};