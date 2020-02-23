/* -----------------------------------------------------------------------------
 *
 * File Name:  BinaryTree.h
 * Author: Marco Borth
 * Assignment:   EECS-560 Lab 4 – Implementation of Binary Tree
 * Description:  BinaryTree Template Class is defined.
 * Date: 2/22/20
 *
 ---------------------------------------------------------------------------- */

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "LinkedList.h"
#include "Movie.h"
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept> //For runtime_error
using namespace std;

template <typename T>
class BinaryTree {
private:
  LinkedList<T> myTree;
  LinkedList<T> orderList;
  int m_nodes;

  Movie* newT;
  int tempNodes;

  void preOrderRec(int i);

  void inOrderRec(int i);

  void postOrderRec(int i);

public:
/*
* @pre define T object.
* @post BinaryTree object is constructed.
*/
  BinaryTree();

/*
* @pre none.
* @post ~BinaryTree clears all BinaryNodes and deletes m_arr.
*/
  ~BinaryTree();

/*
* @pre none.
* @post isEmpty returns false if m_size > 0, returns true otherwise.
*/
  bool isEmpty() const;

/*
* @pre none.
* @post isEmpty returns false if m_size > 0, returns true otherwise.
*/
  bool isFull() const;

/*
* @pre none.
* @post getNumberOfNodes returns m_size - 1.
*/
  int getNumberOfNodes() const;

/*
* @pre none.
* @post getHeight returns the number of levels of BinaryTree.
*/
  int getHeight() const;

/*
* @pre none.
* @param data is a valid T object.
* @post adds the BinaryNode to myTree in levelOrder.
* @post resizes m_arr to add BinaryNode to m_arr.
*/
  void add(T data);

/*
* @pre none.
* @post removes the BinaryNode from myTree in levelOrder.
* @post if BinaryNode is not the root node, calls removeRec.
*/
  void remove(); //Can throw std::runtime_error

/*
* @pre none.
* @post deletes all BinaryNodes within myTree.
*/
  void clear();

  void print();

  void preOrder();

  void inOrder();

  void postOrder();

  void levelOrder();
};

#include "BinaryTree.cpp"

#endif
