# Monju Tech Library System (MTLS)

Monju Tech Library System (MTLS) is a simple C++ program designed to simulate a library system. It allows members to register, borrow, and return books, while librarians have the ability to add or delete books from the library catalog. The system ensures that books are either marked as "Available" or "Borrowed", and users can interact with the system through a console-based interface.

## Features

- **User Registration:** Members can register with their name, contact information, and password.
- **User Login:** Members can log in with their credentials, and librarians can log in with a fixed password.
- **Library Management:** Librarians can add or delete books from the library.
- **Book Borrowing and Returning:** Members can borrow and return books, with real-time status updates (Available/Borrowed).
- **Book Display:** Both members and librarians can view the list of available books in the catalog.

## Prerequisites

To run this program, you'll need:

- A C++ compiler (such as GCC or Clang)
- A text editor or IDE (e.g., Visual Studio Code, Code::Blocks, etc.)

## How to Run

1. **Clone the repository** to your local machine using the following command:

   ```bash
   git clone https://github.com/your-username/monju-tech-library-system.git
   
 2.  Navigate to the project directory in your terminal or IDE.

3.Compile the program using your C++ compiler:

bash
Copy code
g++ -o library_system main.cpp
4.Run the program:

bash
Copy code
./library_system
Program Structure
The program consists of several components:

Book Structure: Defines the properties of a book, such as title, author, status (Available or Borrowed), and a URL to the book.
User Structure: Defines user information, including their name, contact, password, and whether they are a librarian.
Library Class: Manages the books and users, allows for book addition, deletion, borrowing, and returning, and handles user login functionality.
Main Function: Provides the user interface for both members and librarians to interact with the library system.
Menu Options
Member Menu (m):

1. Register User: Register as a new user.
2. Display Books: View all books in the library.
3. Borrow Book: Borrow a book if it's available.
4. Return Book: Return a borrowed book.
5. Exit: Exit the program.
Librarian Menu (l):

1. Add Book: Add a new book to the library.
2. Delete Book: Delete a book from the library.
3. Display Books: View all books in the library.
4. Exit: Exit the program.
File Storage
The library data (books) is saved in a text file named library_books.txt. This file is automatically loaded when the program starts and updated when books are added or deleted.

How It Works
Member Role: Members can view books, borrow them if available, and return borrowed books.
Librarian Role: Librarians have full control over the book catalog, including adding and deleting books.
License
This project is open-source and available under the MIT License.

Acknowledgments
Special thanks to the C++ community for their resources and support in building this program.
The program uses basic file I/O operations and simple data structures (vectors) to manage book and user data.
css
Copy code

