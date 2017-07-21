#ifndef __QUEUE_H__
#define __QUEUE_H__

template <class T>
class Queue
{
	T* data;
	size_t tail;
	const size_t maxSIZE = 100;
public:
	Queue(const size_t);
	Queue(const Queue<T>&);
	Queue(Queue<T>&&);
	Queue& operator=(const Queue<T>&);
	Queue& operator=(Queue<T>&&);
	~Queue();

	size_t size() const;
	bool empty() const;
	void clear();

	void push(const T&);
	void pop();
	T& back();
	T& front();
};

#endif /* __QUEUE_H__ */

template<class T>
inline Queue<T>::Queue(const size_t SIZE):
	              maxSIZE(SIZE), tail(0) {
	data = new T[maxSIZE];
}
template<class T>
inline Queue<T>::Queue(const Queue<T>& newQueue):
	                         tail(newQueue.tail)
{
	if (this == &newQueue) {
	    return *this;
		}
	delete[] data;
	data = new T[maxSIZE];
	for (size_t i(0); i <= top; ++i) {
		data[i] = newQueue.data[i];
	    }
}

template<class T>
inline Queue<T>::Queue(Queue<T>&& newQueue):
	              data(newQueue.data), tail(newQueue.tail) 
{
	if (this == &newQueue) {
		return *this;
		}
	delete[] data;
	data = newQueue.data;
	newQueue.data = 0;
	newQueue.data = nullptr;
}


template<class T>
inline Queue<T>& Queue<T>::operator=(const Queue<T>& obj)
{
	if (this == &obj) {
		return *this;
	}
	delete[] data;
	data = new T[maxSIZE];
	for (size_t i = 0; i <= top; ++i) {
		data[i] = obj.data[i];
	}
	return *this;
}


template<class T>
inline Queue<T>& Queue<T>::operator=(Queue<T>&& obj)
{
	if (this == &obj) {
		return *this;
	}
	delete[] data;
	data = obj.data;
	obj.data = 0;
	obj.data = nullptr;
	return *this;
}

template<class T>
inline Queue<T>::~Queue()
{
	delete[] data; 
}

template<class T>
inline size_t Queue<T>::size() const
{
	return size_t(tail);
}

template<class T>
inline bool Queue<T>::empty() const
{
	return tail;
}

template<class T>
inline void Queue<T>::clear()
{
	if (empty()) {
		delete[] data;
		data = 0;
		data = nullptr;
	}
}

template<class T>
inline void Queue<T>::push(const T &value)
{
	if (++tail <= maxSIZE)
	{
		*(data + tail - 1) = value;
		return;
	}
	return;
}

template<class T>
inline void Queue<T>::pop()
{
	if (empty()) {
		for (size_t i(0); i < tail - 1; ++i) {
			 data[i] = data[i + 1];
		}
	}
}

template<class T>
inline T & Queue<T>::back()
{
	return *(data + tail - 1);
}

template<class T>
inline T & Queue<T>::front()
{
	return *data;
}

