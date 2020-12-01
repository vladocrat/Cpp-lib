#pragma once

#include "libs.h"

//finding NOD(russian)
int gcd(int x, int y)
{

	while (x > 0 && y > 0)
	{
		if (x > y)
			x = x % y;
		else
			y = y % x;
	}
	cout << x + y;

	return x + y;
}

//converting to binary
void toBinary(int x)
{
	bool first = false;

	vector<int> v = {};
	
	if (x == 0)
	{
		cout << "0";
	}

	while (x != 0)
	{
		v.push_back(x % 2);
		x = x / 2;
	}
	for (int i = v.size() - 1; i >= 0; i--)
	{

		if (!first && v[i] == 1)
		{
			first = true;
		}
		if (first)
		{
			cout << v[i];
		}
	}
}

//finding factorial
int Factorial(int x)
{
	int factorial = 1;
	if (x < 0)
	{
		return 1;
	}
	else
	{
		for (int i = 1; i <= x; i++)
		{
			factorial *= i;
		}

		return factorial;
	}

}

//detecting palindrom
bool IsPalindrom(string x)
{
	bool letter = true;


	if (x != "")
	{
		for (int i = 0; i < x.length(); i++)
		{

			if (x[i] != x[x.length() - i - 1])
			{
				letter = false;

			}
		}
	}

	return letter;
}

//returns vector of polindroms out of vector of words
vector<string> PalindromFilter(vector<string>words, int minLength)
{
	bool palindrom = true;
	vector<string> truePalindrom;

	for (int i = 0; i < words.size(); i++)
	{
		for (int j = 0; j < words[i].size(); j++)
		{
			if (words[i][j] != words[i][words[i].size() - 1 - j])
			{
				palindrom = false;
			}
		}
		if (palindrom)
		{
			if (words[i].length() >= minLength)
			{
				truePalindrom.push_back(words[i]);
			}
		}
		palindrom = true;
	}
	return truePalindrom;
}

//user input to fill in a vector through space
vector<string> FillingVector()
{
	vector<string> words = {};
	string x;
	string x1 = "";

	getline(cin, x);
	for (int i = 0; i < x.length(); i++)
	{
		if (x[i] != ' ')
		{
			x1 += x[i];
		}
		else
		{
			words.push_back(x1);
			x1 = "";
		}
	}
	words.push_back(x1);

	return words;
}

//if first is greater than second, second == first;
void UpdateIfGreater(int first, int& second)
{

	if (first > second)
	{
		second = first;
	}
}

//moves strings from first to second vector and clears the first one
void MoveStrings(vector<string>& source, vector<string>& destination)
{
	for (int i = 0; i < source.size(); i++)
	{
		destination.push_back(source[i]);
	}
	source.clear();
}

//reverses the containtment of the vector
void Reverse(vector<int>& v)
{
	vector<int> reversed;

	for (int i = v.size() - 1; i >= 0; i--)
	{
		reversed.push_back(v[i]);
	}

	v = reversed;
}

//reverses the containtment of the vector without changing the value of the original vector
vector<int> Reversed(const vector<int>& input)
{
	vector<int> result;
	for (int i = input.size() - 1; i >= 0; --i) {
		result.push_back(input[i]);
	}

	return result;
}

//returns a vector that consists of numbers that are higher than the average of the source vector 
//(was made for the problem about  temperature)
vector<int> avgNumbers(vector<int> temp, int  days)
{
	vector<int> newTemp;

	int avgTemp;
	int temperature;
	int	sumOfVector = 0;
	int amountOfDays = 0;

	for (int i = 0; i < days; i++)
	{
		cin >> temperature;
		sumOfVector += temperature;
		temp.push_back(temperature);
		amountOfDays++;
	}

	avgTemp = sumOfVector / amountOfDays;

	for (int k = 0; k < temp.size(); k++)
	{
		if (temp[k] > avgTemp)
		{
			newTemp.push_back(k);
		}
	}

	cout << endl;
	cout << newTemp.size() << endl;

	for (auto x : newTemp)
	{
		cout << x << " ";

	}


	return newTemp;
}

//counts amount of each char in a vector<string>
map<char, int> BuildCharCounters(const string& word) {
	map<char, int> counters;
	for (char c : word) {
		++counters[c];
	}
	return counters;
}

//allows to build queue, add and delete ppl from it, also allows you to calculate amount of ppl worrying(about to leave);
class QueueStructure 
{

public: 

	//worry - false
	//calm - true

	int worry_count(vector<bool>& queueVector)
	{
		int worryCounter = 0;

		for (auto v : queueVector)
		{
			if (!v)
			{
				worryCounter++;
			}
		}

		return worryCounter;
	}


	void quiet(vector<bool>& queueVector, int number) {
		// cout << "v size q: " << queueVector.size();
		queueVector[number] = true;
		//  cout << "v number q: " << queueVector[number];
	}

	void worry(vector<bool>& queueVector, int number) {

		//cout << "v size w: "<< queueVector.size();
		queueVector[number] = false;

		// cout <<"v number w: "<<queueVector[number];
	}

	void come(vector<bool>& queueVector, int amountOfCome) {

		if (amountOfCome < 0)
		{
			for (int i = 0; i > amountOfCome; i--)
			{

				queueVector.pop_back();

			}
		}
		else
		{
			for (int i = 0; i < amountOfCome; i++)
			{
				//  cout <<"v size c: \t" << queueVector.size() << endl;
				queueVector.push_back(true);
			}
		}

	}


	int procedure() {


		vector<bool> isQuiet;
		vector<int> count;

		int q;
		string s;
		int x;


		//cout << "enter amount of operations: ";
		cin >> q;

		// cout << "enter operation and x: ";


		for (int i = 0; i < q; i++)
		{
			cin >> s;

			if (s == "WORRY_COUNT" && !isQuiet.empty())
			{
				count.push_back(worry_count(isQuiet));

			}
			else if (s == "WORRY_COUNT" && isQuiet.empty())
			{
				count.push_back(0);
			}
			else
			{
				cin >> x;

				if (s == "WORRY" && !isQuiet.empty())
				{
					worry(isQuiet, x);
				}
				if (s == "QUIET" && !isQuiet.empty())
				{
					quiet(isQuiet, x);
				}
				if (s == "COME")
				{
					come(isQuiet, x);
				}
			}

		}

		for (auto x : count)
		{
			cout << x << endl;
		}



		return 0;
	}

	private:
};

//creates a calender for each month and allows you to assign tasks to any day in a month you want.
//If there are mroe less days in the next month then all the "extra" tasks are moved to the last day of the next month.
class BasicallyCalender{ 
public: 

	void add(vector<vector<string>>& DayInMonth, int dayNumber, string task)
	{
		DayInMonth[dayNumber - 1].push_back(task);
	}

	void dump(vector<vector<string>>& DayInMonth, int dayNumber, vector<string>& output)
	{
		string resultStr;
		resultStr = (to_string(DayInMonth[dayNumber - 1].size())) + " ";
		for (auto& x : DayInMonth[dayNumber - 1])
		{
			resultStr += x + " ";
		}
		output.push_back(resultStr);
	}

	void next(int& currentMonth, vector<vector<string>>& DayInMonth)
	{
		vector<int> monthsLength = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int tempMonth;

		tempMonth = currentMonth;
		currentMonth++;
		if (currentMonth > 11)
		{
			currentMonth = 0;
		}
		if (monthsLength[currentMonth] < monthsLength[tempMonth])
		{
			for (int i = monthsLength[currentMonth]; i < monthsLength[tempMonth]; i++)
			{
				for (auto& x : DayInMonth[i])
				{
					DayInMonth[monthsLength[currentMonth] - 1].push_back(x);

				}
				DayInMonth[i].clear();
			}
		}

	}

	vector<string> createVector()
	{
		vector<string> task;
		return task;
	}


	void calenderBuild()
	{
		int q;
		string command;
		string  task;
		int day;

		int currentMonth{ 0 };

		vector<string> output;

		vector<vector<string>> DayInMonth(31, createVector());

		cin >> q;
		for (int i = 0; i < q; i++)
		{
			cin >> command;

			if (command == "NEXT")
			{
				next(currentMonth, DayInMonth);

			}
			else
			{
				cin >> day;

				if (command == "ADD")
				{
					cin >> task;
					add(DayInMonth, day, task);

				}
				if (command == "DUMP")
				{
					dump(DayInMonth, day, output);
				}
			}

		}


		for (auto& x : output)
		{
			cout << x << endl;
		}


	}




};

//calculates the amount of UNIQUE strings (even if string used twice it will add 1 to the result);
set<string> sameStringsCounter(set<string> words)
{
	for (int i = 0; i < words.size(); i++)
	{
		words.size();
	}
	return words;
}

//converts given map into set (to get rid of duplicates)
set<string>BuildMapValuesSet(map<int, string> startDictinoary)
{
	set<string> wordsFromDictionary;

	for (auto& x : startDictinoary)
	{
		wordsFromDictionary.insert(x.second);
	}

	cout << wordsFromDictionary.size() << endl;

	/*for (auto& x : wordsFromDictionary)
	{
		cout << x << " ";
	}*/

	return wordsFromDictionary;
}

//creates a map of cities which is filled by user. Allows to procedue actions on their names;
class CountriesHandbook
{
public:
	int changeCapital(string country, string capital, map<string, string>& mCountryCapital)
	{
		if (!mCountryCapital.empty())
		{
			for (auto& x : mCountryCapital)
			{
				if (mCountryCapital.find(country) == mCountryCapital.end())
				{
					cout << "Introduce new country " << country << " with capital " << capital << endl;
					mCountryCapital[country] = capital;

					return 0;
				}
				else if (mCountryCapital[country] == capital)
				{
					cout << "Country " << country << " hasn't changed its capital " << endl;
					return 0;
				}
				else if (mCountryCapital[country] != capital)
				{
					cout << "Country " << country << " has changed its capital from " << mCountryCapital[country] << " to " << capital << endl;
					mCountryCapital[country] = capital;

					return 0;
				}
			}
		}
		else
		{
			cout << "Introduce new country " << country << " with capital " << capital << endl;
			mCountryCapital[country] = capital;

			return 0;
		}
	}


	int rename(string country, string newCountry, map<string, string>& mCountryCapital)
	{
		if (country != newCountry && mCountryCapital.find(country) != mCountryCapital.end() && mCountryCapital.find(newCountry) == mCountryCapital.end())
		{
			cout << "Country " << country << " with capital "
				<< mCountryCapital[country] << " has been renamed to " << newCountry << endl;
			mCountryCapital[newCountry] = mCountryCapital[country];
			mCountryCapital.erase(country);
			return 0;
		}
		else
		{
			cout << "Incorrect rename, skip" << endl;
			return 0;
		}
	}


	void about(map<string, string> mCountryCapital, string country)
	{
		if (mCountryCapital.find(country) == mCountryCapital.end())
		{
			cout << "Country " << country << " doesn't exist" << endl;
		}
		else
		{
			cout << "Country " << country << " has capital " << mCountryCapital[country] << endl;
		}
	}

	void dump(map<string, string> mCountryCapital)
	{
		if (mCountryCapital.empty())
		{
			cout << "There are no countries in the world" << endl;
		}
		else
		{
			for (auto& x : mCountryCapital)
			{
				cout << x.first << "/" << x.second << " ";
			}
			cout << endl;
		}


	}

	int menu()
	{
		int q = 0;

		string command;
		string capital;
		string country;
		string newCountry;


		map<string, string> mCountryCapital;

		cin >> q;


		for (int i = 0; i < q; i++)
		{
			cin >> command;

			if (command == "CHANGE_CAPITAL")
			{
				cin >> country >> capital;
				changeCapital(country, capital, mCountryCapital);
			}
			else if (command == "RENAME")
			{
				cin >> country >> newCountry;
				rename(country, newCountry, mCountryCapital);
			}
			else if (command == "ABOUT")
			{
				cin >> country;

				about(mCountryCapital, country);

			}
			else if (command == "DUMP")
			{
				dump(mCountryCapital);

			}
		}
		return 0;
	}
};

//allows to add busses and stops for them. Allow to check what buses can you switch to on what stations.
class BusStations {
public:
	void NEW_BUS(map<string, vector<string>>& routesAndStops, string bus, int amountOfStops, vector<string>& busesNums)
	{
		string stop;

		vector<string> listOfSstops;

		busesNums.push_back(bus);

		for (int i = 0; i < amountOfStops; i++)
		{
			cin >> stop;
			listOfSstops.push_back(stop);
		}
		routesAndStops[bus] = listOfSstops;


	}

	void BUSES_FOR_STOP(map<string, vector<string>>& routesAndStops, string stop, vector<string>& busesNums)
	{
		int ok = 0;

		for (auto& x : busesNums)
		{
			for (auto& y : routesAndStops[x])
			{
				if (y == stop)
				{
					ok = 1;
					cout << x << " ";
					continue;
				}
			}

		}

		if (ok == 0)
		{
			cout << "No stop";
		}
		cout << endl;
	}

	void STOPS_FOR_BUS(map<string, vector<string>>& routesAndStops, string bus, vector<string>& busesNums)
	{
		int no = 0;
		if (routesAndStops.find(bus) != routesAndStops.end())
		{
			for (auto& stops : routesAndStops[bus])
			{
				cout << "Stop " << stops << ": ";
				for (auto& listOfStops : busesNums)
				{
					for (auto& otherStops : routesAndStops[listOfStops])
					{

						if (otherStops == stops)
						{

							if (listOfStops != bus)
							{
								no = 1;
								cout << listOfStops << " ";
								continue;
							}
						}
					}
				}
				if (no == 0)
				{
					cout << "no interchange";
				}
				no = 0;
				cout << endl;
			}

		}
		else
		{
			cout << "No bus" << endl;
		}
	}

	void ALL_BUSSES(map<string, vector<string>>& routesAndStops)
	{
		if (!routesAndStops.empty())
		{
			for (auto& x : routesAndStops)
			{
				cout << "Bus " << x.first << ": ";
				for (auto& y : x.second)
				{
					cout << y << " ";

				}
				cout << endl;
			}
		}
		else
		{
			cout << "No buses" << endl;
		}
	}

	void BUS_BY_STOPS(map<string, vector<string>>& routesAndStops, int amountOfStops, int& veryNewBuses)
	{
		bool no = false;

		string stop;

		vector<string> listOfSstops;

		//busesNums.push_back(bus);

		for (int i = 0; i < amountOfStops; i++)
		{
			cin >> stop;
			listOfSstops.push_back(stop);
		}

		for (auto& x : routesAndStops)
		{
			if (x.second == listOfSstops)
			{
				no = true;
				cout << "Already exists for " << x.first << endl;
			}
		}

		if (no == false)
		{
			cout << "New bus " << veryNewBuses << endl;
			routesAndStops[to_string(veryNewBuses)] = listOfSstops;
			veryNewBuses++;
		}
	}

	int menue()
	{
		int amountOfStop = 0;
		int k = 0;
		int q = 0;
		int veryNewBuses = 1;

		map<string, vector<string>> routesAndStops;
		vector<string> busesNums;

		string bus;
		string stop;
		string command;
		string firstCommand;

		cin >> q;

		for (int i = 0; i < q; i++)
		{

			cin >> command;

			if (command == "NEW_BUS")
			{
				cin >> bus;
				cin >> amountOfStop;
				NEW_BUS(routesAndStops, bus, amountOfStop, busesNums);
			}
			else if (command == "BUSES_FOR_STOP")
			{
				cin >> stop;
				BUSES_FOR_STOP(routesAndStops, stop, busesNums);
			}
			else if (command == "STOPS_FOR_BUS")
			{
				cin >> bus;
				STOPS_FOR_BUS(routesAndStops, bus, busesNums);

			}
			else if (command == "ALL_BUSES")
			{
				ALL_BUSSES(routesAndStops);
			}
			else if (isdigit(command[0]))
			{
				firstCommand = command.substr(0, command.find_first_of(" ") - 1);

				for (int j = 0; j < firstCommand.length(); j++)
				{

					if (isdigit(firstCommand[j]))
					{

						k++;
					}
				}

				if (k == firstCommand.length())
				{

					BUS_BY_STOPS(routesAndStops, stoi(firstCommand), veryNewBuses);
				}
				k = 0;
			}

		}

		return 0;
	};
};

//creates pairs of words and marks them as synonyms.
//allows to check existance of synonms.
//counts them.
//SUPER FASTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT;
class Synonyms
{
public:
	int add2(set<set<string>>& twoWords, string& firstWord, string& secondWord, map<string, int>& allWords)
	{

		set<string> temp;

		temp.insert(firstWord);
		temp.insert(secondWord);
		//twoWords.emplace(sw);
		if (twoWords.find(temp) != twoWords.end())
		{
			return 0;
		}
		twoWords.insert(temp);

		allWords[firstWord] += 1;
		allWords[secondWord] += 1;

		return 0;
	}



	void count(map<string, int>& allWords, string& firstWord)
	{

		cout << allWords[firstWord] << endl;
	}


	int check(set<set<string>>& twoWords, string& firstWord, string& secondWord)
	{
		set<string> temp;

		temp.insert(firstWord);
		temp.insert(secondWord);

		if (twoWords.find(temp) != twoWords.end())
		{
			cout << "YES" << endl;
			return 0;
		}

		cout << "NO" << endl;

		return 0;
	}

	int menue()
	{
		int q = 0;
		string command;
		string firstWord;
		string secondWord;
		set<set<string>> twoWords;
		map<string, int> allWords;

		cin >> q;

		for (int i = 0; i < q; i++)
		{
			cin >> command;

			if (command == "ADD")
			{
				cin >> firstWord >> secondWord;
				add2(twoWords, firstWord, secondWord, allWords);
			}
			else if (command == "CHECK")
			{
				cin >> firstWord >> secondWord;
				check(twoWords, firstWord, secondWord);
			}
			else if (command == "COUNT")
			{
				cin >> firstWord;
				count(allWords, firstWord);
			}

		}



		return 0;
	}

};

//sorts without case
void handMadeSortForStringWithoutCase()
{
	vector<string> vectorOfWords;
	vector<string> vectorOfLowercaseWords;
	string s;
	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		vectorOfWords.push_back(s);
		transform(s.begin(), s.end(), s.begin(),
			[](unsigned char c) { return tolower(c); });
		vectorOfLowercaseWords.push_back(s);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (vectorOfLowercaseWords[j] > vectorOfLowercaseWords[j + 1])
			{
				swap(vectorOfLowercaseWords[j], vectorOfLowercaseWords[j + 1]);
				swap(vectorOfWords[j], vectorOfWords[j + 1]);
			}
		}
	}
}

//A class that has methods for reversing strings and outputing them
class ReversibleString {

public:

	ReversibleString(const string& word = "") {
		mainWord = word;
	}
	~ReversibleString() {};

	void Reverse()
	{
		for (int i = 0; i < mainWord.length() / 2; i++)
		{
			swap(mainWord[i], mainWord[mainWord.length() - i - 1]);
		}
	}

	string ToString()
		const {
		return mainWord;
	}
private:
	string mainWord;

};

//Next three tructs show the correct way of initialatizing;
//start of them
struct Specialization
{
	string value;
	explicit Specialization(string newValue)
	{
		value = newValue;
	}
};

struct Course
{
	string value;
	explicit Course(string newValue)
	{
		value = newValue;
	}
};

struct Week
{
	string value;
	explicit Week(string newValue)
	{
		value = newValue;
	}
};

struct LectureTitle
{
	string specialization;
	string course;
	string week;

	LectureTitle(Specialization newSpecialization, Course newCourse, Week newWeek)
	{
		specialization = newSpecialization.value;
		course = newCourse.value;
		week = newWeek.value;
	}
};
//end;


//reading text from the file and writing it into another file
void ReadAndWriteIntoFile()
{
	fstream output("input.txt");
	string line;
	ofstream input("output.txt");


	if (output.is_open())
	{
		while (getline(output, line))
		{
			cout << line << endl;
			input << line << endl;
		}
	}
	else
	{
		cout << "bad" << endl;
	}
}

//reads doubles from a file and formats them;
void ReadAndFormat()
{
	ifstream output("input.txt");
	double value;
	if (output.is_open())
	{
		while (output >> value)
		{
			cout << fixed << setprecision(3) << value << endl;
		}
	}
}

//formates the table given the rows and cols
void formatingForTheTable() {
	ifstream output("input.txt");
	int value;
	int valueTwo;
	int x = 0;
	bool r = true;

	if (output)
	{
		output >> value;
		//cout <<"value "<< value << endl;
		output >> valueTwo;
		//cout << "value two " << valueTwo << endl;*/

		for (int i = 0; i < value; i++)
		{
			for (int j = 0; j < valueTwo; j++)
			{
				output >> x;
				output.ignore(1);
				cout << setw(10) << x;
				if (j != valueTwo - 1)
				{
					cout << " ";
				}
			}
			if (i != value - 1)
			{
				cout << endl;
			}
			else
			{
				break;
			}
		}
	}
}

//creates a small history of name changes including:
//separate changes of first and last names in different years;
class Person {
public:
	string Search(int year, const vector<int>& v, map<int, string>& m)
	{
		int exactYear = -1;
		if (!empty(m)) {
			if (v.size() > 1) {
				for (int i = 0; i < v.size() - 1; i++) {
					if (year < v[i + 1] && year >= v[i]) {
						exactYear = i;
					}
				}
			}
			if (year >= v[v.size() - 1]) {
				exactYear = v.size() - 1;
			}
			if (year < v[0]) {
				return " with unknown ";
			}
			return m[v[exactYear]];
		}
		return " with unknown ";
	}

	void ChangeFirstName(int year, const string& first_name)
	{
		yearAndFirstName[year] = first_name;
		yearsFirstName.push_back(year);
		sort(begin(yearsFirstName), end(yearsFirstName));
	}
	void ChangeLastName(int year, const string& last_name)
	{
		yearAndLastName[year] = last_name;
		yearsLastName.push_back(year);
		sort(begin(yearsLastName), end(yearsLastName));
	}
	string GetFullName(int year)
	{
		string name = Search(year, yearsFirstName, yearAndFirstName);
		string lastName = Search(year, yearsLastName, yearAndLastName);
		string s = " with unknown ";

		// cout << name << " is name " << endl;
		// cout << lastName << " is last name" << endl;

		if (name == s && lastName == s) {
			return "Incognito";
		}
		else if (name == s && lastName != s) {
			return (lastName + s + "first name");
		}
		else if (name != s && lastName == s) {
			return (name + s + "last name");
		}
		else {
			return (name + " " + lastName);
		}
		return "!     fck you     !";
	}
private:
	map<int, string> yearAndFirstName;
	map<int, string> yearAndLastName;
	vector<int> yearsFirstName;
	vector<int> yearsLastName;
};



