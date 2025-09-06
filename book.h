#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

class book {
public:
    int id;
    string title;
    string author;

    book(int id, string title, string author);
    void display() const;
    bool operator<(const book &second) const;
};

#endif // BOOK_H
