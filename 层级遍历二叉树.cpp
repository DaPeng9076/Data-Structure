#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

typedef char TElemType;
//二叉树的二叉链表存储表示
typedef struct BiTNode {
   TElemType data;                      //结点数据域
   struct BiTNode *lchild, *rchild; //左右孩子指针
} BiTNode, *BiTree;

typedef struct QNode {
  BiTree data ;
  struct QNode *next ;
}QNode , *QueuePtr ;

typedef struct {
  QueuePtr front ;//队头指针
  QueuePtr rear ;//队尾指针
}LinkQueue ;

void InitQueue(LinkQueue& Q)
{
  Q.front = Q.rear = new QNode ;
  Q.front->next = NULL ;
}

void EnQueue(LinkQueue& Q , BiTree& T)
{
  QueuePtr p ;
  p = new QNode ;
  p->data = T ;
  p->next = NULL ;
  Q.rear->next = p ;
  Q.rear = p ;
}

void DeQueue(LinkQueue&Q , BiTree& T)
{
  QueuePtr p ;
  if(Q.front == Q.rear) return ;
  p = Q.front->next ;
  T = p->data ;
  Q.front->next = p->next ;
  if(Q.rear==p) Q.rear = Q.front ;
  delete p ;
}

int EmptyQueue(LinkQueue& Q)
{
  if(Q.front == Q.rear) return 1 ;
  else return 0 ;
}

void CreateBiTree(BiTree &T)
{
   //按先序次序输入二叉树中结点的值（一个字符），创建二叉链表表示的二叉树T
   TElemType ch;

   //此处和教材的不同是，要处理多组数据，输入ch如果遇到EOF，应该结束程序
   //所以main函数用while(1)
   if(!(cin >> ch)) exit(0);       //用此行替换教材上的语句：cin>>ch;   实现若读入失败就退出，避免死循环。
   /****在此下面完成代码***************/
    if(ch=='#') T = NULL ;
    else {
      T = new BiTNode ;
      T->data = ch ;
      CreateBiTree(T->lchild);
      CreateBiTree(T->rchild);
    }
   /***********************************/
}   //CreateBiTree

void TraveTree(LinkQueue& Q){
  BiTree T ;
  while(!EmptyQueue(Q)) {
    DeQueue(Q,T);
    if(T->lchild != NULL ) EnQueue(Q,T->lchild) ;
    if (T->rchild != NULL ) EnQueue(Q,T->rchild) ;
    printf(" %c",T->data) ;
  }
  
}

void DestroyBitree(BiTree& T)
{
   /****在此下面完成代码***************/
    if(T){
      DestroyBitree(T->lchild);
      DestroyBitree(T->rchild);
      delete T ;
    }
   /***********************************/
}

int main()
{
   LinkQueue Q ;
   BiTree tree;
   while(1) {
      InitQueue(Q) ;
      CreateBiTree(tree);
      if(tree != NULL)
        EnQueue(Q,tree);
      TraveTree(Q) ;
      cout << endl;
      DestroyBitree(tree);
   }
}
