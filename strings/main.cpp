#include <iostream>

using namespace std;

int countWords(char str[]);
int findShortestWordLenth(char str[]);
void getNumOfVolvesAndNotVolves(char str[]);
bool isVolve(char letter);

int main() {
	char str[] = "Otecz Ruskoi democratii";
	
	cout << str << endl;
	cout << "there are " << countWords(str) << " words in the string" << endl;
	cout << "The shortes word`s lenght = " << findShortestWordLenth(str) << endl;
	getNumOfVolvesAndNotVolves(str);

	char str1[256];
	cin.getline(str1, 256, '.');
	cout << str1;
	return 0;
}

int countWords(char str[])
{
	int counter = 0;
	//int counter = 0;
	////int i = 0;
	////while (str[i] != '\0') {
	////	if (str[i] == ' ')
	////		counter++;
	////}
	////i++;
	//for (int = 0; str[i] != '/0'; i++) {
	//	if (str[i] == ' ')
	//		counter++;
	//}
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == 32)
			counter++;
	}
	counter++;

	return counter;
}

int findShortestWordLenth(char str[])
{
	int min = 10000;
	for (int i = 0; i <= strlen(str); i++) {
		if (str[i] == ' ' || str[i] == '\0') {
			int counter = 0;
			for (int j = i - 1; (j >= 0 && str[j] != ' '); j--) {
				counter++;
			}
			if (counter < min) {
				min = counter;
			}
		}
	}
	return min;
}

void getNumOfVolvesAndNotVolves(char str[])
{
	int volves = 0;
	int notVolves = 0;
	for (int i = 0; i < strlen(str); i++) {
		char letter = toupper(str[i]);
		if (isVolve(letter) == true)
			volves++;
		else if ((letter >= 65 && letter <= 90))
			notVolves++;
	}
	cout << "Volves = " << volves << endl;
	cout << "Not volves = " << notVolves << endl;
	if (volves > notVolves) {
		cout << "Num of volves if greater" << endl;
	}
	else {
		cout << "Num of notvolves if greater" << endl;
	}
	
}

bool isVolve(char letter)
{
	if (letter == 'A' || letter == 'O' || letter == 'J' || letter == 'I' || letter == 'E' || letter == 'Y' || letter == 'U')
		return true;
	else
		return false;
}