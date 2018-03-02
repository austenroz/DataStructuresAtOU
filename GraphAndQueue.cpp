/*
    Developed by Austen Rozanski
	Created 4/22/2017
	Last Updated 2/30/2017
*/

/*
	OBJECTIVES:
	1.	Graph Class with Bit Representation of Adjacency Matrix (Line 30)
	2.  Add Edge Method (Line 168)
	3.  Using Queue STL for use as part of BFS (BFS on line 254)
	4.  Ostream operator to print the graph in edge list format (Overloaded method
	    on line 374 and used on line 439)
	5.  Implement the copy constructor and the overloaded = operator
	    (copy constructor on line 122, = operator overloaded method on line 369,
		= overloaded method uses copy constructor and = used on line 442)
	6.  BFS on line 254
	7.  DFS on line 314
	8.  Project documented
*/

#include <iostream>
#include <queue>

using namespace std;

///////////////////////////////////////////////////////////////
//BitMatrixGraph Class
///////////////////////////////////////////////////////////////
class BitMatrixGraph {
protected:
	//Instance Variables
	unsigned char** bitAdjacencyMatrix; //2D array of bits used for adjacency matrix
	int n; // Number of nodes in the graph

	//Protected Method
	void dfsHelper(int index, int* parent, bool* visited); //Method used with depthFirstSearch for recursion
public:
	//Constructor and Destructor
	BitMatrixGraph(); //Default constructor
	BitMatrixGraph(int numNodes); //Constructor with size parameter
	BitMatrixGraph(const BitMatrixGraph& otherGraph); //Copy Constructor
	~BitMatrixGraph(); //Destructor

	//General Methods
	void addEdge(int u, int v); //Adds edge between nodes u and v
	bool isAnEdge(int u, int v) const; //Checks if there is an edge between u and v
	void display(); //Outputs the matrix to the console
	void breadthFirstSearch(int k); //Outputs a parent array representation of a bfs tree
	void depthFirstSearch(int k); //Outputs a parent array representation of a dfs tree
	
	//Overloaded Operators
	friend ostream& operator<< (ostream& s, const BitMatrixGraph& bmg); //Overloaded << operator
	void printBits(ostream& s) const; //Method used with overloaded << operator method
	BitMatrixGraph& operator= (BitMatrixGraph& otherGraph); // Overloaded = operator

	//Getters
	//Get the size n
	int getSize() const {
		return n;
	}
	//Get the matrix
	unsigned char** getMatrix() const {
		return bitAdjacencyMatrix;
	}

};

//////////////////////////////
//Constructor and Destructor
//////////////////////////////

//Default Constructor
BitMatrixGraph::BitMatrixGraph() {
	n = 8;
	int size;

	//Create the bit Adjacency Matrix structure
	if (n % 8 == 0)
		size = n / 8;
	else
		size = (int)(n / 8) + 1;

	bitAdjacencyMatrix = new unsigned char*[n];
	for (int i = 0; i < n; i++) {
		bitAdjacencyMatrix[i] = new unsigned char[size];
	}

	//Initialize the bit Adjacency Matrix structure
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < size; j++) {
			bitAdjacencyMatrix[i][j] = 0x00 << 8;
		}
	}
}

//Constructor with size parameter
BitMatrixGraph::BitMatrixGraph(int numNodes) {
	n = numNodes;
	int size;

	//Create the bit Adjacency Matrix structure
	if (n % 8 == 0)
		size = n / 8;
	else
		size = (int)(n / 8) + 1;

	bitAdjacencyMatrix = new unsigned char*[n];
	for (int i = 0; i < n; i++) {
		bitAdjacencyMatrix[i] = new unsigned char[size];
	}

	//Initialize the bit Adjacency Matrix structure
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < size; j++) {
			bitAdjacencyMatrix[i][j] = 0x00 << 8;
		}
	}
}

//Copy Constructor
BitMatrixGraph::BitMatrixGraph(const BitMatrixGraph& otherGraph) {
	n = otherGraph.getSize();

	int size;

	//Create the bit Adjacency Matrix structure
	if (n % 8 == 0)
		size = n / 8;
	else
		size = (int)(n / 8) + 1;

	bitAdjacencyMatrix = new unsigned char*[n];
	for (int i = 0; i < n; i++) {
		bitAdjacencyMatrix[i] = new unsigned char[size];
	}

	//Initialize the bit Adjacency Matrix structure
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < size; j++) {
			bitAdjacencyMatrix[i][j] = 0x00 << 8;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (otherGraph.isAnEdge(i, j)) {
				addEdge(i, j);
			}
		}
	}
}

//Destructor
BitMatrixGraph::~BitMatrixGraph() {
	for (int i = 0; i < n; i++) {
		delete[] bitAdjacencyMatrix[i];
	}

	delete[] bitAdjacencyMatrix;
}

//////////////////////
//General Methods
//////////////////////

//Adds edge between nodes u and v
void BitMatrixGraph::addEdge(int u, int v) {

	//Create edge from u to v
	int index; //index of second index of matrix. Need to determine which set of 8 bits to use.
	if (v % 8 == 0) {
		index = (v / 8);
	}
	else {
		index = (int)(v / 8);
	}
	bitAdjacencyMatrix[u][index] |= 0x01 << (7 - (v % 8));

	//Create edge from v to u
	if (u % 8 == 0) {
		index = (u / 8);
	}
	else {
		index = (int)(u / 8);
	}

	bitAdjacencyMatrix[v][index] |= 0x01 << (7 - (u % 8));
}

//Checks if there is an edge between u and v
bool BitMatrixGraph::isAnEdge(int u, int v) const{

	int index; //index of second index of matrix. Need to determine which set of 8 bits to use.
	if (v % 8 == 0) {
		index = (v / 8);
	}
	else {
		index = (int)(v / 8);
	}

	//Check if the value of the specified bit in the matrix is a set or not. If set, return true, else return false.
	if (bitAdjacencyMatrix[u][index] & (1 << (7 - (v % 8)))) {
		return true;
	}
	else {
		return false;
	}

}

//Outputs the matrix to the console
void BitMatrixGraph::display() {

	
	int size; //Number of chars per column
	int remainder; //remaining number of bits in last char
	if (n % 8 == 0) {
		size = n / 8;
		remainder = 8;
	}
	else {
		size = (int)(n / 8) + 1;
		remainder = n % 8;
	}

	//Loop through the matrix of chars and output if edge exists
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < size; y++) {

			//Check if the char is the last one in the column. If so only output remainder# of chars, else output all.
			if (y != size - 1) {
				for (int i = 0; i < 8; i++) {
					if (bitAdjacencyMatrix[x][y] & (1 << (7 - i)))
						cout << 1 << " ";
					else
						cout << 0 << " ";
				}
			}
			else {
				for (int i = 0; i < remainder; i++) {
					if (bitAdjacencyMatrix[x][y] & (1 << (7 - i)))
						cout << 1 << " ";
					else
						cout << 0 << " ";
				}
			}
		}
		cout << endl;
	}
}

//Outputs a parent array representation of a bfs tree
void BitMatrixGraph::breadthFirstSearch(int k) {

	//Queue used for calculating bfs tree
	queue<int> q = queue<int>();

	//array of bools representing the nodes visited
	bool* visited = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}

	//Array of ints representing the indexes parent node
	int* parent = new int[n];
	for (int i = 0; i < n; i++) {
		parent[i] = -1;
	}

	//Loop through each node and add it to the queue if it has not been visited
	for (int i = k; i < n+k; i++) {
		int index = i%n;
		if (!visited[index]) {
			visited[index] = true;
			q.push(index);

			//For every element in the queue, add all nodes it is attached to to the parent array and queue
			//if they have not been visited
			while (!q.empty()) {
				int x = q.front();
				q.pop();
				for (int j = 0; j < n; j++) {
					if (isAnEdge(x, j)) {
						if (!visited[j]) {
							visited[j] = true;
							parent[j] = x;
							q.push(j);
						
						}
					}
				}
			}
		}
	}

	//Output parent array
	for (int i = 0; i < n; i++) {
		cout << "(" << i << ": " << parent[i] << ")";
		if ((i + 1) % 5 == 0) {
			cout << endl;
		}
		else {
			cout << " ";
		}
	}

	//delete the dynamically created arrays
	delete[] parent;
	delete[] visited;
}

//Outputs a parent array representation of a dfs tree
void BitMatrixGraph::depthFirstSearch(int k) {

	//array of bools representing the nodes visited
	bool* visited = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}

	//Array of ints representing the indexes parent node
	int* parent = new int[n];
	for (int i = 0; i < n; i++) {

		parent[i] = -1;
	}

	//for each node in the matrix not visited, call the dfsHelper method using its index
	for (int i = k; i < n + k; i++) {
		int index = i % n;
		if (!visited[index]) {
			dfsHelper(index, parent, visited);
		}
	}

	//output parent array
	for (int i = 0; i < n; i++) {
		cout << "(" << i << ": " << parent[i] << ")";
		if ((i + 1) % 5 == 0) {
			cout << endl;
		}
		else {
			cout << " ";
		}
	}

	//delete the dynamically created arrays
	delete[] parent;
	delete[] visited;
}

//Method used with depthFirstSearch for recursion
void BitMatrixGraph::dfsHelper(int index, int* parent, bool* visited) {
	visited[index] = true;
	for (int i = 0; i < n; i++) {
		if (!visited[i] && isAnEdge(index, i)) {
			parent[i] = index;
			dfsHelper(i, parent, visited);
		}
	}
}

///////////////////////////
//Overloaded Operators
///////////////////////////

//Overloaded assignment operator
BitMatrixGraph& BitMatrixGraph::operator=(BitMatrixGraph& otherGraph) {
	return BitMatrixGraph(otherGraph);
}

//Overloaded ostream operator
ostream& operator<< (ostream& s, const BitMatrixGraph& bmg) {
	bmg.printBits(s);
	return s;
}

//Method used with ostream operator
void BitMatrixGraph::printBits(ostream& s) const {
	
	int column = 0; //Used for counting the current column being output to

	//Loop through half of the matrix (Only need to loop through half because graph is not directed)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i+1; j++ ) {
			if (isAnEdge(i, j)) {
				s << "(" << i << ", " << j << ")";

				//Go to a new line every fifth column
				column++;
				if (column == 5) {
					column = 0;
					cout << endl;
				}
				else
					cout << " ";
			}
		}
	}
	cout << endl;
}

///////////////////////////////////////////////////////////////
//Main method
///////////////////////////////////////////////////////////////
int main() {

	//Create graph based on input
	cout << "Enter number of nodes in the graph." << endl;
	int graphSize = 10;
	cin >> graphSize;
	BitMatrixGraph bmg = BitMatrixGraph(graphSize);

	//Input Loop.
	//Keep looping and creating edges between u and v until eof character entered.
	int u, v = 0;
	while (!cin.eof()) {
		cout << endl << "Enter two nodes where an edge exists between or EOF to finish." << endl;
		cin >> u;
		cin >> v;
		if (!cin.eof()) {
			if (u >= 0 && v >= 0 && u < bmg.getSize() && v < bmg.getSize()) {
				bmg.addEdge(u, v);
				cout << "Edge added." << endl;
			}
			else {
				cout << "Node not within the matrix. Edge not added." << endl;
			}
		}
	}

	//Output the matrix
	cout << endl << "Matrix: " << endl;
	bmg.display();

	//Output using ostream operator
	cout << endl << "Matrix in edge list format: " << endl << "(Node 1, Node 2), Edge exists between Node 1 and Node 2." << endl;
	cout << bmg;

	//Copy constructor demonstration
	BitMatrixGraph bmg2 = bmg;

	//Breadth First Search
	cout << endl << "Breadth First Search (With 0 as starting node): " << endl << "(Node: Parent Node), -1 parent represent root." << endl;
	bmg2.breadthFirstSearch(0);

	//Depth First Search
	cout << endl << "Depth First Search (With 0 as starting node): " << endl << "(Node: Parent Node), -1 parent represent root." << endl;
	bmg2.depthFirstSearch(0);

	return 0;
}