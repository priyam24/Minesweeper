#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctype.h>
#include<conio.h>
#include<time.h>

#define MAX 10

using namespace std;

void expand(int,int);
void display();
void display1();

char board[MAX][MAX];
int cn=0;
int main(){
	cout<<"----------WELCOME TO MINESWEEPER-----------\n";
	char ch='y';
	while(tolower(ch)=='y'){
		cn=0;
		srand(time(0));
		int m,coun=0;
		sec0:
		cout<<"\nCHOOSE DIFFICULTY : \n1) EASY \n2)MEDIUM \n3) HARD\n";
		cin>>m;
		if(m<1||m>3){
			system("cls");
			goto sec0;
		}
		if(m==1){
			for(int i=0;i<MAX;i++){
				for(int j=0;j<MAX;j++){
					int rx=rand();
					if(rx%7==0){
						board[i][j]='X';
					}
					else {
						board[i][j]='-';	
						cn++;
					}
				}
			}			
		}
		else if(m==2){
			for(int i=0;i<MAX;i++){
				for(int j=0;j<MAX;j++){
					int rx=rand();
					if(rx%5==0){
						board[i][j]='X';
					}
					else {
						board[i][j]='-';	
						cn++;
					}
				}
			}			
		}
		else{
			for(int i=0;i<MAX;i++){
				for(int j=0;j<MAX;j++){
					int rx=rand();
					if(rx%3==0){
						board[i][j]='X';
					}
					else {
						board[i][j]='-';	
						cn++;
					}
				}
			}
		}
		int flag=0;
		while(1){
			sec1:
			system("cls");
			display();
			cout<<"UNCOVER A CELL\n";
			cout<<"Give the 'x' & 'y' coordinates of the cell(indexing starts from '0')\n";
			int x,y;
			cin>>x>>y;
			if(x<0||x>=MAX||y<0||y>=MAX||(board[x][y]!='-'&&board[x][y]!='X')){
				goto sec1;
			}
			else{
				coun++;
				if(board[x][y]=='X'){
					system("cls");
					display1();
					flag=1;
					break;
				}
				else{
					expand(x,y);
					if(!cn){
						break;
					}
				}
			}
		}
			if(flag){
				cout<<"YOU LOSE!!!\nTOTAL MOVES = "<<coun<<endl;
			}
			else{
				cout<<"YOU WON!!!\nTOTAL MOVES = "<<coun<<endl;
			}
		cout<<"\nPRESS 'y' TO START NEW GAME : ";
		ch=getche();
		system("cls");
	}
}

void display(){
	cout<<"   ";
	for(int i=0;i<MAX;i++){
		cout<<i<<" ";
	}
	cout<<"\n";
		for(int i=0;i<MAX;i++){
			cout<<i<<"  ";
			for(int j=0;j<MAX;j++){
				if(board[i][j]=='X'){
					cout<<"- ";
				}
				else cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
}
void display1(){
	cout<<"   ";
	for(int i=0;i<MAX;i++){
		cout<<i<<" ";
	}
	cout<<"\n";	
		for(int i=0;i<MAX;i++){
			cout<<i<<"  ";			
			for(int j=0;j<MAX;j++){
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
}

void expand(int i,int j){
	if(board[i][j]=='-'){
		int c=0;
				for(int k=i-1;k<=i+1;k++){
					if(k<0||k>=MAX){
						continue;
					}					
					for(int p=j-1;p<=j+1;p++){
						if(p<0||p>=MAX){
							continue;
						}						
						if(board[k][p]=='X'){
							c++;
						}
					}
				}	
				if(c){
					board[i][j]=48+c;
					cn--;
				}	
				else{
				for(int k=i-1;k<=i+1;k++){
					if(k<0||k>=MAX){
						continue;
					}					
					for(int p=j-1;p<=j+1;p++){
						if(p<0||p>=MAX){
							continue;
						}						
						if(k==i&&p==j){
							board[k][p]='.';
							cn--;
						}
						else expand(k,p);
					}
				}					
				}
	}
}
