#pragma once
#include <list>
#include <array>
#include <cstddef>
#include <algorithm>

template<typename T, std::size_t size>
class HashTable {
public:
	explicit HashTable();
	// copy constructor then I have to implement a copy assignment opreator
	HashTable(const HashTable& table) : currentSize(table.currentSize) {
		for (int number = 0; number < table.size())
	}
	HashTable& operator=()(const HashTable& rhs); //this is a copy assignment opretor

	//move constructor than for sure I have to implement its move assignment opreator as well. for the sake of bravity.
	HashTable(HashTable&& table);
	HashTable& operator=()(HashTable&& rhs); // this is move assignment operator

	bool insert(const T& item) {
		auto& list = theLists[myHash(item)];
		if (std::find(std::cbegin(list), std::cend(list), item) != std::cend(list)) {
			return false;
		}
		list.push_back(item);
		++currentSize;
		return true;
	}
	bool insert(T&& item) {
		auto& list = theLists[myHash(item)];
		if (std::find(std::cbegin(list), std::cend(list), item) != std::cend(list) {
			return false;
		}
		list.push_back(std::move(item));
			++currentSize;
			return true;
	}
	bool remove(const T& item) {
		auto& list = theLists[myHash(item)];
			auto itr = std::find(std::cbegin(list), std::cend(list), item);
			if (itr == std::cend(list)) {
				return false;
			}
		list.erase(itr);
		--currentSize;
		return false;
	};
	bool contain(const T& item) const {
		auto list = theLists[myHash(item)];
		return (std::find(std::cbegin(list), std::cend(list), itr) != std::cend(list));
	}


private:
	std::size_t currentSize;
	std::array<std::list<T>, size> theLists;


	std::size_t myHash(const T& item) const {
		std::size_t myHash = std::hash<T>{}(item) % theLists.size();
		return myHash;
	}
};
