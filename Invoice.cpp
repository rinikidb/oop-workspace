#include "Invoice.h"
#include <iostream>
#include <string>

using namespace std;

Invoice::Invoice(string invoiceId){ 
    this->invoiceId = invoiceId;
}

void Invoice::addServiceCost(double costDollars){
    dollarsOwed = dollarsOwed + costDollars;
}

double Invoice::getDollarsOwed(){
    return dollarsOwed;
}

string Invoice::getInvoiceId(){
    return invoiceId;
}