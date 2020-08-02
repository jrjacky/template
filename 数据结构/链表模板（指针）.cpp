#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<cstring>
#include<cctype>
using namespace std;
#define o 666
#define _ 233
#define QAQ (o^_^o)
struct node
{
	int data;
	node *next;
	node(){
		next=NULL
	}
}*head;
void print()
{
	node *p=head;
	while(p->next!=NULL){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
void insert1(int ch1)                  //在头结点插入 
{
	node *p=new node();
	p->data=ch1;
	p->next=head;
	head=p;
}
void insert2(int ch1,int ch2)          //在ch1的前面插入ch2
{
	node *p=head,*pre=NULL;
	while(p!=NULL&&p->data!=ch1){
		pre=p;
		p=p->next;
	}
	if(p!=NULL){
		pre->next=new node();
		pre->next->data=ch2;
		pre->next->next=p;
	}
}
void del(int ch)
{
	node *p=head,*pre=NULL;
	while(p!=NULL&&p->data!=ch){
		pre=p;
		p->next;
	}
	if(p!=NULL){
		pre->next=p->next;
		delete p;
	}
}
int main()
{
	head=new node();
	...... 
  return QAQ;
}
