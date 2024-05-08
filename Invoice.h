#ifndef INVOICE_H
#define INVOICE_H

#include <string>

using namespace std; 

class Invoice{
    private:
        string invoiceId;
        double dollarsOwed = 0.0;

    public:
        Invoice(string invoiceId); 
        void addServiceCost(double costDollars);
        double getDollarsOwed();
        string getInvoiceId();

};

#endif