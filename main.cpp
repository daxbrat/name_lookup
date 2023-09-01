#include "std_lib_facilities.h"

int main()
{
	vector <string> names{};
	vector <int> scores{};
	string name{ "" };
	int score{ 1 };
	int counter{ 1 };

	while (true) {

		cout << counter << ". Enter a name with a score: ";
		cin >> name >> score;
		if (name == "NoName" && score == 0) {
			break;
		}
		//---------------------Checking for duplicate name

		bool duplicate = false;
		for (int i = 0; i < names.size(); i++) {
			if (names[i] == name) {
				cout << "You can't enter the same name twice. Please try again!\n";
				duplicate = true;
				break;
			}
		}

		if (!duplicate) {
			names.push_back(name);
			scores.push_back(score);
			counter++;
		}
	}
	//------------------------Printing the vectors
	for (int i = 0; i < names.size(); i++) {
		cout << names[i] << ": " << scores[i] << '\n';
	}

	// ----------------------Score Lookup
	string score_finder{};
	bool nameFound = false;
	cout << "Whose score would you like to find? ";
	cin >> score_finder;
	for (int i = 0; i < names.size(); i++) {
		if (names[i] == score_finder) {
			cout << score_finder << "'s score is " << scores[i] << '\n';
			nameFound = true;
		}
	}
	if (!nameFound) {
		cout << "Name not found!";
	}
	// ------------------------Name Lookup
	int name_finder{};
	bool scoreFound = false;
	cout << "Which score would you like to look for? ";
	cin >> name_finder;
	for (int i = 0; i < scores.size(); i++) {
		if (scores[i] == name_finder) {
			cout << name_finder << " is the score of " << names[i] << '\n';
			scoreFound = true;
		}
	}
	if (!scoreFound) {
		cout << "Score not found.";
	}


	return 0;
}
