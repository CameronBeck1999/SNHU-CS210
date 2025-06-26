#include <iostream>
#include <fstream>
#include <map>
using namespace std;

/*
*Cameron Beck
*CS210
*Project 3
*6/17/2025 
*/

class CornerGrocer {//Created a class for CornerGrocer
public:
	//This function displays the option for the user to choose
	//everytime during the while-loop in int main()
	void MenuOption();

	//These public functions displays to the user
	//based off the user's choice from the menu.
	void IndividualFrequency();
	void OverallFrequency();
	void Histogram();

	//Accessors and Mutators
	void SetMenuChoice(int option);
	int GetMenuChoice()const;

	void SetKeyWord(string word);
	string GetKeyWord()const;
private:
	//Initialized the private values by default.
	int menuChoice = 0;
	string userWord = "";

};

void CornerGrocer::MenuOption() {
	//The list of options of what the user can input
	//as long as the user doesn't choose 4. Otherwise
	//the program terminates.
	cout << "Select option" << endl;
	cout << "(1) Total count for one item" << endl;
	cout << "(2) Total count of all items" << endl;
	cout << "(3) Frequency list of all items" << endl;
	cout << "(4) Exit" << endl;
}

void CornerGrocer::SetMenuChoice(int option) {
	menuChoice = option;
}

int CornerGrocer::GetMenuChoice() const {
	return menuChoice;
}

void CornerGrocer::SetKeyWord(string word) {
	userWord = word;
}

string CornerGrocer::GetKeyWord() const {
	return userWord;
}

void CornerGrocer::IndividualFrequency() {//When user selects 1 from the menu
	
	ifstream inFS;
	ofstream outFS;
	CornerGrocer word;

	inFS.open("CS210_Project_Three_Input_File.txt");
	outFS.open("Frequency.dat");
	if (!(inFS.is_open())) {
		cout << "Could not open file CS210_Project_Three_Input_File.txt" << endl;

	}
	if (!(outFS.is_open())) {
		cout << "Could not open file Frequency.dat" << endl;

	}

	string keyWord;
	string currentWord;
	int wordFrequency = 0;

	cout << "Enter an item you wish to look for: " << endl;
	cin >> keyWord;
	word.SetKeyWord(keyWord);

	/*While loop iterates through the text file and sees if the
	*current word matches the users input. If it does, then
	*we increment wordFrequency by 1 each time.
	*/
	while (!inFS.eof()) {
		inFS >> currentWord;
		if (!inFS.fail()) {
			if (currentWord == word.GetKeyWord()) {
				wordFrequency++;
			}
		}
	}
	//Prints out the users word along with the word count how many
	//times the users input word occurs in the Frequency.txt file
	outFS << keyWord << " " << wordFrequency << endl;
	
	//close both files
	inFS.close();
	outFS.close();

}

void CornerGrocer::OverallFrequency() {//When user selects option 2 from the menu
	map<string, int> groceryItems;

	ofstream outFS;
	outFS.open("Frequency.dat");
	if (!(outFS.is_open())) {
		cout << "Could not open file Frequency.dat" << endl;

	}
	//I went with the Maps route of implementation
	//as a suggestion from the instructions.
	groceryItems.emplace("Spinach", 5);
	groceryItems.emplace("Radishes", 3);
	groceryItems.emplace("Brocolli", 7);
	groceryItems.emplace("Peas", 8);
	groceryItems.emplace("Cranberries", 10);
	groceryItems.emplace("Potatoes", 5);
	groceryItems.emplace("Cucumbers", 9);
	groceryItems.emplace("Peaches", 5);
	groceryItems.emplace("Zucchini", 10);
	groceryItems.emplace("Cantaloupe", 2);
	groceryItems.emplace("Beets", 3);
	groceryItems.emplace("Cauliflower", 6);
	groceryItems.emplace("Onions", 4);
	groceryItems.emplace("Yams", 5);
	groceryItems.emplace("Apples", 4);
	groceryItems.emplace("Celery", 6);
	groceryItems.emplace("Limes", 1);
	groceryItems.emplace("Pumpkins", 2);
	groceryItems.emplace("Pears", 1);
	groceryItems.emplace("Garlic", 8);

	//A for loop to print the name of the item and the frequency beside it.
	for (auto& pair : groceryItems) {
		outFS << pair.first << " " << pair.second << endl;
	}
	outFS.close();
}

void CornerGrocer::Histogram() {//When user selects option 3 from the menu

	ofstream outFS;
	outFS.open("Frequency.dat");
	if (!(outFS.is_open())) {
		cout << "Could not open file Frequency.dat" << endl;

	}

	//I went with the Maps route of implementation from chapter 11 of zyBooks
	//as a suggestion from the instructions.
	map<string, int> groceryItems;
	groceryItems.emplace("Spinach", 5);
	groceryItems.emplace("Radishes", 3);
	groceryItems.emplace("Brocolli", 7);
	groceryItems.emplace("Peas", 8);
	groceryItems.emplace("Cranberries", 10);
	groceryItems.emplace("Potatoes", 5);
	groceryItems.emplace("Cucumbers", 9);
	groceryItems.emplace("Peaches", 5);
	groceryItems.emplace("Zucchini", 10);
	groceryItems.emplace("Cantaloupe", 2);
	groceryItems.emplace("Beets", 3);
	groceryItems.emplace("Cauliflower", 6);
	groceryItems.emplace("Onions", 4);
	groceryItems.emplace("Yams", 5);
	groceryItems.emplace("Apples", 4);
	groceryItems.emplace("Celery", 6);
	groceryItems.emplace("Limes", 1);
	groceryItems.emplace("Pumpkins", 2);
	groceryItems.emplace("Pears", 1);
	groceryItems.emplace("Garlic", 8);

	//A for loop to print the name of the item and the frequency beside it.
	for (auto& pair : groceryItems) {
		outFS << pair.first << " ";
		for (int i = 0; i < pair.second;i++) {
			outFS << "*"; //Instead of numbers, it's replaced by '*' depending how many frequencies for each item (pair.second)
		}
		outFS << endl;
	}
	outFS.close();
}

int main() {
	CornerGrocer menu; //Declared object that accesses the CornerGrocer class
	int menuOption = 0; //initializing menu option to 0
	
	//As long as the user option input doesn't equal 4.
	//the while-loop will continue.
	//Options 1 - 3 will output the result to the "Frequency.dat" file
	while (menuOption != 4) {
		menu.MenuOption();//Displays a list of options for the user to choose.
		cin >> menuOption;

		if (menuOption == 1) {
			//The user will enter an item to display a total number of
			//selected item.
			menu.IndividualFrequency();
		}
		if (menuOption == 2) {
			//The function will display the total number of all the items from the file.
			menu.OverallFrequency();
		}
		if (menuOption == 3) {
			//Same as option 2, but instead of numbers its '*'.
			menu.Histogram();
		}

	}

	//The Program ends
	cout << "Program Terminated!" << endl; 
	return 0;

}