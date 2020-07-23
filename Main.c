#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>


void database(FILE * fPtr,char FilePath[17], char code[100][15], char name[100][100], char date[100][20], char point[100][10], int* ptr)
{
    
/*----------------------------Get student data------------------------------*/
// Constant Variables
	int k=0,linetxt=0;
	
//Number of students exist
	char line[256];
	fPtr = fopen(FilePath, "r");
	while(fgets(line, sizeof line, fPtr) != NULL){
				(*ptr)++;		
		}
		printf("%d",*ptr);
	fclose(fPtr);
	
/*===========================Reload student data==============================*/
	while(1){
		fPtr = fopen(FilePath, "r");
	
		char n[256],Scode[10],Sname[50],Sdate[50],Spoint[50];
		char word[256];
	//Reset variables
		memset(word,0,sizeof word);
		memset(Scode,0,sizeof Scode);
		memset(Sname,0,sizeof Sname);
		memset(Sdate,0,sizeof Sdate);
		memset(Spoint,0,sizeof Spoint);
		int cot=0,j=0;
	
	//Copy data to n
	   	while(fgets(word, sizeof word, fPtr) != NULL){
			if(cot==linetxt){
				strcpy(n,word);
				printf("%s\n",n);
				fclose(fPtr);
			}
			else{
				cot++;
			}
		}
//		puts(n);

/*-------------------------End Copy data-----------------------------*/	
		
		char* p;
	//Student Code: find
		p = strstr(n,"Code:");
		do{
			Scode[j]=p[j+5];
			j++;
		}while(p[j+5]!=',');
	
		j=0;
		strcpy(code[k],Scode);
		
	//Student Name: find
		p = strstr(n,"Name:");
		do{
			Sname[j]=p[j+5];
			j++;
		}while(p[j+5]!=',');
	
		j=0;
		strcpy(name[k],Sname);
	
	//Student Date: find
		p = strstr(n,"Date:");
	
		do{
			Sdate[j]=p[j+5];
			j++;
		}while(p[j+5]!=',');
		
		j=0;
		strcpy(date[k],Sdate);
	
	//Student Point: find
		p = strstr(n,"Point:");
	
		do{
			Spoint[j]=p[j+6];
			j++;
		}while(p[j+6]!=';');
	
		j=0;
		strcpy(point[k],Spoint);
		
	//Go to next student
		k++;
		linetxt++;
		if(k==(*ptr)){
			
			return;
		}
	}
}

void AppendData(FILE * fPtr,char FilePath[17], char code[15], char name[100], char date[20], char point[10], int* count){
	fPtr = fopen(FilePath, "a");
	
	fprintf(fPtr,"Code:%s,Name:%s,Date:%s,Point:%s;\n",code,name,date,point);
	
	fclose(fPtr);

    return;
}



void textColor(int x) {
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

void gotoxy(int x, int y)
{
    static HANDLE h = NULL;  
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };  
    SetConsoleCursorPosition(h,c);
}

void delay(int number_of_seconds) 
{ 
    int milli_seconds = 10 * number_of_seconds; 
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds); 
}

void about(){
	system("cls");
	textColor(2);
	gotoxy(32, 4);
	printf(" @@@@@@   @@@@@@@    @@@@@@   @@@  @@@  @@@@@@@");
	gotoxy(32, 5);
	printf("@@@@@@@@  @@@@@@@@  @@@@@@@@  @@@  @@@  @@@@@@@");
	gotoxy(32, 6);
	printf("@@!  @@@  @@!  @@@  @@!  @@@  @@!  @@@    @@!");
	gotoxy(32, 7);
	printf("!@!  @!@  !@   @!@  !@!  @!@  !@!  @!@    !@!");
	gotoxy(32, 8);
	printf("@!@!@!@!  @!@!@!@   @!@  !@!  @!@  !@!    @!!");
	gotoxy(32, 9);
	printf("!!!@!!!!  !!!@!!!!  !@!  !!!  !@!  !!!    !!!");
	gotoxy(32, 10);
	printf("!!:  !!!  !!:  !!!  !!:  !!!  !!:  !!!    !!:");
	gotoxy(32, 11);
	printf(":!:  !:!  :!:  !:!  :!:  !:!  :!:  !:!    :!:");
	gotoxy(32, 12);
	printf("::   :::   :: ::::  ::::: ::  ::::: ::     ::");
	gotoxy(32, 13);
	printf(" :   : :  :: : ::    : :  :    : :  :      :");
	textColor(7);
	gotoxy(23,16);
	printf("Members : ");
	gotoxy(23,17);
	printf(" + Dao Huu Duc");
	gotoxy(23,18);
	printf(" + Tran Nhi Hao");
	gotoxy(23,19);
	printf(" + Tran Dang Khoa");
	gotoxy(23,20);
	printf(" + Nguyen Minh Quan");
	gotoxy(23,21);
	printf(" + Nguyen Nam Hoang Long");
	
	int color = 0;
	
	while (kbhit() != 1){
		textColor(3);
		gotoxy(32, 4);
		printf(" @@@@@@   @@@@@@@    @@@@@@   @@@  @@@  @@@@@@@");
		delay(5);
		gotoxy(32, 5);
		printf("@@@@@@@@  @@@@@@@@  @@@@@@@@  @@@  @@@  @@@@@@@");
		delay(5);
		gotoxy(32, 6);
		printf("@@!  @@@  @@!  @@@  @@!  @@@  @@!  @@@    @@!");
		delay(5);
		gotoxy(32, 7);
		printf("!@!  @!@  !@   @!@  !@!  @!@  !@!  @!@    !@!");
		delay(5);
		gotoxy(32, 8);
		printf("@!@!@!@!  @!@!@!@   @!@  !@!  @!@  !@!    @!!");
		delay(5);
		gotoxy(32, 9);
		printf("!!!@!!!!  !!!@!!!!  !@!  !!!  !@!  !!!    !!!");
		delay(5);
		gotoxy(32, 10);
		printf("!!:  !!!  !!:  !!!  !!:  !!!  !!:  !!!    !!:");
		delay(5);
		gotoxy(32, 11);
		printf(":!:  !:!  :!:  !:!  :!:  !:!  :!:  !:!    :!:");
		delay(5);
		gotoxy(32, 12);
		printf("::   :::   :: ::::  ::::: ::  ::::: ::     ::");
		delay(5);
		gotoxy(32, 13);
		printf(" :   : :  :: : ::    : :  :    : :  :      :");
		delay(5);
		textColor(7);
		delay(100);
		textColor(2);
		gotoxy(32, 4);
		printf(" @@@@@@   @@@@@@@    @@@@@@   @@@  @@@  @@@@@@@");
		delay(5);
		gotoxy(32, 5);
		printf("@@@@@@@@  @@@@@@@@  @@@@@@@@  @@@  @@@  @@@@@@@");
		delay(5);
		gotoxy(32, 6);
		printf("@@!  @@@  @@!  @@@  @@!  @@@  @@!  @@@    @@!");
		delay(5);
		gotoxy(32, 7);
		printf("!@!  @!@  !@   @!@  !@!  @!@  !@!  @!@    !@!");
		delay(5);
		gotoxy(32, 8);
		printf("@!@!@!@!  @!@!@!@   @!@  !@!  @!@  !@!    @!!");
		delay(5);
		gotoxy(32, 9);
		printf("!!!@!!!!  !!!@!!!!  !@!  !!!  !@!  !!!    !!!");
		delay(5);
		gotoxy(32, 10);
		printf("!!:  !!!  !!:  !!!  !!:  !!!  !!:  !!!    !!:");
		delay(5);
		gotoxy(32, 11);
		printf(":!:  !:!  :!:  !:!  :!:  !:!  :!:  !:!    :!:");
		delay(5);
		gotoxy(32, 12);
		printf("::   :::   :: ::::  ::::: ::  ::::: ::     ::");
		delay(5);
		gotoxy(32, 13);
		printf(" :   : :  :: : ::    : :  :    : :  :      :");
		textColor(7);
		delay(100);
	}
	
	getch();
	system("cls");
}

void menu(int n){
	textColor(n);
	gotoxy(6,4);
	printf("   _____ _             _            _     __  __                                                   _   ");
	gotoxy(6,5);
	printf("  / ____| |           | |          | |   |  \\/  |                                                 | |  ");
	gotoxy(6,6);
	printf(" | (___ | |_ _   _  __| | ___ _ __ | |_  | \\  / | __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_ ");
	gotoxy(6,7);
	printf("  \\___ \\| __| | | |/ _` |/ _ \\ '_ \\| __| | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '_ ` _ \\ / _ \\ '_ \\| __|");
	gotoxy(6,8);
	printf("  ____) | |_| |_| | (_| |  __/ | | | |_  | |  | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_ ");
	gotoxy(6,9);
	printf(" |_____/ \\__|\\__,_|\\__,_|\\___|_| |_|\\__| |_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_| |_| |_|\\___|_| |_|\\__|");
	gotoxy(6,10);
	printf("                                                                    __/ |                              ");
	gotoxy(6,11);
	printf("                                                                   |___/                               ");
	gotoxy(6,13);
	printf("__________________________________________________________________________________________________________");
	textColor(7);
}

void sidemenu(int n){
	gotoxy(40, 3);   //TOP LEFT
	printf("%c", 201);
	
	gotoxy(111, 3);   //TOP RIGHT
	printf("%c",187);
	
	gotoxy(40, n);  // BOTTOM LEFT
	printf("%c", 200);
	
	gotoxy(111, n);   // BOTTOM RIGHT
	printf("%c", 188);
	
	gotoxy(41, 3);    //TOP LINE
	for (int i = 0; i < 70; i++){
		printf("%c",205);
	}
	
	gotoxy(41, n);   // BOTTOM LINE
	for (int i = 0; i < 70; i++){
		printf("%c",205);
	}
	
	for (int i = 4; i < n; i++){
		gotoxy(40, i);       // VERTICAL LEFT
		printf("%c", 186);
	}
	
	for (int i = 4; i < n; i++){
		gotoxy(111, i);      // VERTICAL RIGHT
		printf("%c", 186);
	}
}
void menuPrintAll(char code[100][15], char name[100][100], char date[100][20], char point[100][10], int count){
	sidemenu(24);
	
	gotoxy(45, 5);
	textColor(12);
	printf("                        Students List                        ");
	textColor(7);
	gotoxy(45, 6);
	
	for (int i = 0; i < 61; i++) 
	{
		if (i == 0 || i == 11 || i == 30 || i == 50 || i == 60) printf("%c", 206);
		else printf("%c",205);
	}
	
	
	gotoxy(45, 7);
	printf("%c   Code   %c       Name       %c   Date of Birth   %c  Point  %c", 186, 186, 186, 186, 186);
	gotoxy(45 , 8);
	printf("");
	
	gotoxy(45, 8);
	for (int i = 0; i < 61; i++) 
	{
		if (i == 0 || i == 11 || i == 30 || i == 50 || i == 60) printf("%c", 206);
		else printf("%c",205);
	}
	
	for (int i = 0; i < count; i++){
		gotoxy(45, 9 + i);
		printf("%c%10s%c%18s%c%19s%c%9s%c", 186, code[i], 186, name[i], 186, date[i], 186, point[i], 186);
	}
		getch();
	system("cls");	
}

void menuSearch(){
	char* type[30] = {"Code", "Name", "Date of Birth", "Point"};
	int pointer = 0;
	sidemenu(24);
	gotoxy(45, 5);
	printf("Find using : ");
	gotoxy(45, 8);
	printf("[Up] [Down] : Scroll through mode");
	gotoxy(45, 9);
	printf("[Enter] : Select.");
	do{
			for (int i = 0; i < 5; i++){              // Selected Menu //
			if (pointer == i){
				gotoxy(58, 5);
				textColor(10);
				printf("%s          ",type[i]);
				textColor(7);
			}
		}
		
		gotoxy(0, 0);
		
		int key = getch();
		if (key == 72){                  			// UP KEY //
			if ((pointer - 1) < 0) pointer = 3;
			else pointer -= 1;
		}
		if (key == 80){  								// DOWN KEY //
			if ((pointer + 1) > 3) pointer = 0;
			else pointer += 1;
		}
		if (key == 13){  							// ENTER KEY //
			if (pointer == 0) {
			searchUsing(1); break;
			}
			if (pointer == 1) {
			searchUsing(2); break;
			}	
			if (pointer == 2) {
			searchUsing(3); break;
			}
			if (pointer == 3) {
			searchUsing(4); break;
			}
			if (pointer == 4){
				system("cls");
				return;
			}
		}
	} while(1);
	getch();
	system("cls");	
}
void searchUsing(int type){
	gotoxy(45, 5);
	printf("                                         ");
	gotoxy(45, 8);
	printf("                                   ");
	gotoxy(45, 9);
	printf("                                             ");
	
	switch(type){
		case 1:{
			gotoxy(45, 5);
			printf("Code to find : ");
			break;
		}
		case 2:{
			gotoxy(45, 5);
			printf("Name to find : ");
			break;
		}
		case 3:{
			gotoxy(45, 5);
			printf("Date to find : ");
			break;
		}
		case 4:{
			gotoxy(45, 5);
			printf("Point to find : ");
			break;
		}
	}
	getch();
}

void menuAdd(char code[15], char name[100], char date[20], char point[10]){
	int lengthInput = 0;
	sidemenu(16);
	
	gotoxy(45, 5);
	textColor(12);
	printf("New Student");
	textColor(7);

	
	gotoxy(45, 8);
	textColor(10);
	printf("Student Code: ");
	textColor(7);
	while(1) {
		char key = getch();
		if (key != 13) {
			if ( ('a' <= key && key <= 'z') || ('0' <= key && key <= '9') || ('A' <= key && key <= 'Z')) {
				if (0 <= lengthInput && lengthInput < 8) {
					code[lengthInput++] = key;
				}
				for (int i = 0; i < lengthInput; i++) {
					gotoxy(59 + i, 8);
					printf("%c", code[i]);
				}
			}
			if (key == 8) {		//Dell
				if (lengthInput > 0) {
					gotoxy(59 + lengthInput - 1, 8);
					printf(" ");
					lengthInput--;
					code[lengthInput] = '\0';
					gotoxy(59 + lengthInput, 8);
				}
			}
		} else {					//Enter
			if (lengthInput == 8) {
				code[lengthInput] = '\0';
				lengthInput = 0;
				break;
			}
		}
	}

		
	gotoxy(45, 10);
	textColor(10);
	printf("Name: ");
	textColor(7);
	while(1) {
		char key = getch();
		if (key != 13) {
			if ( ('a' <= key && key <= 'z') || key == ' ' || ('A' <= key && key <= 'Z')) {
				if (0 <= lengthInput && lengthInput < 35) {
					name[lengthInput++] = key;
				}
				for (int i = 0; i < lengthInput; i++) {
					gotoxy(51 + i, 10);
					printf("%c", name[i]);
				}
			}
			if (key == 8) {		//Enter
				if (lengthInput > 0) {
					gotoxy(51 + lengthInput - 1, 10);
					printf(" ");
					lengthInput--;
					name[lengthInput] = '\0';
					gotoxy(51 + lengthInput, 10);
				}
			}
		} else {					//Enter
			if (lengthInput > 0) {
				name[lengthInput] = '\0';
				lengthInput = 0;
				break;
			}
		}
	}
	
	gotoxy(45, 12);
	textColor(10);
	printf("Date of Birth: ");
	textColor(7);
	while(1) {
		int day = 0, month = 0, year = 0;
		int num1, num2, num3, num4;
		char key = getch();
		if (key != 13) {
			if ('0' <= key && key <= '9') {
				if (0 <= lengthInput && lengthInput < 10) {
					date[lengthInput++] = key;
					if(lengthInput == 2 || lengthInput == 5) {
						date[lengthInput++] = '/';
					} else if(lengthInput == 4 && date[0] == '0' && date[1] == '0' ) {
						date[--lengthInput] = '\0';
						date[--lengthInput] = '\0';
						date[--lengthInput] = '\0';
					} else if(lengthInput == 7 && date[3] == '0' && date[4] == '0' ) {
						date[--lengthInput] = '\0';
						date[--lengthInput] = '\0';
						date[--lengthInput] = '\0';
					} else if(lengthInput == 10 && date[6] == '0' && date[7] == '0' && date[8] == '0' && date[9] == '0') {
						date[--lengthInput] = '\0';
						date[--lengthInput] = '\0';
						date[--lengthInput] = '\0';
					}
				}
				for (int i = 0; i < lengthInput; i++) {
					gotoxy(60 + i, 12);
					printf("%c", date[i]);
				}
				
			}
			if (key == 8) {		//Del
				if (lengthInput > 0) {
					gotoxy(60 + lengthInput - 1, 12);
					printf(" ");
					lengthInput--;
					date[lengthInput] = '\0';
					gotoxy(60 + lengthInput, 12);
					if(lengthInput == 3 || lengthInput == 6) {
						gotoxy(60 + lengthInput - 1, 12);
						printf(" ");
						lengthInput--;
						date[lengthInput] = '\0';
						gotoxy(60 + lengthInput, 12);
					}
				}
			}
		} else {					//Enter
			if (lengthInput == 10) {
				//Change char day to integer
				num1 = num2 = num3 = num4 = 0;
				num1 = date[0] - 48;
				num2 = date[1] - 48;
				day = num1 * 10 + num2;
				//Change char month to integer
				num1 = num2 = num3 = num4 = 0;
				num1 = date[3] - 48;
				num2 = date[4] - 48;
				month = num1 * 10 + num2;
				//Change char day to integer
				num1 = num2 = num3 = num4 = 0;
				num1 = date[6] - 48;
				num2 = date[7] - 48;
				num3 = date[8] - 48;
				num4 = date[9] - 48;
				year = num1 * 1000 + num2 * 100 + num3 * 10 + num4;
				
				date[lengthInput] = '\0';
				lengthInput = 0;
				puts(date);
				getch();
				break;
			}
		}
		
	}
	
	gotoxy(45, 14);
	textColor(10);
	printf("Learning Point: ");
	textColor(7);
	int count = 0;
	while(1) {
		char key = getch();
		if (key != 13) {
			if ('0' <= key && key <= '9' || key == '.') {
				if (0 <= lengthInput && lengthInput < 5) {
					if(key == '.' ) {
						if(count == 0 && lengthInput != 0) {
							point[lengthInput++] = key;
							count = 1;
						} else {
						}
					} else if(key == '0') {
						if(lengthInput != 0) {
							point[lengthInput++] = key;	
						}
					} else if('2' <= key && key <= '9' && lengthInput == 0) {
						point[lengthInput++] = key;
						point[lengthInput++] = '.';
						count = 1;
					} else if(lengthInput == 1 && point[0] == '1' && '1' <= key && key <= '9') {
						continue;
					} else {
						point[lengthInput++] = key;	
					}
					if(lengthInput == 2 && point[0] == '1' && point[1] == '0') {
//						point[lengthInput++] = '.';
						count = 1;
					}
				
				}
				for (int i = 0; i < lengthInput; i++) {
					gotoxy(61 + i, 14);
					printf("%c", point[i]);
				}
			}
			if (key == 8) {		//Del
				if (lengthInput > 0) {
					if(point[lengthInput - 1] == '.') {
						count = 0;
						gotoxy(61 + lengthInput - 1, 14);
						printf(" ");
						lengthInput--;
						point[lengthInput] = '\0';
						gotoxy(61 + lengthInput, 14);	
					}
					gotoxy(61 + lengthInput - 1, 14);
					printf(" ");
					lengthInput--;
					point[lengthInput] = '\0';
					gotoxy(61 + lengthInput, 14);
				}
			}
		} else {					//Enter
			if (lengthInput > 0) {
				if(point[lengthInput - 1] == '.');
					point[lengthInput++] = '0';
				point[lengthInput] = '\0';
				lengthInput = 0;
				break;
			}
		}
	}
//	getch();
	system("cls");	   
}
void menuRemove(){
	
}
void start(FILE * fPtr, char FilePath[17], char code[100][15], char name[100][100], char date[100][20], char point[100][10], int* count){            // Menu After Start
	char* choices[] = {"View All Students", "Find a student", "Add a student", "Remove a student", "Exit"};
	int pointer;
	system("cls");
	while (1){
		// BOX IN MENU //
													// HORIZONTAL
		gotoxy(8, 3);
		for (int i = 0; i < 25; i++){
			printf("%c",205);
		}
		
		gotoxy(8, 7);
		for (int i = 0; i < 25; i++){
			printf("%c", 205);
		}
		
		gotoxy(8, 11);
		for (int i = 0; i < 25; i++){
			printf("%c", 205);
		}
		
		gotoxy(8, 15);
		for (int i = 0; i < 25; i++){
			printf("%c", 205);
		}
		
		gotoxy(8, 19);
		for (int i = 0; i < 25; i++){
			printf("%c", 205);
		}
		
		gotoxy(8, 23);
		for (int i = 0; i < 25; i++){
			printf("%c", 205);
		}
													// VERTICAL
													
		for (int i = 1; i < 20; i++){
			gotoxy(7, 3 + i);
			printf("%c", 186);
		}
		
		for (int i = 1; i < 20; i++){
			gotoxy(33, 3 + i);
			printf("%c", 186);
		}
		
		                                             // CORNER
		                                        
		gotoxy(7, 3);                        //TOP LEFT
		printf("%c", 201);              
		
		gotoxy(33, 3);                       // TOP RIGHT
		printf("%c", 187);               
		
		gotoxy(7, 23);                       // BOTTOM LEFT
		printf("%c", 200);
		
		gotoxy(33, 23);                       // BOTTOM RIGHT
		printf("%c", 188);
		
		for (int i = 0; i < 5; i++){              // Selected Menu //
			if (pointer == i){
				gotoxy(10, 5 + i*4);
				textColor(11);
				printf(">>> %s",choices[i]);
				textColor(7);
			}
			else{									// Unselected Menu //
				gotoxy(10,5 + i*4);
				printf("%s     ",choices[i]);
			}
		}
		
		gotoxy(0, 0);
		
		int key = getch();
		if (key == 72){                  			// UP KEY //
			if ((pointer - 1) < 0) pointer = 4;
			else pointer -= 1;
		}
		if (key == 80){  								// DOWN KEY //
			if ((pointer + 1) > 4) pointer = 0;
			else pointer += 1;
		}
		if (key == 13){  							// ENTER KEY //
			if (pointer == 0) menuPrintAll(code, name, date, point, *count);
			if (pointer == 1) menuSearch();
			if (pointer == 2) {
				menuAdd(code[*count], name[*count], date[*count], point[*count]);
				AppendData(fPtr, FilePath, code[*count], name[*count], date[*count], point[*count], *count);
				(*count)++;
			}
			if (pointer == 3) menuRemove();
			if (pointer == 4){
				system("cls");
				return;
			}
		}
	}

}

void goodbye(){
	system("cls");
}

void firstmenu(){
	char* sel[] = {"Start", "About", "Donate", "Quit"};
	FILE * fPtr;
	char FilePath[17]="Data/Student.txt";
	char code[100][15];
	char name[100][100];
	char date[100][20];
	char point[100][10];
	int count = 0;
	int pointer = 0;
	int key;
	database(fPtr, FilePath, code, name, date, point,&count);
	system("cls");                        
	while (1){ 
		
		menu(10);                //  Print out menu header  //
		for (int i = 0; i < 4; i++){              // Selected Menu //
			if (pointer == i){
				gotoxy(50,17 + i*3);
				textColor(11);
				printf(">>> %s",sel[i]);
				textColor(7);
			}
			else{									// Unselected Menu //
				gotoxy(50,17 + i*3);
				printf("%s               ",sel[i]);
			}
		}
		key = getch();
		if (key == 72){                  			// UP KEY //
			if ((pointer - 1) < 0) pointer = 3;
			else pointer -= 1;
		}
		if (key == 80){  								// DOWN KEY //
			if ((pointer + 1) > 3) pointer = 0;
			else pointer += 1;
		}
		if (key == 13){  							// ENTER KEY //
			if (pointer == 0) start(fPtr, FilePath, code, name, date, point, &count);
			if (pointer == 1) about();
			if (pointer == 2){
				gotoxy(80, 23);
				printf("Just for fun =DDD");
				getch();
				gotoxy(80, 23);
				printf("                        ");
			}
			if (pointer == 3) exit(1);
		}
	}
}

void loading(){
	
	gotoxy(20, 3);   //TOP LEFT
	printf("%c", 201);
	
	gotoxy(100, 3);   //TOP RIGHT
	printf("%c",187);
	
	gotoxy(20, 6);  // BOTTOM LEFT
	printf("%c", 200);
	
	gotoxy(100, 6);   // BOTTOM RIGHT
	printf("%c", 188);
	
	gotoxy(21, 3);    //TOP LINE
	for (int i = 0; i < 79; i++){
		printf("%c",205);
	}
	
	gotoxy(21, 6);   // BOTTOM LINE
	for (int i = 0; i < 79; i++){
		printf("%c",205);
	}
	
	for (int i = 4; i < 6; i++){
		gotoxy(20, i);       // VERTICAL LEFT
		printf("%c", 186);
	}
	
	for (int i = 4; i < 6; i++){
		gotoxy(100, i);      // VERTICAL RIGHT
		printf("%c", 186);
	}

	textColor(2);
	gotoxy(99, 8);
	printf("Loading...");
	textColor(7);
	
	textColor(2);
	for(int i = 21; i < 100; i++){
		gotoxy(i, 4);
		printf("%c",219);
		gotoxy(i, 5);
		printf("%c",219);
		delay(1);
	}
	textColor(7);
	
	textColor(2);
	gotoxy(99, 8);
	printf("Complete....");
	textColor(7);

	delay(100);
//	
}

int main(){
//	loading();
	firstmenu();
}

