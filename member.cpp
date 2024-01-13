#include <string>
#include <map>
#include "member.h"
#include "person.h"
#include "librarian.h"

// std::vector<Member> memberMap;

Member::Member(int memberID, std::string name, std::string address, std::string email)
{
    std::cout << "Member made" << '\n';
    Member::memberId = memberID;
    setName(name);
    setAddress(address);
    setEmail(email);

};

const std::string Member::getMemberID()
{
    return std::to_string(memberId);
};

std::vector<Book> Member::getBooksBorrowed()
{
    return booksLoaned;
}

void Member::setBooksBorrowed(Book book)
{
    Member::booksLoaned.push_back(book);
}
