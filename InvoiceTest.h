#ifndef INVOICETEST_H
#define INVOICETEST_H

// InvoiceTest.h

#include <iostream> 
#include "Invoice.h"
#include <string>

using namespace std;

class InvoiceTest {
public:
    void runTests() {
        testAddServiceCost();
        // Add other test methods here
        testGetDollarsOwed();
        testGetInvoiceId();
    }

private:
    void testAddServiceCost() {
        {
            Invoice invoice("ABCD"); 
            invoice.addServiceCost(10);
            if (invoice.getDollarsOwed() != 10) {
                std::cout << "Test 1 failed!" << std::endl;
            }
        }

        {
            Invoice invoice("ABCD");
            invoice.addServiceCost(1);
            if (invoice.getDollarsOwed() != 1) {
                std::cout << "Test 2 failed!" << std::endl;
            }
        }

        // Add more test cases here

        {
            Invoice invoice("ABCD");
            invoice.addServiceCost(15); 
            invoice.addServiceCost(20);
            if (invoice.getDollarsOwed() != 35) {
                std::cout << "Test 2 failed!" << std::endl;
            }
        }

        
    }

    // Add other test functions here
    void testGetDollarsOwed(){
        {
            Invoice invoice("ABCD");
            invoice.addServiceCost(50);
            double x = invoice.getDollarsOwed();    
            if (x != 50) {
                std::cout << "Test 2 failed!" << std::endl;
            }
        }
    }

    void testGetInvoiceId(){
        {
            Invoice invoice("ABCD");
            string x = invoice.getInvoiceId();    
            if (x != "ABCD") {
                std::cout << "Test 2 failed!" << std::endl;
            }
        }
    }
};
 
#endif 