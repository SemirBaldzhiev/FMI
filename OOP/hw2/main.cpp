#include <iostream>
#include <fstream>
#include "Library.h"
#include "Book.h"
#include "PeriodicalEdition.h"
#include "Comics.h"

int main() {

    std::ifstream ifs("testEditions.txt");
    std::ifstream ifs2("testUsers.txt");

    if (!ifs.is_open()) {
        std::cout << "Cannot open file testEditions.txt for reading\n";
        return -1;
    }

    if (!ifs2.is_open()) {
        std::cout << "Cannot open file testUsers.txt for reading\n";
        return -1;
    }

    std::ofstream ofs("testEditions.txt");
    std::ofstream ofs2("testUsers.txt");

    if (!ofs.is_open()) {
        std::cout << "Cannot open file testEditions.txt for writing\n";
        return -1;
    }

    if (!ofs.is_open()) {
        std::cout << "Cannot open file testUsers.txt for writing\n";
        return -1;
    }

    Library lib;
    try {
        lib.readEditions(ifs);
    }
    catch (std::invalid_argument &e) {
        std::cout << e.what() << '\n';  
    }

    lib.readUsers(ifs2);

    Book b12("Book12", "book12 description", 12,2021, "Author12", "Publisher12", Characteristic::FICTION, Type::DRAMA, TargetAudience::ADULTS);
    Book b23("Book23", "book23 description", 23,2022, "Author23", "Publisher23", Characteristic::CRIME_FICTION, Type::PROSE, TargetAudience::ADOLESCENTS);
    PeriodicalEdition p1("Periodical2", "period2", 345, 2020,Periodicity::MONHTLY, 2);
    Comics c1("Comics12", "comics12 description", 58, 2020, "Author12", "Pub12", Characteristic::FICTION, Type::PROSE, TargetAudience::ADULTS, Periodicity::ONCE_A_YEAR, 3);
    Book b34("Book34", "booк34 description", 72,2022, "Author34", "Publisher34", Characteristic::THRILLER, Type::PROSE, TargetAudience::CHILDREN);
    Book b45("Book45", "book45 description", 95,2022, "Author45", "Publisher45", Characteristic::CRIME_FICTION, Type::PROSE, TargetAudience::ADULTS);
    Book b56("Book56", "book56 description", 89,2022, "Author56", "Publisher56", Characteristic::FICTION, Type::DRAMA, TargetAudience::ADOLESCENTS);
    Book b67("Book67", "book67 description", 121,2021, "Author567", "Publisher67", Characteristic::THRILLER, Type::POETRY, TargetAudience::CHILDREN);

    User newUser("newUser");
    User u1("User1");
    User u2("User2");
    User dummyUser("DummyUser");


    lib.addEdition(b12);
    lib.addEdition(b23);
    lib.addEdition(p1);
    lib.addEdition(c1);
    lib.addEdition(b34);
    lib.addEdition(b45);
    lib.addEdition(b56);
    lib.addEdition(b67);

    lib.addUser(u1);
    lib.addUser(u2);
    lib.addUser(newUser);
    lib.addUser(dummyUser);

    lib.borrowEdition(newUser, 12);
    lib.borrowEdition(newUser, 23);
    lib.borrowEdition(u1, 345);
    lib.borrowEdition(u2, 72);
    lib.borrowEdition(u1, 95);
    lib.borrowEdition(newUser, 58);
    lib.borrowEdition(u2, 89);
    lib.borrowEdition(u1, 12);
    lib.borrowEdition(u1, 23);

    lib.returnEdition(u1, 345);
    lib.returnEdition(u2, 72);
    lib.returnEdition(newUser, 12);

    lib.printEditionsInfo();
    std::cout << "-------------------------------------------------------------------------\n";
    lib.printUsersByReadedEditions();
    std::cout << "-------------------------------------------------------------------------\n";
    lib.printUsersNotReturnedEdition(23);
    std::cout << "-------------------------------------------------------------------------\n";
    lib.printOverdueEditions();
    std::cout << "-------------------------------------------------------------------------\n";

    lib.removeEdition(121);
    lib.removeUser("DummyUser");

    std::cout << b12.getCharacteristic() << " " << b12.getType() << " " << b12.getTargetAudience() << "\n";

    lib.writeEditions(ofs);
    lib.writeUsers(ofs2);

    ofs.close();
    ofs2.close();
    return 0;
}