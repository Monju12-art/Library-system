// Developer's Name: Isaaclyne Jelleh
// Project Name: Monju Tech Library System (MTLS)
// Librarian password: 123

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>

using namespace std;

// Book structure
struct Book
{
    string title;
    string author;
    string status; // "Available" or "Borrowed"
    string url;    // Link to the book
};

// User structure
struct User
{
    string name;
    string contact;
    bool isLibrarian; // True if the user is a librarian
    string password;  // Password for user login
};

// Library class
class Library
{
private:
    vector<Book> books;
    vector<User> users;                          // To store user details
    const string filename = "library_books.txt"; // File to store book data
    const string librarianPassword = "123";      // Fixed librarian password

    // Load books from the file
    void loadBooks()
    {
        ifstream inFile(filename);
        if (inFile)
        {
            Book book;
            while (getline(inFile, book.title))
            {
                getline(inFile, book.author);
                getline(inFile, book.status);
                getline(inFile, book.url); // Read the book URL
                books.push_back(book);
            }
            inFile.close();
        }
    }

    // Save books to the file
    void saveBooks()
    {
        ofstream outFile(filename);
        for (const auto &book : books)
        {
            outFile << book.title << endl;
            outFile << book.author << endl;
            outFile << book.status << endl;
            outFile << book.url << endl; // Save the book URL
        }
        outFile.close();
    }

public:
    Library()
    {
        loadBooks(); // Load books when the library is created
    }

    ~Library()
    {
        saveBooks(); // Save books when the library is destroyed
    }

    // Register a user with no password complexity check
    void registerUser()
    {
        User newUser;
        cout << "Enter user name: ";
        cin.ignore();
        getline(cin, newUser.name);
        cout << "Enter contact information: ";
        getline(cin, newUser.contact);

        // Set password for the user without any complexity check
        string password;
        cout << "Enter password: ";
        cin >> password;

        newUser.password = password;
        users.push_back(newUser);
        cout << "User registered successfully!" << endl;
    }

    // Login a user
    User *loginUser(const string &name, const string &password)
    {
        for (auto &user : users)
        {
            if (user.name == name && user.password == password)
            {
                cout << "Login successful!" << endl;
                return &user;
            }
        }
        cout << "Invalid credentials!" << endl;
        return nullptr;
    }

    // Librarian login using fixed password
    User *loginLibrarian()
    {
        string password;
        cout << "Enter librarian password: ";
        cin >> password;

        if (password == librarianPassword)
        {
            cout << "Librarian login successful!" << endl;
            return nullptr; // No need for a User object, just access granted
        }
        else
        {
            cout << "Invalid librarian password!" << endl;
            return nullptr;
        }
    }

    // Add book to library (only for librarians)
    void addBook()
    {
        Book newBook;
        cout << "Enter book title: ";
        cin.ignore();
        getline(cin, newBook.title);
        cout << "Enter book author: ";
        getline(cin, newBook.author);
        newBook.status = "Available";

        // Get book URL
        cout << "Enter book URL: ";
        getline(cin, newBook.url);

        books.push_back(newBook);
        cout << "Book added successfully!" << endl;
    }

    // Delete a book
    void deleteBook()
    {
        displayBooks();
        int choice;
        cout << "Enter book number to delete: ";

        // Check if input is valid
        while (!(cin >> choice) || choice < 1 || choice > books.size())
        {
            cin.clear();                                         // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter a valid book number: ";
        }

        books.erase(books.begin() + choice - 1);
        cout << "Book deleted successfully!" << endl;
    }

    // Display all books
    void displayBooks()
    {
        if (books.empty())
        {
            cout << "No books available in the library." << endl;
            return;
        }
        cout << "Library Catalog:" << endl;
        for (int i = 0; i < books.size(); i++)
        {
            cout << i + 1 << ". " << books[i].title << " by " << books[i].author
                 << " (" << books[i].status << ")" << endl;
            cout << "   URL: " << books[i].url << endl; // Display the book URL
        }
    }

    // Borrow book
    void borrowBook()
    {
        if (users.empty())
        {
            cout << "No registered users. Please register a user first." << endl;
            return;
        }

        int userIndex;
        cout << "Select a user to borrow a book (1-" << users.size() << "): ";
        for (int i = 0; i < users.size(); ++i)
        {
            cout << i + 1 << ". " << users[i].name << " (" << users[i].contact << ")" << endl;
        }

        // Check if input is valid
        while (!(cin >> userIndex) || userIndex < 1 || userIndex > users.size())
        {
            cin.clear();                                         // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please select a valid user: ";
        }

        int bookIndex;
        displayBooks();
        cout << "Enter book number to borrow: ";

        // Check if input is valid
        while (!(cin >> bookIndex) || bookIndex < 1 || bookIndex > books.size())
        {
            cin.clear();                                         // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter a valid book number: ";
        }

        if (books[bookIndex - 1].status == "Available")
        {
            books[bookIndex - 1].status = "Borrowed";
            cout << "Book borrowed successfully by " << users[userIndex - 1].name << "!" << endl;
        }
        else
        {
            cout << "Book is already borrowed!" << endl;
        }

        cin.ignore(); // Clear the input buffer
    }

    // Return book
    void returnBook()
    {
        int choice;
        displayBooks();
        cout << "Enter book number to return: ";

        // Check if input is valid
        while (!(cin >> choice) || choice < 1 || choice > books.size())
        {
            cin.clear();                                         // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter a valid book number: ";
        }

        if (books[choice - 1].status == "Borrowed")
        {
            books[choice - 1].status = "Available";
            cout << "Book returned successfully!" << endl;
        }
        else
        {
            cout << "Book is already available!" << endl;
        }
    }

    // Get registered users
    const vector<User> &getUsers() const
    {
        return users;
    }
};

int main()
{
    Library library;

    while (true)
    {
        char role;
        cout << "Welcome to Monju Tech Library System" << endl;
        cout << "Please enter whether you are a Member(m) or Librarian(l)? (m/l): ";
        cin >> role;

        if (role == 'm' || role == 'M')
        { // Member Menu
            while (true)
            {
                cout << "\nMember Menu:" << endl;
                cout << "1. Register User" << endl;
                cout << "2. Display Books" << endl;
                cout << "3. Borrow Book" << endl;
                cout << "4. Return Book" << endl;
                cout << "5. Exit" << endl;
                cout << "Enter your choice: ";

                int choice;
                cin >> choice;

                switch (choice)
                {
                case 1:
                    library.registerUser();
                    break;
                case 2:
                    if (library.getUsers().empty())
                    { // Check if there are registered users
                        cout << "No registered users found. Please register first." << endl;
                    }
                    else
                    {
                        library.displayBooks(); // Display books if users are registered
                    }
                    break;
                case 3:
                    library.borrowBook();
                    break;
                case 4:
                    library.returnBook();
                    break;
                case 5:
                    return 0;
                default:
                    cout << "Invalid choice!" << endl;
                }
            }
        }
        else if (role == 'l' || role == 'L')
        {                             // Librarian Menu
            library.loginLibrarian(); // Prompt for librarian login
            while (true)
            {
                cout << "\nLibrarian Menu:" << endl;
                cout << "1. Add Book" << endl;
                cout << "2. Delete Book" << endl;
                cout << "3. Display Books" << endl;
                cout << "4. Exit" << endl; // Adjusted to match the menu options
                cout << "Enter your choice: ";

                int choice;
                cin >> choice;

                switch (choice)
                {
                case 1:
                    library.addBook();
                    break;
                case 2:
                    library.deleteBook();
                    break;
                case 3:
                    library.displayBooks();
                    break;
                case 4:
                    return 0;
                default:
                    cout << "Invalid choice!" << endl;
                }
            }
        }
        else
        {
            cout << "Invalid input. Please enter 'm' for Member or 'l' for Librarian." << endl;
        }
    }

    return 0;
}
