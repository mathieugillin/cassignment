#ifndef TREE_H
#define TREE_H

#include "treenode.h"

// TODO your code goes here:
template<class T>
class BinarySearchTree{
private:
  unique_ptr<TreeNode<T>> root;
  
  void deleteOper(const TreeNode<T>*  node){
    if(node){
    if(node->leftChild != nullptr)
        {deleteOper(node->leftChild.get());}
    if(node->rightChild != nullptr)
        {deleteOper(node->rightChild.get());}
        delete node;
  }
}
  
  void assignOper(const TreeNode<T>*  node){
      insert(node->data);

    if(node->leftChild != nullptr)
        {assignOper(node->leftChild.get());}
    if(node->rightChild != nullptr)
        {assignOper(node->rightChild.get());}
  }

public:


  BinarySearchTree(){};

    void write(ostream & o)const{
  root -> write(o);
  }

    TreeNode<T>* insert(const T data){

    TreeNode<T>* nRoot = new TreeNode<T>(data);
    if(!root){
      root.reset(nRoot);
      return nRoot;
    }
    delete nRoot;

    TreeNode<T>* now = root.get();

    while(now){
      if(now->data < data){
        if(now->rightChild.get()){
          now = now->rightChild.get();
        }
        else{
          TreeNode<T>* insertRightNode = new TreeNode<T>(data);
          now->setRightChild(insertRightNode);
        }
      }
      else if
          (data < now->data){
          if(now->leftChild.get()){
            now = now->leftChild.get();
          }
          else{
            TreeNode<T>* insertLeftNode = new TreeNode<T>(data);
            now->setLeftChild(insertLeftNode);
          }
      }
    else{
      return now;
      }
    }
    return nullptr;
  }

  BinarySearchTree (const BinarySearchTree & other){

    if(other.root.get())  {
        root = nullptr;
        deleteOper(root.get());
        TreeNode<T> * copy = other.root.get();
        assignOper(copy);
        }
    

};

