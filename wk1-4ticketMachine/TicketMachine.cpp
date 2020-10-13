//
// Created by jbji on 20-3-24.
//

#include "TicketMachine.h"

#include <iostream>
using namespace std;

TicketMachine::TicketMachine() : PRICE(0){
    //consturctor

}
TicketMachine::~TicketMachine() {
    //destructor

}

void TicketMachine::showPrompt() {
    cout << "something";
}

void TicketMachine::insertMoney(int money) {
    balance += money;

}
void TicketMachine::showBalance() {
    cout << balance;
}