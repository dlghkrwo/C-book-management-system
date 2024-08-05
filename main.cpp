#include <iostream>
#include <unordered_map>
#include <string>

// Book class
class Book {
public:
    std::string title;
    std::string author;
    bool isLoaned;

    // book generator
    Book() : title(""), author(""), isLoaned(false) {}
    
    // get parameter : title, author, isloaned
    Book(std::string t, std::string a) : title(t), author(a), isLoaned(false) {}
};

// Library class
class Library {
private:
    // key: title , value : book
    std::unordered_map<std::string, Book> books;

public:
    //  const std::string& title: for title, 
    // const std::string& author: for author
    void addBook(const std::string& title, const std::string& author) {
        books[title] = Book(title, author);
        std::cout << "Book added: " << title << " by " << author << std::endl;
    }

    // book delete by title
    void deleteBook(const std::string& title) {
        books.erase(title);
        std::cout << "Book deleted: " << title << std::endl;
    }

    // book modify
    void modifyBook(const std::string& title, const std::string& newTitle, const std::string& newAuthor) {
        if (books.find(title) != books.end()) {
            books[title].title = newTitle;
            books[title].author = newAuthor;
            std::cout << "Book modified: " << newTitle << " by " << newAuthor << std::endl;
        }
    }

    // book isLoaned = true
    void loanBook(const std::string& title) {
        if (books.find(title) != books.end() && !books[title].isLoaned) {
            books[title].isLoaned = true;
            std::cout << "Book loaned: " << title << std::endl;
        }
    }

    // book isLoaned = false
    void returnBook(const std::string& title) {
        if (books.find(title) != books.end() && books[title].isLoaned) {
            books[title].isLoaned = false;
            std::cout << "Book returned: " << title << std::endl;
        }
    }
};

// main 
int main() {
    Library library;
    library.addBook("1984", "George Orwell");
    library.addBook("To Kill a Mockingbird", "Harper Lee");
    library.loanBook("1984");
    library.returnBook("1984");
    library.modifyBook("To Kill a Mockingbird", "To Kill a Mockingbird", "Lee Harper");
    library.deleteBook("1984");
    return 0;
}