/*
	Developed by: Austen Rozanski
	Student ID:   113371188


	Created:       4/6/2017
	Last Updated:  4/14/2017
*/

//Would recommend using a tree size of 300 in order to effectively use the input file.

/*
[10 pts] Use STL Stack and Vector in the project
	-According to message sent through canvas, the Vector class is not required
	and was not used in this version.
	-The STL stack was used for storing freeLocations in the array, determining the height of a tree,
	and outputting the preorder/inorder traversals.

[30 pts] Implement ArrayBT class
	-ArrayBT class begins on line 195.
	-All methods in normal Binary Tree are implemented in this class.

[25 pts] Implement ArrayBST class
	-ArrayBST class begins on line 514.
	-ArrayBST inherits all ArrayBT methods and instance variables and implements
	the three bst methods: insert, find, and remove.

[35 pts] Implement main() that reads and processes input
	-Main method begins on line 776
	-The main method loops continuosly and calls the appropriate functions based on input.

[20 Bonus pts] Remove method
	-The remove method is on line 670.
	-The three conditions for the remove method are implemented and delete the data according to how it should be for each condition.
*/

#include <iostream>
#include <stack>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////
//Class ArrayBTNode
////////////////////////////////////////////////////////////////////////////////////////

template <class DT>
class ArrayBTNode {
protected:
	//Instance Variables
	DT* _info;
	int _left;
	int _right;

public:
	//Constructors and Destructor
	ArrayBTNode();
	ArrayBTNode(DT& info);
	~ArrayBTNode();

	//Accessor Methods
	DT* info() const;
	int left();
	int right();

	//Mutator Methods
	void setInfo(DT& info);
	void setInfoNull(); //Sets _info to Null
	void setLeft(int left);
	void setRight(int right);

	//Display Method
	//Outputs data in _info, _left, _right 
	void display(ostream& os) const;

	//Overloaded Comparison Operators
	//Used for comparing _info field with other ArrayBTNodes
	bool operator< (const ArrayBTNode<DT>& x);
	bool operator> (const ArrayBTNode<DT>& x);
	bool operator== (const ArrayBTNode<DT>& x);
	bool operator>= (const ArrayBTNode<DT>& x);
	bool operator<= (const ArrayBTNode<DT>& x);
	bool operator!= (const ArrayBTNode<DT>& x);

	//Overloaded Ostream Operator
	//Uses display method to output ArrayBTNode contents
	friend ostream& operator<< (ostream& os, const ArrayBTNode<DT>& node) {
		node.display(os);
		return os;
	}
};

//Default Constructor
template <class DT>
ArrayBTNode<DT>::ArrayBTNode() {
	_info = NULL;
	_left = -1;
	_right = -1;
}

//Constructor that sets the info variables
template <class DT>
ArrayBTNode<DT>::ArrayBTNode(DT& info) {
	_info = new DT(info);
	_left = -1;
	_right = -1;
}

//Destructor
template <class DT>
ArrayBTNode<DT>::~ArrayBTNode() {
	delete _info;
}

//Accessor Methods
template <class DT>
DT* ArrayBTNode<DT>::info() const {
	return _info;
}

template <class DT>
int ArrayBTNode<DT>::left() {
	return _left;
}

template <class DT>
int ArrayBTNode<DT>::right() {
	return _right;
}

//Mutator Methods
template <class DT>
void ArrayBTNode<DT>::setInfo(DT& info) {
	delete _info;
	_info = new DT(info);
}

template <class DT>
void ArrayBTNode<DT>::setInfoNull() {
	_info = NULL;
}

template <class DT>
void ArrayBTNode<DT>::setLeft(int left) {
	_left = left;
}

template <class DT>
void ArrayBTNode<DT>::setRight(int right) {
	_right = right;
}

//Display Method used with ostream operator
template <class DT>
void ArrayBTNode<DT>::display(ostream& os) const{
	os << "Info: " << *_info << ", Left: " << _left << ", Right: " << _right;
}

//Overloaded Comparison Operators
template<class DT>
bool ArrayBTNode<DT>::operator< (const ArrayBTNode<DT>& x){
	return (*_info < *x.info());
}

template<class DT>
bool ArrayBTNode<DT>::operator> (const ArrayBTNode<DT>& x) {
	return (*_info > *x.info());
}

template<class DT>
bool ArrayBTNode<DT>::operator== (const ArrayBTNode<DT>& x) {
	return (*_info == *x.info());
}

template<class DT>
bool ArrayBTNode<DT>::operator>= (const ArrayBTNode<DT>& x) {
	return (*_info >= *x.info());
}

template<class DT>
bool ArrayBTNode<DT>::operator<= (const ArrayBTNode<DT>& x) {
	return (*_info <= *x.info());
}

template<class DT>
bool ArrayBTNode<DT>::operator!= (const ArrayBTNode<DT>& x) {
	return (*_info != *x.info());
}


////////////////////////////////////////////////////////////////////////////////////////
//Class ArrayBT
////////////////////////////////////////////////////////////////////////////////////////

template <class DT>
class ArrayBT {
protected:
	//Instance Variables
	ArrayBTNode<DT>* _tree; //Array of ArrayBTNodes used to create a tree
	int _rootIndex; //Index of the root node in _tree
	int _numNodes; //Number of nodes in the tree
	int _size; //Maximum size of the _tree array
	stack<int> _freeLocations; //Stack containing indexes of freeLocations in the _tree array

public:
	//Constructors and Destructor
	ArrayBT();
	ArrayBT(int k);
	~ArrayBT();

	//Accessor Methods
	bool isEmpty() const;
	int Height();
	int Size();
	int rootIndex();
	int maxSize();

	//Mutator Methods
	void setData(int index, DT& value);
	void setLeft(int index, int value);
	void setRight(int index, int value);

	//Display methods and traversals
	void display(ostream& os) const;
	void displayPreOrder(ostream& os) const;
	void displayInOrder(ostream& os) const;
	void printRaw(); // Display the array and all of its contents

	//Overridden ostream operator
	friend ostream& operator<< (ostream& os, const ArrayBT& bt) {
		bt.display(os);
		return os;
	}
};

//Default Constructor
template <class DT>
ArrayBT<DT>::ArrayBT() {
	_tree = new ArrayBTNode<DT>[100];
	_rootIndex = 0;
	_numNodes = 0;
	_size = 100;

	for (int i = 100 - 1; i >= 0; i--) {
		_freeLocations.push(i);
	}
	for (int i = 0; i < 100; i++) {
		_tree[i] = ArrayBTNode<DT>();
	}
}

//Constructor with k being the size of the tree array
template <class DT>
ArrayBT<DT>::ArrayBT(int k) {
	_tree = new ArrayBTNode<DT>[k];
	_rootIndex = 0;
	_numNodes = 0;
	_size = k;

	for (int i = k - 1; i >= 0; i--) {
		_freeLocations.push(i);
	}
	for (int i = 0; i < k; i++) {
		_tree[i] = ArrayBTNode<DT>();
	}
}

//Destructor
template <class DT>
ArrayBT<DT>::~ArrayBT() {
	delete[] _tree;
}

//Checked if the tree is empty
template <class DT>
bool ArrayBT<DT>::isEmpty() const {
	if (_tree[_rootIndex].info() == NULL) {
		return true;
	}
	else return false;
}

//Returns the height of the tree
template <class DT>
int ArrayBT<DT>::Height() {

	//ArrayBT Height Algorithm
	/*
		stack s1
		stack s2
		currentHeight <- 0
		s1 <- root
		while s1 is not empty
			currentHeight++

			while s1 is not empty
				if s1.top.left exists, push it onto s2
				if s1.top.right exists, push it onto s2
				pop s1

			swap(s1, s2)
	*/


	stack<int>* s1 = new stack<int>();
	stack<int>* s2 = new stack<int>();

	int currentHeight = 0;


	s1->push(_rootIndex);

	while (!s1->empty()) {
		currentHeight++;

		while (!s1->empty()) {
			if (_tree[s1->top()].left() != -1) {
				s2->push(_tree[s1->top()].left());
			}
			if (_tree[s1->top()].right() != -1) {
				s2->push(_tree[s1->top()].right());
			}
			s1->pop();
		}

		s1->swap(*s2);
	}

	delete s1;
	delete s2;

	return currentHeight;
}

//Returns the size of the tree
template <class DT>
int ArrayBT<DT>::Size() {
	return _numNodes;
}

//Returns the root index
template <class DT>
int ArrayBT<DT>::rootIndex() {
	return _rootIndex;
}

//Returns the size of the tree array
template <class DT>
int ArrayBT<DT>::maxSize() {
	return _size;
}

//Set the data at a given index
template <class DT>
void ArrayBT<DT>::setData(int index, DT& value) {
	_tree[index].setInfo(value);
}

//Set the left node index value at a given index
template <class DT>
void ArrayBT<DT>::setLeft(int index, int value) {
	_tree[index].setLeft(value);
}

//Set the right node index value at a given index
template <class DT>
void ArrayBT<DT>::setRight(int index, int value) {
	_tree[index].setRIght(value);
}

//Display method used with ostream operator
template <class DT>
void ArrayBT<DT>::display(ostream& os) const {
	//Output the preorder traversal and then the inorder traversal
	os << "Pre Order Traversal: " << endl;
	displayPreOrder(os);
	os << endl << "In Order Traversal: " << endl;
	displayInOrder(os);
	os << endl;
}

//Output the data in the tree in preorder order
template <class DT>
void ArrayBT<DT>::displayPreOrder(ostream& os) const {
	
	//Condition to check if tree is empty
	if (isEmpty()) {
		os << "Tree is empty";
		return;
	}

	//Display Preorder algorithm
	/*
		stack s
		s <- _root
		while s is not empty
			t <- top of s
			output t
			pop s
			push t.right() if t.right() exists
			push t.left() if t.left() exists
	*/

	stack<int> s;
	
	s.push(_rootIndex);

	while (!s.empty()) {
		//Store top of s
		int top = s.top();

		//Output top of s
		os << *(_tree[top].info()) << " ";

		//Pop s
		s.pop();

		//Push right and left if they exist
		if (_tree[top].right() != -1)
			s.push(_tree[top].right());
		if (_tree[top].left() != -1)
			s.push(_tree[top].left());
	}
}

//Output the data in the tree in inorder order
template <class DT>
void ArrayBT<DT>::displayInOrder(ostream& os) const {
	
	//Condition to check if tree is empty
	if (isEmpty()) {
		os << "Tree is empty";
		return;
	}

	//Display InOrder algorithm
	/*
		stack s
		s <- root
		push to bottom left of root
		while s is not empty
			t <- top of s
			output t
			pop s
			if t.right() exists
				s <-t.right()
				push to bottom left of t.right()
	*/

	stack<int> s;

	s.push(_rootIndex);

	//push to bottom left of root
	while (_tree[s.top()].left() != -1) {
		s.push(_tree[s.top()].left());
	}

	while (!s.empty()) {

		//store top of s
		int index = s.top();

		//output top of s
		os << *(_tree[index].info()) << " ";

		//pop s
		s.pop();

		//if right node of index exists
		if (_tree[index].right() != -1) {
			s.push(_tree[index].right());

			//push to bottom left
			while (_tree[s.top()].left() != -1) {
				s.push(_tree[s.top()].left());
			}

		}

	}
}

//Print out the raw data of the tree array and the stack
template <class DT>
void ArrayBT<DT>::printRaw() {
	//Output each ArrayBTNode that exists within the _tree
	for (int i = 0; i < _size; i++) {
		if (_tree[i].info() != NULL)
			cout << "Index " << i << ": " << _tree[i] << endl;
	}

	//Output the stack
	cout << "Free Indexes: " << endl;
	stack<int> stackCopy = _freeLocations;
	if (!stackCopy.empty()) {
		while (!stackCopy.empty()) {
			cout << stackCopy.top();
			stackCopy.pop();
			if (!stackCopy.empty()) cout << ", ";
		}
	}
	else {
		cout << "None.";
	}

	cout << endl;
}

////////////////////////////////////////////////////////////////////////////////////////
//Class ArrayBST
////////////////////////////////////////////////////////////////////////////////////////

template <class DT>
class ArrayBST :virtual public ArrayBT<DT> {
protected:

public:
	//Constructors and Destructor
	ArrayBST();
	ArrayBST(int k);
	~ArrayBST();

	//BST Specific Methods
	void insert(DT& object);
	bool find(DT& object);
	int findIndex(DT& object);
	void remove(DT& object);

	//Overridden operators
	friend ostream& operator<< (ostream& os, const ArrayBST& bt) {
		bt.display(os);
		return os;
	}
};

//Default Constructor
template <class DT>
ArrayBST<DT>::ArrayBST() {

}

//Constructor with k being the size of the tree array
template <class DT>
ArrayBST<DT>::ArrayBST(int k) : ArrayBT(k) {

}

//Destructor
template <class DT>
ArrayBST<DT>::~ArrayBST() {

}

//Insert an object into the tree
template <class DT>
void ArrayBST<DT>::insert(DT& object) {
	
	//Output error if the BST if full
	if (_size <= _numNodes) {
		cout << "Cannot insert data, BST Full." << endl;
		return;
	}

	//Get a free index in the tree
	int freeIndex = _freeLocations.top();
	_freeLocations.pop();
	_numNodes++;

	//insert the object into the tree
	_tree[freeIndex].setInfo(object);

	//Traverse tree and set parent node of new nodes properties correctly
	int currentIndex = _rootIndex;

	if (_rootIndex != freeIndex) {

		while (1) {
			//Loop until the spot in tree is found where the new data will be inserted. Once found,
			//Assign the parent of the new data to have the new data as a child.
			if (_tree[currentIndex] > _tree[freeIndex]) {
				if (_tree[currentIndex].left() == -1) {
					_tree[currentIndex].setLeft(freeIndex);
					break;
				}
				else {
					currentIndex = _tree[currentIndex].left();
				}
			}
			else {
				if (_tree[currentIndex].right() == -1) {
					_tree[currentIndex].setRight(freeIndex);
					break;
				}
				else {
					currentIndex = _tree[currentIndex].right();
				}
			}
		}
	}
}

//Find an object in the tree. If found return true, else return false
template <class DT>
bool ArrayBST<DT>::find(DT& object) {

	//Return false if tree empty
	if (_numNodes == 0) return false;

	//Use to traverse tree
	int currentIndex = _rootIndex;

	while (1) {
		//Loop until object is found a NULL leaf is reached. Return true if found, false if NULL.
		if (*_tree[currentIndex].info() == object) return true;
		else if (*_tree[currentIndex].info() > object) {
			if (_tree[currentIndex].left() == -1) {
				return false;
			}
			else {
				currentIndex = _tree[currentIndex].left();
			}
		}
		else {
			if (_tree[currentIndex].right() == -1) {
				return false;
			}
			else {
				currentIndex = _tree[currentIndex].right();
			}
		}
	}
}

//Return an index of an object in the tree
template <class DT>
int ArrayBST<DT>::findIndex(DT& object) {

	//-1 implies index not found.
	//Return -1 if tree is empty
	if (_numNodes == 0) return -1;

	//Used to traverse tree
	int currentIndex = _rootIndex;

	while (1) {
		//Loop until object is found or NULL leaf reached. 
		//Return the index of object if object found, NULL if object not found.
		if (*_tree[currentIndex].info() == object) return currentIndex;
		else if (*_tree[currentIndex].info() > object) {
			if (_tree[currentIndex].left() == -1) {
				return -1;
			}
			else {
				currentIndex = _tree[currentIndex].left();
			}
		}
		else {
			if (_tree[currentIndex].right() == -1) {
				return -1;
			}
			else {
				currentIndex = _tree[currentIndex].right();
			}
		}
	}
}

//Remove an object from the tree
template <class DT>
void ArrayBST<DT>::remove(DT& object) {

	//Return if tree empty
	if (_numNodes == 0) {
		cout << "Object note found." << endl;
		return;
	}

	//Get index of the object
	int index = findIndex(object);

	//Return if object not found
	if (index == -1) {
		cout << "Object not found." << endl;
		return;
	}

	//If node with object has no children
	if (_tree[index].left() == -1 && _tree[index].right() == -1) {

		//Set size and free locations variables
		_numNodes--;
		_freeLocations.push(index);

		//Remove data from tree
		_tree[index].setInfoNull();

		//Go through the tree array and remove any connections to the deleted data index
		for (int i = 0; i < _size; i++) {
			if (_tree[i].left() == index) {
				_tree[i].setLeft(-1);
				break;
			}
			if (_tree[i].right() == index) {
				_tree[i].setRight(-1);
				break;
			}
		}
	}
	//If node with object has children on left and right
	else if (_tree[index].right() != -1 && _tree[index].left() != -1) {

		//Find the index of the smallest number in tree larger than the number being removed.
		int newIndex = _tree[index].right();
		while (_tree[newIndex].left() != -1) {
			newIndex = _tree[newIndex].left();
		}

		//Store object from index found above
		DT* newInfo = _tree[newIndex].info();

		//Remove the object from index found above from the tree
		remove(*_tree[newIndex].info());
		
		//Assign object found above to the index of the object being removed
		_tree[index].setInfo(*newInfo);
	}
	//If node with object only has a right child,
	//Assign that right childs properties to the index being removed
	else if (_tree[index].right() != -1) {
		int newIndex = _tree[index].right();

		_tree[index].setLeft(_tree[newIndex].left());

		_tree[index].setInfo(*_tree[newIndex].info());

		_tree[index].setRight(_tree[newIndex].right());

		_tree[newIndex].setLeft(-1);
		_tree[newIndex].setRight(-1);
		_tree[newIndex].setInfoNull();
		_numNodes--;
		_freeLocations.push(newIndex);
		
	}
	//If node with object only has a left child,
	//Assign that left childs properties to the index being removed
	else {
		int newIndex = _tree[index].left();

		_tree[index].setRight(_tree[newIndex].right());

		_tree[index].setInfo(*_tree[newIndex].info());

		_tree[index].setLeft(_tree[newIndex].left());

		_tree[newIndex].setLeft(-1);
		_tree[newIndex].setRight(-1);
		_tree[newIndex].setInfoNull();
		_numNodes--;
		_freeLocations.push(newIndex);
	}
}

//Method used to null terminate all characters in the string created for input
void nullTerminate(char* a, int size) {
	for (int i = 0; i < size; i++) {
		a[i] = '\0';
	}
}


////////////////////////////////////////////////////////////////////////////////////////
//Main Method
////////////////////////////////////////////////////////////////////////////////////////

int main() {

	//Variable used to set the size of the input command array.
	//Array is used to prevent errors and extra looping when invalid commands are given.
	int INPUT_ARRAY_SIZE = 10;

	//Get input for the size of the tree
	int inputSize = 50;
	cout << "Input the size of the tree: ";
	cin >> inputSize;
	cout << "Creating tree of size " << inputSize << "." << endl << endl;

	//Create a BST of the size inputSize
	ArrayBST<int> myBST = ArrayBST<int>(inputSize);


	//Input variables used with every loop
	char* commandInput = new char[INPUT_ARRAY_SIZE];
	int numberInput;

	//Main input loop. Will continue looping until user enters EOF character
	while (!cin.eof()) {

		cout << endl << endl << "Commands: I - Insert, O - Output, R - Remove, F - Find, A - Output Raw Data, EOF Character (ctrl+z on windows) - End Program"  << endl << "Enter Command: ";

		nullTerminate(commandInput, INPUT_ARRAY_SIZE);

		//send input to the command input variable
		cin >> commandInput;
		
		//Check what the command was
		if (commandInput[0] == 'I') {
			//Insert
			cout << "Enter number to insert: ";
			cin >> numberInput;

			cout << endl;

			if (!cin.eof()) {
				cout << "Inserting " << numberInput << endl;
				myBST.insert(numberInput);
			}
		}
		else if (commandInput[0] == 'O') {
			//Output using ostream
			cout << endl << "Information in Tree" << endl;
			cout << myBST;
		}
		else if (commandInput[0] == 'R') {
			//Remove
			cout << "Enter number to remove: ";
			cin >> numberInput;

			cout << endl;

			if (!cin.eof()) {
				cout << "Removing " << numberInput << endl;
				myBST.remove(numberInput);
			}
		}
		else if (commandInput[0] == 'F') {
			//Find/Search
			cout << "Enter number to find: ";
			cin >> numberInput;

			cout << endl;

			if (!cin.eof()) {
				cout << "Finding " << numberInput << endl;
				int indexOfNumber = myBST.findIndex(numberInput);
				if (indexOfNumber != -1) {
					cout << "Number found at index " << indexOfNumber << "." << endl;
				}
				else {
					cout << "Number not found." << endl;
				}
			}
		}
		else if (commandInput[0] == 'A') {
			//Output using raw data
			cout << endl << "Raw Data" << endl;
			myBST.printRaw();
		}
		else if (cin.eof()) {
			//eof entered
			break;
		}
		else {
			cout << endl << "Invalid Command" << endl;
			cin.clear();
		}
	}

	//Delete the commandInput array
	delete[] commandInput;

	return 0;
}