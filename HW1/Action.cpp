#include "Action.h"
#include "Studio.h"
#include "Trainer.h"

using namespace std;

BaseAction::BaseAction() : status(COMPLETED) {}


OpenTrainer::OpenTrainer(int id, std::vector<Customer *> &customersList):BaseAction(),trainerId(id),customers(customersList){

}

void OpenTrainer::act(Studio &studio) {

}


string OpenTrainer::toString() const {

}


PrintWorkoutOptions ::PrintWorkoutOptions() :BaseAction() {

}

void PrintWorkoutOptions::act(Studio &studio) {
    Studio st;
    vector<Workout> &opts = st.getWorkoutOptions();
    for (auto &curr_opt: opts) {
        cout <<curr_opt.getName(),curr_opt.getType(),curr_opt.getPrice();
    }
}

string PrintWorkoutOptions::toString() const{

}


 PrintTrainerStatus ::PrintTrainerStatus(int id):BaseAction(),trainerId(id) {
    //the trainer status(open/closed)
    //list of customers
    //list of orders done by each customers
    //vector<Customer*>lst = tr.getCustomers()

}