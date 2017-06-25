#pragma once
class MyVector
{
	int* arr;
	size_t size;
	size_t capacity;
	static int counterCreated;// отвичает за количество созданных векторов
	static int counterExisting;// отвичает за количество существующих векторов
public:
	MyVector() : capacity(32), size(0)
	{ 
		arr = new int[32]; 
		++counterCreated;
		++counterExisting;
	}
	MyVector(int* newArr, size_t newSize, size_t newCapacity) : 
		arr(newArr), size(newSize), capacity(2) 
	{
		++counterCreated;
		++counterExisting;
	};
	
	MyVector(const MyVector &newArray) :
		size(newArray.size), capacity(newArray.capacity) {// конструктор капирование
		arr = new int[capacity];
		for (size_t i = 0; i < newArray.size; ++i){ 
			arr[i] = newArray.arr[i]; 
		}
		++counterCreated;
		++counterExisting;
	}
	MyVector(MyVector&& newArray) : arr(newArray.arr), size(newArray.size),
		capacity(newArray.capacity){// конструктор перемещение
		newArray.arr = nullptr;
		newArray.size = newArray.capacity = 0;
	}

	MyVector& operator=(const MyVector& obj);// копирующий оператор присваивание
	MyVector& operator=(MyVector&& obj); // копирующий оператор присваивание
	int* operator[](size_t);

	bool operator> (const MyVector&) const;
	bool operator< (const MyVector&) const;
	bool operator<=(const MyVector&) const;
	bool operator>=(const MyVector&) const;
	bool operator==(const MyVector&) const;
	bool operator!=(const MyVector&) const;

	MyVector operator+(const MyVector newDigit);
	
	int* getArr() const;
	size_t get_size() const;
	size_t get_capacity() const;
	static int getCounterCreated();
	static int getCounterExisting();
	
	void setArr(int*);
	void setSize(const size_t);
	void setCapacity(const size_t);
	// проверяет пуст ли вектор
	bool empty() 
	{
		return capacity;
	}
	// добавляет элемент 
	int* push_back(int);
	int pop_back();
	int& at(size_t);
	~MyVector()
	{
		delete[]arr;
		--counterExisting;
	}
};

