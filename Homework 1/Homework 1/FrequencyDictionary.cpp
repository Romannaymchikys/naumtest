
#include "FrequencyDictionary.h"

void FrequencyDictionary::readAvailablefileNames() {
	std::ifstream filein;
	filein.open(FILES_NAMES, std::ios_base::in);
	if (!filein.is_open()){
		std::cout << FILES_NAMES <<
		        "Файл не найден" <<
		  "(file NOT found )!!!" << std::endl;
		return;
	}
	// чтение в файл
	std::string value;
	while (filein >> value) {
		writeFileVec.push_back(value);
	}
	filein.close();
}

std::string FrequencyDictionary::testNameFile(){
	std::string writeFileName;
	std::cout << "Введите имя файла";
	std::cout << "(Enter the file name): \n";
	std::cin  >> writeFileName;
	writeFileName += ".txt";
	// проверка есть ли токой фаил
	if(!(std::count_if(writeFileVec.begin(), writeFileVec.end(),
		                       TestStringName(writeFileName)))){
		writeFileVec.push_back(writeFileName);
		return writeFileName;
	}
	return testNameFile();
}

void FrequencyDictionary::writeFile(const std::string writeFile,
	                                      std::vector<std::string>& writeData) {
	/// где нужно плюсуем строку до входа в функцию 
	std::ofstream fileout;
	fileout.open(writeFile, std::ios_base::out);
	if (!fileout.is_open()){
		std::cout << writeFile <<
			  "Файл не найден" <<
	    "(file NOT found )!!!" << std::endl;
		return;
	}
	// запись в файл
	for (size_t i(0); i < writeData.size(); ++i){
		fileout << writeData.at(i) << "\n";
	}
	writeData.clear();
	writeData.shrink_to_fit();
}

// подшапка
void FrequencyDictionary::dataCreationProcessing
                        (std::vector<std::string>& writeData ) {
	int selector;
	std::cout << "0 - выход в меню " << "(exit to the menu) \n"
		      << "1 - запись в фаил" << " (write to file)   \n";
	std::cin >> selector;
	if (selector) {
		// имя файла в который нужно записать
		std::string writeFileName = testNameFile();
		writeFile(writeFileName, writeData);
	}
	return;
}

// основная шапка
void FrequencyDictionary::BasicFunctionality() {
	//считывание с файла название файлов каторые уже есть
	readAvailablefileNames();
	int selector = 0;
	// вектор для записи данных в фаил
	std::vector<std::string> writeData;
	std::cout << "1 - получить самое частое / самое редкое слово в словаре\n" <<
		         "    (get the most common / rarest word in the dictionary) \n\n";

	std::cout << "2 - получить  слово  с  заданным  рангом \n" <<
		         "    (Get a word with a given rank) \n\n";

	std::cout << "3 - получить ранг и частоту заданного слова \n" <<
		         "    (get the rank and frequency of the given word) \n\n";

	std::cout << "4 - получить  все  ,  ранг  которых  заключен  в  заданном  диапазоне\n" <<
		         "    (get everything whose rank is within a given range) \n\n";

	std::cout << "5 - получить информацию (ранг,  частота, лемма) обо всех словах заданной\n" <<
		         "    части речи \n" <<
		         "    (get information(rank, frequency, lemma) about all words given \n" <<
		         "    parts of speech) \n\n";

	std::cout << "6 - получить все слова определенной части речи, частота которых \n" <<
		         "    не меньше заданного значения \n" <<
		         "    (get all the words of a certain part of the speech, \n" <<
		         "    whose frequency is not less than setpoint) \n\n";

	std::cout << "7 - получить статистику, сколько слов каждой части речи есть в словаре \n" <<
		         "    и какая их средняя частота на 1 миллион словоупотреблений \n" <<
		         "    (To get statistics, how many words of each part of speech is in the \n" <<
		         "    dictionary and what Their average frequency is 1 million words \n\n";

	std::cout << "8 - выход " << "exit \n";

	std::cin >> selector;
	switch (selector)
	{
	case 1: mostfrequentAndRarestWord(writeData);
		       dataCreationProcessing(writeData);
			   break;
	case 2:          assignedRankWord(writeData); 
		       dataCreationProcessing(writeData);                      
			   break;
	case 3:         rankFrequencyWord(writeData);
		       dataCreationProcessing(writeData);
		       break;
	case 4:            wordsRangeRank(writeData);
		       dataCreationProcessing(writeData);
		       break;
	case 5:     choicePartOfSpeech(writeData, 0);
			   dataCreationProcessing(writeData);
		       break;
	case 6: choicePartOfSpeech(writeData,
		                           inputRange());
		       dataCreationProcessing(writeData);
		       break;
	case 7:  frequencyStatisticsWords(writeData);
		       dataCreationProcessing(writeData);
		       break;
	case 8: writeFile(FILES_NAMES, writeFileVec);
		       return;
	default:   return;
	}
	BasicFunctionality();
}

std::string FrequencyDictionary:: descriptionPartsOfSpeech() {
	std::string partSpeech;
	//ввести обозначение части речи 
	std::cout << "s  - cуществительные(naun)\n"
		      << "a  - прилагательные(adjective)\n"
			  << "v  - глаголы(verd)\n"
		      << "pr - предлоги(excuses)\n"
		      << "num  - числительные(numerals)\n"
			  << "adv  - наречие(adverb); в этот класс включены также предикативы"
		      <<         "(жаль, хорошо, пора) и вводные слова(кстати, по–моему)\n"
			  << "anum - числительное–прилагательные(numeral-adjectives)\n"
			  << "spro - местоимения–существительные(pronouns-nouns)\n"
			  << "apro - местоимения–прилагательные(Adjectives)\n"
			  << "conj - союзы(Conjunctions)\n"
			  << "part - частицы(Particle)\n"
			  << "intj - междометия(Interjections)\n"
			  << "init - инициалы(initials)\n";
	std::cin >> partSpeech;
	return partSpeech;
}


double FrequencyDictionary::inputRange() {
	double range;
	std::cout << "Получить слова с частотой от\n"
		      << "(get words with frequency from):\n";
	std::cin >> range;
	return range;
}
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
// 1
std::vector<std::string> FrequencyDictionary:: 
               mostfrequentAndRarestWord(std::vector<std::string>& writeData) {
	std::cout << "Наиболее частое слово";
	std::cout << "(the most frequent word): \n "  << lemmaVec.at(0) 
		                                        << std::endl;
	writeData.push_back(lemmaVec.at(0));
	std::cout << "Самое редкое слово";
	std::cout << "(the rarest word): \n "
		      << lemmaVec.at(lemmaVec.size() - 1) << std::endl;
	writeData.push_back(lemmaVec.at(lemmaVec.size() - 1));
	return writeData;
	
}

// 2
std::vector<std::string> FrequencyDictionary:: 
                        assignedRankWord(std::vector<std::string>& writeData) {
	std::string strRankWord;
	int rankWord = 0;
	do {
		std::cout << "Введите ранг слово";
		std::cout << "(input rank word): \n";
		std::cin >> strRankWord;
		rankWord = atoi(strRankWord.c_str());
		std::cout << rankWord;
	} while (rankWord > lemmaVec.size() || rankWord <= 0);
	std::cout << "ранг cлова" << "(word with rank) " <<
	 rankWord << " = " << lemmaVec.at(rankWord - 1) << std::endl;
	return writeData;
}

// 3
std::vector<std::string> FrequencyDictionary:: 
                       rankFrequencyWord(std::vector<std::string>& writeData) {
	std::string givenWord;
	std::cout << "Введите  слово";
	std::cout << "(input given word): \n";
	std::cin  >> givenWord;

	// поиск первого вхождения элемента 
    int resultFind = (std::find_if(lemmaVec.begin(), lemmaVec.end(),
		             TestStringName(givenWord))) - lemmaVec.begin();
	if (resultFind < lemmaVec.size()) {
		std::cout << "ранк слова"
			      << "(rank word): "
		          << wordRankVec.at(resultFind)
			      << std::endl;
		std::cout << "Частотное слово"
			      << "(frequency word): "
			      << FrequencyWordVec.at(resultFind)
			      << std::endl;
		writeData.push_back(lemmaVec.at(resultFind));
		writeData.push_back(wordRankVec.at(resultFind));
		// преобразуем double в строку
		writeData.push_back(std::to_string(FrequencyWordVec.at(resultFind)));
		return writeData;
	}
	// такого слова нет в списке
	std::cout << "В словаре нет такого слова \n";
	std::cout << "There is no such word in the dictionary!\n";
	return writeData;
}

//4
std::vector<std::string> FrequencyDictionary::
                          wordsRangeRank(std::vector<std::string>& writeData) {
	size_t  leftAdge, rightAdge;
	std::cout << "Введите левый и правый край диопазона";
	std::cout << "(inter the left and right edge of the range): \n";
	std::cin  >> leftAdge >> rightAdge;
	// проверка на правельный ввод
	if (leftAdge > rightAdge || leftAdge < 0 || rightAdge < 0) {
		return wordsRangeRank(writeData);
	}
	for (;leftAdge <= rightAdge; ++leftAdge) {
		std::cout << lemmaVec.at(leftAdge - 1) << std::endl; 
		writeData.push_back(lemmaVec.at(leftAdge - 1));
	}
	return writeData;
}

// 5 - 6
std::vector<std::string>  FrequencyDictionary::
             choicePartOfSpeech(std::vector<std::string>& writeData, double range){
	int resultFind = 0;
	// вывод меню данного функционала
	std::string partSpeech = descriptionPartsOfSpeech();
	while (true)
	{
		resultFind = (std::find_if(PartSpeechVec.begin() + resultFind + 1,
			PartSpeechVec.end(),
		                    TestStringName(partSpeech))) - PartSpeechVec.begin();
		if (resultFind < PartSpeechVec.size() && range < FrequencyWordVec.at(resultFind))
		{
			std::cout << " ранг(rank): "         << resultFind + 1          
		              << std::endl;
			std::cout << " лемма(lemma): "       << lemmaVec.at(resultFind) 
				      << std::endl;
			std::cout << " частота(frequency): " << FrequencyWordVec.at(resultFind) 
				      << std::endl << std::endl;
			// фармеруем в одну строку, чтобы отправить на запись
			writeData.push_back(wordRankVec.at(resultFind) + " " +
				lemmaVec.at(resultFind) + " " + std::to_string(FrequencyWordVec.at(resultFind)));
		}
		else {
			return writeData;
		}
	}
}

// 7
std::vector<std::string> FrequencyDictionary::
                frequencyStatisticsWords(std::vector<std::string>& writeData) {
	std::vector<std::string> partSpeech{
		"s",   // - cуществительные(naun)
		"a",   // - прилагательные(adjective)
		"v",   // - глаголы(verd)
	    "pr",  // - предлоги(excuses)
		"num", // - числительные(numerals)
	    "adv", // - наречие(adverb); в этот класс включены также предикативы
		       //   (жаль, хорошо, пора) и вводные слова(кстати, по–моему)
		"anum",// - числительное–прилагательные(numeral-adjectives)
		"spro",// - местоимения–существительные(pronouns-nouns)
		"apro",// - местоимения–прилагательные(Adjectives)
		"conj",// - союзы(Conjunctions)
		"part",// - частицы(Particle)
		"intj",// - междометия(Interjections)
		"init" // - инициалы(initials)
	};
	for (size_t i(0), counter(0); i < partSpeech.size(); ++i) {
		double summa = 0;
		for (int resultFind(0); true;){
			// resultFind явлляется итератором на данный элемент с вектора partSpeech
			resultFind = (std::find_if(PartSpeechVec.begin() + resultFind + 1,
				PartSpeechVec.end(),
				TestStringName(partSpeech.at(i)))) - PartSpeechVec.begin();
			// проверка нашли ли мы такой элемент
			if (resultFind < PartSpeechVec.size()) {
				summa += FrequencyWordVec.at(resultFind);
				++counter;
			}
			else { break; }
			}
		if (counter) {
			// фармеруем в одну строку, чтобы отправить на запись
			writeData.push_back(partSpeech.at(i)
				+ " " + std::to_string(counter)
				+ " " + std::to_string(summa / counter));
			std::cout << writeData.at(i) << std::endl;
		   }
		counter = 0;
	}
	return writeData;
}
