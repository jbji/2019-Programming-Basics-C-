//
// Created by jbji on 20-3-24.
//

#ifndef WK1_4TICKETMACHINE_TICKETMACHINE_H
#define WK1_4TICKETMACHINE_TICKETMACHINE_H


class TicketMachine {
public:
    TicketMachine();
    virtual ~TicketMachine();
    void showPrompt();
    void insertMoney(int money);
    void showBalance();
    void printTicket();
    void showTotal();
private:
    const int PRICE;
    int balance;
    int total;
};


#endif //WK1_4TICKETMACHINE_TICKETMACHINE_H
