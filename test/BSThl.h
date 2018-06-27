# define MAX_NODE_BST 100
# define LEFT 0
# define RIGHT 1
int height = 0;
int ElementLength = 5;
int last[1611];
int needline[1611];

typedef struct NODE_BST{
  elementtype_BST data;
  struct NODE_BST *left,*right,*parent;
} NODE_BST;

int max(int a,int b)
{
  return a>b?a:b;
}

NODE_BST *makeNewNode_BST(elementtype_BST data)
{
  NODE_BST *p = (NODE_BST*) malloc(sizeof(NODE_BST));
  p -> data = data;
  p -> parent = NULL;
  p -> left = NULL;
  p -> right = NULL;
  return p;
}

void insertNode_BST(NODE_BST **tree,elementtype_BST data)
{
  NODE_BST *root = *tree;
  NODE_BST *p = makeNewNode_BST(data);
  if (root == NULL)
    {
      *tree = p;
      return;
    }
  while (2109)
    {
      if (data < root->data)
	{
	  if (root->left == NULL)
	    {
	      p->parent = root;
	      root->left = p;
	      return;
	    }
	  else
	    root = root->left;
	}
      else
	{
	  if (root->right == NULL)
	    {
	      p->parent = root;
	      root->right = p;
	      return;
	    }
	  else
	    root = root->right;
	}
    }
}

NODE_BST *findLeftMost_BST(NODE_BST *tree)
{
  if (tree->left != NULL)
    return findLeftMost_BST(tree->left);
  else return tree;
}

NODE_BST *findRightMost_BST(NODE_BST *tree)
{
  if (tree->right != NULL)
    return findRightMost_BST(tree->right);
  else return tree;
}

void deleteNode_BST(NODE_BST **root,NODE_BST *deletenode)
{
  if (deletenode == NULL) return;
  NODE_BST *p = NULL;
  int t = 0;
  if (deletenode->right != NULL)
    {
      p = findLeftMost_BST(deletenode->right);
      t = 0;
    }
  else if (deletenode->left != NULL)
    {
      p = findRightMost_BST(deletenode->left);
      t = 1;
    }
  if (p == NULL)
    {
      if (deletenode->parent == NULL)
	{
	  free(deletenode);
	  *root = NULL;
	  return;
	}
      else
	{
	  if (deletenode->data < deletenode->parent->data)
	      deletenode->parent->left = NULL;
	  else deletenode->parent->right = NULL;
	  free(deletenode);
	  return;
	}
    }
  if (t == 0)
    {
      if (p->parent == deletenode)
	{
	  p->parent->right = p->right;
	}
      else
	{
	  p->parent->left = p->right;
	}
      if (p->right != NULL)
	p->right->parent = p->parent;
    }
  else
    if (t == 1)
    {
      if (p -> parent == deletenode)
	{
	  p->parent->left = p->left;
	}
      else
	{
	  p->parent->right = p->left;
	}
      if (p->left != NULL)
	p->left->parent = p->parent;
    }
  deletenode->data = p->data;
  //deleteNode_BST(root,p);
  free(p);
}

NODE_BST *findNode_BST(NODE_BST *root,elementtype_BST data)
{
  if (root == NULL) return NULL;
  if (data < root->data)
    return findNode_BST(root->left,data);
  else if (data > root->data)
    return findNode_BST(root->right,data);
  else return root;
}

void freeTree_BST(NODE_BST *root)
{
  if (root == NULL) return;
  freeTree_BST(root->left);
  freeTree_BST(root->right);
  free(root);
}

int getHeight(NODE_BST *root)
{
  if (root == NULL) return 0;
  if (root->left == NULL && root->right == NULL) return 0;
  return max(getHeight(root->left),getHeight(root->right))+1;
}

void printNode_BST(elementtype_BST data);
//cai nay tu viet trong chuong trinh chinh
//vi du elementtype la int
//{
//  printf("%*d",ElementLength,data);
//}

void moveto(int l)
{
  for (int i = l; i < height; i++)
    {
      for (int j=0; j<ElementLength; j++) printf(" ");
      printf("  ");
    }
  //getchar();
}

void fill(int l)
{
  for (int i=l-2; i>=0; i--)
    {
      for (int j=0; j<ElementLength; j++) printf(" ");
      printf(" ");
      if (needline[i] == 1) printf("%s","\u2502");
      else printf(" ");
    }
}

void draw(NODE_BST *p,NODE_BST *parent,int h,int pos)
{
  if (p == NULL) return;
  if (h == height)
    {
      printf(" ");
      printNode_BST(p->data);
      if (parent != NULL)
	{
	  printf("%s","\u2500");
	  if (p == parent->left)
	    printf("%s","\u2510");
	  else if (p == parent->right)
	    printf("%s","\u2518");
	}
      if (pos == LEFT && last[h-1] == 0) needline[h-1] = 1; else
	if (pos == RIGHT && last[h-1] == 1) needline[h-1] = 0;
      fill(h);
      printf("\n");
      return;
    }
  last[h] = 0;
  needline[h] = 0;
  if (pos == RIGHT && last[h-1] == 1) needline[h-1] = 1; else if (pos == LEFT && last[h-1] == 0) needline[h-1] = 0;
  draw(p->left,p,h+1,LEFT);
  last[h] = 1;
  moveto(h);
  if (p->left != NULL && p->right != NULL) printf("%s","\u251C");
  else if (p->left == NULL && p->right != NULL) printf("%s","\u250C");
  else if (p->left != NULL && p->right == NULL) printf("%s","\u2514");
  else printf(" ");
  printNode_BST(p->data);
  if (parent != NULL)
      {
	printf("%s","\u2500");
	if (p == parent->left)
          printf("%s","\u2510");
	else if (p == parent->right)
          printf("%s","\u2518");
      }
  last[h]=1;
  if (pos == LEFT && last[h-1] == 0) needline[h-1] = 1; else if (pos == RIGHT && last[h-1] == 1) needline[h-1] = 0;
  fill(h);
  printf("\n");
  draw(p->right,p,h+1,RIGHT);
  needline[h] = 0;
}

void drawTree(NODE_BST *p)
{
  height = getHeight(p);
  draw(p,NULL,0,-1);
}
