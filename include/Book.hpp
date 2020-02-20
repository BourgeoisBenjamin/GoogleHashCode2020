/*
** EPITECH PROJECT, 2020
** Book
** File description:
** Book
*/

#ifndef BOOK_HPP
#define BOOK_HPP

#include <string.h>

class Book {
    public:
        Book(int id);
        ~Book();

        void scanBook();

        bool isScan() const;

        int getId() const;

    private:
        int _id;
        bool _scan;
};

#endif /* !BOOK_HPP */
