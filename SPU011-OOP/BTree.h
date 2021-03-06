#pragma once

#pragma once

template<class TKey, class TVal>
class BTreeNode
{
public:
	TKey key;
	TVal value;

	BTreeNode *left = nullptr;
	BTreeNode *right = nullptr;

	BTreeNode(TKey key, TVal val) :key(key), value(val) {}

	void print() //симетричный
	{
		if (left != nullptr) left->print();
		cout << value;
		//value.print();
		if (right != nullptr) right->print();

	}

	void del()
	{
		if (left != nullptr) left->del();
		if (right != nullptr) right->del();
		delete this;
	}

	TVal* get(const TKey &key)
	{
		if (key == this->key) return &value;
		if (key < this->key && left != nullptr) return left->get(key);
		if (key > this->key && right != nullptr) return right->get(key);
		return nullptr;
	}


};


template<class TKey, class TVal>
class BTree
{
public:
	static BTreeNode<TKey, TVal> *root;
	~BTree()
	{
		clear();
	}
	bool isEmpty()
	{
		return root;
	}

	void clear()
	{
		if (root)
			root->del();
		root = nullptr;
		cout << "Tree deleted" << endl;
	}

	void print()
	{
		if (root)
			root->print();
		else
			cout << "Tree empty";
		cout << endl;
	}

	TVal* get(const TKey &key)
	{
		if (root)
			return root->get(key);
		return nullptr;
	}

	bool push(TKey key, TVal val)
	{
		if (!root)
		{
			root = new BTreeNode<TKey, TVal>(key, val);
			return true;
		}
		bool working = true;
		BTreeNode<TKey, TVal> *next = root;
		do
		{
			// go left
			if (key < next->key)
			{
				if (next->left)
				{
					next = next->left;
				}
				else
				{
					next->left = new BTreeNode<TKey, TVal>(key, val);
					working = false;
				}
			}
			// go right
			else if (key > next->key)
			{
				if (next->right)
				{
					next = next->right;
				}
				else
				{
					next->right = new BTreeNode<TKey, TVal>(key, val);
					working = false;
				}
			}
			else
			{
				return false;
			}
		} while (working);
		return true;
	}

	BTreeNode<TKey, TVal>* push_r(TKey key, TVal val, BTreeNode<TKey, TVal> *&node = root)
	{
		if (!node)
		{
			node = new BTreeNode<TKey, TVal>(key, val);
			return node;
		}
		if (key < node->key) node->left = push_r(key, val, node->left);
		else if (key > node->key) node->right = push_r(key, val, node->right);
		return node;
	}
};

template<class TKey, class TVal>
BTreeNode<TKey, TVal>* BTree<TKey, TVal>::root = nullptr;
