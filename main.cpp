#include <iostream>
#include "List.h"
#include "Player.h"

int main() {
    // ---- Part 1: required test harness, do not modify ----
    std::cout << "== List<int>: addAnywhere / deleteAnywhere / reverse =="
              << std::endl;
    std::unique_ptr<List<int>> nums = makeList<int>();
    nums->addFront(new int(10));
    nums->addFront(new int(20));
    nums->addFront(new int(30));
    nums->print();
    nums->addAnywhere(1, new int(99));
    nums->print();
    nums->deleteAnywhere(2);
    nums->print();
    nums->reverse();
    nums->print();

    std::cout << std::endl << "== List<int>: concat ==" << std::endl;
    std::unique_ptr<List<int>> more = makeList<int>();
    more->addFront(new int(2));
    more->addFront(new int(1));
    more->print();
    nums->concat(more.get());
    nums->print();
    more->print();

    // ---- Part 2: your Uno scene goes below ----

    std::cout << "\n=== Game Night ===" << std::endl;

    auto table = makeList<Player>();
    table->addFront(new Player(4, "Joseph"));
    table->addFront(new Player(3, "Sebastian"));
    table->addFront(new Player(2, "Jean"));
    table->addFront(new Player(1, "William"));
    std::cout << "Table sits down. Turn order: ";
    table->print();

    std::cout << "\nEli pulls up a chair between Sebastian and Jean." << std::endl;
    table->addAnywhere(2, new Player(5, "Gabriel"));
    std::cout << "Turn order: ";
    table->print();

    std::cout << "\nJoseph plays a Reverse card!" << std::endl;
    std::cout << "Before: ";
    table->print();
    table->reverse();
    std::cout << "After:  ";
    table->print();

    std::cout << "\nGabriel plays his last card and leaves the table." << std::endl;
    table->deleteAnywhere(2);
    std::cout << "Turn order: ";
    table->print();

    auto second = makeList<Player>();
    second->addFront(new Player(8, "Isa"));
    second->addFront(new Player(7, "Jayden"));
    second->addFront(new Player(6, "Finn"));

    std::cout << "\nA second table wanders over and joins in." << std::endl;
    std::cout << "Before merge, first table:  ";
    table->print();
    std::cout << "Before merge, second table: ";
    second->print();
    table->concat(second.get());
    std::cout << "After merge, first table:   ";
    table->print();
    std::cout << "After merge, second table:  (empty)";
    second->print();
}
