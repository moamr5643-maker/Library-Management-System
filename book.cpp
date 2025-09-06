#include "book.h"

book::book(int Id, string Title, string Author)
    : id(Id), title(Title), author(Author) {}

bool book::operator<(const book &second) const {
    return id < second.id;
}

void book::display() const {
    cout << "ID: " << id
         << ", Title: " << title
         << ", Author: " << author;
}
