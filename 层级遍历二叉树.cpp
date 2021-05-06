#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

typedef char TElemType;
//�������Ķ�������洢��ʾ
typedef struct BiTNode {
   TElemType data;                      //���������
   struct BiTNode *lchild, *rchild; //���Һ���ָ��
} BiTNode, *BiTree;

typedef struct QNode {
  BiTree data ;
  struct QNode *next ;
}QNode , *QueuePtr ;

typedef struct {
  QueuePtr front ;//��ͷָ��
  QueuePtr rear ;//��βָ��
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
   //�������������������н���ֵ��һ���ַ������������������ʾ�Ķ�����T
   TElemType ch;

   //�˴��ͽ̲ĵĲ�ͬ�ǣ�Ҫ����������ݣ�����ch�������EOF��Ӧ�ý�������
   //����main������while(1)
   if(!(cin >> ch)) exit(0);       //�ô����滻�̲��ϵ���䣺cin>>ch;   ʵ��������ʧ�ܾ��˳���������ѭ����
   /****�ڴ�������ɴ���***************/
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
   /****�ڴ�������ɴ���***************/
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
