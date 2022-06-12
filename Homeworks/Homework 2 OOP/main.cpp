#include <iostream>
#include <fstream>

#include "Book.h"
#include "User.h"
#include "Rating.h"
#include "Comment.h"
#include "Kindle.h"

const int INPUT_SIZE = 60;
const int PAGE_SIZE = 1024;
using namespace std;

int main()
{
	char command[INPUT_SIZE];
	User loggedUser = User();
	do
	{
		cout << "Write down a command: " << endl;
		cin.getline(command, INPUT_SIZE);

		if (strcmp(command, "sign up") == 0)
		{
			char username[INPUT_SIZE];
			cout << "Username: ";
			cin.getline(username, INPUT_SIZE);
			char password[INPUT_SIZE];
			cout << "Password: ";
			cin.getline(password, INPUT_SIZE);

			User newUser = User();
			newUser.registerUser(username, password);
		}
		else if (strcmp(command, "log in") == 0)
		{
			char username[INPUT_SIZE];
			cout << "Username: ";
			cin.getline(username, INPUT_SIZE);
			char password[INPUT_SIZE];
			cout << "Password: ";
			cin.getline(password, INPUT_SIZE);

			Kindle kindle = Kindle();
			loggedUser.setName(username);
			loggedUser.setPassword(password);
			kindle.logIn(loggedUser);
		}

		if (!loggedUser.getLoggedIn())
		{
			cout << "Either this command doesn't exist or you are not logged in!" << endl;
			continue;
		}

		if (strcmp(command, "view booklist") == 0)
		{
			loggedUser.viewBookList();
		}
		else if (strcmp(command, "rate") == 0)
		{
			char bookName[INPUT_SIZE];
			cout << "Write down the name of the book you want to rate: ";
			cin.getline(bookName, INPUT_SIZE);
			Book book(bookName);

			int stars;
			cout << "How many stars do you rate the book with? : ";
			cin >> stars;
			Rating rating(loggedUser.getName(), stars);
			loggedUser.rateBook(book, rating);
		}
		else if (strcmp(command, "comment") == 0)
		{
			char bookName[INPUT_SIZE];
			cout << "Write down the name of the book you want to comment: ";
			cin.getline(bookName, INPUT_SIZE);
			Book book(bookName);

			char commentContent[INPUT_SIZE];
			cout << "Your comment: ";
			cin.getline(commentContent, INPUT_SIZE);
			Comment comment(loggedUser.getName(), commentContent);
			loggedUser.commentBook(book, comment);
		}
		else if (strcmp(command, "view comments") == 0)
		{
			char bookName[INPUT_SIZE];
			cout << "Which book do you want to see the comments of? : ";
			cin.getline(bookName, INPUT_SIZE);
			Book book(bookName);
			loggedUser.viewComments(bookName);
		}
		else if (strcmp(command, "view ratings") == 0)
		{
			char bookName[INPUT_SIZE];
			cout << "Which book do you want to see the ratings of? : ";
			cin.getline(bookName, INPUT_SIZE);
			Book book(bookName);
			loggedUser.viewRatings(bookName);
		}
		else if (strcmp(command, "read") == 0)
		{
			char bookName[INPUT_SIZE];
			cout << "Which book do you want to read? : ";
			cin.getline(bookName, INPUT_SIZE);
			Book book(bookName);
			loggedUser.readBook(bookName);
		}
		else if (strcmp(command, "write") == 0)
		{
			loggedUser.writeBook();
		}
		else if (strcmp(command, "add page") == 0)
		{
			char bookName[INPUT_SIZE];
			cout << "Which book do you want to add page to? : ";
			cin.getline(bookName, INPUT_SIZE);
			Book book(bookName);

			char pageContent[PAGE_SIZE];
			cout << "Write down the text you want to add to the new page: ";
			cin.getline(pageContent, PAGE_SIZE);
			Page page(pageContent);
			loggedUser.addPageToBook(book, page);
		}
	} while (strcmp(command, "log out") != 0);

}