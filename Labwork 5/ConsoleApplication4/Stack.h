#pragma once
template <typename T>
class Stack
{
	T* stackPtr; // указатель на стек
	const size_t maxSize = 1000; // максимальный размер стека
	int top; // индекс вершины 
public:

	Stack(const size_t Size):maxSize(Size), top(0){
		stackPtr = new T[maxSize];
	}

	Stack(const Stack& newStack) : top(newStack.top){
		if (this == &newStack) {
			return;
		}
		delete[] stackPtr;
		stackPtr = new T[maxSize];
		for (size_t i = 0; i <= top; ++i) {
			stackPtr[i] = newStack.stackPtr[i];
		}
	}
	
	Stack(Stack&& newStack) :
		stackPtr(newStack.stackPtr), top(newStack.top) {
		if (this == &newStack) {
			return;
		}
		delete[] stackPtr;
		stackPtr = newStack.stackPtr;
		newStack.stackPtr = 0;
		newStack.stackPtr = nullptr;
	}



	bool empty() { return top; }


	void push(const T& value) {
		if (top < maxSize) {
			stackPtr[top++] = value;
		}
	}  

	void pop() {
		if (top > 0) {
			stackPtr[--top];
		}
	}  

	
	T getTopValue() const { return stackPtr[top]; }
	T* getStackPtr() const { return stackPtr; }
	int getSize() const { return top + 1; }  // получить размер стека
	

	Stack& operator=(const Stack& obj) {
		if (this == &obj) {
			return *this;
		}
		delete[] stackPtr;
		stackPtr = new T[maxSize];
		for (size_t i = 0; i <= top; ++i) {
			stackPtr[i] = obj.stackPtr[i]; 
		}
		return *this;
	}


	Stack& operator=(Stack&& obj) {
		if (this == &obj) {
			return *this;
		}
		delete[] stackPtr;
		stackPtr = obj.stackPtr;
		obj.stackPtr = 0;
		obj.stackPtr = nullptr;
		return *this;
	}


	bool operator==(const Stack& obj) {
		if (getSize() == obj.getSize())
		{
			for (T* ptr = getStackPtr(), *ptrObj = obj.getStackPtr();
				ptr < getStackPtr() + getSize();
				++ptr, ++ptrObj)
			{
				if (ptr != ptrObj) {
					return false;
				}
			}
			return true;
		}
		return false;
	}
	

	bool operator!=(const Stack& obj) {
		for (T* ptr = getStackPtr(), *ptrObj = obj.getStackPtr();
			ptr < getStackPtr() + getSize();
			++ptr, ++ptrObj)
		{
			if (ptr != ptrObj) {
				return true;
			}
		}
		if (getSize() == obj.getSize()) {
			return false;
		}
		return true;
	}

};



















