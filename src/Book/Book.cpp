/*
** EPITECH PROJECT, 2020
** book
** File description:
** book
*/

#include "Book.hpp"

Book::Book(int id) : _id(id), _scan(false)
{
}

Book::~Book()
{
}

void Book::scanBook()
{
    _scan = true;
}

bool Book::isScan() const
{
    return (_scan);
}

int Book::getId() const
{
    return (_id);
}