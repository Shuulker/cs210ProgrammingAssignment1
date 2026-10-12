#pragma once
#include <ostream>
#include <string>
#include "Card.h"
#include "Stack.h"

class Player {
public:
    Player(int id, const std::string& name)
        : id_(id), name_(name), hand_(new Stack<Card>()) {}

    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;

    ~Player() { delete hand_; }

    const std::string& name() const { return name_; }

    void draw(Card* card) { hand_->push(card); }

    Card* playCard() {
        if (hand_->isEmpty()) return nullptr;
        return hand_->pop();
    }

    bool hasCards() const { return !hand_->isEmpty(); }

    bool operator==(const Player& other) const {
        return id_ == other.id_;
    }

    friend std::ostream& operator<<(std::ostream& out, const Player& p) {
        return out << p.id_ << " " << p.name_;
    }

private:
    int id_;
    std::string name_;
    Stack<Card>* hand_;
};