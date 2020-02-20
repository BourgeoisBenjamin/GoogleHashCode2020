#include "Parser.hpp"
#include <iostream>
#include <sstream>

Parser::Parser(const std::string filename) : _file(filename)
{
}

Parser::~Parser()
{
}

void Parser::getInfoNB()
{
    std::string line;
    std::string nbBooks;
    std::string nbLibs;
    std::string nbDays;
    _file.getDataLine(line);
    std::istringstream ss(line);

    ss >> nbBooks;
    ss >> nbLibs;
    ss >> nbDays;

    _booksNb = std::stoi(nbBooks);
    _libNb = std::stoi(nbLibs);
    _daysNb = std::stoi(nbDays);
}

void Parser::parseBook()
{
    std::string line;
    std::string scoreBook;
    _file.getDataLine(line);
    std::istringstream ss(line);

    while (ss >> scoreBook) {
        Book *newBook = new Book(std::stoi(scoreBook));
        _books.push_back(newBook);
    }
}

void Parser::parseLibrary()
{
    std::string line;
    _file.getDataLine(line);
    std::istringstream ss(line);
    size_t bookNb;
    size_t signupProcess;
    size_t booksPerDay;
    static int id = 0;

    ss >> bookNb;
    ss >> signupProcess;
    ss >> booksPerDay;

    Library *lib = new Library(id, booksPerDay, signupProcess);
    _libraries.push_back(lib);

    this->parseBooksLib(lib);
    id++;
}

void Parser::parseBooksLib(Library *lib)
{
    std::string line;
    _file.getDataLine(line);
    std::istringstream ss(line);
    size_t libID;

    while (ss >> libID)
        lib->pushBook(_books[libID]);
}


void Parser::parseFile()
{
    std::string line;

    this->getInfoNB();
    this->parseBook();

    for (size_t i = 0; i < _libNb; i++)
        this->parseLibrary();
}

std::vector<Library *> Parser::getLibraries() const
{
    return (_libraries);
}

std::vector<Book *> Parser::getBooks() const
{
    return (_books);
}

size_t Parser::getDaysNb() const
{
    return (_daysNb);
}

size_t Parser::getLibNb() const
{
    return (_libNb);
}

size_t Parser::getBooksNb() const
{
    return (_booksNb);
}