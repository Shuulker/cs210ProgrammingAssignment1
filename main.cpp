#include <iostream>
#include "List.h"
#include "Player.h"

void dealHand(Player* player, int count, int offset) {
    const char* colors[] = {"Red", "Green", "Blue", "Yellow"};
    const char* ranks[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "Skip"};
    for (int i = 0; i < count; ++i) {
        player->draw(new Card(colors[(offset + i) % 4], ranks[(offset * 3 + i * 2) % 10]));
    }
}

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

    // ---- Part 3: extra credit Uno scene //
    std::cout << "\n=== Game Night 2 ===" << std::endl;

    Player* joseph = new Player(4, "Joseph");
    Player* sebastian = new Player(3, "Sebastian");
    Player* jean = new Player(2, "Jean");
    Player* william = new Player(1, "William");
    dealHand(william, 3, 0);
    dealHand(jean, 3, 1);
    dealHand(sebastian, 3, 2);
    dealHand(joseph, 3, 3);
    joseph->draw(new Card("Red", "Reverse"));

    auto table2 = makeList<Player>();
    table2->addFront(joseph);
    table2->addFront(sebastian);
    table2->addFront(jean);
    table2->addFront(william);
    std::cout << "Table sits down and gets dealt in. Turn order: ";
    table2->print();

    Card* opening = william->playCard();
    std::cout << "\nWilliam opens the round with " << *opening << "." << std::endl;
    delete opening;

    Player* gabriel = new Player(5, "Gabriel");
    gabriel->draw(new Card("Blue", "7"));
    std::cout << "\nGabriel pulls up a chair between Sebastian and Jean." << std::endl;
    table2->addAnywhere(2, gabriel);
    std::cout << "Turn order: ";
    table2->print();

    Card* reverseCard = joseph->playCard();
    std::cout << "\nJoseph plays " << *reverseCard << "!" << std::endl;
    delete reverseCard;
    std::cout << "Before: ";
    table2->print();
    table2->reverse();
    std::cout << "After:  ";
    table2->print();

    Card* lastCard = gabriel->playCard();
    std::cout << "\nGabriel plays " << *lastCard << ", his last card, and leaves the table." << std::endl;
    delete lastCard;
    table2->deleteAnywhere(2);
    std::cout << "Turn order: ";
    table2->print();

    Player* isa = new Player(8, "Isa");
    Player* jayden = new Player(7, "Jayden");
    Player* finn = new Player(6, "Finn");
    dealHand(finn, 2, 4);
    dealHand(jayden, 2, 5);
    dealHand(isa, 2, 6);
    auto second2 = makeList<Player>();
    second2->addFront(isa);
    second2->addFront(jayden);
    second2->addFront(finn);

    std::cout << "\nA second table wanders over and joins in." << std::endl;
    std::cout << "Before merge, first table:  ";
    table2->print();
    std::cout << "Before merge, second table: ";
    second2->print();
    table2->concat(second2.get());
    std::cout << "After merge, first table:   ";
    table2->print();
    std::cout << "After merge, second table:  (empty)";
    second2->print();
}
