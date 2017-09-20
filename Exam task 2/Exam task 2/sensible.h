#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>


class sensible
{
public:
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
	sensible(const char* newReadFile) : readFile(newReadFile) {};

	void InputFiles();
	void textCreatorWritingFile();
	
	
	//----------------------------------------------
	// считывание с фаЙла название файлов которые уже есть
	void readAvailablefileNames();

	// проверка есть ли такой файл
	std::string testNameFile();
	// запись в фаЙл различных данных
	void writeFile(const std::string, std::vector<std::string>&);
	void dataCreationProcessing(std::vector<std::string>&);
	//----------------------------------------------
	
	~sensible() {};
private:
	const std::string FILES_NAMES = "FILES_NAMES.txt";
	std::string readFile;
	//ключ пара слов, значение map в катором, 
	//ключ слова встречающиеся после данных пары слов,
	//значение частота употребления
	std::map<std::pair<std::string, std::string>, 
		           std::map<std::string, size_t>> mapFrequencTWO;
	//содержит слова с заглавной буквы
	std::map<size_t,std::string> mapFrequencONE;
	// вектор считывающий слова
	std::vector<std::string> writeFileVec;
	// содержатся имена файлов которые уже создались
	std::vector	<std::string> fileNameVec;
	size_t   numberRec, // кол рецептов
		numberWordsRec; // кол слов в рецепце
};

