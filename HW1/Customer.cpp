#include "Customer.h"

using namespace std;
Customer::Customer(string c_name, int c_id) : name(c_name), id(c_id){
}

std::string Customer::toString() const {
    //return name;
    //needs to return also which training Customer is doing
}

vector<int> Customer::order(const std::vector<Workout> &workout_options) {
}

int Customer::getId() const {
    return id;
}

string Customer::getName() const {
    return name;
}

SweatyCustomer::SweatyCustomer(std::string name, int id): Customer(name,id){
}

std::vector<int> SweatyCustomer::order(const std::vector<Workout> &workout_options) {}