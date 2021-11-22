#include "Action.h"
#include "Studio.h"
#include "Trainer.h"

using namespace std;

BaseAction::BaseAction() {}

ActionStatus BaseAction::getStatus() const {
    return status;
}

void BaseAction::complete(){
    status = COMPLETED;
}

void BaseAction::error(string errorMsg){
    cout <<errorMsg;
    status = ERROR;
}

string BaseAction::getErrorMsg() const {
    return errorMsg;
}

OpenTrainer::OpenTrainer(int id, std::vector<Customer *> &customersList):trainerId(id),customers(customersList){}

void OpenTrainer::act(Studio &studio){
    Trainer* my_trainer =  studio.getTrainer(trainerId);
    if (my_trainer == 0 || my_trainer->isOpen()){
        error("Workout session does not exist or is already open");}

    my_trainer->openTrainer();
    int cap = my_trainer->getCapacity();
    for (int i = 0; i <= cap && i < customers.size(); ++i) {
        my_trainer->addCustomer(customers[i]);
        my_trainer->setCapacity(my_trainer->getCapacity()-1);
    }
}

string OpenTrainer::toString() const {
    string output = "open";
    for(int i = 0; i <= customers.size(); ++i) {
        output= output+customers[i]->toString();//go bACK AFTER
    }
}

Order :: Order(int id): trainerId(id) {}

void Order :: act(Studio &studio) {
    Trainer* my_trainer = studio.getTrainer(trainerId);
    if (my_trainer == 0 || !my_trainer->isOpen()){
        BaseAction::error("Workout session does not exist or is already open") ;}
    string output;
    vector<Workout> wo = studio.getWorkoutOptions();
    vector<Customer*> trainers_customers = my_trainer->getCustomers();
    for(int i = 0; i < trainers_customers.size(); ++i) {
        vector<int> workouts_ids = trainers_customers[i]->order(studio.getWorkoutOptions());
        my_trainer->order(trainers_customers[i]->getId(), workouts_ids, studio.getWorkoutOptions());
        for(int j = 0; j < workouts_ids.size(); ++j) {
            output = output + trainers_customers[i]->getName() + " is doing " + wo[workouts_ids[j]].getName()+"\n";
        }
    }

    cout << output;
}

string Order:: toString() const {}

MoveCustomer:: MoveCustomer(int src, int dst, int customerId) : srcTrainer(src), dstTrainer(dst), id(customerId){}

void MoveCustomer:: act(Studio &studio) {
    Trainer* src_trainer = studio.getTrainer(srcTrainer);
    Trainer* dst_trainer = studio.getTrainer(dstTrainer);
    if ( src_trainer == 0 || !src_trainer->isOpen() || dst_trainer == 0 || !dst_trainer->isOpen()) {
        BaseAction::error("Cannot move customer");}
    else if ()


}



PrintWorkoutOptions:: PrintWorkoutOptions() :BaseAction() {

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