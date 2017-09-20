#include "sensible.h"
#include <cstdlib>
#include <ctime>
#define NUM_LEFT_RANGE  191
#define NUM_RIGHT_RANGE 224
#define CHAR_POINT      '.'
#define EMPTY_STR       " " 
#define WORD_WITH_CAPITAL_LETTER(VALUE)(unsigned char)VALUE[0] < NUM_RIGHT_RANGE &&\
                                       (unsigned char)VALUE[0] > NUM_LEFT_RANGE    \

void sensible::readAvailablefileNames() {
	std::ifstream filein;
	filein.open(FILES_NAMES, std::ios_base::in);
	if (!filein.is_open()) {
		std::cout << FILES_NAMES <<
			"Файл не найден" <<
			"(file NOT found )!!!" << std::endl;
		return;
	}
	// чтение в файл
	std::string value;
	while (filein >> value) {
		fileNameVec.push_back(value);
	}
	filein.close();
}

std::string sensible::testNameFile() {
	std::string writeFileName;
	std::cout << "Введите имя файла";
	std::cout << "(Enter the file name): \n";
	std::cin >> writeFileName;
	writeFileName += ".txt";
	// проверка есть ли такой фаил
	if (!(std::count_if(fileNameVec.begin(), fileNameVec.end(),
		TestStringName(writeFileName)))) {
		fileNameVec.push_back(writeFileName);
		return writeFileName;
	}
	return testNameFile();
}

void sensible::writeFile(const std::string writeFile,
	std::vector<std::string>& writeFileVec) {
	/// где нужно плюсуем строку до входа в функцию 
	std::ofstream fileout;
	fileout.open(writeFile, std::ios_base::out);
	if (!fileout.is_open()) {
		std::cout << writeFile <<
			"Файл не найден" <<
			"(file NOT found )!!!" << std::endl;
		return;
	}
	// запись в файл
	for (size_t i(0); i < writeFileVec.size(); i++ ) {
		// для разделения рецептов
		if (!(i % numberWordsRec ) && i != 0) {
			fileout << "\n" << "\n";
		}
		fileout << writeFileVec.at(i) << " ";
		
	}

	writeFileVec.clear();
	writeFileVec.shrink_to_fit();
}

// подшапка
void sensible::dataCreationProcessing
(std::vector<std::string>& writeFileVec) {
	int selector;
	std::cout << "0 - выход в меню " << "(exit to the menu) \n"
		      << "1 - запись в фаил" << " (write to file)   \n";
	std::cin >> selector;
	if (selector) {
		// имя файла в который нужно записать
		std::string writeFileName = testNameFile();
		writeFile(writeFileName, writeFileVec);
	}
	return;
}

//-------------------------------------------------------------------

void sensible::InputFiles()
{
	std::ifstream filein;
	filein.open(readFile, std::ios_base::in);
	if (!filein.is_open())
	{
		std::cout << readFile << "File NOT found !!!" << std::endl;
		return;
	}
	// чтение в файл
	std::map<std::string, size_t> mapValue;
	std::string first_val, second_val, third_val;
	filein >> first_val >> second_val >> third_val;
	for (;filein;) {
		if (WORD_WITH_CAPITAL_LETTER(first_val)){
			auto it = std::find_if(mapFrequencONE.begin(),
				                   mapFrequencONE.end(),
				[&](const std::pair<size_t, std::string> A)
			{return !strcmp(A.second.c_str(), first_val.c_str()); });
			if (it == mapFrequencONE.end()) {
				mapFrequencONE.insert(std::pair<size_t,
					 std::string>(mapFrequencONE.size(), first_val));
			}
		}
		std::pair<std::string, std::string> _pair(first_val, second_val);
		auto it1 = mapFrequencTWO.find(_pair);
		// если слова этого  нет
		// то добавляем его
		if (it1 == mapFrequencTWO.end()) {
			mapValue[third_val] = 1;
			mapFrequencTWO[_pair] = mapValue;
		
		}
		else {
			auto _it = it1->second.find(third_val);
			// если второе слово есть то увеличиваем счетчик 
			if (_it != it1->second.end()) {
				++_it->second;
			}
			// иначе добовляем в влложеный маp
			else {
				it1->second[third_val] = 1;	
			}
		}
		mapValue.clear();
		
	    first_val  = second_val;
		second_val = third_val;
		filein >> third_val;
	}
	filein.close();
}


void sensible::textCreatorWritingFile() {

	std::pair<std::string, std::string> _pair;
	std::cout << "Введите количество слов в рецепте и кол. рецептов \n";
	std::cin >> numberWordsRec >> numberRec ;
	// ищем по first слово
	srand(time(NULL));
	auto it_mapONE = mapFrequencONE.find(rand() % mapFrequencONE.size());
	// добавляем первое слово
	writeFileVec.push_back(it_mapONE->second);
	//ищем слово в паре первым
	auto it1 = std::find_if(mapFrequencTWO.begin(), mapFrequencTWO.end(),
		[&](const std::pair<std::pair<std::string, std::string>,
			std::map<std::string, size_t>> A)
	{return !strcmp(A.first.first.c_str(), writeFileVec.front().c_str()); });
	_pair = it1->first;
	writeFileVec.push_back(_pair.second);

	std::string value;
	for (std::map<std::string, size_t> mapValue;
		writeFileVec.size() < numberRec * numberWordsRec;) {
		// проверяем последнее ли слово в рецепте
		if (numberWordsRec == (writeFileVec.size() % numberWordsRec) + 1)
		{
			//если предпоследнее слово рецепта заканчивается на точку 
			if (writeFileVec.back().back() == CHAR_POINT) {
				// вставляем пустую строку для перевода на новую строку
				writeFileVec.push_back(EMPTY_STR);
			}
			else {
				//ищем слово с точкой
				auto it2 = mapFrequencTWO.find(_pair);
				auto itEmb = std::find_if(it2->second.begin(), it2->second.end(),
					[](const std::pair<std::string, size_t> A) {
					return A.first.back() == CHAR_POINT; });
				// если во вложеном map нет слова с точкой
				// ищем слово с точкой в основном map
				if (itEmb == it2->second.end()) {
					auto it_mapTWO = std::find_if(it2, mapFrequencTWO.end(),
						[](const std::pair<std::pair<std::string, std::string>, 
							                std::map<std::string, size_t>> A) {
						return A.first.second.back() == CHAR_POINT; });
					value = it_mapTWO->first.second;
					_pair.first = it_mapTWO->first.first;
					_pair.second = it_mapTWO->first.second;
					
				}
				else {
					value = itEmb->first;
					_pair.first = _pair.second;
					_pair.second = value;
				}
				writeFileVec.push_back(value);	
			}
		}
		else {
			auto it2 = mapFrequencTWO.find(_pair);

			if (it2->second.size() > 1) {
				for (auto itEmb1 = it2->second.begin(),
					      itEmb2 = ++it2->second.begin();
					itEmb2 != it2->second.end(); ++itEmb1, ++itEmb2) {

					if (itEmb1->second == itEmb2->second) {
						if (rand() % 2) { value = itEmb2->first;}
						else { value = itEmb1->first; }
					}
					else if (itEmb1->second < itEmb2->second) {
						value = itEmb2->first; 
					}
					else { value = itEmb1->first; }
				}
				// если слово заканчивается на точку
				if (_pair.second.back() == _pair.second.find(CHAR_POINT)) {
					if (WORD_WITH_CAPITAL_LETTER(value)) {
						auto itEmb = std::find_if(it2->second.begin(), 
							                      it2->second.end(),
							[&](const std::pair<std::string, size_t> A)
						{return WORD_WITH_CAPITAL_LETTER(A.first); });

						if (itEmb == it2->second.end()) {
							it2 = std::find_if(mapFrequencTWO.begin(),
								               mapFrequencTWO.end(),
								[&](const std::pair<std::pair<std::string, std::string>,
									                 std::map<std::string, size_t>> A) {
								return WORD_WITH_CAPITAL_LETTER(A.first.first); });
							value = it2->first.first;
						}
					}
				}
	
				}
			else {
				value = it2->second.begin()->first;
			}
			writeFileVec.push_back(value);
			_pair.first = _pair.second;
			_pair.second = value;
		}
	}
	dataCreationProcessing(writeFileVec);
    writeFile (FILES_NAMES, fileNameVec);

}