#include <iostream>
#include <cstring>

template<class T>
class dynamicArray{
private:
	T* data;
	int size;
	int capacity;

public:
	dynamicArray();
	~dynamicArray();

	int get_size();
	int get_capacity();
	bool is_empty();
	T at(int idx);
	void push(T item);
	void insert(int idx, T item);
	void prepend(T item);
	T pop();
	void del(int idx);
	void remove(T item);
	int find(T item);
	void resize();
};

template<class T>
dynamicArray<T>::dynamicArray(){
	size = 0;
	capacity = 16;
	data = new T[capacity];
}

template<class T>
dynamicArray<T>::~dynamicArray(){
	delete[] data;
}

template<class T>
int dynamicArray<T>::get_size(){
	return size;
}

template<class T>
int dynamicArray<T>::get_capacity(){
	return capacity;
}

template<class T>
bool dynamicArray<T>::is_empty(){
	if (size == 0){
		return true;
	} else {
		return false;
	}
}

template<class T>
T dynamicArray<T>::at(int idx){
	return data[idx];
}

template<class T>
void dynamicArray<T>::push(T item){
	if (size == capacity){
		resize();
	}
	data[size] = item;
	size++;
}

template<class T>
void dynamicArray<T>::insert(int idx, T item){
	if (size == capacity){
		resize();
	}
	memcpy(data+(idx+1)*sizeof(T), data+idx*sizeof(T), (size-idx)*sizeof(T));
	data[idx] = item;
	size++;
}

template<class T>
void dynamicArray<T>::prepend(T item){
	insert(0, item);
	size++;
}

template<class T>
T dynamicArray<T>::pop(){
	T temp = data[0];
	memcpy(data, data+sizeof(T), (size-1)*sizeof(T));
	size--;
	return temp;
}

template<class T>
void dynamicArray<T>::del(int idx){
	if (idx == size-1){
		size--;
	} else {
		memcpy(data+idx*sizeof(T), data+(idx+1)*sizeof(T), (size-idx-1*sizeof(T)));
		size--;
	}
}

template<class T>
void dynamicArray<T>::remove(T item){
	for (int i = 0; i < size; i++){
		if (data[i] == item){
			del(i);
		}
	}
}

template<class T>
int dynamicArray<T>::find(T item){
	for (int i = 0; i < size; i++){
		if (data[i] == item){
			return i;
		}
	}
	return -1;
}

template<class T>
void dynamicArray<T>::resize(){
	capacity = capacity*2;
	T* temp = data;
	data = new T[capacity];
	memcpy(data, temp, capacity*sizeof(T));
	delete[] temp;
}
