#include "Book.hpp"
#include "Library.hpp"
#include "Parser.hpp"
#include <string>
#include <algorithm>
#include <iostream>

void signedProcess(std::vector<Library *> libraries)
{
    static int libId = -1;

    if (libId == -1) {
        std::for_each(libraries.begin(), libraries.end(), [](Library *library) {
            if (library->isSigned() == false) {
                libId = library->getId();
                std::cout << library->getId() << " " << library->getBooksPerDay() << std::endl;
            }
        });
        return;
    }
    std::for_each(libraries.begin(), libraries.end(), [](Library *library) {
        if (library->getId() == libId) {
            if (library->signedUp() == true) {
                libId = -1;
            }
        }
    });
}

void scanBooks(std::vector<Library *> libraries)
{
    std::for_each(libraries.begin(), libraries.end(), [](Library *library) {
        if (library->isSigned()) {
            library->scanBooks();
        }
    });
}

int main(int argc, char **argv)
{
    Parser parser(argv[1]);
    parser.parseFile();

    std::vector<Library *> libraries = parser.getLibraries();

    size_t daysNb = parser.getDaysNb();
    (void)argc;
    std::cout << libraries.size() << std::endl;
    for (size_t i = 0; i < daysNb; i++) {
        signedProcess(libraries);
        scanBooks(libraries);
    }
    return 0;
}