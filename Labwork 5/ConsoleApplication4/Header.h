template <typename T>
T getMax(T* arr, const size_t arSize){
	T max = 0;
	if (arSize > 1){
		for (size_t i = 0; i < arSize; ++i){
			if (arr[i] > max){
				max = arr[i];
			}
		}
	}
	else { return 0; }
	return max;
}

template<int size, typename T>
T getMax(T* arr){
	T max = 0;
	if (size > 1){
		for (size_t i = 0; i < size; ++i){
			if (arr[i] > max){
				max = arr[i];
			}
		}
	}
	else { return 0; }
	return max;
}

template<typename T>
void sort(T* arr, const size_t arSize){
	if (arSize < 2){
	}
	for (size_t i = 0; i < arSize; ++i){
		for (size_t j = 0; j < arSize; ++j){
			if (arr[i] < arr[j]){
				T tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}	
		}
	}
}

template<typename T>
T find(T* arr, const size_t arSize, const size_t index){
	for (size_t i = 0; i < arSize; ++i){
		if (i == index){
			T elForIndex = arr[i];
			return elForIndex;
		}
	}
}

void printarr(int* arr, const size_t arSize){
	for (size_t i = 0; i < arSize; ++i){
		std::cout << arr[i] <<" " ;
	}
	std::cout << std::endl;
}

template <typename T, typename U>
auto getmax(T x, U y) -> decltype((x > y) ? x : y)
{
	return ((x > y) ? x : y);
}
	

