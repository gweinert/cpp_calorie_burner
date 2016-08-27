#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

void introduction();
float getActivityMET();
float getValidMET(string);
float getWeight();
void calculateCaleriesBurned(float MET, float weight);
float convertLbToKg(float);
string upCase(string);

int main() {
	float MET;
	float weight;
	
	introduction();
	MET = getActivityMET();
	weight = getWeight();
	calculateCaleriesBurned(MET, weight);

	return 0;
}

void introduction() {
	cout << "Hello Welcome to Calorie Counter";
}

float getActivityMET() {
	string activity;
	float MET = 0;
	
	while(!MET) {
		cout << "Please enter one of the below \n 1. SLEEPING \n 2. RUNNING \n 3. BASKETBALL \n";
		cin >> activity;
		MET = getValidMET(activity);
	}
	
	return MET;

}

float getWeight() {
	float weight;
	
	//@@dev check if is number
	cout << "Please enter your weight in lbs \n";
	cin >> weight;

	return weight;
}

void calculateCaleriesBurned(float MET, float weight) {
	float kgWeight = convertLbToKg(weight);
	cout << " kgweight " << kgWeight << " and METS " << MET;
	float caloriesBurned = (2.0 * MET) * weight;
	cout << "You've burned " << caloriesBurned << ". Congrats! \n";
}

float convertLbToKg(float weight) {
	cout << weight << " and " << weight/2.2;
	return weight/2.2;
}

float getValidMET(string activity) {
	float MET;
	activity = upCase(activity);

	map<string, int> activities = {
		{ "SLEEPING", 1 },
		{ "RUNNING", 2 },
		{ "BASKETBALL", 8 }
	};

	return activities[activity] | 0;
}

//didnt feel like doing for loop
string upCase(string str) {
	transform(str.begin(), str.end(),str.begin(), ::toupper);
	cout << " string was capitalize to " << str;
	return str;
}


