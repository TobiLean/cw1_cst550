#include <string>
#include "member.h"
#include "person.h"


Member::Member(int memberID, std::string name, std::string address, std::string email)
{
    std::cout << "Member made" << '\n';
    Member::memberId = memberID;
    setName(name);
    setAddress(address);
    setEmail(email);
};

const std::string Member::getMemberID(){
    return std::to_string(memberId);
};

void setBooksBorrowed(){}
