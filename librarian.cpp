#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "person.h"
#include "librarian.h"
#include "member.h"
#include "book.h"
#include "date.h"
#include <vector>
#include <regex>

std::vector<Member> memberMap;

Librarian::Librarian(int staffID, std::string name, std::string address, std::string email, int salary)
{
    std::cout << "object created" << '\n';
    Librarian::staffId = staffID;
    Person::setName(name);
    Person::setAddress(address);
    Person::setEmail(email);
    Librarian::salary = salary;
};

// Function to add create a member and add the Member to the Member Vector;
void Librarian::addMember()
{

    int tempMemID;
    std::string tempName;
    std::string tempAddress;
    std::string tempEmail;
    bool isValidEmail;
    // std::string& email = tempEmail;
    const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

    std::cout << "please enter member ID (Must be number): ";
    std::cin >> tempMemID;
    std::cout << "please enter member name: ";
    std::cin >> tempName;
    std::cout << "please enter member address: ";
    std::cin >> tempAddress;

    do
    {
        std::cout << "please enter member email: ";
        std::cin >> tempEmail;

        if (!std::regex_match(tempEmail, pattern))
        {
            isValidEmail = false;
            std::cout << "Please enter valid email!";
        }
        else
        {
            isValidEmail = true;
        }

    } while (isValidEmail == false);

    Member memberObj(tempMemID, tempName, tempAddress, tempEmail);

    memberMap.push_back(memberObj);

    memberObj.getMemberID();
    memberObj.getName();
    memberObj.getAddress();
    memberObj.getEmail();
};

void Librarian::issueBook(int memberID, int bookID)
{
    std::fstream bookfile;
    bool isValidDay;
    bool isValidMonth;
    bool isValidYear;

    bookfile.open("library_books.csv", std::ios::in);

    // check if book is open
    if (!bookfile.is_open())
    {
        std::cerr << "Error opening csv file!" << std::endl;
        return;
    }
    else
    {
        std::cout << "Book Open" << '\n';
    }

    std::vector<std::string> row, bookDetails;
    std::string line, word;
    int d, m, y;
    int count = 0;

    while (std::getline(bookfile, line))
    {
        row.push_back(line);
        count++;
    }

    // close book
    bookfile.close();

    std::string tempStr = row[bookID];

    std::stringstream bookStream(tempStr);

    while (bookStream.good())
    {
        std::getline(bookStream, word, ',');
        bookDetails.push_back(word);
    }

    //create book object with each part of the book detail
    Book bookObj(std::stoi(bookDetails[0]), bookDetails[1], bookDetails[2], bookDetails[3]);

    //getting due day from user input and validating date.
    do
    {
        std::cout << "Please set a due day (d): ";
        std::cin >> d;

        if (d > 31 || d == 0)
        {
            isValidDay = false;
            std::cout << "Please enter valid day, must be between 1 and 31!";
        }
        else
        {
            isValidDay = true;
        }

    } while (isValidDay == false);

    //getting due month from user input and validating date.
    do
    {
        std::cout << "Please set due month (m): ";
        std::cin >> m;

        if (m > 12)
        {
            isValidMonth = false;
            std::cout << "Please enter valid month, month must be between 1 and 12!";
        }
        else if (d > 29 && m == 2)
        {
            isValidMonth = false;
            std::cout << "Please enter valid month, this month has less than 30 days!";
        }
        else if (d == 31 && (m == 4 || m == 6 || m == 9 || m == 11))
        {
            isValidMonth = false;
            std::cout << "Please enter valid month, this month does not have 31 days!";
        }
        else
        {
            isValidMonth = true;
        }

    } while (isValidMonth == false);

    //getting due year from user input and validating date.
    do
    {
        std::cout << "Please set a due year (yyyy): ";
        std::cin >> y;

        if (std::to_string(y).size() != 4)
        {
            isValidYear == false;
            std::cout << "Please enter valid year of 4 numbers!";
        }
        else if (d > 28 && m == 2 && y % 4 == 0)
        {
            isValidYear = false;
            std::cout << "Please enter valid year, February only has 28 days in a leap year!";
        }
        else
        {
            isValidYear = true;
        }

    } while (isValidYear == false);

    Date validDate(d, m, y);
    bookObj.setDueDate(validDate);

    for (auto &obj : memberMap)
    {
        if (std::stoi(obj.getMemberID()) == memberID)
        {
            bookObj.borrowBook(&obj, validDate);
            obj.setBooksBorrowed(bookObj);
            std::cout << "Book titled: " << bookObj.getbookName() << " borrowed."
                      << " It is due on " << bookObj.getDueDate() << '\n';
        }
        else
        {
            std::cout << "wrong ID: " << memberID << std::endl;
        }
    }
};

// function to return book/remove book from booksLoaned in Member class
void Librarian::returnBook(int memberID, int bookID)
{
    for (auto &obj : memberMap)
    {
        if (std::stoi(obj.getMemberID()) == memberID)
        {
            std::vector<Book> &books = obj.getBooksBorrowed();
            if (!books.empty())
            {
                bool bookFound = false;
                for (size_t i = 0; i < books.size(); ++i)
                {
                    if (std::stoi(books[i].getbookID()) == bookID)
                    {
                        this->calcFine(memberID);
                        obj.getBooksBorrowed().erase(books.begin() + i);
                        bookFound = true;
                    }
                }
                if (bookFound)
                {
                    std::cout << "Book returned. Amount of books left: " << books.size() << std::endl;
                }
                else
                {
                    std::cout << "No book found with that ID." << std::endl;
                }
            }
            else
            {
                std::cout << "No book borrowed by this member!";
            }
            return;
        }
    }
    std::cout << "Member ID not found." << std::endl;
}

const void Librarian::displayBorrowedBooks(int memberID)
{
    for (auto &member : memberMap)
    {
        if (std::stoi(member.getMemberID()) == memberID)
        {
            if (member.getBooksBorrowed().size() > 0)
            {
                std::cout << "The Members book(s) include: ";
                if (member.getBooksBorrowed().size() == 1)
                {
                    for (Book book : member.getBooksBorrowed())
                    {
                        std::cout << book.getbookName();
                    };
                }
                else if (member.getBooksBorrowed().size() > 1)
                {
                    for (Book book : member.getBooksBorrowed())
                    {
                        std::cout << book.getbookName() << ", ";
                    };
                }
            }
            else
            {
                std::cout << "Member has no borrowed books.";
            }
        }
    }
}

void Librarian::calcFine(int memberID)
{
    bool isValidDay;
    bool isValidMonth;
    bool isValidYear;
    bool bookExpired;
    int d, m, y, daysDifference, fine;
    int bookID;

    std::cout << "Please enter bookID to confirm: ";
    std::cin >> bookID;

    do
    {
        std::cout << "Please enter return day (d): ";
        std::cin >> d;

        if (d > 31 || d == 0)
        {
            isValidDay = false;
            std::cout << "Please enter valid day, must be between 1 and 31!";
        }
        else
        {
            isValidDay = true;
        }

    } while (isValidDay == false);

    do
    {
        std::cout << "Please enter return month (m): ";
        std::cin >> m;

        if (m > 12)
        {
            isValidMonth = false;
            std::cout << "Please enter valid month, month must be between 1 and 12!";
        }
        else if (d > 29 && m == 2)
        {
            isValidMonth = false;
            std::cout << "Please enter valid month, this month has less than 30 days!";
        }
        else if (d == 31 && (m == 4 || m == 6 || m == 9 || m == 11))
        {
            isValidMonth = false;
            std::cout << "Please enter valid month, this month does not have 31 days!";
        }
        else
        {
            isValidMonth = true;
        }

    } while (isValidMonth == false);

    do
    {
        std::cout << "Please enter return year (yyyy): ";
        std::cin >> y;

        if (std::to_string(y).size() != 4)
        {
            isValidYear == false;
            std::cout << "Please enter valid year of 4 numbers!";
        }
        else if (d > 28 && m == 2 && y % 4 == 0)
        {
            isValidYear = false;
            std::cout << "Please enter valid year, February only has 28 days in a leap year!";
        }
        else
        {
            isValidYear = true;
        }

    } while (isValidYear == false);

    Date returnDate(d, m, y);

    for (auto &member : memberMap)
    {
        if (memberID == std::stoi(member.getMemberID()))
        {
            for (auto &book : member.getBooksBorrowed())
            {
                if (std::stoi(book.getbookID()) == bookID)
                {
                    if (returnDate > book.getDueDate())
                    {
                        daysDifference = returnDate.getNumberOfDays(returnDate, book.getDueDate());
                        std::cout << daysDifference;
                        if (daysDifference > 3)
                        {
                            bookExpired = true;
                        }
                        else
                        {
                            bookExpired = false;
                        }
                    }
                }
                else
                {
                    std::cout << "no book like that sir";
                }
            };
        }
    }

    if (bookExpired == true)
    {
        fine = daysDifference * 1;
        std::cout << "This book has expired, the fine is: " << fine << '\n';
    }
    else
    {
        std::cout << "This book has not expired!" << '\n';
    }
}

const int Librarian::getStaffID()
{
    return Librarian::staffId;
}

void Librarian::setStaffID(int staffID)
{
    Librarian::staffId = staffID;
}

const int Librarian::getSalary()
{
    std::cout << "Salary is " << Librarian::salary << '\n';
    return Librarian::salary;
}

void Librarian::setSalary(int salary)
{
    Librarian::salary = salary;
}
