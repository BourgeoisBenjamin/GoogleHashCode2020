/*
** EPITECH PROJECT, 2020
** Library
** File description:
** Librayr
*/

#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include "Book.hpp"
#include <vector>

class Library {
    public:
        Library(int id, int _booksPerDay, int _signedUpProcess);
        ~Library();

        void pushBook(Book *book);
        bool signedUp();

        void scanBooks();

        bool isSigned() const;
        int getId() const;
        int getBooksPerDay() const;

    protected:
    private:
        int _id;
        int _booksPerDay;
        int _signedUpProcess;
        std::vector<Book *> _books;
        bool _isSigned;
};

#endif /* !LIBRARY_HPP */
