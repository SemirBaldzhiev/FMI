#include <iostream>
#include <cstring>

class Book {
    public:
        Book();
        Book(const Book& other);
        Book& operator=(const Book& other);
        ~Book();

        const char* getName() const;
        void setName(const char* name);

        const char* getTitle() const;
        void setTitle(const char* title);

        unsigned getCountPages() const;
        void setCountPages(unsigned pages);

        unsigned getYear() const;
        void setYear(unsigned year);

    private:
        char* name;
        char* title;
        unsigned countPages;
        unsigned year;

        void copy(const Book& other);
        void clear();
};

const char* Book::getName() const {
    return this->name;
}

void Book::setName(const char* name) {
    if (name == nullptr) {
        std::cout << "Set name parameter nullptr!\n";
        return;
    }

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
} 

const char* Book::getTitle() const {
    return this->title;
}

void Book::setTitle(const char* title) {
    if (title == nullptr) {
        std::cout << "Set title parameter nullptr!\n";
        return;
    }

    this->title = new char[strlen(title) + 1];
    strcpy(this->title, title);
}

unsigned Book::getCountPages() const {
    return this->countPages;
}

void Book::setCountPages(unsigned pages) {
    this->countPages = pages;
}

unsigned Book::getYear() const {
    return this->year;
}

void Book::setYear(unsigned year) {
    this->year = year;
}

void Book::copy(const Book& other) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    title = new char[strlen(other.title) + 1];
    strcpy(title, other.title);

    countPages = other.countPages;
    year = other.year; 
}

void Book::clear() {
    delete[] name;
    delete[] title;
}

Book::Book() : countPages(0), year(1970), name(nullptr), title(nullptr) { }

Book::Book(const Book& other) {
    copy(other);
}

Book& Book::operator=(const Book& other) {
    if (this != &other) {
        clear();
        copy(other);
    }

    return *this;
}

Book::~Book() {
    clear();
}


class Library {
    public:
        Library();
        Library(const char* address);
        Library(const Library& other);
        Library& operator=(const Library& other);
        ~Library();

        const char* getAddress() const;
        const Book* getBooks() const;

        void setAddress(const char* address);

        void sortByBookSize();
        void sortAlphabeticalOrder();

        void printBooks() const; 

    private:
        const unsigned count = 10;
        Book* books;
        char* address;

        void copy(const Library& other);
        void clear();
};

Library::Library() : address(nullptr) {
    books = new Book[count];
}

Library::Library(const char* address) {
    setAddress(address);
    books = new Book[count];
}

Library::Library(const Library& other) : count(other.count) {
    copy(other);
}

Library& Library::operator=(const Library& other) {
    if (this != &other) {
        clear();
        copy(other);
    }

    return *this;
}

Library::~Library() {
    clear();
}

void Library::clear() {
    delete[] books;
    delete[] address;
}

void Library::copy(const Library& other) {
    address = new char[strlen(other.address) + 1];
    strcpy(address, other.address);

    books = new Book[count];

    for (int i = 0; i < count; i++) {
        books[i] = other.books[i];
    }
}

const char* Library::getAddress() const {
            return address;
}

const Book* Library::getBooks() const {
    return books;
}

void Library::setAddress(const char* address) {
    this->address = new char[strlen(address) + 1];
    strcpy(this->address, address);
}


void Library::sortByBookSize() {

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (books[j].getCountPages() > books[j+1].getCountPages()) {
                Book temp = books[j];
                books[j] = books[j+1];
                books[j+1] = temp;
            }
        }
    }
}

void Library::sortAlphabeticalOrder() {

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(books[j].getTitle(), books[j+1].getTitle()) > 0) {
                Book temp = books[j];
                books[j] = books[j+1];
                books[j+1] = temp;
            }
        }
    }
}



int main() {


    return 0;
}