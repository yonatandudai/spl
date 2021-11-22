#include "Studio.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

Studio ::Studio(const std::string &configFilePath): open(false) {
    ifstream studioFile(configFilePath);
    if (studioFile.is_open()) {
        string line;
        vector<string> textOfFile;
        vector<int> capacities;
        while (!studioFile.eof()) {
            getline(studioFile, line);
            if (line[0] == '#' || line.empty())
                continue;
            else
                textOfFile.push_back(line);
        }
        for (int i = 0; i < textOfFile.size(); ++i) {
            int wo_id = 0;
            if (i == 0) {
                stringstream my_num(textOfFile[0]);
                my_num >> numOfTrainers;
            }
            if (i == 1) {
                string cap = textOfFile[1];
                for (int j = 0; j < numOfTrainers; ++j) {
                    int ind = cap.find(',');
                    string sub = cap.substr(0, ind - 1);
                    stringstream my_num(sub);
                    my_num >> capacities[j];
                    cap = cap.substr(ind + 1, cap.length() - 1);
                }
                for (int j = 0; j < capacities.size(); ++j) {
                    Trainer* my_trainer = new Trainer(capacities[j]);
                    my_trainer->setId(j);
                    trainers.push_back(my_trainer);
                }
            } else {
                string w = textOfFile[i];
                int firstComma = w.find(',');
                string name_of_workout = w.substr(0, firstComma-1);
                w = w.substr(firstComma+1, w.length()-1);
                int secComma = w.find(',');
                string my_str = w.substr(0, secComma-1);
                WorkoutType type_of_workout = Convert(my_str);
                w = w.substr(secComma+1, w.length()-1);
                int price_of_workout;
                stringstream my_num (w);
                my_num >> price_of_workout;
                workout_options.push_back(Workout(wo_id, name_of_workout, price_of_workout, type_of_workout));
                ++wo_id;

                //need to initialize actionLog

            }
        }
    }
}

void Studio::start() {
    cout << "Studio is now open!" << endl ;
}

int Studio::getNumOfTrainers() const {
    return numOfTrainers;
}

int Studio::getCustomersCount() const {
    return customers_counter;
}

Trainer* Studio::getTrainer(int tid) {
    if(tid >= 0 and tid < trainers.size()) {
        return trainers[tid];
    }
    else {
        throw invalid_argument("No such trainer exist");
    }
}

const vector<BaseAction*>& Studio::getActionsLog() const {}

vector<Workout>& Studio::getWorkoutOptions() {
    return workout_options;
}

WorkoutType Studio:: Convert(std::string str){
    if (str=="Anaerobic")
        return ANAEROBIC;
    if (str=="Mixed")
        return MIXED;
    if (str=="Cardio")
        return CARDIO;
}


