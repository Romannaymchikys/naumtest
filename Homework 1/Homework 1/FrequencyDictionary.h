#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

class FrequencyDictionary
{
public:
	
	FrequencyDictionary(const char* readFile) {
		std::ifstream filein;
		filein.open(readFile, std::ios_base::in);
		if (!filein.is_open())
		{
			std::cout << readFile << "File NOT found !!!" << std::endl;
			return;
		}
		// чтение в файл
		std::string value;
		for (size_t i(1); filein >> value ; ++i)
		{
			switch (i)
			{
			case 1: wordRankVec.push_back(value);                  break;
			case 2: lemmaVec.push_back(value);                     break;
			case 3: PartSpeechVec.push_back(value);                break;
				//преобразуем сразу в const char* потом в double
			case 4:FrequencyWordVec.push_back(atof(value.c_str()));break;
			case 10: i = 0;    break; // десять слов в строке
			default:           break;
			}
		}
		filein.close();
	}
	
	// проверка есть ли такой фаил
	class TestStringName {
		std::string string;
	public:
		TestStringName(std::string newString)
			              : string(newString) {};
		bool operator()(const std::string& stringName) const {
			// проверяет есть ли такое имя файла;
			return !(stringName.compare(string));
		}
		~TestStringName() {};
	};

	//######  Основная шапка всех функций ########
	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	void BasicFunctionality();
	// подшапка
	void dataCreationProcessing(std::vector<std::string>&);
	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

	// вспомогательная для 5 - 6 задание
	std::string descriptionPartsOfSpeech();
	// вспомогательная для 6 
	double inputRange();

	// считывание с файла название файлов каторые уже есть
	void readAvailablefileNames();
	
	// проверка есть ли такой фаил
	std::string testNameFile();
	// запись в фаил различных данных 
	void writeFile(const std::string, std::vector<std::string>&);
	

	// 1
	// самое частое/ редкое слова
	std::vector<std::string> mostfrequentAndRarestWord(std::vector<std::string>&);
	// 2
	// получить  слово  с  заданным  рангом 
	std::vector<std::string> assignedRankWord(std::vector<std::string>&);
	// 3
	// получить ранг и частоту заданного слова
	std::vector<std::string> rankFrequencyWord(std::vector<std::string>&);
	// 4
	// получить  все слова,  ранг  которых  заключен  в  заданном  диапазоне
	std::vector<std::string> wordsRangeRank(std::vector<std::string>&);
	// 5 - 6
	//получить  информацию  (ранг,  частота,  лемма)  обо  всех  словах  заданной 
	//части речи(например, о глаголах)
	//получить все слова определенной  части речи, частота  которых не меньше
	//заданного значения
	std::vector<std::string> choicePartOfSpeech(std::vector<std::string>&, double);
	// 7
	//получить статистику, сколько слов каждой части речи есть в словаре и какая
	//их средняя частота на 1 миллион словоупотреблений.
	std::vector<std::string> frequencyStatisticsWords(std::vector<std::string>&);

	~FrequencyDictionary() {};


private:
	const std::string FILES_NAMES = "FILES_NAMES.txt";
	// ранг слова
	std::vector	<std::string> wordRankVec;
	// начальная форма слова
	std::vector	<std::string> lemmaVec;
	// часть речи
	std::vector	<std::string> PartSpeechVec;
	// частота слова на один миллион словоупатреблений
	std::vector	<double> FrequencyWordVec;

	// содержатся имена файлов каторые уже создались
	std::vector	<std::string> writeFileVec;
};
