//21µã-v3£»

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int table[21];
int record[52] = {0};      //record the cards have been used ;if used,the relevant number is 1;
char poker[52][11] = {"Spade A","Spade 2","Spade 3","Spade 4","Spade 5","Spade 6","Spade 7","Spade 8","Spade 9","Spade 10","Spade J","Spade Q","Spade K",
						"Heart A","Heart 2","Heart 3","Heart 4","Heart 5","Heart 6","Heart 7","Heart 8","Heart 9","Heart 10","Heart J","Heart Q","Heart K",
						"Diamond A","Diamond 2","Diamond 3","Diamond 4","Diamond 5","Diamond 6","Diamond 7","Diamond 8","Diamond 9","Diamond 10","Diamond J","Diamond Q","Diamond K",
						"Club A","Club 2","Club 3","Club 4","Club 5","Club 6","Club 7","Club 8","Club 9","Club 10","Club J","Club Q","Club K"};
						//store the poker cards for printing;
						
void get_a_card(int &t,double &score);
void player_stage(int &p,double &p_score);
int computer_stage(int &c,double &c_score,int &p, double &p_score);

int main(){
	int c,p;                 //store how many cards have been got;
	double c_score,p_score;   		//store the scores;
	char judge = 'y';							//wether to start a new game;
	
	while(judge == 'y'){
		c=0;p=0;
		c_score=0;p_score=0;
		record[52] = {0};
										//for each game, these value should be new;
										// what would be printed is determined by 'p' or 'c',so it's not necessary to assign a new value to "table[]" ;
		srand(time(NULL));
		player_stage(p,p_score);
		if (p_score > 21){									//in this case, player must be the loser,game over;
			cout<<"\nyou lose!!!\n\n"<<"another game?(y/n):";
			cin>>judge;
			continue;                                    //computer needn't play;
		}
		computer_stage(c,c_score,p,p_score);
		cout<<"\nyou lose!!!\n\n"<<"another game?(y/n):";
		cin>>judge;
	}
	return 0;
}

void get_a_card(int &t,double &score){
	int num;
	
	num = rand()%52;
	while(record[num] != 0) num = rand()%52;		//record[i] ------ poker[i] 
	record[num] = 1;                              //the relevant card has been used ;
	table[t] = num;t++;                           // t: c or p, record the number of appeared cards;
	
	if (num%13 > 9) score += 0.5;
	else score += num%13 + 1.0;				//caculate the score;
}

void player_stage(int &p,double &p_score){
	char judge='y';
	
	get_a_card(p,p_score);
	get_a_card(p,p_score);
	cout<<"player:\nplayer's cards:";
	for(int i=0;i<p;i++) {cout<<poker[table[i]]<<"   ";} //at first, get two cards;
	
	while(judge == 'y' ||judge == 'Y'){
		cout<<"\nanother one card?(y/n):";
		cin>>judge;
		if (judge == 'y'){
			get_a_card(p,p_score);
			cout<<"\nplayer's cards:";
			for(int i=0;i<p;i++) {cout<<poker[table[i]]<<"   ";}
		}
		if (p_score > 21) break;  //game over;
	}
}

int computer_stage(int &c,double &c_score,int &p, double &p_score){    //int instead of void; so we can end it midway by 'return';
																	   //if the program use this fuction,p_score<21;
	char judge='y';
	
	cout << "\ncomputer Stage\ncomputer's cards: ";
	get_a_card(c,c_score); get_a_card(c,c_score);
	for(int i=0;i<c;i++) {cout<<poker[table[i]]<<"   ";}
	while (c_score < p_score || (c_score == p_score && c < p)){		//p_score must be less than 21 or the game is over;
		cout << "\ncomputer's cards: ";
		get_a_card(c,c_score);
		for(int i=0;i<c;i++) {cout<<poker[table[i]]<<"   ";}
	}
	if (c_score > 21 || (c_score == p_score && c > p)) {cout << "\nYou win!!\n\n"; return 0;}  //'return 0' to end the fuction;
	if (c_score > p_score || (c_score == p_score &&  c < p)) cout << "\nYou lose!!!\n\n";
	else cout << "\nTie\n\n";
	return 0;
}


