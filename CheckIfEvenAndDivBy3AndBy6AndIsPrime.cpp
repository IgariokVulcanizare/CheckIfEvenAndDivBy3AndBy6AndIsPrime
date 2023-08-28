#include <iostream>
#include <list>
#include <cmath>

using namespace std;
float prob(float favOutcome, float nrFavOutcomes);
bool isPrime(int n);

bool isPrime(int n) {
	if (n <= 1)
		return false;
	for (int i = 2; i < sqrt(n); i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

float prob(float favOutcome, float nrFavOutcomes) {
	float probability = (favOutcome / nrFavOutcomes) * 100;

	return probability;
}

int main() {
	list<int> Numbers;
	list<int> ChosenNumbers;
	int listLength;
	cout << "Please provide the listLength : " << endl;
	cin >> listLength;
	cout << endl;
	cout << "Now please provide the numbers in the given list :"<<endl;
	for (int i = 0; i < listLength; i++) {
		int listItem;
		cin >> listItem;
		Numbers.push_back(listItem);
	}

	float favOutcome = 0;
	for (int number : Numbers) {
		if (number % 2 == 0 && number / 3 == 0 && number / 6 == 0 && isPrime(number)) {
			ChosenNumbers.push_back(number);
			favOutcome++;
		}
	}
	cout << endl;
	for (int chosenNumber : ChosenNumbers)
		cout << "The Chosen number/numbers are : " << chosenNumber << endl;

	cout << endl;
	cout << "The probability of getting a number from the list that is even, divisible by 3 and 6, and prime is: "
		<< prob(favOutcome, static_cast<float>(Numbers.size())) << "%" << endl;

}