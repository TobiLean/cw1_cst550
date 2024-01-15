#include <string>
#include "member.h"
#include "person.h"
#include "librarian.h"

/*
    parameterized constructor of Member Class
*/
Member::Member(int memberID, std::string name, std::string address, std::string email)
{
    std::cout << "Member made" << '\n';
    Member::memberId = memberID;
    setName(name);
    setAddress(address);
    setEmail(email);
};

/*
    function to get member ID
    @return a string of the member ID
*/
const std::string Member::getMemberID()
{
    return std::to_string(memberId);
};

/*
    function to get books borrowed vector
    @return a vector of the books borrowed by a member
*/
std::vector<Book> &Member::getBooksBorrowed()
{
    return Member::booksLoaned;
}

/*
    function to set books loaned by member
    @param book object
*/
void Member::setBooksBorrowed(Book book)
{
    Member::booksLoaned.push_back(book);
}
