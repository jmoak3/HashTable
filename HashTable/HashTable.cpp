#include <iostream>
#include "Table.h"

int main()
{
	Table hashTable;
	std::cout << "storing 5 into 'hash'" << std::endl;
	hashTable.insert("hash", 5);
	hashTable.displayContents();

	std::cout << std::endl << "storing 4 3 2 9 0 -1 -5 into 'hello' 'my' 'name' 'uh' 'borat' 'I like you' 'I like sex'" << std::endl;
	hashTable.insert("hello", 4);
	hashTable.insert("my", 3);
	hashTable.insert("name", 2);
	hashTable.insert("uh", 9);
	hashTable.insert("borat", 0);
	hashTable.insert("I like you", -1);
	hashTable.insert("I like sex", -5);
	hashTable.displayContents();

	std::cout << std::endl << "removing 'hello'" << std::endl;
	hashTable.remove("hello");
	hashTable.displayContents();

	std::cout << std::endl << "is 'hello' in table? " << hashTable.contains("hello") << std::endl;
	std::cout << std::endl << "is 'hash' in table? " << hashTable.contains("hash") <<  std::endl;

	std::cout << std::endl << "getting the value in 'hash' " << hashTable.getValue("hash") << std::endl << std::endl;
	
	std::cout << std::endl << "getting the value in 'uh' " << hashTable.getValue("uh") << std::endl << std::endl;

	std::cin.get();
	return 0;
}