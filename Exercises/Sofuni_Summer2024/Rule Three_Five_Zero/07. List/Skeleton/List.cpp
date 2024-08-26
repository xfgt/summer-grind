//
// Created by twister on 8/21/24.
//
// TODO

#include <sstream>

#include "List.h"

// Node
List::Node::Node(int value, Node* prev, Node* next){
    this->setValue(value);
    this->setPrev(prev);
    this->setNext(next);
}

int List::Node::getValue() const { return value; }
List::Node* List::Node::getNext() const { return next; }
List::Node* List::Node::getPrev() const { return prev; }

void List::Node::setValue(int value) { this->value = value; }
void List::Node::setNext(Node* next) { this->next = next; }
void List::Node::setPrev(Node* prev) { this->prev = prev; }


// List
List::List(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}


List::List(const List& other){
    this->head = other.head;
    this->tail = other.tail;
    this->size = other.size;
}

int List::first() const { return size == 0 ? tail->getValue() : head->getValue(); }

void List::add(int value){


    if(size == 0){
        tail = new Node(value, nullptr, nullptr);
    } else {

        if(tail->getNext() == nullptr){
            head = new Node(value, nullptr, nullptr);
            tail->setNext(head);
            head->setPrev(tail);
        } else{
            Node* prv = head;
            head = new Node(value, prv, nullptr);
        }


    }


    ++size;
}

void List::addAll(const List& other){

    Node* p = other.tail;
    while(p != other.head){
        this->add(p->getValue());
        p = p->getNext();
    }
}

void List::removeFirst(){
    if(size != 0){
        delete head;
        head = nullptr;
        --size;
    }
}

void List::removeAll(){
    while(this->getSize() != 0)
        removeFirst();
}

size_t List::getSize() const { return size; }
bool List::isEmpty() const { return size == 0; }


List List::getReversed(List l){

    List* nL = new List();

    Node* p = l.head;
    while(p != l.tail){
        nL->add(p->getValue());
        p = p->getPrev();
    }

    return *nL;
}


std::string List::toString() const{
    std::ostringstream str_out;

    Node* p = tail;
    while(p != head){
        str_out << p->getValue() << ' ';
        p = p->getNext();
    }

    return str_out.str();
}

List& List::operator<<(const int& value) { this->add(value); return *this;}

List& List::operator<<(const List& other){
    Node* p = other.tail;
    while(p != other.head){
        this->add(p->getValue());
        p = p->getNext();
    }
    return *this;
}

List& List::operator=(const List& other){
    this->removeAll();
    Node* p = other.tail;
    while(p != other.head){
        this->add(p->getValue());
        p = p->getNext();
    }
    return *this;
}

List::~List(){
    removeAll();
    delete tail;
    tail = nullptr;
}
