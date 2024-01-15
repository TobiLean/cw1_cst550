CXX = g++
CXXFLAGS = -g -Wall -Wextra -Wpedantic

.PHONY : all
all : lSys

lSys : main.o person.o member.o librarian.o book.o date.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o : main.cpp person.h member.h librarian.h book.h date.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

person.o : person.cpp person.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

member.o : member.cpp member.h person.h book.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

librarian.o : librarian.cpp librarian.h person.h member.h book.h date.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

book.o : book.cpp book.h member.h date.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY : clean
clean :
	rm -f *.o
	rm -f lSys
