#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

typedef char TElemType;
//�������Ķ�������洢��ʾ
typedef struct BiTNode {
   string data;                      //���������
   struct BiTNode *lchild, *rchild; //���Һ���ָ��
} BiTNode, *BiTree;

void CreateBiTree(BiTree &T)
{
   //�������������������н���ֵ��һ���ַ������������������ʾ�Ķ�����T
   string ch;

   //�˴��ͽ̲ĵĲ�ͬ�ǣ�Ҫ����������ݣ�����ch�������EOF��Ӧ�ý�������
   //����main������while(1)
   if(!(cin >> ch)) exit(0);       //�ô����滻�̲��ϵ���䣺cin>>ch;   ʵ��������ʧ�ܾ��˳���������ѭ����
   /****�ڴ�������ɴ���***************/
    if(ch[0]=='#') T = NULL ;
    else {
      T = new BiTNode ;
      T->data = ch ;
      CreateBiTree(T->lchild);
      CreateBiTree(T->rchild);
    }
   /***********************************/
}   //CreateBiTree

void OutPut(BiTree& T , int num )
{
  if(T == NULL) return ;
  else{
    OutPut(T->rchild,num+1);
    for( int i = 0 ; i < num ; i ++ ){
      printf("    ");
    }
    for( int i = 0 ; i < T->data.size();i++){
    	printf("%c",T->data[i]);
	}
	printf("\n");
    OutPut(T->lchild,num+1);
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
   BiTree tree;
   int num = 0 ;
   while(1) {
      CreateBiTree(tree);
      OutPut(tree,num) ;
      cout << endl;
      DestroyBitree(tree);
   }
}
