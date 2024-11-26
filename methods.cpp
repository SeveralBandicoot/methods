#include <iostream>
using namespace std;

struct node {
  int data;
  struct node* left;
  struct node* right;
};

struct node* newNode(int idata) {
  struct node* node = new struct node;
  node->data = idata;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void preOrderDisplay(struct node* root) {
  if (root == nullptr) {
    return;
  }
  cout << " " << root->data;
  preOrderDisplay(root->left);
  preOrderDisplay(root->right);
}

void inOrderDisplay(struct node* root) {
  if (root == nullptr) {
    return;
  }
  inOrderDisplay(root->left);
  cout << " " << root->data;
  inOrderDisplay(root->right);
}

void postOrderDisplay(struct node* root) {
  if (root==nullptr) {
    return;
  }
  postOrderDisplay(root->left);
  postOrderDisplay(root->right);
  cout << " " << root->data; 
}

int main() {
  struct node* root = newNode(9);
  root->left = newNode(8);
  root->right = newNode(3);
  root->left->left = newNode(4);
  
  // Display tree
  cout << "Pre-Order Traversal" << endl;
  preOrderDisplay(root);

  cout << "\n\n";

  cout << "In-Order Traversal" << endl;
  inOrderDisplay(root);

  cout << "\n\n";

  cout << "Post-Order Traversal" << endl;
  postOrderDisplay(root);  
  
  // Access and print specific data

  // Free allocated memory (good practice)
  delete root->left->left;
  delete root->left;
  delete root->right;
  delete root;

  return 0;
}
