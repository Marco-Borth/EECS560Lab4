/* -----------------------------------------------------------------------------
 *
 * File Name:  BinaryTree.cpp
 * Author: Marco Borth
 * Assignment:   EECS-560 Lab 4 – Implementation of Binary Tree
 * Description:  BinaryTree methods are defined.
 * Date: 2/22/20
 *
 ---------------------------------------------------------------------------- */

template <typename T>
BinaryTree<T>::BinaryTree() {
	m_nodes = 0;
}

template <typename T>
BinaryTree<T>::~BinaryTree() {
	clear();
}

template <typename T>
bool BinaryTree<T>::isEmpty() const {
	return myTree.isEmpty();
}

template <typename T>
bool BinaryTree<T>::isFull() const {
	int h = getHeight();
	int maxNodes = 2 ^(h+1) - 1;

	if(myTree.getLength() == maxNodes)
		return true;
	else
		return false;
}

template <typename T>
int BinaryTree<T>::getNumberOfNodes() const {
	m_nodes = myTree.getLength();
	return m_nodes;
}

template <typename T>
int BinaryTree<T>::getHeight() const {
	int height = 0;

	while (2 * height < myTree.getLength() - 1)
		height++;

	return height;
}

template <typename T>
void BinaryTree<T>::add(T data) {
	myTree.insert(myTree.getLength() + 1, data);
	m_nodes = myTree.getLength();

	newT = new Movie();
	newT->setTitle(myTree.getEntry(myTree.getLength())->getTitle());
	newT->setRating(myTree.getEntry(myTree.getLength())->getRating());
	orderList.insert(orderList.getLength() + 1, newT);
	newT = nullptr;
}

template <typename T>
void BinaryTree<T>::print() {
	for(int i = 1; i <= orderList.getLength(); i++) {
		cout << orderList.getEntry(i)->getTitle();
		if(i != orderList.getLength())
			cout << ", ";
	}
	cout << "\n\n";
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
		newT = myTree.getEntry(orderList.getLength());
		myTree.remove(myTree.getLength());
		delete newT;

		m_nodes = myTree.getLength();

		newT = orderList.getEntry(orderList.getLength());
		orderList.remove(myTree.getLength());
		delete newT;
		newT = nullptr;
	} else {
		throw(std::runtime_error("ERROR: Tree is empty.\n"));
	}
}

template <typename T>
void BinaryTree<T>::preOrder() {
	if (!isEmpty()) {
		tempNodes = 0;
		int i = 1;
		int k = i * 2;
		orderList.getEntry(tempNodes + 1)->setTitle(myTree.getEntry(i)->getTitle());
		orderList.getEntry(tempNodes + 1)->setRating(myTree.getEntry(i)->getRating());
		tempNodes++;
		preOrderRec(k);
		preOrderRec(k + 1);
	} else {
		throw(std::runtime_error("ERROR: Tree is empty.\n"));
	}
}

template <typename T>
void BinaryTree<T>::preOrderRec(int i) {
	if(i <= myTree.getLength()) {
		int k = i *2;
		orderList.getEntry(tempNodes + 1)->setTitle(myTree.getEntry(i)->getTitle());
		orderList.getEntry(tempNodes + 1)->setRating(myTree.getEntry(i)->getRating());
		tempNodes++;
		preOrderRec(k);
		preOrderRec(k + 1);
	}
}

template <typename T>
void BinaryTree<T>::inOrder() {
	if (!isEmpty()) {
		tempNodes = 0;
		int i = 1;
		int k = i * 2;
		inOrderRec(k);
		orderList.getEntry(tempNodes + 1)->setTitle(myTree.getEntry(i)->getTitle());
		orderList.getEntry(tempNodes + 1)->setRating(myTree.getEntry(i)->getRating());
		tempNodes++;
		inOrderRec(k + 1);
	} else {
		throw(std::runtime_error("ERROR: Tree is empty.\n"));
	}
}

template <typename T>
void BinaryTree<T>::inOrderRec(int i) {
	if(i <= myTree.getLength()) {
		int k = i *2;
		inOrderRec(k);
		orderList.getEntry(tempNodes + 1)->setTitle(myTree.getEntry(i)->getTitle());
		orderList.getEntry(tempNodes + 1)->setRating(myTree.getEntry(i)->getRating());
		tempNodes++;
		inOrderRec(k + 1);
	}
}

template <typename T>
void BinaryTree<T>::postOrder() {
	if (!isEmpty()) {
		tempNodes = 0;
		int i = 1;
		int k = i * 2;
		postOrderRec(k);
		postOrderRec(k + 1);
		orderList.getEntry(tempNodes + 1)->setTitle(myTree.getEntry(i)->getTitle());
		orderList.getEntry(tempNodes + 1)->setRating(myTree.getEntry(i)->getRating());
		tempNodes++;
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
		orderList.getEntry(tempNodes + 1)->setTitle(myTree.getEntry(i)->getTitle());
		orderList.getEntry(tempNodes + 1)->setRating(myTree.getEntry(i)->getRating());
		tempNodes++;
	}
}

template <typename T>
void BinaryTree<T>::levelOrder() {
	if (!isEmpty()) {
		for (int i = 1; i <= myTree.getLength(); i++) {
			orderList.getEntry(i)->setTitle(myTree.getEntry(i)->getTitle());
			orderList.getEntry(i)->setRating(myTree.getEntry(i)->getRating());
		}
	} else {
		throw(std::runtime_error("ERROR: Tree is empty.\n"));
	}
}
