#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <stdexcept>

using namespace std;





class ActivityCalculator {
	private:
		const float FORMULA = 0.0175;
		float MET;
		float weight;
		string activity;
		map<string, int> activities = {
			{ "SLEEPING", 1 },
			{ "WALKING", 2 },
			{ "BASKETBALL", 8 }	
		};

		float convertLbToKg(float weight) {
			return weight/2.2;
		}
		
		// returns MET if activity found otherwise error
		float getMET(string activityKey) {
			activityKey = upCase(activityKey);
			if(activities[activityKey]) {
				return activities[activityKey];
			} else return 0;
		}

		//didnt feel like doing for loop
		//converts a string to all uppercase
		string upCase(string str) {
			transform(str.begin(), str.end(),str.begin(), ::toupper);
			return str;
		}

	public:

		//constructor
		ActivityCalculator() {
		}

		bool validActivity(string activity) {
			if(getMET(activity) != 0) {
				return true;
			}
			return false;
		}

		//calulates cals burned based on activity and weight in lbs
		float getCaloriesBurned(string activity, int minutes, float weight) {
			const float FORMULA = 0.0175;
			float kgWeight = convertLbToKg(weight);
			float MET = getMET(activity);
			float caloriesBurned = minutes*( (FORMULA * MET) * kgWeight);
			
			return caloriesBurned;
		}
};

class Helper {
	public:
		Helper() {}		

		float loopTillValidNumber(istream& stream) {
			float weight;
			
			stream >> weight;
			
			while(!weight) {
				cout << "\n ERROR, enter a number:";
				stream.clear();
				stream.ignore(256, '\n');
				stream >> weight;
			}
			return weight;
		}

};


int main() {
	string activity;
	float weight;
	float caloriesBurned;
	int minutes;
	ActivityCalculator activityCalc;
	Helper helper;

	cout << "Hello Welcome to Calorie Counter";

	// grab valid activity from user
	do {
		cout << "Please enter one of the below \n 1. SLEEPING \n 2. WALKING \n 3. BASKETBALL \n";
		cin >> activity;
	} while(!activityCalc.validActivity(activity));

	// get weight from user 
	// @@dev validation
	cout << "Please enter weight in lbs\n";
    	weight = helper.loopTillValidNumber(cin);

	cout << "Enter amount of time spent on activity in minutes \n";
	minutes = helper.loopTillValidNumber(cin);

	caloriesBurned = activityCalc.getCaloriesBurned(activity, minutes, weight);

	cout << "Congrats, you burned " << caloriesBurned << " calories!\n";

	return 0;
}
