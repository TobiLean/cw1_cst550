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

/*
    function to get book ID
    @return a string of the book ID
*/
const std::string Book::getbookID()
{
    return std::to_string(bookID);
};

/*
    function to get book Name
    @return a string of the book Name
*/
const std::string Book::getbookName(){
    return bookName;
};

/*
    function to get Author first name
    @return a string of the Author's first name
*/
const std::string Book::getAuthorFirstName(){
    return authorFirstName;
};

/*
    function to get book Author's last name
    @return a string of the Author's last name
*/
const std::string Book::getAuthorLastName(){
    return authorLastName;
};

/*
    function to get book due date
    @return Date of the book due date
*/
const Date Book::getDueDate()
{
    return Book::dueDate;
};

/*
    function to set book due date
    @param due date of the book
*/
void Book::setDueDate(Date dueDate)
{
    Book::dueDate = dueDate;
};

/*
    function to set book borrower to NULL
*/
void Book::returnBook()
{
    this->borrower = NULL;
};

/*
    function to add borrower to book
*/
void Book::borrowBook(Member* borrower, Date dueDate)
{
    Book::borrower = borrower;
};