// Developed by: Austen Rozanski (113371188)
// Created: 3/15/2017
// Last Updated: 3/22/2017

/*
Checklist:
1. [20 pts] (LinkedList class at line 155)
2. [20 pts] (Process class at line 33)
3. [50 pts]
	a. [10 pts] Memory allocated within add method of ProcessLinkedList class.
	            getIndexByID method within ProcessLinkedList class finds a process within
				the linked list.
	b. [10 pts] Memory is de-allocated within the add method of ProcessLinkedList class.
	            Processes are also removed within the add method.
	c. [10 pts] Both print methods are found within ProcessLinkedList class.
	d. [20 pts] compactProcesses method within ProcessLinkedList class performs memory compaction.
4. [10 pts] All classes, methods, and steps commented.
*/

#include <iostream>

using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////
//Process Class
//
//Desc: Basic class used to store variables that represent the address in memory for each process
//      along with an id for each process. 
//      Methods for overriding assignment, equal-to, and ostream operators included.
//      Copy constructor included with constructors and destructors.
//      All other methods are used for retrieving and setting the instance variables.
//////////////////////////////////////////////////////////////////////////////////////////////////
class Process {
protected:
	//Instance variables
	int _beginAddress;
	int _endAddress;
	bool _hole;
	int _processID;
public:
	//constructors
	Process();
	Process(int beginAddress, int size, bool hole, int processID);
	//copy constructor
	Process(const Process& p);
	//destructor
	~Process();

	//overridden operators
	void operator= (const Process& p);
	friend bool operator== (const Process& p1, const Process& p2);
	friend ostream& operator<< (ostream& os, const Process& p);

	//copy method used to copy the contents of a process object into this process object
	void copy(const Process& ps);

	//outputs the address, id, and if the memory is available or not
	void Display();

	//Get the size of the process
	int getSize() const;

	//Getters and Setters for instance variables
	int getProcessID() const;
	int getBeginAddress() const;
	int getEndAddress() const;
	bool isHole() const;
	void isHole(bool hole);
	void setBeginAddress(int beginAddress);
	void setEndAddress(int endAddress);
};
Process::Process() {
}
Process::Process(int beginAddress, int size, bool hole, int processID) : 
	_beginAddress(beginAddress), _endAddress(beginAddress+size), _hole(hole), _processID(processID) {
}
Process::Process(const Process& p) {
	copy(p);
}
Process::~Process() {
}
ostream& operator<< (ostream& os, const Process& p) {
	if (!p.isHole()) {
		os << "Begin Address: " << p.getBeginAddress() << ", End Address: " << p.getEndAddress() <<
			", ProcessID: " << p.getProcessID() << ".";
	}
	else {
		os << "Begin Address: " << p.getBeginAddress() << ", End Address: " << p.getEndAddress() <<
			", Space available.";
	}
	return os;
}
bool operator== (const Process& p1, const Process& p2) {
	if ((p1.getBeginAddress() == p2.getBeginAddress()) &&
		(p1.getEndAddress() == p2.getEndAddress()) &&
		(p1.getProcessID() == p2.getProcessID())) {
		return true;
	}
	else {
		return false;
	}
}
void Process::operator= (const Process& ps) {
	copy(ps);
}
void Process:: copy(const Process& ps) {
	_beginAddress = ps.getBeginAddress();
	_endAddress = ps.getEndAddress();
	_hole = ps.isHole();
	_processID = ps.getProcessID();
}
void Process::Display() {
	if (!_hole) {
		cout << "Begin Address: " << _beginAddress << ", End Address: " << _endAddress <<
			", ProcessID: " << _processID << "." << endl;
	}
	else {
		cout << "Begin Address: " << _beginAddress << ", End Address: " << _endAddress <<
			", Space available." << endl;
	}
}
int Process::getSize() const {
	return _endAddress - _beginAddress;
}
int Process::getProcessID() const {
	return _processID;
}
int Process::getBeginAddress() const {
	return _beginAddress;
}
int Process::getEndAddress() const {
	return _endAddress;
}
bool Process::isHole() const {
	return _hole;
}
void Process::isHole(bool hole) {
	_hole = hole;
}
void Process::setBeginAddress(int beginAddress) {
	_beginAddress = beginAddress;
}
void Process::setEndAddress(int endAddress) {
	_endAddress = endAddress;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//LinkedList Class
//
//Desc: Basic Linked List data structure. Descriptions for each of the methods can be found in the class.
//WARNING: Exceptions not used in this class. All methods in this LinkedList class are called from the
//         ProcessLinkedList class in this file which automatically avoids any errors that could be 
//         caused by this LinkedList class.
/////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class DataType>
class LinkedList {
protected:
	//Instance variables
	DataType* _data;
	LinkedList* _next;
public:
	//Constructors
	LinkedList();
	LinkedList(const DataType& data);
	LinkedList(const DataType& data, LinkedList<DataType>* next);
	//Copy Constructor
	LinkedList(const LinkedList<DataType>& ll);
	//Destructor
	~LinkedList();

	//copy the contents from the LinkedList in the paramter to this LinkedLIst
	void copy(const LinkedList<DataType>& ll);

	//overridden operators
	void operator= (const LinkedList<DataType>& ll);
	friend ostream& operator<< (ostream& os, const LinkedList<DataType>& LL);

	//Check if the list is empty
	bool isEmpty();

	//return the value of the data
	DataType data();

	//return a pointer the the next node
	LinkedList<DataType>* next();

	//return the size of the list
	int size() const;

	//Find an object in the LinkedList that is equivalent to the object in the parameter and
	//return a reference to it.
	DataType& find(const DataType& key);

	//Return a reference to the data found at the index of the position in the parameter
	DataType& dataAt(int position) const;

	//Add object to the list
	void add(const DataType& object);

	//Add newObj to the list at the index position
	void insertAt(const DataType& newObj, int position);

	//Set this nodes next node to next and return the old next.
	LinkedList<DataType>* setNext(LinkedList<DataType>* next);

	//remove the contents of the current node and replace them with the contents
	//of the next node.
	//Returns the data in the node removed.
	DataType remove();

	//remove the node at the index position from the list
	//Returns the data in the node removed.
	DataType removeAt(int position);
};

template<class DataType>
LinkedList<DataType>::LinkedList() {
	_data = NULL;
	_next = NULL;
}

template<class DataType>
LinkedList<DataType>::LinkedList(const DataType& data) {
	_data = new DataType(data);
	///if (_data == NULL) throw LinkedListMemory();
	_next = NULL;
}

template<class DataType>
LinkedList<DataType>::LinkedList(const DataType& data, LinkedList<DataType>* next) {
	_data = new DataType(data);
	///if (_data == NULL) throw LinkedListMemory();
	_next = next;
}

template<class DataType>
LinkedList<DataType>::LinkedList(const LinkedList<DataType>& ll) {
	copy(ll);
}

template<class DataType>
LinkedList<DataType>::~LinkedList() {
	if (_data != NULL) {
		delete _data;
		_data = NULL;
	}
	if (_next != NULL) {
		delete _next;
		_next = NULL;
	}
}

template<class DataType>
void LinkedList<DataType>::copy(const LinkedList<DataType>& ll) {
	if (ll._data == NULL) _data = NULL;
	else {
		_data = new DataType(*(ll._data));
		///if (_data == NULL) throw LinkedListMemory();
	}
	if (ll._next == NULL) {
		_next = NULL;
	}
	else {
		_next = new LinkedList<DataType>(*(ll._next));
		///if (_next == NULL) throw LinkedListMemory();
	}
}

template<class DataType>
void LinkedList<DataType>::operator= (const LinkedList<DataType>& ll) {
	if (_data != NULL) delete _data;
	if (_next != NULL) delete _next;
	copy(ll);
}

template<class DataType>
ostream& operator<< (ostream& os, const LinkedList<DataType>& LL) {
	for (int i = 0; i < LL.size(); i++) {
		os << LL.dataAt(i);
	}
	return os;
}

template<class DataType>
bool LinkedList<DataType>::isEmpty() {
	return (_data == NULL);
}

template<class DataType>
DataType LinkedList<DataType>::data() {
	///if (isEmpty()) throw LinkedListBounds();
	return *_data;
}

template<class DataType>
LinkedList<DataType>* LinkedList<DataType>::next() {
	return _next;
}

template<class DataType>
int LinkedList<DataType>::size() const {
	if (_next == NULL) {
		if (_data == NULL) return 0;
		else return 1;
	}
	else return 1 + _next->size();
}

template<class DataType>
DataType& LinkedList<DataType>::find(const DataType& key) {
	///if (isEmpty()) throw LinkedListNotFound();
	if (key == *_data) { return *_data; }
	///if (_next == NULL) throw LinkedListBounds();
	return _next->find(key);
}

template<class DataType>
DataType& LinkedList<DataType>::dataAt(int position) const {
	///if (isEmpty()) throw LinkedListNotFound();
	if (position == 0) { return *_data; }
	///if (_next == NULL) throw LinkedListBounds();
	return _next->dataAt(position - 1);
}

template<class DataType>
void LinkedList<DataType>::add(const DataType& object) {
	if (_data == NULL) { _data = new DataType(object); }
	else {
		LinkedList<DataType>* newList = new LinkedList<DataType>(*_data, _next);
		///if (newList == NULL) throw LinkedListMemory();
		*_data = object;
		_next = newList;
	}
}

template<class DataType>
void LinkedList<DataType>::insertAt(const DataType& newObj, int position) {
	if (position == 0) add(newObj);
	else {
		if (_next == NULL) {
			_next = new LinkedList(newObj);
			///if (_next == NULL) throw LinkedListMemory();
		}
		else {
			_next->insertAt(newObj, position - 1);
		}
	}
}

template<class DataType>
LinkedList<DataType>* LinkedList<DataType>::setNext(LinkedList<DataType>* next) {
	///if (isEmpty()) throw LinkedListAttachToEmpty();
	LinkedList<DataType>* temp = _next;
	_next = (linkedList<DataType>*) next;
	return temp;
}

template<class DataType>
DataType LinkedList<DataType>::remove() {
	///if (isEmpty()) throw LinkedListBounds();
	DataType temp = *_data;
	delete _data;
	if (_next == NULL) { _data = NULL; }
	else {
		LinkedList<DataType>* oldNext = _next;
		_data = _next->_data;
		_next = _next->_next;
		oldNext->_data = NULL;
		oldNext->_next = NULL;
		delete oldNext;
	}
	return temp;
}

template<class DataType>
DataType LinkedList<DataType>::removeAt(int position) {
	///if (isEmpty()) throw LinkedListBounds();
	if (position == 0) { return remove(); }
	///if (_next == NULL) throw LinkedListBounds();
	return _next->removeAt(position - 1);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ProcessLinkedList Class
//
//Desc: Uses a LinkedList of Process classes to simulate memory. Methods are used to add, subtract, and remove
//      processes from this simulated memory. The capacity of the memory is set when the ProcessLinkedList is created.
//      Use method add for adding, subtracting, and removing processes from the memory.
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ProcessLinkedList {
protected:
	//Root node for the linked list used.
	LinkedList<Process>* _root;

	//total capacity of simulated memory
	int _memoryCapacity = 0;

	//Method that returns the index of a process given an id of the process
	//if no process with the given id was found, method returns -1
	int getIndexByID(int id);

	//Method to find an index with enough space to fit a process with the given size
	//If no index can be found with enough space, method returns -1
	int findIndexWithSpace(int size);

	//Method to perform Memory Compaction
	void compactProcesses();
public:
	//Constructors and Destructors
	ProcessLinkedList();
	ProcessLinkedList(int memoryCapacity);
	~ProcessLinkedList();

	//Method that allocates memory to add/expand a process
	//or de-allocates memory to remove a process.
	bool add(int id, int size);

	//Method that displays the contents of each of the processes within the ProcessLinkedList object as
	//well as any free space between the processes
	void Display();

	//Method that displays total amount of free space available in memory
	void DisplayFreeSpace();
};

ProcessLinkedList::ProcessLinkedList() {
	_root = new LinkedList<Process>();
	_memoryCapacity = 0;
}
ProcessLinkedList::ProcessLinkedList(int memoryCapacity) {
	_root = new LinkedList<Process>();
	_memoryCapacity = memoryCapacity;
}
ProcessLinkedList::~ProcessLinkedList() {
	delete _root;
	_root = NULL;
}
bool ProcessLinkedList::add(int id, int size) {

	int processIndex = getIndexByID(id);
	int previousProcessSize = 0;

	//If processIndex != -1, a process was found with the same id
	if (processIndex != -1) {

		if (size <= 0) {
			//If process size is decreasing
			cout << endl << "Decreasing size of process " << id << "..." << endl;

			if (_root->dataAt(processIndex).getSize() + size <= 0 || size == 0) {
				//If the size after decreasing is less than or equal to 0, get rid of process
				//and readjust all positions of processes after the deleted one.
				int currentBeginAddress = _root->dataAt(processIndex).getEndAddress();
				_root->removeAt(processIndex);
				for (int i = processIndex; i < _root->size(); i++) {
					int currentSize = _root->dataAt(i).getSize();
					_root->dataAt(i).setBeginAddress(currentBeginAddress);
					_root->dataAt(i).setEndAddress(currentBeginAddress+currentSize);
					currentBeginAddress = _root->dataAt(i).getEndAddress();
				}
				cout << "Process " << id << " removed successfully!" << endl;
				return true;
			}
			else {
				//If the size after decreasing is greater than 0, change the size of the current process and
				//then create a hole to fill the new gap between the current process and the next one
				int newEndAddress = _root->dataAt(processIndex).getBeginAddress() + _root->dataAt(processIndex).getSize() + size;
				_root->dataAt(processIndex).setEndAddress(newEndAddress);
				if (_root->size() != processIndex + 1) {
					_root->insertAt(Process(newEndAddress, (size*-1), true, id), processIndex + 1);
				}
				cout << "Process " << id << " size decreased by " << (size*-1) << " successfully!" << endl;
				return true;
			}
		} 
		else {

			//If process size is increasing
			cout << endl << "Increasing size of process " << id << "..." << endl;
			_root->dataAt(processIndex).isHole(true);
			size += _root->dataAt(processIndex).getSize();
			previousProcessSize = _root->dataAt(processIndex).getSize();
		}
	}
	else if (size <= 0) {
		//invalid command if process not found and size <= 0
		cout << endl << "Invalid command. Cannot decrease size of nonexisting process." << endl;
		return false;
	}
	else {
		cout << endl << "Adding process " << id << "..." << endl;
	}

	//Find an index where the new process will fit in memory
	int newIndex = findIndexWithSpace(size);
	//If there was not enough space anywhere, compact empty holes and try again.
	if (newIndex == -1) {
		compactProcesses();
		newIndex = findIndexWithSpace(size);
		if (newIndex == -1)
		{
			//If there still is not enough room after removing all holes, there is not enough
			//memory currently to store the process.

			//if process existed previously, add the process back
			if (previousProcessSize > 0) {
				_root->insertAt(Process(_root->dataAt(_root->size() - 1).getEndAddress(), previousProcessSize, false, id), _root->size());
				cout << "Unable to increase size of process " << id << ". Not enough memory available." << endl;
			}
			else {
				cout << "Unable to add process " << id << ". Not enough memory available." << endl;
			}
			return false;
		}
	}

	//Determine where the address of the new process begins
	int beginAddress = 0;
	if (_root->size() > 0) {
		if (newIndex > 0) {
			beginAddress = _root->dataAt(newIndex - 1).getEndAddress();
		}
		else {
			beginAddress = 0;
		}
	}

	//Insert the new process at the index found above
	_root->insertAt(Process(beginAddress, size, false, id), newIndex);

	//Test if the new process is the last node in the linked list
	//if not, we need to adjust the size of the hole in memory after the new process
	if (_root->size() != newIndex + 1) {
		_root->dataAt(newIndex + 1).setBeginAddress(beginAddress + size);
		if (_root->dataAt(newIndex + 1).getSize() <= 0) {
			_root->removeAt(newIndex + 1);
		}
	}

	cout << "Process " << id << " added successfully!" << endl;
	return true;
}
int ProcessLinkedList::getIndexByID(int id) {
	//If the size of the list is 0, return -1
	if (_root->size() == 0) { return -1; }

	//search through the list for a process with same id and return its index
	for (int i = 0; i < _root->size(); i++) {
		if (_root->dataAt(i).getProcessID() == id && !_root->dataAt(i).isHole()) {
			return i;
		}
	}
	return -1;
}
int ProcessLinkedList::findIndexWithSpace(int size) {
	//If the size of the list is 0, return 0 if the size <= _memoryCapacity
	if (_root->size() == 0) { 
		if (_memoryCapacity >= size) {
			return 0;
		}
		else {
			return -1;
		}
	}
	else {
		//go through the list and return the index of a hole >= size
		for (int i = 0; i < _root->size(); i++) {
			if (_root->dataAt(i).isHole() && _root->dataAt(i).getSize() >= size) {
				return i;
			}
		}

		//check the hole after the last process
		int lastProcessEndAddress = _root->dataAt(_root->size() - 1).getEndAddress();
		if ((_memoryCapacity - lastProcessEndAddress) >= size) {
			return _root->size();
		}
		else {
			//if no space was found
			return -1;
		}
	}
}
void ProcessLinkedList::compactProcesses() {

	int currentIndex = 0;
	//current begin address is the end address of the last node that was not a hole
	int currentBeginAddress = 0;

	//Loop through all nodes in linked list
	while (_root->size() > currentIndex) {
		//Store the next node and current node size
		int currentSize = _root->dataAt(currentIndex).getSize();
		//reset the position of the node
		_root->dataAt(currentIndex).setBeginAddress(currentBeginAddress);
		_root->dataAt(currentIndex).setEndAddress(currentBeginAddress + currentSize);

		//if current node is a hole, delete the node.
		if (_root->dataAt(currentIndex).isHole()) {
			_root->removeAt(currentIndex);
		}
		else {
			//if the current node is not a hole, continue to the next node
			currentBeginAddress += currentSize;
			currentIndex++;
		}
	}
}
void ProcessLinkedList::Display() {
	//if the size of the list is 0, there are no nodes so there is only an empty space from 0 to _memoryCapacity
	if (_root->size() == 0) { cout << "Space available from 0 to " << _memoryCapacity << endl; }
	else {
		//output the data in every node
		for (int i = 0; i < _root->size(); i++) {
			_root->dataAt(i).Display();
		}
	}
}
void ProcessLinkedList::DisplayFreeSpace() {
	//Store the total space available
	int spaceAvailable = 0;

	//if the size of the list is 0, there are no nodes so there is only an empty space from 0 to _memoryCapacity
	if (_root->size() == 0) { spaceAvailable += _memoryCapacity; }
	else {
		//Add up all the holes between the processes
		for (int i = 0; i < _root->size(); i++) {
			if (_root->dataAt(i).isHole()) {
				spaceAvailable += _root->dataAt(i).getSize();
			}
		}
		//Add the space after the processes
		spaceAvailable += _memoryCapacity - _root->dataAt(_root->size() - 1).getEndAddress();
	}

	//Output the total space available
	cout << "Total space Available: " << spaceAvailable << endl;
}


////////////////////////////////////////////////
//MAIN METHOD
////////////////////////////////////////////////
int main() {

	cout << "Memory Simulation Program" << endl << endl << endl <<
		"Commands: (comma used to represent space, do not enter any commas)" << endl << endl <<
		"ADD PROCESS: Process ID(int), Size(int)" << endl <<
		"INCREASE/DECREASE PROCESS SIZE: Process ID(int), Size(int)" << endl << 
		"REMOVE PROCESS: Process ID(int), Size(int)" << endl <<
		"DISPLAY CONTENTS OF MEMORY: 0, 0" << endl <<
		"DISPLAY SPACE AVAILABLE: -1, 0" << endl <<
		"END PROGRAM: End Of File Character (ctrl+z on windows)" << endl << endl;

	const int MAIN_MEMORY_SIZE = 128;
	ProcessLinkedList mainMemory = ProcessLinkedList(MAIN_MEMORY_SIZE) ;
	
	//INPUT LOOP
	while (!cin.eof()) {
		int processID;
		int memoryRequired;
		cin >> processID;
		if (!cin.eof()) {
			cin >> memoryRequired;
			if (!cin.eof()) {
				if (processID == -1) {
					//Print total free space 
					cout << endl << "FREE SPACE IN MEMORY" << endl;
					mainMemory.DisplayFreeSpace();
				}
				else if (processID == 0) {
					//Print the contents of the memory
					cout << endl << "CONTENTS OF MEMORY" << endl;
					mainMemory.Display();
				}
				else {
					//Add the new process to memory
					mainMemory.add(processID, memoryRequired);
				}
			}
		}
	}
	return 0;
}