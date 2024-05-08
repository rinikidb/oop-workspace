#ifndef EQUIVALENCETESTS_H
#define EQUIVALENCETESTS_H

// EquivalenceTests.h

#include <iostream>
#include "Addition.h"

class EquivalenceTests {
public:
    void runTests() {
        testPositiveIntegers();
        testNegativeIntegers();

        // Add other tests here
        
        testPositiveNegativeIntegers();
        testBothZeroes();
        testOneZero();
        testBigPositiveIntegers();
        testBigNegativeIntegers();
        testAdditionOf1AndNegative1();
    }

private:
    void testPositiveIntegers() {
        Addition addition;
        if (addition.add(5, 10) != 15) {
            std::cout << "Test 1 failed!" << std::endl;
        }
    }

    void testNegativeIntegers() {
        Addition addition;
        if (addition.add(-4, -5) != -9) {
            std::cout << "Test 2 failed!" << std::endl;
        }
    }

    // Add other test functions here

    void testPositiveNegativeIntegers(){
        Addition addition;
        if (addition.add(2, -5) != -3) {
            std::cout << "Test 2 failed!" << std::endl;
        }
    }

    void testBothZeroes(){
        Addition addition;
        if (addition.add(0, 0) != 0) {
            std::cout << "Test 2 failed!" << std::endl;
        }
    }

    void testOneZero(){
        Addition addition;
        if (addition.add(0, 7) != 7) {
            std::cout << "Test 2 failed!" << std::endl;
        }
    }

    void testBigPositiveIntegers(){
        Addition addition;
        if (addition.add(7563488, 102627378) != 110190866) {
            std::cout << "Test 2 failed!" << std::endl;
        }
    }

    void testBigNegativeIntegers(){
        Addition addition;
        if (addition.add(-7563488, -102627378) != -110190866) {
            std::cout << "Test 2 failed!" << std::endl;
        }
    }

    void testAdditionOf1AndNegative1(){
        Addition addition;
        if (addition.add(-1, 1) != 0) {
            std::cout << "Test 2 failed!" << std::endl;
        }
    }
    
};

#endif