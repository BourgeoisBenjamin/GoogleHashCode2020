/*
** EPITECH PROJECT, 2019
** Google Hash Code
** File description:
** Library
*/

#include "Library.hpp"
#include <algorithm>
#include <iostream>

Library::Library(int id, int booksPerDay, int signedUpProcess) : _id(id), _booksPerDay(booksPerDay), _signedUpProcess(signedUpProcess)
{
}

Library::~Library()
{
}

void Library::pushBook(Book *book)
{
    _books.push_back(book);
}

bool Library::signedUp()
{
    if (_signedUpProcess == 0) {
        _isSigned = true;
        return (true);
    }
    _signedUpProcess--;
    return (false);
}

int Library::getId() const
{
    return (_id);
}

bool Library::isSigned() const
{
    return (_isSigned);
}

int Library::getBooksPerDay() const
{
    return (_booksPerDay);
}

void Library::scanBooks()
{
    int nb_book = 0;

    std::for_each(_books.begin(), _books.end(), [&nb_book, this](Book *book) {
        if (nb_book == _booksPerDay)
            return;
        if (book->isScan() == false) {
            std::cout << (nb_book == 0 ? "" : " ") << book->getId();
            book->scanBook();
            nb_book++;
        }
    });
    std::cout << std::endl;
}