#include <iostream>

using namespace std;

class Node
{
private:
	int v; //key
	Node* left_node; //wskaznik na lewego syna
	Node* right_node; //wskaznik na prawego syna
	Node* parent_node; //wskaznik na rodzica
public:
	Node(int v, Node* l, Node* r); //konstruktor, tworzy nowy wezel, ktory nie ma rodzica
	int value(); //zwraca key
	Node* left(); //zwraca left_node
	Node* right(); //zwraca right_node
	Node* parent(); //zwraca parent_node
	void setValue(int v); //ustawia key
	void setLeft(Node* l); //ustawia left_node
	void setRight(Node* r); //ustawia right_node
	void setParent(Node* p); //ustawia parent_node
};

Node::Node(int v, Node* l, Node* r)
{
	this->v = v;
	left_node = l;
	right_node = r;
	parent_node = NULL;
}

int Node::value()
{
	return v;
}

Node* Node::left()

{
	return left_node;
}

Node* Node::right()
{
	return right_node;
}

Node* Node::parent()
{
	return parent_node;
}

void Node::setValue(int v)
{
	this->v = v;
}

void Node::setLeft(Node* l)
{
	left_node = l;
}

void Node::setRight(Node* r)
{
	right_node = r;
}

void Node::setParent(Node* p)
{
	parent_node = p;
}

class Tree
{
private:
	Node* root; //wskaznik na korzen drzewa
	bool empty(Node* n);	//zwraca prawdę gdy węzeł nie istnieje
	void preorder(Node* n); //przejscie preorder
	void inorder(Node* n); //przejscie inorder
	void postorder(Node* n); //przejscie postorder
	int size(Node* n); //metoda obliczająca i zwracająca liczbę węzłów
	int height(Node* n); //metoda obliczająca i zwracająca wysokość drzewa, czyli dlugosc najdluzszej sciezki w drzewie
	void clear(Node* n); //usuwa drzewo
public:
	Tree();			//tworzy puste drzewo
	Tree(Node* r); //tworzy nowe drzewo
	bool empty();		//zwraca prawdę gdy drzewo jest puste
	void preorder(); //wywolujemy private preorder
	void inorder(); //wywolujemy private inorder
	void postorder(); //wywolujemy private postorder
	int size(); //wywolujemy private size
	int height(); //wywolujemy private height
	void clear(); //wywolujemy private clear
};

bool Tree::empty(Node* n)
{
	/**if (n == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}**/

	if(n == NULL)
		return true;
	return false;
}

void Tree::preorder(Node* n) //rekurencja
{
	if (!empty(n))
	{
		cout << n->value() << " "; //odwiedzamy wezel
		preorder(n->left()); //przechodzimy lewe poddrzewo
		preorder(n->right()); //przechodzimy prawe poddrzewo
	}
	else
	{
		return;
	}
}

void Tree::inorder(Node* n) //rekurencja
{
	if (!empty(n))
	{
		inorder(n->left()); //przechodzimy lewe poddrzewo
		cout << n->value() << " "; //odwiedzamy wezel
		inorder(n->right()); //przechodzimy prawe poddrzewo
	}
	else
	{
		return;
	}
}

void Tree::postorder(Node* n) //rekurencja
{
	if (!empty(n))
	{
		postorder(n->left()); //przechodzimy lewe poddrzewo
		postorder(n->right()); //przechodzimy prawe poddrzewo
		cout << n->value() << " "; //odwiedzamy wezel
	}
	else
	{
		return;
	}
}

int Tree::size(Node* n) //rekurencja
{
	/**sprawdzasz lewe poddrzewo, prawe poddrzewo, sumujesz i masz ilość węzłów u dzieci, następnie dodajesz obecny węzeł i masz ilość węzłów poddrzewa i tak od liści do korzenia**/
	int s = 0;
	if (n != NULL) 
	{
		s += size(n->left()); //sumuje liczbe dzieci w lewym poddrzewie
		s += size(n->right()); //sumuje liczbe dzieci w prawym poddrzewie
		return ++s; //i do sumy dzieci w lewym i prawym poddrzewie dodaje wezel, w którym sie znajduje
	}
	else
		return 0;
}

int Tree::height(Node* n) //rekurencja
{
	/**Podobnie jest dla wysokości drzewa, tylko tutaj robisz dla każdego węzła jakby dwie możliwości, tj albo idziesz do lewego dziecka, albo do prawego
		Tworzą się wtedy takie pojedyncze drogi od korzenia do liści**/
	int left = 0;
	int right = 0;
	if (!empty(n)) {
		left += height(n->left());
		right += height(n->right());

		left++;
		right++;
		if (left > right)
			return left;
		else
			return right;
	}
	else
		return 0;
}

void Tree::clear(Node* n) //rekurencja
{
	if (!empty(n->left()))
		clear(n->left());
	if (!empty(n->right()))
		clear(n->right());

	delete n;
}

Tree::Tree()
{
	root = NULL;
}

Tree::Tree(Node* r)
{
	root = r;
}

bool Tree::empty()
{
	/**if (root == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}**/

	/**if (root == NULL)
		return true;
	return false;**/

	if (empty(root))
		return true;
	else
		return false;
}

void Tree::preorder()
{
	if (!empty())
	{
		preorder(root);
	}
	else
	{
		return;
	}
}

void Tree::inorder()
{
	if (!empty())
	{
		inorder(root);
	}
	else
	{
		return;
	}
}

void Tree::postorder()
{
	if (!empty())
	{
		postorder(root);
	}
	else
	{
		return;
	}
}

int Tree::size()
{
	return size(root);
}

int Tree::height()
{
	return height(root);
}

void Tree::clear()
{
	clear(root);
}

/*
przykładowe drzewo do testów (bez ustawienia ojca):
	Tree* t=new Tree(new Node(9, new Node(5, new Node(2, new Node(3, NULL,
NULL), new Node(3, NULL, NULL)),
	new Node(7, NULL, new Node(8,NULL, NULL))), new Node(12, new Node(10,
NULL, new Node(11, NULL, NULL)), NULL)));

*/

int main()
{
	Tree* t = new Tree(new Node(9, new Node(5, new Node(2, new Node(3, NULL,
		NULL), new Node(3, NULL, NULL)),
		new Node(7, NULL, new Node(8, NULL, NULL))), new Node(12, new Node(10,
			NULL, new Node(11, NULL, NULL)), NULL)));

	cout << "Preorder: ";
	t->preorder();
	cout << endl;

	cout << "Inorder: ";
	t->inorder();
	cout << endl;

	cout << "Postorder: ";
	t->postorder();
	cout << endl;

	cout << "Liczba wezlow: " << t->size() << endl;

	cout << "Wysokosc drzewa (najdluzsza sciezka w drzewie): " << t->height() << endl;

	//usuwamy cale drzewo
	t->clear();

	return 0;
}