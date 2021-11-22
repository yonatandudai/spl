#ifndef STUDIO_H_
#define STUDIO_H_

#include <vector>
#include <string>
#include "Workout.h"
#include "Trainer.h"
#include "Action.h"


class Studio{		
public:
	Studio();
    Studio(const std::string &configFilePath);
    void start();
    int getNumOfTrainers() const;
    int getCustomersCount() const;
    Trainer* getTrainer(int tid);
	const std::vector<BaseAction*>& getActionsLog() const; // Return a reference to the history of actions
    std::vector<Workout>& getWorkoutOptions();

private:
    bool open;
    int numOfTrainers;
    int customers_counter;
    std::vector<Trainer*> trainers;
    std::vector<BaseAction*> actionsLog;
    std::vector<Workout> workout_options;
    WorkoutType Convert(std::string str);

};



#endif