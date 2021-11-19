#include "Action.h"
#include "Studio.h"
#include "Trainer.h"

using namespace std;

BaseAction::BaseAction() : status(COMPLETED) {}


OpenTrainer::OpenTrainer(int id, std::vector<Customer *> &customersList):BaseAction(),trainerId(id),customers(customersList){

}

void OpenTrainer::act(Studio &studio) {
    Studio st0;
    Trainer* my_trainer =  st0.getTrainer(trainerId);
    my_trainer->openTrainer();
    Studio st1;
    vector<Workout> &opts = st1.getWorkoutOptions();
    for (int i = 0; i < OpenTrainer::customers.size(); ++i) {
        //now the customer needs to order the current workout of the Trainer
    }

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
    //return:
    //1) the trainer status(open/closed)
    //2) list of customers
    //3) list of orders done by each customers

    //vector<Customer*>lst = tr.getCustomers()

}