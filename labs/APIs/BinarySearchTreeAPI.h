#ifndef BST_GUARD
#define BST_GUARD

/**************************************
Interface for a Binary Tree ADT

Author:  Judi McCuaig
October, 2012
Modfied: James Fraser (Nov 2017)
**************************************/

/**
 * Function pointer tyepdefs
 */
typedef int (*CompareFunc)(const void* a, const void* b);
typedef void (*DeleteFunc)(void* data);
typedef void (*PrintFunc)(void* data);

/*
 * Typedef the void* to make the API cleaner and more readable.
 */
typedef void* TreeDataPtr;

/*
 * A Single Binary Tree Node.
 * Left and Right branches
 * void* data
 */
typedef struct binTreeNode TreeNode;
struct binTreeNode{
	TreeDataPtr data;
	TreeNode * left;
	TreeNode * right;
	//TreeNode * parent; Optional but useful
};

/**
 * This is the definition of the Binary Tree.
 *
 */
typedef struct binTree
{
	TreeNode *root;
	CompareFunc compareFunc;
	DeleteFunc deleteFunc;

	// Additions must work with abstract data types.
	// Additional function pointers to generalize tree.
	// Additional properties can be added such as count.
} Tree;

/**
 * Creates a TreeNode. TreeNode children are set to NULL and data is set to the passed in data.
 * @param data - the data to be stored within the Node. 
 * @return
 *
 */
TreeNode* createTreeNode(TreeDataPtr data);

/**
 * createBinTree allocates memory for Tree and assigned function pointers
 * @param  compare [Function pointer to Compare data in tree nodes]
 * @param  del     [Function pointer to delete data from node]
 * @return
 */
Tree * createBinTree(CompareFunc compare, DeleteFunc del);

/**
 * destroyBinTree - remove all items and free memory
 * @param  toDestroy - the tree
 * @return
 */
void  destroyBinTree(Tree * toDestroy);

/**
 * Add data to a tree
 * @param theTree 
 * @param data    
 */
void addToTree(Tree * theTree, TreeDataPtr data);

/**
 * Remove data from the tree
 * @param theTree [description]
 * @param data    [description]
 */
void removeFromTree(Tree * theTree, TreeDataPtr data);

/**
 * Get data from the root of the Tree if it exists.
 */
TreeDataPtr getRootData(Tree * theTree);

/**
 * printTreeByOrder (OPTIONAL) - Generic version of print Tree
 * 	   Consider that print pre/post/inorder could be done with a small change in coding logic.
 *     This function could be implemented to allow the ordering of print and traversing the nodes to change.
 *     nodeOrder manages the order the TreeNode and it's children will be printed.
 *     ie it will order the print statemetn for InOrder,PreOrder,PostOrder
 * @param tree      
 * @param nodeOrder order to print nodes
 * @param printData How to display the actual data.
 */
void printTreeByOrder( Tree * tree, PrintFunc nodeOrder, PrintFunc printData );

/**
 * [printInOrder This function prints the tree using an inOrder traversal
 * @param theTree   [description]
 * @param printData [description]
 */
void printInOrder(Tree * theTree, PrintFunc printData);

/**
 * [printPreOrder This function prints the tree using an preOrder traversal
 * @param theTree   [description]
 * @param printData [description]
 */
void printPreOrder(Tree * theTree, PrintFunc printData);

/**
 * [printPostOrder This function prints the tree using an postOrder traversal
 * @param theTree   [description]
 * @param printData [description]
 */
void printPostOrder(Tree * theTree, PrintFunc printData);

/**
 * Checks if a tree is empty
 * @param  theTee [description]
 * @return        [description]
 */
int isTreeEmpty(Tree* theTee);


/**
 * Helper function for checking if a single node is a leaf (no children)
 * @param  treeNode [description]
 * @return          [description]
 */
int isLeaf( TreeNode * treeNode);

/**
 * Helper funciton for checking if a single node has two children.
 * @param  treeNode [description]
 * @return          [description]
 */
int hasTwoChildren( TreeNode *treeNode);

/**
 * You may add additional API functions below this comment if you want to extend the funcitonality.
 */


#endif
