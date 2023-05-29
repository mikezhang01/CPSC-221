#include <iostream>

#include "cs221util/catch.hpp"
#include "queue.h"
#include "stack.h"
#include "quack.h"
using namespace std;

TEST_CASE("stack::basic functions", "[weight=1][part=stack]") {
    // cout << "Testing Stack..." << endl;
    Stack<int> intStack;
    vector<int> result;
    vector<int> expected;
    for (int i = 10; i > 0; i--) {
        expected.push_back(i);
    }
    for (int i = 1; i <= 10; i++) {
        intStack.push(i);
    }
    while (!intStack.isEmpty()) {
        result.push_back(intStack.pop());
    }
    REQUIRE(result == expected);
}

TEST_CASE("queue::basic functions", "[weight=1][part=queue]") {
    Queue<int> intQueue;
    vector<int> result;
    vector<int> expected;
    for (int i = 1; i <= 10; i++) {
        expected.push_back(i);
    }
    for (int i = 1; i <= 10; i++) {
        intQueue.enqueue(i);
    }
    while (!intQueue.isEmpty()) {
        result.push_back(intQueue.dequeue());
    }
    REQUIRE(result == expected);
}

TEST_CASE("queue::size", "[weight=1][part=queue]") {
    Queue<int> intQueue;
    vector<int> result;
    Queue<int> expected;

    for (int i = 1; i <= 2; i++) {
        intQueue.enqueue(i);
    }
    intQueue.dequeue();
    //intQueue.dequeue();

    bool check = false;



    REQUIRE(check == intQueue.isEmpty());
}


/**
TEST_CASE("quack::size", "[weight=1][part=quack]") {
    Quack<int> quack1;
    vector<int> result;
    Queue<int> expected;

    for (int i = 0; i <= 5; i++) {
        quack1.pushR(i);
    }

    quack1.popL();
    quack1.popL();
    quack1.popR();
    quack1.popL3333();

    int size = quack1.sizeq();


    int check = 2;



    REQUIRE(check == size);
}
*/