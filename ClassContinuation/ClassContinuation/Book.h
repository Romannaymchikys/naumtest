#pragma once
#include <string>
#include <iostream>
class Book
{
	std::string author;
	std::string title;
	std::string publishHouse;
	std::string yearPublish;
	int numberPages;
public:
	Book(const std::string newAuthor, const std::string newTitle,
		const std::string newPublishHouse, const std::string newYearPublish,
		const int newNumberPages) :author(newAuthor), title(newTitle), publishHouse(newPublishHouse),
		yearPublish(newYearPublish), numberPages(newNumberPages) {};

	std::string getAuthor() const;
	std::string getTitle() const;
	std::string getPublishHouse() const;
	std::string getYearPublish() const;
	int getNumberPages() const;

	void setAuthor(const std::string);
	void setTitle(const std::string);
	void setPublishHouse(const std::string);
	void setYearPublish(const std::string);
	void setNumberPages(const int);

	void informatbook();
	~Book(){};
};

