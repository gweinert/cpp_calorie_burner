#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <stdexcept>

using namespace std;





class ActivityCalculator {
	private:
		float MET;
		float weight;
		string activity;
		map<string, int> activities = {
			{ "SLEEPING", 1 },
			{ "RUNNING", 2 },
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
		string upCase(string str) {
			transform(str.begin(), str.end(),str.begin(), ::toupper);
			// cout << " string was capitalize to " << str;
			return str;
		}

	public:

		ActivityCalculator() {
		}

		bool validActivity(string activity) {
			if(getMET(activity) != 0) {
				return true;
			} else return false;
		}

		//calulates cals burned based on activity and weight in lbs
		float getCaloriesBurned(string activity, float weight) {
			float kgWeight = convertLbToKg(weight);
			float MET = getMET(activity);
			float caloriesBurned = (2.0 * MET) * weight;
			
			return caloriesBurned;
		}
};


int main() {
	string activity;
	float weight;
	float caloriesBurned;
	ActivityCalculator activityCalc;

	cout << "Hello Welcome to Calorie Counter";

	// grab valid activity from user
	do {
		cout << "Please enter one of the below \n 1. SLEEPING \n 2. RUNNING \n 3. BASKETBALL \n";
		cin >> activity;
	} while(!activityCalc.validActivity(activity));

	// get weight from user 
	// @@dev validation
	cout << "Please enter your weight in lbs \n";
	cin >> weight;

	caloriesBurned = activityCalc.getCaloriesBurned(activity, weight);

	cout << "Congrats, you burned " << caloriesBurned << "calories!\n";
}