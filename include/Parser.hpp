/*
** EPITECH PROJECT, 2020
** parser
** File description:
** parser
*/

#ifndef PARSER_HPP
#define PARSER_HPP

#include "Library.hpp"
#include "Book.hpp"
#include <vector>
#include <string>
#include "File.hpp"

class Parser {
    public:
        Parser(const std::string filename);
        ~Parser();

        void parseFile();
        void getInfoNB();
        void parseBook();
        void parseLibrary();
        void parseBooksLib(Library *lib);

        std::vector<Library *> getLibraries() const;
        std::vector<Book *> getBooks() const;
        size_t getDaysNb() const;
        size_t getLibNb() const;
        size_t getBooksNb() const;

    protected:
        std::vector<Library *> _libraries;
        std::vector<Book *> _books;
        size_t _booksNb;
        size_t _libNb;
        size_t _daysNb;
        File _file;
};

#endif /* !PARSER_HPP */

