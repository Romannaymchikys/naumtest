#include "Book.h"

std::string Book::getAuthor() const { return author; }
std::string Book::getTitle() const { return title; }
std::string Book::getPublishHouse() const { return publishHouse; }
std::string Book::getYearPublish() const { return yearPublish; }
int Book::getNumberPages() const { return numberPages; }

void Book::setAuthor(const std::string newAuthor) { author = newAuthor; }
void Book::setTitle(const std::string newTitle) { title = newTitle; }

void Book::setPublishHouse(const std::string newPublishingHouse) {
	publishHouse = newPublishingHouse;
}
void Book::setYearPublish(const std::string newYearPublishing) {
	publishHouse = newYearPublishing;
}
void Book::setNumberPages(const int newNumberPages){
	publishHouse = newNumberPages;
}
void Book::informatbook(){
	std::cout << author << std::endl;
	std::cout << title << std::endl;
	std::cout << publishHouse << std::endl;
	std::cout << yearPublish << std::endl;
	std::cout << numberPages << std::endl;
}
