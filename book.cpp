#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include "book.h"

Book::Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName)
{
    Book::bookID = bookID;
    Book::bookName = bookName;
    Book::authorFirstName = authorFirstName;
    Book::authorLastName = authorLastName;
}

std::string Book::getbookID()
{
    return std::to_string(bookID);
};

std::string Book::getbookName(){
    return bookName;
};

std::string Book::getAuthorFirstName(){
    return authorFirstName;
};

std::string Book::getAuthorLastName(){
    return authorLastName;
};

time_t Book::getDueDate(){};

void Book::setDueDate(time_t Date){};

void Book::returnBook(){};

void borrowBook(Member borrower, time_t dueDate){};