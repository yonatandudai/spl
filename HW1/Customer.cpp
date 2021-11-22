#include "Customer.h"
#include <vector>
#include <algorithm>

using namespace std ;

Customer::Customer(std::string c_name, int c_id) : name(c_name), id(c_id) {}

string Customer::getName() const {
    return name; }

int Customer::getId() const {
    return id; }

SweatyCustomer:: SweatyCustomer(string name, int id) : Customer(name, id) {}
vector<int> SweatyCustomer ::order(const std::vector<Workout> &workout_options) {
    vector<int> output;
    for (int i = 0; i < workout_options.size(); i++) {
        if (workout_options[i].getType() == CARDIO) {
            output.push_back(workout_options[i].getId());
        }
    }
    return output;
}

string SweatyCustomer::toString() const {
    return (this->getName() + ",swt");
}

bool Customer::price_comparator(Workout w1, Workout w2) {
    return(w1.getPrice() < w2.getPrice());
}

CheapCustomer :: CheapCustomer(std::string name, int id) : Customer(name, id) {}

vector<int> CheapCustomer :: order(const std::vector<Workout> &workout_options) {
    vector<int> output;
    int cheapest_price = workout_options[0].getPrice();
    int cheapest_id = workout_options[0].getId() ;
    for(int i=1; i<workout_options.size(); ++i) {
        if (workout_options[i].getPrice() < cheapest_price) {
            cheapest_id = workout_options[i].getId();
        }
    }
    output.push_back(cheapest_id);
    return output;
}

string CheapCustomer::toString() const {
    return (this->getName() + ",chp");
}

HeavyMuscleCustomer::HeavyMuscleCustomer(std::string name, int id) : Customer(name, id){}

vector<int> HeavyMuscleCustomer::order(const std::vector<Workout> &workout_options) {
    vector<Workout> Anaerobic_options;
    vector<int> output;
    for (int i = 0; i < workout_options.size(); i++) {
        if (workout_options[i].getType() == ANAEROBIC) {
            Anaerobic_options.push_back(workout_options[i]);
        }
    }
    sort(Anaerobic_options.begin(), Anaerobic_options.end(), price_comparator);
    for (int i = 0; i < Anaerobic_options.size(); ++i) {
        output.push_back(Anaerobic_options[i].getId());
    }
    return output;
}

string HeavyMuscleCustomer::toString() const {
    return (this->getName() + ",mcl");
}

FullBodyCustomer :: FullBodyCustomer(std::string name, int id) : Customer(name, id){}

vector<int> FullBodyCustomer ::order(const std::vector<Workout> &workout_options) {
    vector<int> output;
    vector<Workout> Cardio_options;
    vector<Workout> Mixed_options;
    vector<Workout> Anaerobic_options;
    for(int i=0; i<workout_options.size(); ++i) {
       if(workout_options[i].getType() == CARDIO)
           Cardio_options.push_back(workout_options[i]);
       else if(workout_options[i].getType() == MIXED)
           Mixed_options.push_back(workout_options[i]);
       else
           Anaerobic_options.push_back(workout_options[i]);
   }
    sort(Cardio_options.begin(), Cardio_options.end(), price_comparator);
    sort(Mixed_options.begin(), Mixed_options.end(), price_comparator);
    sort(Anaerobic_options.begin(), Anaerobic_options.end(), price_comparator);
    output.push_back(Cardio_options[0].getId());
    output.push_back(Mixed_options[Mixed_options.size()-1].getId());
    output.push_back(Anaerobic_options[0].getId());
    return output;
}

string FullBodyCustomer::toString() const {
    return (this->getName() + ",fbd");
}












