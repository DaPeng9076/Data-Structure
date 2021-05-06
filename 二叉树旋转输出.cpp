#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

typedef char TElemType;
//二叉树的二叉链表存储表示
typedef struct BiTNode {
   string data;                      //结点数据域
   struct BiTNode *lchild, *rchild; //左右孩子指针
} BiTNode, *BiTree;

void CreateBiTree(BiTree &T)
{
   //按先序次序输入二叉树中结点的值（一个字符），创建二叉链表表示的二叉树T
   string ch;

   //此处和教材的不同是，要处理多组数据，输入ch如果遇到EOF，应该结束程序
   //所以main函数用while(1)
   if(!(cin >> ch)) exit(0);       //用此行替换教材上的语句：cin>>ch;   实现若读入失败就退出，避免死循环。
   /****在此下面完成代码***************/
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
   BiTree tree;
   int num = 0 ;
   while(1) {
      CreateBiTree(tree);
      OutPut(tree,num) ;
      cout << endl;
      DestroyBitree(tree);
   }
}
