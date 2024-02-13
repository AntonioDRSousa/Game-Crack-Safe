#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void title(){
	system("title Crack The Safe");
	printf("===================================================================== \n");
	printf("!                         Crack The Safe                            ! \n");
	printf("===================================================================== \n\n");
}

void help(){
	printf("------------------ \n");
	printf("HELP \n\n");
	printf("The objective of this game is find the correct numbers for open the safe. \n");
	printf("The numbers of safe are showed for player and you can take actions for crack this safe. \n");
	printf("This actions are take by one character in command line. \n");
	printf("If you write '1', '2' or '3' character then you select one wheel for rotate. \n");
	printf("After this selection, you can write '-' or '+', \n");
	printf("these characters indicate the direction of rotation. \n");
	printf("If you not select one of the wheels, \n");
	printf("you can test if number of wheels is the real number that open the safe, by write 'c'. \n");
	printf("Each attempt to test the number increase by 1. \n");
	printf("You win if you find the correct number that open the safe. \n\n");
	printf("------------------ \n");
}

void new_game(){
	printf("new game\n\n");
	int num = 10;
	int r1 = rand() % num;
	int r2 = rand() % num;
	int r3 = rand() % num;
	
	int attemps = 0;
	int x1 = 0; 
	int x2 = 0; 
	int x3 = 0;
	
	char c , d;
	
	while(1){
		printf("========================================================\n");
		printf("%d%d%d\n",x1,x2,x3);
		printf("attemps = %d\n",attemps);
		
		fflush(stdin);
		printf("\nup '+' or down '-' wheel : ");
		scanf("%c",&d);
		fflush(stdin);
		
		int sgn;
		if(d=='+'){
			sgn = 1;
		}
		else if(d=='-'){
			sgn = -1;
		}
		else{
			printf("Error .....\n");
			continue;
		}
		
		printf("\nwrite 1,2,3 for select wheel to rotate : ");
		scanf("%c",&c);
		fflush(stdin);
		
		if(c=='1'){
			x1+=sgn;
		}
		else if(c=='2'){
			x2+=sgn;
		}
		else if(c=='3'){
			x3+=sgn;
		}
		else{
			printf("Error .....\n");
			continue;
		}
		
		attemps++;
		
		if((x1==r1)&&(x2==r2)&&(x3==r3)){
			printf("You Win in %d attemps\n",attemps);
			break;
		}
		printf("========================================================\n");
	}
}

void menu(){
	for(;;){
		printf("----------------------\n");
		printf("[1] New Game \n");
		printf("[2] Help \n");
		printf("[3] Quit \n");
		printf("----------------------\n");
		int op;
		scanf("%d",&op);
		switch(op){
			case 1:
				new_game();
				break;
			case 2:
				help();
				break;
			case 3:
				exit(0);
				break;
			default:
				printf("Invalid Options .....\n");
		}
	}
}

int main(){
	title();
	srand(time(NULL));
	menu();
	system("pause");
	return 0;
}