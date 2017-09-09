#pragma once

template <typename T>
class ForwardList {
	struct node {
		T data;
		node* next = nullptr;
	};
	node* head;
	node* tail;
	size_t list_size;

public:
	ForwardList() :
		 head(nullptr), tail(nullptr), list_size(0){};
	~ForwardList() {
		while (list_size) {
			pop_back();
		}
	};

	size_t size() const { return list_size; }
	bool empty() const { return !(list_size);  }

	void push_back(const T&);
	void push_front(const T&);
	bool insert(const T&, const T&);

	T pop_back();
	T pop_front();
	bool erase(const T&);

	void print();

private:
	node* create_node(const T&);
	void create_first_node(const T&);
	node* find_node(const T&);
	node* find_previous_node(const T&);
};
// ----------------------------------------------------------------------------------
template <typename T>
typename ForwardList<T>::node* ForwardList<T>::
                                create_node(const T& data) {
	node* _node = new node;
	_node->data = data;
	_node->next = nullptr;
	return _node;
}
template <typename T>
void ForwardList<T>::create_first_node(const T& data) {
	node* _node = new node;
	_node->data = data;
	_node->next = nullptr;
	 head = _node;
	 tail = _node;
}
template <typename T>
// вставка элемента в конец файла
void ForwardList<T>::push_back(const T& data) {
	if (list_size) {
		node* newNode = create_node(data);
		node* node = head;
		while (node->next)
		{
			node = node->next;
		}
		node->next = newNode;
		//указатель на конец
		tail = newNode;
	}
	else {
		create_first_node(data);
	}
	++list_size;
}
template <typename T>
// вставка элемента в начало файла
void ForwardList<T>::push_front(const T& data) {
	if (list_size) {

		node* newNode = create_node(data);
		newNode->next = head;
		head = newNode;
	}
	else {
		 create_first_node(data);
	}
	++list_size;
}
template <typename T>

bool ForwardList<T>::insert(const T& dataInsert, const T& data) {
	if (list_size) {
		node* newNode = create_node(dataInsert);
		node* node = head;
		while (node)
		{
			// если нашли такое слово
			if (node->data == data) {
				// если оно не в конце
				if (node->next) {
					newNode->next = node->next;
					node->next = newNode;
					++list_size;
					return true;
				}
				else {
					node->next = newNode;
					tail = newNode;
					++list_size;
					return true;
				}
			}
			node = node->next;
		}
	}
	else {
		return false;
	}
}
template <typename T>
// удаляем элемент из конца списка
T ForwardList<T>::pop_back() {
	if (list_size) {
		node* _node = head;
		// если в списке как минимум два элемента
		if (_node->next) {
			while (_node->next->next)
			{
				_node = _node->next;
			}
			T _data = _node->next->data;
			delete _node->next;
			_node->next = nullptr;
			--list_size;
			return _data;
		}
		// если в списке один элемент
		else {
			T _data = _node->data;
			delete _node;
			head = nullptr;
			tail = nullptr;
			--list_size;
		}
	}
	// если нет элементов
	return 0;
}

template <typename T>
// удаляем элемент в начале списка
T ForwardList<T>::pop_front() {
	if (list_size) {
		node* first = head;

		if (head->next) {
			head = head->next;
		}
		else {
			head = nullptr;
			tail = nullptr;
		}
		T _data = first->data;
		delete first;
		--list_size;
		return _data;
	}
	return 0;
}
template <typename T>
bool ForwardList<T>::erase(const T& _data) {
	if (list_size) {
		node* _node = head;
		// проверяем не является ли первым элементом
		if (_node->data == _data) {
			pop_front();
			return true;
		}
		else if (_node->next) {
			while (_node->next->data != _data){
				_node = _node->next;
			}
			// проверяем не я вляется ли последним элементом
			if (_node->next->next) {
				node* delNode = _node->next;
				_node->next =_node->next->next;
				delete delNode;
				--list_size;
				return true;
			}
			// если элемент в середине
			else {
				pop_back();
				return true;
			}
		}
	}
	else { 
		return false;
	}
}
template <typename T>
// печать списка
void ForwardList<T>::print() {
	if (list_size) {
		node* _node = head;
		while (_node)
		{
			std::cout << _node->data << std::endl;
			_node = _node->next;
		}
	}
}
template <typename T>
// поиск узла по значению
typename ForwardList<T>::node* ForwardList<T>::
                                    find_node(const T& _data) {
	if (list_size) {
		node* _node = head;
		while (_node)
		{
			if (_node->data == _data) {
				return _node
			}
			_node = _node->next;
		}
	}
	return nullptr;
}
template <typename T>
// поиск предыдущего узла по значению
typename ForwardList<T>::node* ForwardList<T>::
               find_previous_node(const T& _data) {
	if (list_size > 1) {
		node* _node = head;
		if (_node->data != _data) {
			while (_node->next)
			{
				if (_node->next->data == _data) {
					return _node
				}
				_node = _node->next;
			}
		}
	}
	return nullptr;
}