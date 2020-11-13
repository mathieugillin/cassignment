#ifndef NODE_H
#define NODE_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

// TODO your code for the Node class goes here:
// (Note the 'NodeIterator' class will report lots of errors until Node exists

template<typename T>
class Node{
public:
  T data;
  Node<T> *previous;
  Node<T> *next;
  

  Node(T dataInput)
      : data(dataInput),next(nullptr),previous(nullptr){
  }
};




template<typename T>
class NodeIterator {
public:

  Node<T>* current;



    NodeIterator(Node<T>* currentIn)
        : current(currentIn) {
    }



     void operator++(){
      current = current->next;
    }


    NodeIterator()
        : current(nullptr) {
    }

  bool operator==(const NodeIterator<T> &other) const{
      return (current == other.current);
    }




    T & operator*() const{
        return current->data;
    }



   

    bool operator!=(const NodeIterator<T> &other) const{
      return (current != other.current);
    }

    




};

// do not edit below this line

#endif

