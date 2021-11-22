#include "Trainer.h"
#include "Customer.h"
#include <vector>
using namespace std;

Trainer::Trainer(int t_capacity) : capacity(t_capacity), open(false), salary(0)  {}

int Trainer::getCapacity() const {
    return capacity;}

void Trainer::addCustomer(Customer *customer) {
    customersList.push_back(customer);}

void Trainer::removeCustomer(int id) {
    for(int i = 0; i < customersList.size(); ++i) {
        if (customersList[i]->getId() == id) {
            customersList.erase(customersList.begin()+i-1);
        }
    }
}

Customer* Trainer::getCustomer(int id) {
    Customer* output = nullptr;
    for(int i = 0; i < customersList.size(); ++i) {
        if (customersList[i]->getId() == id) {
            output = customersList[i];
        }
    }
    return output;
}

vector<Customer*>& Trainer::getCustomers() {
  return customersList;}

vector<OrderPair>& Trainer::getOrders() {
    return orderList;}

void Trainer::openTrainer() {
    open = true;
}

void Trainer::closeTrainer() {
    open = false;
}

int Trainer::getSalary() {
    return salary;
}

bool Trainer::isOpen() {
    return open;
}

void Trainer::order(const int customer_id, const std::vector<int> workout_ids,
                    const std::vector<Workout> &workout_options) {
    for(int i =0; i < workout_ids.size(); ++i) {
        orderList.push_back(make_pair(customer_id,workout_options[workout_ids[i]]));
        salary = salary + workout_options[workout_ids[i]].getPrice();
    }
}

void Trainer::setId(int trainer_id) {
    id = trainer_id;
}

void Trainer::setCapacity(int trainer_capacity) {
    capacity = trainer_capacity;
}