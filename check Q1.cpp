#include<iostream>


using namespace std;

class node{
	
	
	public:
	    node*next;
		node*previous;
		int coefficent;
		char variable;
		int exponent;
		
		node()
		{
			coefficent=0;
			variable;
			exponent=0;
			next=NULL;
//			previous=NULL;
		}
		
		
		node(int coeff, char var,int exp)
		{
			coefficent=coeff;
			variable=var;
			exponent=exp;
			next=NULL;
//			previous=NULL;
		}
};

class cdbly{
	public:
		node*head;
		int size;
		
		cdbly(){head=NULL;size=0;
		}
		void display()
		{
			if(head==NULL)
			{
				cout<<"Linklist is empty!\n";
				return;	
			}
			node*ptr=head;
			do{
				cout<<ptr->coefficent<<" "<<ptr->variable<<" "<<ptr->exponent<<endl;
				ptr=ptr->next;
			}while(ptr!=head);
		}
		void swap(node*curr,node*in)
		{
			int c,ex;
			char v;
			
				c=curr->coefficent;
				ex=curr->exponent;
				v=curr->variable;
				curr->coefficent=in->coefficent;
				curr->exponent=in->exponent;
				curr->variable=in->variable;
				in->coefficent=c;
				in->exponent=ex;
				in->variable=v;
						
		}
		void sort()
		{
			if(head==NULL)
				return;
			node*curr=head,*index=NULL;
			int count=0;
			
			do{
				index=curr->next;
				do{
					if(curr->variable<index->variable)//exponentonent sorting
						{
							count++;
							swap(curr,index);
							
						}	
					index=index->next;
					
				}while(index!=head);
				curr=curr->next;
			}while(curr!=head);
			if(count!=0)
				{
					do{
						index=curr->next;
						do{
							if(curr->variable==index->variable && curr->exponent>index->exponent )//variableiable sorting
								swap(curr,index);
							
							index=index->next;
							
						}while(index!=head);
						curr=curr->next;
					}while(curr!=head);
				}
				
				if(count==0)	
				{
					do{
						index=curr->next;
						do{
							if(curr->variable==index->variable && curr->exponent<index->exponent )//variableiable sorting
								swap(curr,index);
							
							index=index->next;
							
						}while(index!=head);
						curr=curr->next;
					}while(curr!=head);
				}
			}
				
		void addnode(int co,char va,int ex)
		{
			node* newn=new node(co,va,ex);
			if(head==NULL)
			{
				newn->next=newn;
				newn->previous=newn;
				head=newn;
				size++;
				return;
			}
			node*last=head->previous;
			newn->next=head;
			head->previous=newn;
			newn->previous=last;
			last->next=newn;
			size++;
		}
		
};

void sum(node*h1,node*h2,int *size)
	{
		node*l1=h1;
		node*l2=h2;
		
		do{
			do{
				if(l1->variable==l2->variable && l1->exponent==l2->exponent &&l2->coefficent!=999)
				{
					l1->coefficent=l1->coefficent+l2->coefficent;
					l2->coefficent=999;
				}
				l2=l2->next;
			}while(l2!=h2);
			
			
			l1=l1->next;
		}while(l1!=h1);
			do{
				if(l2->coefficent!=999)
				{
					node*newn=new node(l2->coefficent,l2->variable,l2->exponent);
					newn->next=l1->next;
					newn->previous=l1;
					newn->next->previous=newn;
					l1->next=newn;
					*size=*size+1;
				}
				l2=l2->next;
			}while(l2!=h2);
				
	}


int main()
{
	
	cdbly cd;
	
	int x;
	cin>>x;
	for(int i=0;i<x;i++)
	{
		int c,e;
		char v;
		cin>>c>>v>>e;
		cd.addnode(c,v,e);
	}
	int y;
	cin>>y;
	cdbly cdd;
	for(int i=0;i<y;i++)
	{
		int c,e;
		char v;
		cin>>c>>v>>e;
		cdd.addnode (c,v,e);
	}
	sum(cd.head,cdd.head,&cd.size);
	cd.sort();
	
	cout<<cd.size<<endl;
	cd.display();	
	

	
	return 0;
}