#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "person.h"
#include "date.h"
#include "librarian.h"
#include "member.h"
#include "book.h"

TEST_CASE("Date default constructor initializes correctly ", "[Date]")
{
    Date date;
    REQUIRE(date.getDay() == 9);
    REQUIRE(date.getMonth() == 1);
    REQUIRE(date.getYear() == 2003);
}

TEST_CASE("Date parameterized constructor initializes correctly ", "[Date]")
{
    Date date(1, 10, 2003);
    REQUIRE(date.getDay() == 1);
    REQUIRE(date.getMonth() == 10);
    REQUIRE(date.getYear() == 2003);
}

TEST_CASE("Date function to get difference between days calculates correctly ", "[Date]")
{
    Date d1(4, 5, 2015);
    Date d2(8, 5, 2015);

    REQUIRE(d1.getDateDiffernce(d1, d2) == 4);
}

TEST_CASE("Date comparison operators work correctly", "[Date]")
{
    Date d1(4, 5, 2015);
    Date d2(8, 5, 2015);
    Date d3(4, 5, 2015);

    REQUIRE(d1 < d2);
    REQUIRE(d2 > d1);
    REQUIRE(d1 == d3);
}

TEST_CASE("Person setters and getters produce expected outcome", "[Person]")
{
    Person person;

    SECTION("Setting name and getting name")
    {
        person.setName("Boba");
        REQUIRE(person.getName() == "Boba");
    }

    SECTION("Setting address and getting address")
    {
        person.setAddress("1, yinka street");
        REQUIRE(person.getAddress() == "1, yinka street");
    }

    SECTION("Setting email and getting email")
    {
        person.setEmail("Boba@tea.com");
        REQUIRE(person.getEmail() == "Boba@tea.com");
    }
}

TEST_CASE("Librarian parameterized constructor initializes correctly", "[Librarian]")
{
    Librarian librarian(1, "John Michael Kane", "1 Action street", "bourne@jmail.com", 1000);

    REQUIRE(librarian.getStaffID() == 1);
    REQUIRE(librarian.getName() == "John Michael Kane");
    REQUIRE(librarian.getAddress() == "1 Action street");
    REQUIRE(librarian.getEmail() == "bourne@jmail.com");
    REQUIRE(librarian.getSalary() == 1000);
}

TEST_CASE("Librarian returnBook function works correctly", "[Librarian]")
{
    std::vector<Member> memberContainer;

    Librarian librarian(1, "John Michael Kane", "1 Action street", "bourne@jmail.com", 1000);
    Member member(1, "Fine Bouy", "7 keen street", "fine@jmail.com");
    Book book(1, "A great book", "Paul", "Adewale");
    memberContainer.push_back(member);
    memberContainer[0].setBooksBorrowed(book);

    SECTION("Returning a book borrowed by member")
    {
        librarian.returnBook(1, 1);
        for(auto& mem : memberContainer)
        {
            std::vector<Book> &books = mem.getBooksBorrowed();
            REQUIRE(std::stoi(books[0].getbookID()) == 1);
        }
    }

    SECTION("Returning a book not borrowed by member")
    {
        librarian.returnBook(1, 2);
        REQUIRE(!memberContainer[0].getBooksBorrowed().empty());
    }

    SECTION("Returning a book borrowed by member that is not created")
    {
        librarian.returnBook(2, 1);
        REQUIRE(memberContainer[0].getBooksBorrowed().size() == 1);
    }

    memberContainer.clear();

}

TEST_CASE("Member parameterized constructor working properly", "[Member]")
{
    Member member(1, "Fine Bouy", "7 keen street", "fine@jmail.com");
    
    REQUIRE(member.getMemberID() == "1");
    REQUIRE(member.getName() == "Fine Bouy");
    REQUIRE(member.getAddress() == "7 keen street");
    REQUIRE(member.getEmail() == "fine@jmail.com");
}

TEST_CASE("Member get and set booksborrowed function working correctly", "[Member]")
{
    Member member(1, "Fine Bouy", "7 keen street", "fine@jmail.com");
    Book book(1, "A great book", "Paul", "Adewale");

    member.setBooksBorrowed(book);
    for(auto &b : member.getBooksBorrowed())
    {
        REQUIRE(std::stoi(b.getbookID()) == 1);
    }
}

TEST_CASE("Book parameterized constructor working properly", "[Book]")
{
    Book book(1, "A great book", "Paul", "Adewale");
    REQUIRE(std::stoi(book.getbookID()) == 1);
    REQUIRE(book.getbookName() == "A great book");
    REQUIRE(book.getAuthorFirstName() == "Paul");
    REQUIRE(book.getAuthorLastName() == "Adewale");
}

TEST_CASE("Book class setDueDate working expectedly", "[BOok]")
{
    Book book(1, "A great book", "Paul", "Adewale");
    Date date(1, 12, 2026);

    book.setDueDate(date);
    REQUIRE(book.getDueDate() == date);
}
