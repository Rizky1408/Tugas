#include <iostream>
using namespace std;

struct Node
{
	char label;
	Node *left, *right, *parent;
};

//variabel global
Node *root, *newNode;

// create tree
void createNewTree(char label)
{
	if (root != NULL)
	{
		cout << "\nTrue sudah di buat" << endl;
	}
	else
	{
		root = new Node();
		root->label = label;
		root->left = NULL;
		root->right = NULL;
		root->parent = NULL;
		cout << "\nNode " << label << " berhasil dibuat menjadi root" << endl;
	}
}

//insert left
Node *insertLeft(char label, Node *node)
{
	if (!root)
	{
		cout << "\nBuat tree terlebih dahulu" << endl;
		return NULL;
	}
	else
	{
		// cek apakah ada anak kiri
		if (node->left != NULL)
		{
			//jika ada maka
			cout << "\nNode " << node->label << " Sudah ada anak kiri" << endl;
			return NULL;
		}
		else
		{
			//dan jika tidak ada maka
			newNode = new Node();
			newNode->label = label;
			newNode->left = NULL;
			newNode->right = NULL;
			newNode->parent = node;
			node->left = newNode;
			cout << "\nNOde " << label << " berhasil ditambahkan ke anak kiri " << newNode->parent->label << endl;
			return newNode;
		}
	}
}

//insert right
Node *insertRight(char label, Node *node)
{
	if (!root)
	{
		cout << "\nBuat tree terlebih dahulu" << endl;
		return NULL;
	}
	else
	{
		// cek apakah ada anak kanan maka
		if (node->right != NULL)
		{
			//jika ada maka
			cout << "\nNode " << node->label << " Sudah ada anak kanan" << endl;
			return NULL;
		}
		else
		{
			//dan jika tidak ada maka
			newNode = new Node();
			newNode->label = label;
			newNode->right = NULL;
			newNode->right = NULL;
			newNode->parent = node;
			node->right = newNode;
			cout << "\nNode " << label << " berhasil ditambahkan ke anak kanan " << newNode->parent->label << endl;
			return newNode;
		}
	}
}

//Empty
bool empty()
{
	if (!root)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//update
void update(char label, Node *node)
{
	if (!root)
	{
		cout << "\nBuat Tree Terlebih Dahulu" << endl;
	}
	else
	{
		if (node == NULL)
		{
			cout << "\nNode yang ingin di ganti tidak ada" << endl;
		}
		else
		{
			char temp = node->label;
			node->label = label;
			cout << "\nLabel Node " << temp << " Berhasil di ubah menjadi " << label << endl;
		}
	}
}

//retrive
void retrive(Node *node)
{
	if (!root)
	{
		cout << "\nBuat Tree Terlebih Dahulu" << endl;
	}
	else
	{
		if (!node)
		{
			cout << "\nNode yang ditunjuk tidak ada" << endl;
		}
		else
		{
			cout << "\nLabel Node : " << node->label << endl;
		}
	}
}

//find
void find(Node *node)
{

	if (!root)
	{
		cout << "\nBuat Tree terlebih dahulu" << endl;
	}
	else
	{
		// jika tidak ada root maka
		if (!node)
		{
			cout << "\nNode yang ditunjuk tidak ada" << endl;
		}
		else
		{
			//jika ada maka
			cout << "\nLabel Node : " << node->label << endl;
			cout << "Root Node : " << root->label << endl;

			if (!node->parent)
			{
				cout << "Parent Node : (tidak ada orang tua)" << endl;
			}
			else
			{
				cout << "Parent Node : " << node->parent->label << endl;
			}

			// mencari sepupu  kiri
			if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
			{
				cout << "Sepupu : " << node->parent->left->label << endl;
			}
			// jika ada sepupu kanan maka
			else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
			{
				cout << "Sepupu : " << node->parent->right->label << endl;
			}
			// jika tidak ada sepupu
			else
			{
				cout << "sepupu : (tidak ada punya sepupu)" << endl;
			}

			// jika tidak ada anak kiri maka
			if (!node->left)
			{
				cout << "anak kiri Node : (tidak ada anak kiri)" << endl;
			}
			// jika ada maka tunjukan
			else
			{
				cout << "anak kiri Node : " << node->left->label << endl;
			}

			// jika tidak ada anak kanan maka
			if (!node->right)
			{
				cout << "anak kanan Node : (tidak ada anak kanan)" << endl;
			}

			// jika tidak ada anak kanan
			else
			{
				cout << "anak kanan Node : " << node->right->label << endl;
			}
		}
	}
}

// Tranversal
// preOrder
void preOrder(Node *node = root)
{
	if (!root)
	{
		cout << "\nBuat tree terlebih dahulu" << endl;
	}
	else
	{
		if (node != NULL)
		{
			cout << node->label << ", ";
			preOrder(node->left);
			preOrder(node->right);
		}
	}
}

// inOrder
void inOrder(Node *node = root)
{
	if (!root)
	{
		cout << "\nBuat tree terlebih dahulu" << endl;
	}
	else
	{
		if (node != NULL)
		{
			inOrder(node->left);
			cout << node->label << ", ";
			inOrder(node->right);
		}
	}
}

// postOrder
void postOrder(Node *node = root)
{
	if (!root)
	{
		cout << "\nBuat tree terlebih dahulu" << endl;
	}
	else
	{
		if (node != NULL)
		{
			postOrder(node->left);
			postOrder(node->right);
			cout << node->label << ", ";
		}
	}
}

// deleteTree
void deleteTree(Node *node)
{
	if (!root)
	{
		cout << "\nBuat tree terlebih dahulu" << endl;
	}
	else
	{
		if (node != NULL)
		{
			if (node != root)
			{
				node->parent->left = NULL;
				node->parent->right = NULL;
			}

			deleteTree(node->left);
			deleteTree(node->right);

			if (node == root)
			{
				delete root;
				root = NULL;
			}
			else
			{
				delete node;
			}
		}
	}
}

// delete sub
void deleteSub(Node *node)
{
	if (!root)
	{
		cout << "\nBuat tree terlebih dahulu" << endl;
	}
	else
	{
		deleteTree(node->left);
		deleteTree(node->right);
		cout << "\nsubTree node " << node->label << " berhasil di hapus" << endl;
	}
}

// clear
void clear()
{
	if (!root)
	{
		cout << "\nBuat tree terlebih dahulu" << endl;
	}
	else
	{
		deleteTree(root);
		cout << "\nTree Berhasil Di hapus." << endl;
	}
}

//size
int size(Node *node = root)
{
	if (!root)
	{
		cout << "\nBuat Tree terlebih dahulu" << endl;
		return 0;
	}
	else
	{
		if (!node)
		{
			return 0;
		}
		else
		{
			return 1 + size(node->left) + size(node->right);
		}
	}
}

//height
int height(Node *node = root)
{
	if (!root)
	{
		cout << "\nBuat Tree terlebih dahulu" << endl;
		return 0;
	}
	else
	{
		if (!node)
		{
			return 0;
		}
		else
		{
			int heightKiri = height(node->left);
			int heightKanan = height(node->right);

			if (heightKiri >= heightKanan)
			{
				return heightKiri + 1;
			}
			else
			{
				return heightKanan + 1;
			}
		}
	}
}

//charateristic

void charateristic()
{

	cout << "\nSize Tree : " << size() << endl;
	cout << "\nHeight Tree :" << height() << endl;
	cout << "Averege Node of Tree : " << size() / height() << endl;
}

int main()
{
	system("clear");
	createNewTree('A');

	Node *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ;

	nodeB = insertLeft('B', root);
	nodeC = insertRight('C', root);
	nodeD = insertLeft('D', nodeB);
	nodeE = insertRight('E', nodeB);
	nodeF = insertLeft('F', nodeC);
	nodeG = insertLeft('G', nodeE);
	nodeH = insertRight('H', nodeE);
	nodeI = insertLeft('I', nodeG);
	nodeJ = insertRight('J', nodeG);

	cout << "\nTree empty : " << empty() << endl;
	cout << endl;

	cout << "preOrder : ";
	preOrder();
	cout << endl;
	cout << "inOrder : ";
	inOrder();
	cout << endl;
	cout << "postOrder :";
	postOrder();
	cout << endl;

	cout << "Height : " << height() << endl;

	charateristic();
	cout << "Delete :" << endl;
	deleteSub(nodeE);
	cout << "\npreOrder : " << endl;
	preOrder();
	cout << endl;

	charateristic();

	cout << "Height : " << height() << endl;

	clear();
	cout << "\npreOrder :" << endl;
	preOrder();
	cout << endl;

	cin.get();
	return 0;
}