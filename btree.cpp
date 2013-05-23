#include <iostream>

using namespace std;

struct node
{
  int key_value;
  node *left;
  node *right;
};

class btree
{
    public:
        btree();
        ~btree();

        void insert(int key);
        node *search(int key);
        void destroy_tree();

    private:
        void destroy_tree(node *leaf);
        void insert(int key, node *leaf);
        node *search(int key, node *leaf);
        
        node *root;
};

btree::btree()
{
  root=NULL;
}

btree::~btree()
{
  destroy_tree();
}

void btree::destroy_tree(node *leaf)
{
  if(leaf!=NULL)
  {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}

void btree::insert(int key, node *leaf)
{
  if(key< leaf->key_value)
  {
    if(leaf->left!=NULL)
    {
      cout << "going left..." << endl;
      insert(key, leaf->left);
    }
    else
    {
      cout << "Creating left node ..." << endl;
      leaf->left=new node;
      leaf->left->key_value=key;
      leaf->left->left=NULL;    //Sets the left child of the child node to null
      leaf->left->right=NULL;   //Sets the right child of the child node to null
    }  
  }
  else if(key>=leaf->key_value)
  {
    if(leaf->right!=NULL)
    {
      cout << "going right..." << endl;
      insert(key, leaf->right);
    }
    else
    {
      cout << "Creating right node ..." << endl;
      leaf->right=new node;
      leaf->right->key_value=key;
      leaf->right->left=NULL;  //Sets the left child of the child node to null
      leaf->right->right=NULL; //Sets the right child of the child node to null
    }
  }
}

node *btree::search(int key, node *leaf)
{
  if(leaf!=NULL)
  {
    if(key==leaf->key_value)
    {
      cout << "Found value." << endl;
      return leaf;
    }
    if(key<leaf->key_value)
    {
      cout << "key:" << key << " is less than leaf->key: " << leaf->key_value;
      cout << " goin left ..." << endl; 
      return search(key, leaf->left);
    }
    else
    {
      cout << "key:" << key << " is greater than leaf->key: " <<leaf->key_value;
      cout << " goin right ..." << endl; 
      return search(key, leaf->right);
    }
  }
  else 
  {
    cout << "leaf is null ??" << endl;
    return NULL;
  }
}

void btree::insert(int key)
{
  if(root!=NULL)
    insert(key, root);
  else
  {
    cout << "Creating root node ..." << endl;
    root=new node;
    root->key_value=key;
    root->left=NULL;
    root->right=NULL;
  }
}

node *btree::search(int key)
{
  cout << "Searching for " << key << endl;
  return search(key, root);
}

void btree::destroy_tree()
{
  destroy_tree(root);
}

int main()
{
  int i;
  node *myleaf;
  btree mytree;

  mytree.insert(5);

  for (i=0; i <= 9; ++i)
    mytree.insert(i);

  myleaf = mytree.search(7);
}
