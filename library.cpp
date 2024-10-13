#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool isAvailable;
};

class LibrarySystem {
private:
    vector<Book> books;
    int nextBookId = 1;

public:
    void addBook(string title, string author) {
        Book newBook;
        newBook.id = nextBookId++;
        newBook.title = title;
        newBook.author = author;
        newBook.isAvailable = true;
        books.push_back(newBook);
        cout << "Added book: " << title << " by " << author << " with ID: " << newBook.id << endl;
    }

    void removeBook(int bookId) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].id == bookId) {
                books.erase(books.begin() + i);
                cout << "Removed book with ID: " << bookId << endl;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    void searchBookByTitle(string title) {
        for (const auto &book : books) {
            if (book.title == title) {
                cout << "Found book: " << book.title << " by " << book.author << ". Available: " << (book.isAvailable ? "Yes" : "No") << endl;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    void borrowBook(int bookId) {
        for (auto &book : books) {
            if (book.id == bookId) {
                if (book.isAvailable) {
                    book.isAvailable = false;
                    cout << "You have borrowed: " << book.title << endl;
                } else {
                    cout << "Book is already borrowed!" << endl;
                }
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    void returnBook(int bookId) {
        for (auto &book : books) {
            if (book.id == bookId) {
                book.isAvailable = true;
                cout << "Returned book: " << book.title << endl;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }
};

int main() {
    LibrarySystem library;

    library.addBook("The Great Gatsby", "F. Scott Fitzgerald");
    library.addBook("1984", "George Orwell");

    library.searchBookByTitle("1984");
    library.borrowBook(2);
    library.returnBook(2);
    library.removeBook(1);

    return 0;
}
