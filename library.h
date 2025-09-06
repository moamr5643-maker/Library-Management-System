#ifndef LIBRARY_H
#define LIBRARY_H


#include<bits/stdc++.h>
#include"book.h"
using namespace std;
class Library{
private:
    set<book>allBooks;
    map<string,int>titleToId;
    map<int,bool>isAvailable;
public:
 void addBook(int id,string title,string author);
 bool searchBookById(int id);
 bool searchBookByTitle(string title);
 void borrowBookById(int id);
 void borrowBookByTitle(string title);
 void returnBookById(int id);
 void returnBookByTitle(string title);
 void displayBooks();

};

#endif // LIBRARY_H
