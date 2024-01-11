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

std::string getbookID(){};

std::string getbookName(){};

std::string getAuthorFirstName(){};

std::string getAuthorLastName(){};

time_t getDueDate(){};

void setDueDate(time_t Date){};

void returnBook(){};

void borrowBook(Member borrower, time_t dueDate){};