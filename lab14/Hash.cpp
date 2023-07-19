#include "Hash.h"
#include <iostream>
int HashFunction(int key, int size)    //Хеш-функция
{
	return (key) % size;
}
int HashFunction2(int key, int i, int size) {
	return (key + 12 * i + 3 * i ^ 2) % size;
}
//-------------------------------

//-------------------------------
Object create(int size, int(*getkey)(void*))
{
	return *(new Object(size, getkey));
}
//-------------------------------
Object::Object(int size, int(*getkey)(void*))
{
	N = 0;
	this->size = size;
	this->getKey = getkey;
	this->data = new void* [100];
	for (int i = 0; i < 100; ++i)
		data[i] = NULL;
}
//-------------------------------
bool Object::insert(void* d)
{
	bool b = false;
	int t = getKey(d);
	int j = HashFunction(t, size);
	if (data[j] != NULL) {
		j = HashFunction2(j, size + 5, size);
	}
	if (N != size)

		data[j] = d;
	N++;
	b = true;
	return b;
}
//-------------------------------
int Object::searchInd(int key)
{
	int t = -1;
	bool b = false;
	int j = HashFunction(key, size);
	if (N != 0)
		if (getKey(data[j]) == key)
		{
			t = j; b = true;
		}
		else {
			j = HashFunction2(key, size + 5, size);
			if (getKey(data[j]) == key)
			{
				t = j; b = true;
			}
		}
	return t;
}
//-------------------------------
void* Object::search(int key)
{
	int t = searchInd(key);
	return(t >= 0) ? (data[t]) : (NULL);
}
//-------------------------------
void* Object::deleteByKey(int key)
{
	int i = searchInd(key);
	void* t = data[i];
	if (t != NULL)
	{
		data[i] = DEL;
		N--;
	}
	return t;
}
//-------------------------------
bool Object::deleteByValue(void* d)
{
	return(deleteByKey(getKey(d)) != NULL);
}
//-------------------------------
void Object::scan(void(*f)(void*))
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << " Элемент " << i;
		if ((this->data)[i] == NULL)
			std::cout << "  пусто " << std::endl;
		else
			if ((this->data)[i] == DEL)
				std::cout << "  удален " << std::endl;
			else
				f((this->data)[i]);
	}
}
