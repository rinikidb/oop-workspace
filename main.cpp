// main.cpp
#include "UnitTest.h"
#include "EquivalenceTests.h"
#include "InvoiceTest.h"

int main() {
    UnitTest unitTest;
    unitTest.runTests();

    EquivalenceTests equivalenceTests;
    equivalenceTests.runTests();

    InvoiceTest invoiceTest; 
    invoiceTest.runTests();

    return 0;
}