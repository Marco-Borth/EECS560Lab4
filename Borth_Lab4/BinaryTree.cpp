/* -----------------------------------------------------------------------------
 *
 * File Name:  BinaryTree.cpp
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 10 Program
 * Description:  BinaryTree methods are defined.
 * Date: 5/9/19
 *
 ---------------------------------------------------------------------------- */

template <typename T>
BinaryTree<T>::BinaryTree() {
	m_nodes = myTree.getLength();
}

template <typename T>
BinaryTree<T>::~BinaryTree() {
	clear();
	delete myTree;
}

template <typename T>
bool BinaryTree<T>::isEmpty() const {
	return myTree.isEmpty();
}

template <typename T>
int BinaryTree<T>::getNumberOfNodes() const {
	m_nodes = myTree.getLength();
	return m_nodes;
}

template <typename T>
int BinaryTree<T>::getHeight() const {
	m_nodes = myTree.getLength();
	int height = 0;

	while (2 * height < m_size - 1)
		height++;

	return height;
}

template <typename T>
void BinaryTree<T>::add(T data) {
	myTree.insert(myTree.getLength() + 1, data);
	m_nodes = myTree.getLength();
}

template <typename T>
void BinaryTree<T>::clear() {
	if (!isEmpty())
		myTree.clear();
	m_nodes = myTree.getLength();
}

template <typename T>
void BinaryTree<T>::remove() {
	if (!isEmpty()) {
		myTree.remove(myTree.getLength());
		m_nodes = myTree.getLength();
	} else {
		throw(std::runtime_error("ERROR: Tree is empty.\n"));
	}
}

template <typename T>
LinkedList<T> BinaryTree<T>::preOrder() {
	if (!isEmpty()) {
		orderList.clear();
		int i = 1;
		int k = i * 2;
		orderList.insert(i, myTree.getEntry(i));
		preOrderRec(k);
		preOrderRec(k + 1);
		return orderList;
	} else {
		throw(std::runtime_error("ERROR: Tree is empty.\n"));
	}
}

template <typename T>
void BinaryTree<T>::preOrderRec(int i) {
	if(i <= myTree.getLength()) {
		int k = i *2;
		orderList.insert(i, myTree.getEntry(i));
		preOrderRec(k);
		preOrderRec(k + 1);
	}
}

template <typename T>
LinkedList<T> BinaryTree<T>::inOrder() {
	if (!isEmpty()) {
		orderList.clear();
		int i = 1;
		int k = i * 2;
		inOrderRec(k);
		orderList.insert(i, myTree.getEntry(i));
		inOrderRec(k + 1);
		return orderList;
	} else {
		throw(std::runtime_error("ERROR: Tree is empty.\n"));
	}
}

template <typename T>
void BinaryTree<T>::inOrderRec(int i) {
	if(i <= myTree.getLength()) {
		int k = i *2;
		inOrderRec(k);
		orderList.insert(i, myTree.getEntry(i));
		inOrderRec(k + 1);
	}
}

template <typename T>
LinkedList<T> BinaryTree<T>::postOrder() {
	if (!isEmpty()) {
		orderList.clear();
		int i = 1;
		int k = i * 2;
		postOrderRec(k);
		postOrderRec(k + 1);
		orderList.insert(i, myTree.getEntry(i));
		return orderList;
	} else {
		throw(std::runtime_error("ERROR: Tree is empty.\n"));
	}
}

template <typename T>
void BinaryTree<T>::postOrderRec(int i) {
	if(i <= myTree.getLength()) {
		int k = i *2;
		postOrderRec(k);
		postOrderRec(k + 1);
		orderList.insert(i, myTree.getEntry(i));
	}
}

template <typename T>
LinkedList<T> BinaryTree<T>::levelOrder() {
	if (!isEmpty()) {
		orderList.clear();
		for (int i = 1; i <= myTree.getLength(); i++)
			orderList.insert(i, myTree.getEntry(i));
		return orderList;
	} else {
		throw(std::runtime_error("ERROR: Tree is empty.\n"));
	}
}
