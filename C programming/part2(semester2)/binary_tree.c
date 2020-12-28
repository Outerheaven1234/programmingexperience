typedef struct binaryNode binaryNode, *BinaryNode_Ptr;
struct binaryNode
{
  BinaryNode_Ptr Left;
  BinaryNode_Ptr Right;
  int item;
};
struct binaryTree
{
  BinaryNode_Ptr root;
};
typedef struct binaryTree BinaryTree, * BinaryTree_Ptr;

int identical_trees_nodes(node a, node b){
  if(a==NULL && b==NULL){
    return 1;
  }
  if(a!=NULL && b!=NULL){
    return (a->data == b->data && identical_trees_nodes(a->left, b->left)&& identical_trees_nodes(a->right, b->right));
  }
  return 0;
}
