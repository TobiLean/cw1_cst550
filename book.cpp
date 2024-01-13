#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include "book.h"
#include "date.h"
#include "member.h"

Book::Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName)
{
    Book::bookID = bookID;
    Book::bookName = bookName;
    Book::authorFirstName = authorFirstName;
    Book::authorLastName = authorLastName;
}

const std::string Book::getbookID()
{
    return std::to_string(bookID);
};

const std::string Book::getbookName(){
    return bookName;
};

const std::string Book::getAuthorFirstName(){
    return authorFirstName;
};

const std::string Book::getAuthorLastName(){
    return authorLastName;
};

const Date Book::getDueDate()
{
    return Book::dueDate;
};

void Book::setDueDate(Date dueDate)
{
    Book::dueDate = dueDate;
};

void Book::returnBook()
{
    
};

void Book::borrowBook(Member* borrower, Date dueDate)
{
    Book::borrower = borrower;
};