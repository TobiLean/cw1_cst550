#include <iostream>
#include <vector>
#include <string>
#include "book.h"
#include "date.h"
#include "member.h"

//book constructor
Book::Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName)
{
    Book::bookID = bookID;
    Book::bookName = bookName;
    Book::authorFirstName = authorFirstName;
    Book::authorLastName = authorLastName;
}

//function to get book ID
const std::string Book::getbookID()
{
    return std::to_string(bookID);
};

//function to get book Name
const std::string Book::getbookName(){
    return bookName;
};

//function to get the Author's First Name
const std::string Book::getAuthorFirstName(){
    return authorFirstName;
};

//function to get the Author's Last Name
const std::string Book::getAuthorLastName(){
    return authorLastName;
};

//function to get a book's due date
const Date Book::getDueDate()
{
    return Book::dueDate;
};

//function to set a book's due date
void Book::setDueDate(Date dueDate)
{
    Book::dueDate = dueDate;
};

//function to remove borrower from book;
void Book::returnBook()
{
    this->borrower = NULL;
};

//function to add borrower to book
void Book::borrowBook(Member* borrower, Date dueDate)
{
    Book::borrower = borrower;
};