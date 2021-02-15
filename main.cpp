#include <iostream>

#include "doublyLinkedList.hpp"
#include "movie.hpp"
#include "profile.hpp"
#include "category.hpp"
/*
1) create movie obj
2) create category obj based on movie category which points to list
3) insert movie into list for category obj
4) insert category obj into profile list of categories

category obj = new category(movieObj.getCategory());

for each category, if movie object matches category name, do
category.insertMovie(movieObj), if no category is found, make new category

currentProfile = getProfile(name); <- make this function
categories = currentProfile.getCategories()
*/
using namespace std;
/*
Examples:
	DoublyLinkedList<Movie> list;
	list.insert(movie1);
	list.erase(list.find(movie3));

	Movie movie1("A", 2010, "PG", 1);
*/
enum { horror, family, suspense, comedy, action, thriller } category;
short numProfile{ 0 }, LISTnumProfile{ 0 };
bool running{ true };
profile list[10];
short option{ NULL };
string newName, newCategory, newRating, ratingOption, nameToDelete, yearToDelete;
int newYear, newRanking;

string newProfileLabel, newProfileFName, newProfileLName;
int newProfileAge;
//void functions for different menus, only like 2 lines in main
//doublylinkedlist of profiles here in main

void mainMenu();
void personProfile();
void addPersonProfile();
void mainAddMovie();
void filterByRating(string, int);
void filterByCategory(string, int);
void removeAMovie();
void startRunning();

int main() {
	mainMenu();
	return 0;
}

void mainMenu() {
	cout << "\nWelcome to the Netflix Movie Menu! Please select (or create) a profile:\n";
	//cout << numProfile << endl;
	if (numProfile == 0) {
		cout << numProfile + 1 << ". Add New Profile" << endl;
		cout << numProfile + 2 << ". Exit Program" << endl;
	}
	else { //else if number entered is a number of a profile
			//option = NULL
			//personProfile();
		for (short i = 0; i < numProfile; i++) {
			cout << i + 1 << ". " << list[i].getLabel() << endl;
		}
		cout << numProfile + 1 << ". Add New Profile" << endl;
		cout << numProfile + 2 << ". Exit Program" << endl;
	}
	cin >> option;

	if (option == LISTnumProfile) {
		personProfile();
	}

	if (option == numProfile + 1) {
		addPersonProfile();
	}

	if (option == numProfile + 2) {
		running = false;
		cout << "Exit Program. Goodbye!";
	}

	option = NULL;

	if(running)
		mainMenu();
}

void addPersonProfile() {
	cout << "Enter Profile Label: ";
	cin >> newProfileLabel;
	cout << "Enter First Name: ";
	cin >> newProfileFName;
	cout << "Enter Last Name: ";
	cin >> newProfileLName;
	cout << "Enter Age: ";
	cin >> newProfileAge; cout << endl;
	numProfile++;
	cout << "Profile Created!" << endl << endl;
	profile temp(newProfileLabel, newProfileFName, newProfileLName, newProfileAge);
	list[LISTnumProfile] = temp;
	LISTnumProfile++;
}

void personProfile() {
	cout << list[LISTnumProfile - 1].getLabel() << "'s Profile Movie Queue" << endl;
	cout << "1. Display Movie Queue\n2. Add Movie to Queue\n3. Edit Movie in Queue\n4. Remove Movie from Queue\n5. Search for Movie in Queue\n6. Exit Profile" << endl;
	cin >> option;
	//if(numOfMoviesInQueue[person] == 0){
		cout << "The movie queue is empty! Please add movies to the queue.";
		//personProfile();
	//}
	
	option = NULL;
	
	switch (option) {
	case 1:
		option = NULL;
		break;
	case 2:
		option = NULL;
		break;
	case 3:
		cout << "Enter rating: ";
		cin >> ratingOption;
		option = NULL;
		filterByRating(ratingOption, option);
		break;
	case 4:
		option = NULL;
		break;
	case 5:
		option = NULL;
		break;
	case 6:
		option = NULL;
		break;
	default:
		option = NULL;
		break;
	}
}

void mainAddMovie() {

	cout << "Enter movie name: ";
	cin >> newName;
	cout << endl;

	cout << "Enter year: ";
	cin >> newYear;
	while (cin.fail() || (newYear < 1900 || newYear > 2100)) {
		cin.clear();
		cin.ignore();
		cout << "Not a valid year. Try again." << endl;
		cout << "Enter year: ";
	}
	cout << endl;

	cout << "Category: ";
	cin >> newCategory;
	cout << endl;

	cout << "Rating: ";
	cin >> newRating;
	cout << endl;

	cout << "Ranking (1-5): ";
	cin >> newRanking;
	while (cin.fail() || (newRanking < 1 || newRanking > 5)) {
		cin.clear();
		cin.ignore();
		cout << "Not a valid rating. Try again." << endl;
		cout << "Ranking: ";
	}
	cout << endl;

	cout << "Movie added to the Queue!" << endl;
	option = NULL;

	
	personProfile();
}

void filterByRating(string givenRating, int movieIndex) {
	if ((newRating != "G") && (newRating != "PG") && (newRating != "PG-13") && (newRating != "R") && (newRating != "NC-17")) {
		cout << "Invalid filter option. Try again.";
		filterByRating(givenRating, movieIndex);
	}
	cout << "The movies in your Queue with Rating " << givenRating << " are displayed below." << endl;
	cout << "----------------------------" << endl;
	cout << /*movieName*/ endl;
	cout << "Year: " /*year*/;
	cout << "Category: " /*category*/;
	cout << "Rated: " /*rating*/;
	cout << "Ranking: ";
	for (int i = 0; i < /*rating.length()*/5; i++) {
		cout << '*';
	}
	cout << endl;
	filterByRating(givenRating, movieIndex + 1);
}

void filterByCategory(string givenCategory, int movieIndex) {
	if ((newRating != "G") && (newRating != "PG") && (newRating != "PG-13") && (newRating != "R") && (newRating != "NC-17")) {
		cout << "Invalid filter option. Try again.";
		filterByRating(givenCategory, movieIndex);
	}
	cout << "The movies in your Queue in Category " << givenCategory << " are displayed below." << endl;
	cout << "----------------------------" << endl;
	cout << /*movieName*/ endl;
	cout << "Year: " /*year*/;
	cout << "Category: " /*category*/;
	cout << "Rated: " /*rating*/;
	cout << "Ranking: ";
	for (int i = 0; i < /*rating.length()*/5; i++) {
		cout << '*';
	}
	cout << endl;
	filterByRating(givenCategory, movieIndex + 1);
}

void removeAMovie() {
	cout << "Enter Movie Name: ";
	cin >> nameToDelete;
	cout << "Enter year: ";
	cin >> yearToDelete;
	if (/*success*/1) {
		cout << nameToDelete << "has been removed from your queue!" << endl;
	}
}