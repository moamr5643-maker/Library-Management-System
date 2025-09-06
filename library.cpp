#include "library.h"

void librarySystem::addBook(int Id, string Title, string Author) {
    if (allBooks.find(book(Id, "", "")) != allBooks.end()) {
        cout << "The book with ID " << Id << " already exists\n";
        return;
    }
    if (isAvailableByTitle.find(Title) != isAvailableByTitle.end()) {
        cout << "The book with Title \"" << Title << "\" already exists\n";
        return;
    }
    allBooks.insert(book(Id, Title, Author));
    isAvailableByTitle[Title] = Id;
    isAvailableById[Id] = true;
}

bool librarySystem::searchBookById(int Id) {
    return (allBooks.find(book(Id, "", "")) != allBooks.end());
}

bool librarySystem::searchBookByTitle(string Title) {
    return (isAvailableByTitle.find(Title) != isAvailableByTitle.end());
}

void librarySystem::borrowBookById(int Id) {
    if (isAvailableById.find(Id) != isAvailableById.end()) {
        isAvailableById.erase(Id);
        cout << "The book is borrowed successfully\n";
        return;
    }
    cout << "The book is already borrowed or does not exist\n";
}

void librarySystem::borrowBookByTitle(string Title) {
    if (searchBookByTitle(Title)) {
        int id = isAvailableByTitle[Title];
        borrowBookById(id);
        return;
    }
    cout << "The book is already borrowed or does not exist\n";
}

void librarySystem::returnBookById(int Id) {
    if (allBooks.find(book(Id, "", "")) != allBooks.end() &&
        isAvailableById.find(Id) == isAvailableById.end()) {
        isAvailableById[Id] = true;
        cout << "The book is returned successfully\n";
        return;
    }
    cout << "The book does not exist\n";
}

void librarySystem::returnBookByTitle(string Title) {
    if (isAvailableByTitle.find(Title) != isAvailableByTitle.end()) {
        int id = isAvailableByTitle[Title];
        returnBookById(id);
        return;
    }
    cout << "The book does not exist\n";
}

void librarySystem::ShowAllBooks() {
    if (allBooks.empty()) {
        cout << "The library is empty\n";
        return;
    }

    for (auto it : allBooks) {
        it.display();
        int Id = it.id;
        if (isAvailableById.find(Id) != isAvailableById.end())
            cout << " - Available\n";
        else
            cout << " - Not Available\n";
    }
}
