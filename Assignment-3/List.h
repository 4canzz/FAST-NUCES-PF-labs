/**
 * LIST HEADER FILE
 * CS1002
 * Programming Fundamentals - Assignment 3
 * Syed Furqan Hassan
 * 24L - 6116
 * BEE - 2D
 **/

#pragma once
#include <iostream>
using namespace std;

template <typename var>
class List {
private:
	int size;
	var* arr;
	int count;
public:
	List() : size(0), arr(nullptr), count(0) {}
	List(int s) : size(s), count(0) { arr = new var[size]; }
	~List() {
		delete[] arr;
    }
	int getCount() const { return count; }


	bool add(var item) {
		if (count < size) {
			arr[count++] = item;
			return true;
		}
		return false;
	}

	var& operator[](int index) {
		return arr[index];
	}
};

template <typename var>
ostream& operator<<(ostream& os, const List<var>& list) {
	for (int i = 0; i < list.getCount(); i++) {
		os << *(list.arr[i]) << endl;
	}
	return os;
}
