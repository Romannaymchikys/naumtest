#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <tchar.h>
#include <iostream>
#include <cstring>
#include <conio.h>

const size_t SIZE = 100;
size_t  _selector = 1;
bool _numeric = false;
int _Choice_of_actions(int *, char **, size_t&);

int main()
{
	size_t size_h = 2;
	printf_s("\t\t\t ********Spravochnik*******\n");
	int *_lineleft = new int[size_h];
	char **_mass = new char*[size_h];
	for (size_t i = 0; i < size_h; i++) { _mass[i] = new char[size_h]; }
	_Choice_of_actions(_lineleft, _mass, size_h);
	return 0;
}

int _exitornotexit(char **_mass, size_t size_h, int *_lineleft) {

	printf_s("0 - exid;\n");
	printf_s("1 - continue;\n");
	scanf_s("%d", &_selector);
	if (_selector == 1) {
		_Choice_of_actions(_lineleft, _mass, size_h);
	}
	else {
		for (size_t i = 0; i < size_h; i++) { delete[] _mass[i]; }
		delete[] _mass;
		delete[] _lineleft;
		return 0;
	}
}

// просмотр контактов
void _Print_mass(char **_mass, size_t size_h, int *_lineleft)
{
	size_t i = 0;
	for (char **_ptr_x = _mass; _ptr_x < (_mass + size_h); _ptr_x++, i++)
	{
		for (char *_ptr_y = *_ptr_x, *_ptr = *_ptr_x + _lineleft[i];
			                                _ptr_y < _ptr; _ptr_y++) {
			printf_s("%c", *_ptr_y);
		}
		printf_s("\n");
	}
	_getch();
	_exitornotexit(_mass, size_h, _lineleft);
}
// поиск контактов
void _Search_for_contacts(char **_mass, size_t size_h, int *_lineleft) {
	bool _Selector = false;
	// строка под имя в поиске
	char *_strname = new char[SIZE];
	char *_search_name = _strname;
	printf_s("Enter your name\n");
	std::cin.get();
	std::cin.getline(_search_name, SIZE);
	size_t i = 0, j = 0, _catcher, _countersize_l = 0;
	// копирование элементов
	for (char **_ptr_h = _mass; _ptr_h < (_mass + size_h); _ptr_h++, j++) 
	{
		for (char *_ptr_l = *_ptr_h, *_search_dubal = _search_name,
			                *_ptr = *_ptr_h + _lineleft[j];
			                 _ptr_l < _ptr; _ptr_l++, _search_dubal++, i++) {
			if (*_ptr_l == *_search_dubal) { 
				_Selector = true; 
			}
			else {
				_Selector = false; 
				break;
			}
		}
		if (_Selector == true) {
			if (!(j % 2)) {
				_ptr_h++;
				for (char *_ptr_l2 = *_ptr_h, *_ptr = *_ptr_h + _lineleft[j + 1];
					                                  _ptr_l2 < _ptr; _ptr_l2++) {
					printf_s("%c", *_ptr_l2); 
				}
			}
			else {
				_ptr_h--;
				for (char *_ptr_l2 = *_ptr_h, *_ptr = *_ptr_h + _lineleft[j - 1];
					                                    _ptr_l2 < _ptr; _ptr_l2++) { 
				   printf_s("%c", *_ptr_l2); }
			}
			printf_s("\n");
			printf_s("0 - menu\n");
			printf_s("1 - editing contacts;\n");
			std::cin >> _catcher;
			if (_catcher) {
				//system("cls");
				printf_s("Enter your name\n");
				std::cin.get();
				std::cin.getline(_search_name, SIZE);
				for (size_t i = 0; _search_name[i] != '\0'; i++) {
					_countersize_l++; 
				}
				_countersize_l++;
				_lineleft[j] = _countersize_l;

				char **mass1DUBAL = new char*[size_h];

				for (size_t g = 0; g < size_h; g++) {
					mass1DUBAL[g] = new char[_lineleft[g]];
				}
				size_t k = 0;
				for (char **_str_h = _mass, **_str_hDUBAL = mass1DUBAL;
					_str_h < _mass + size_h; _str_h++, k++, _str_hDUBAL++){
					for (char *_ptr_l1 = *_str_h, *_str_1DUBAL = *_str_hDUBAL,
						      *_ptr = *_str_h + _lineleft[k];
						       _ptr_l1 < _ptr; _ptr_l1++, _str_1DUBAL++){
						if (k == j) {
							*_str_1DUBAL = *_search_name;
							_search_name++;
						}
						else { 
							*_str_1DUBAL = *_ptr_l1; 
						}
					}
					//if (k == j) { memcpy(*_str_hDUBAL, _strname, _lineleft[k] * sizeof(_strname)); }
					//else { memcpy(*_str_hDUBAL, *_str_h, _lineleft[k] * sizeof(*_str_h)); }
				}
				for (size_t f = 0; f < size_h; f++) { 
					delete[] _mass[f]; 
				}
				delete[] _mass;
				//замена временного массива
				_mass = new char*[size_h];
				for (size_t f = 0; f < size_h; f++) { 
					_mass[f] = new char[_lineleft[f]];
				}
				size_t I = 0;
				// копирование элементов
				for (char **_ptr_h = _mass, **_str_h1DUBAL = mass1DUBAL;
					        _ptr_h < (_mass + size_h); 
					        _ptr_h++, I++, _str_h1DUBAL++) {
					for (char *_ptr_l = *_ptr_h, *_str_l1DUBAL = *_str_h1DUBAL, 
						      *_ptr = *_ptr_h + _lineleft[I]; _ptr_l < _ptr;
						       _ptr_l++, _str_l1DUBAL++){
						*_ptr_l = *_str_l1DUBAL;
					}
				}
				delete[] _strname;
				for (size_t m = 0; m < size_h; m++) {
					delete[] mass1DUBAL[m];
				}
				delete[] mass1DUBAL;
				_exitornotexit(_mass, size_h, _lineleft);
			}
			else {
				delete[] _strname;
				_exitornotexit(_mass, size_h, _lineleft);

			}
		}
	}
	delete[] _strname;
	printf_s("There is no such name!\n");

	_exitornotexit(_mass, size_h, _lineleft);
}

int _Setting_the_line_length(int *_lineleftDubal1, size_t size_h,
	                                               size_t _countersize_l, 
	                                               size_t& _index)
{
	for (int *_LINE = _lineleftDubal1; _LINE < (_lineleftDubal1 + size_h); _LINE++)
	{
		if ((_LINE + 2 == (_lineleftDubal1 + size_h)) && (_index == 0)) {
			_index = 1; *_LINE = _countersize_l;
			break;
		}
		if ((_LINE + 1 == (_lineleftDubal1 + size_h)) && (_index == 1)) {
			_index = 0; *_LINE = _countersize_l;
		}
	}
	return _index, *_lineleftDubal1;
}
// добавление контактов

int _Adding_contacts(int *_lineleft, char **_mass, size_t& size_h){
	int *_lineleftDubal = new int[size_h];
	for (int *_str_h = _lineleft, *_str_hDubal = _lineleftDubal;
		      _str_h < (_lineleft + size_h); _str_h++, _str_hDubal++){
		*_str_hDubal = *_str_h;
	}
	delete[]  _lineleft;
	_lineleft = new int[size_h];
	for (int *_str_h = _lineleft, *_str_hDubal = _lineleftDubal; 
		      _str_h < (_lineleft + size_h); _str_h++, _str_hDubal++){
		*_str_h = *_str_hDubal;
	}
	delete[] _lineleftDubal;
	// строка под имя 
	char *_strname = new char[SIZE]; 
	char *_strDubal = _strname;

	printf_s("Enter your name\n");
	std::cin.get();
	std::cin.getline(_strDubal, SIZE);

	size_t _countersize_l = 0, _index = 0;

	for (size_t i = 0; _strDubal[i] != '\0'; i++) {
		_countersize_l++; 
	}
	_countersize_l++;
	int *_lineleftDubal1 = _lineleft;
	_Setting_the_line_length(_lineleftDubal1, size_h, _countersize_l, _index);

	// строка под телефон
	char *_strnumer = new char[SIZE];
	char *_strdubalw = _strnumer;
	printf_s("Enter your number\n");
	std::cin.getline(_strdubalw, SIZE);
	_countersize_l = 0;
	for (size_t i = 0; _strdubalw[i] != '\0'; i++) { 
		_countersize_l++;
	}
	_countersize_l++;
	int *_lineleftDubal2 = _lineleft;
	_Setting_the_line_length(_lineleftDubal2, size_h, _countersize_l, _index);

	char **_massDUBAL = new char*[size_h];
	// каждая строка имеет свою длинну
	for (size_t _i = 0; _i < size_h; _i++) {
		_massDUBAL[_i] = new char[_lineleft[_i]]; 
	} 
	size_t i = 0;
	for (char **_str_h = _mass, **_str_hDUBAL = _massDUBAL;
		        _str_h < (_mass + size_h); _str_h++, i++, _str_hDUBAL++){
		for (char *_str_l = *_str_h, *_str_lDUBAL = *_str_hDUBAL, *_str_hname = _strname, 
			      *_str_hnumer = _strnumer, *_ptr = _str_l + _lineleft[i];
			       _str_l < _ptr; _str_lDUBAL++, _str_l++)
		{
			if ((_mass + size_h) - 2 == _str_h) { 
				// добавели имя
				*_str_lDUBAL = *_str_hname;
				_str_hname++;
			}
			else if ((_mass + size_h) - 1 == _str_h) {
				// добавели телефон
				*_str_lDUBAL = *_str_hnumer;
				_str_hnumer++; }
			else { *_str_lDUBAL = *_str_l; }
		}
	}
	if (_numeric == false) {
		for (size_t i = 0; i < size_h; i++) {
			delete[] _mass[i];
		}
		delete[] _mass;
	}
	else {
		for (size_t i = 0; i < size_h - 2; i++) {
			delete[] _mass[i]; 
		}
		delete[] _mass;
	}
	_numeric = true;
	//замена временного массива
	_mass = new char*[size_h]; 
	for (size_t i = 0; i < size_h; i++) { 
		_mass[i] = new char[_lineleft[i]]; 
	}
	size_t j = 0;
	// копирование элементов
	for (char **_ptr_h = _mass, **_str_hDUBAL = _massDUBAL;
		        _ptr_h < (_mass + size_h); 
		        _ptr_h++, j++, _str_hDUBAL++){
		for (char *_ptr_l = *_ptr_h, *_str_lDUBAL = *_str_hDUBAL,
			      *_ptr = _ptr_l + _lineleft[j]; _ptr_l < _ptr; 
			       _ptr_l++, _str_lDUBAL++)
		{
			*_ptr_l = *_str_lDUBAL;
		}
	}
	//_Print_mass(_mass, size_h, _lineleft);
	for (size_t i = 0; i < size_h; i++) {
		delete[] _massDUBAL[i];
	}
	delete[] _massDUBAL;
	delete[] _strname;
	delete[] _strnumer;
	_exitornotexit(_mass, size_h, _lineleft);
	return 0;
}
int _Choice_of_actions(int *_lineleft, char **_mass, size_t& size_h) {
	size_t _number;
	if (_selector == 1) {
		printf_s("0 - exid;\n");
		printf_s("1 - contacts viewer;\n");
		printf_s("2 - search for contacts;\n");
		printf_s("3 - adding contacts;\n");
		scanf_s("%d", &_number);
		switch (_number) {
		case(0): return 0;
		case(1): _Print_mass(_mass, size_h, _lineleft);// просмотор контактов
		case(2):   _Search_for_contacts(_mass, size_h, _lineleft);//поиск контактов
		// добавление контактов
		case(3): _numeric == true ? size_h += 2, _Adding_contacts(_lineleft, _mass, size_h) : 
			                                     _Adding_contacts(_lineleft, _mass, size_h);
		}
	}
	else { return 0; }
}