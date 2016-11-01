#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct PIKAPIKA{
	int code;
	char name[20];
	char element[10];
	struct PIKAPIKA * left;
	struct PIKAPIKA * right;
}poke;

poke * rootCODE;
poke * rootNAME;
poke * buffer;
poke * aux;

void opening();
void closing();
void strcopy(char * name1, char * name2);
int strcomp(char * name1, char * name2);
/////////////////////////////////////////////////////
void addCODE(char * name, int code, char * element){
	buffer = (poke *) malloc(sizeof(poke));
	
	strcopy(buffer->name, name);
	buffer->code = code;
	strcopy(buffer->element, element);
	buffer->right = NULL;
	buffer->left = NULL;
	
	if(rootCODE == NULL) rootCODE = buffer;
	else{
		aux = rootCODE;
		while(1){
			if(buffer->code < aux->code){
				if(aux->left == NULL){ 
					aux->left = buffer;
					break;
				}
				else aux = aux->left;
			} else {
				if(aux->right == NULL){
					aux->right = buffer;
					break;
				}
				else aux = aux->right;
			}
		}
	}
}

void addNAME(char * name, int code, char * element){
	buffer = (poke *) malloc(sizeof(poke));
	
	strcopy(buffer->name, name);
	buffer->code = code;
	strcopy(buffer->element, element);
	buffer->right = NULL;
	buffer->left = NULL;
	
	if(rootNAME == NULL) rootNAME = buffer;
	else{
		aux = rootNAME;
		while(1){
			if(strcomp(aux->name, buffer->name) > 0){
				if(aux->left == NULL){ 
					aux->left = buffer;
					break;
				}
				else aux = aux->left;
			} else {
				if(aux->right == NULL){
					aux->right = buffer;
					break;
				}
				else aux = aux->right;
			}
		}
	}
}
////////////////////////////////////////////////////////
void codeSEARCH(){
  
  int sCODE;
	printf(">> Pokemon's code: ");
	scanf("%d", &sCODE);
	
  aux = rootCODE;
	while(1){
		if(sCODE < aux->code) {
			if(aux->left != NULL) aux = aux->left;
			else{
			  printf("\n>> Pokemon code #%d not found!\n\n", sCODE);
			  return;
			}
		}
		else if(sCODE > aux->code) {
			if(aux->right != NULL) aux = aux->right;
			else{
			  printf("\n>> Pokemon code #%d not found!\n\n", sCODE);
			  return;
			}
		} else{
		    printf("\n>> Pokemon #%d found! It's %s.\n\n", sCODE, aux->name);
		    return;
		  }
	}
}

void nameSEARCH(){

	char sNAME[21];
	printf(">> Pokemon's name: ");
	scanf("%s", sNAME);
  
  aux = rootNAME;
	while(1){
		int cmp = strcomp(aux->name, sNAME);
		if(cmp > 0) {
			if(aux->left != NULL) aux = aux->left;
			else{
			  printf("\n>> Pokemon named '%s' not found!\n\n", sNAME);
			  return;
			}
		}
		else if(cmp < 0) {
			if(aux->right != NULL) aux = aux->right;
			else{
			  printf("\n>> Pokemon named '%s' not found!\n\n", sNAME);
			  return;
			}
		} else{
			  printf("\n>> %s's INFO:\n\n", sNAME);
			  printf("\t\t | #%d - %s - %s |\n\n", aux->code, aux->name, aux->element);
			  return;
			}
	}
}
////////////////////////////////////////////////////////
void codeLIST(poke * aux){
  if(aux->left != NULL) codeLIST(aux->left);
  printf("\t\t | #%d: %s - %s\n", aux->code, aux->name, aux->element);
  if(aux->right != NULL) codeLIST(aux->right);
}

void nameLIST(poke * aux){
  if(aux->left != NULL) nameLIST(aux->left);
  printf("\t\t | %s - %s - #%d\n", aux->name, aux->element, aux->code);
  if(aux->right != NULL) nameLIST(aux->right);
}
////////////////////////////////////////////////////////
void recovery(){
  char filename[200];
  printf("Enter file's name (with the extension ex.: .txt)\n>> ");
  scanf("%s", filename);
  FILE *fp = fopen(filename, "r");
  int pokecode, nElement, recover=0;
  char pokename[20];
  if(fp == NULL) { 
  	printf("\n>> File not found!\n");
  	recover=-1;
  }
  else 
    while(fscanf(fp, "%d %s %d", &pokecode, pokename, &nElement) != EOF){
      recover = 1; 
      switch(nElement){
        case 1:
          addCODE(pokename, pokecode, "Fire"); 
          addNAME(pokename, pokecode, "Fire");              break;
        case 2: 
          addCODE(pokename, pokecode, "Water");
          addNAME(pokename, pokecode, "Water");             break;
        case 3: 
          addCODE(pokename, pokecode, "Grass");
          addNAME(pokename, pokecode, "Grass");             break;
        case 4: 
          addCODE(pokename, pokecode, "Electric");
          addNAME(pokename, pokecode, "Electric");          break;
        case 5: 
          addCODE(pokename, pokecode, "Normal");
          addNAME(pokename, pokecode, "Normal");            break;
        case 6: 
          addCODE(pokename, pokecode, "Ice");
          addNAME(pokename, pokecode, "Ice");               break;
        case 7: 
          addCODE(pokename, pokecode, "Fighting");
          addNAME(pokename, pokecode, "Fighting");          break;
        case 8: 
          addCODE(pokename, pokecode, "Poison");
          addNAME(pokename, pokecode, "Poison");            break;
        case 9: 
          addCODE(pokename, pokecode, "Ground");
          addNAME(pokename, pokecode, "Ground");            break;
        case 10: 
          addCODE(pokename, pokecode, "Flying");
          addNAME(pokename, pokecode, "Flying");            break;
        case 11: 
          addCODE(pokename, pokecode, "Psychic");
          addNAME(pokename, pokecode, "Psychic");           break;
        case 12: 
          addCODE(pokename, pokecode, "Bug");
          addNAME(pokename, pokecode, "Bug");               break;
        case 13: 
          addCODE(pokename, pokecode, "Rock");
          addNAME(pokename, pokecode, "Rock");              break;
        case 14: 
          addCODE(pokename, pokecode, "Ghost");
          addNAME(pokename, pokecode, "Ghost");             break;
        case 15: 
          addCODE(pokename, pokecode, "Dragon");
          addNAME(pokename, pokecode, "Dragon");            break;
        case 16: 
          addCODE(pokename, pokecode, "Dark");
          addNAME(pokename, pokecode, "Dark");              break;
        case 17: 
          addCODE(pokename, pokecode, "Steel");
          addNAME(pokename, pokecode, "Steel");             break;
        case 18: 
          addCODE(pokename, pokecode, "Fairy");
          addNAME(pokename, pokecode, "Fairy");             break;
      }
    }
  if(recover == 1) printf("\n>> Recovery successfully completed!\n");
  else if (recover == 0) printf("\n>> The file is empty!\n");
  if(fp != NULL) fclose(fp);
        
}
////////////////////////////////////////////////////////
void REGISTER(){
  
  char pokename[20];
  int qPOKES, i, pokecode, nElement;
  system("cls");
  printf("\n\t\t\tP O K E D E X\n");
  printf("\t\t\t\tREGISTER\n\n");
  printf("How many pokemons do you want to register?\n>> ");
  scanf("%d", &qPOKES);
  
  for(i=0;i<qPOKES;i++){
    
    system("cls");
	printf("\n\t\t\tP O K E D E X\n");
    printf("\t\t\t\tREGISTER\n\n");
    printf(">> Code: ");
    scanf("%d", &pokecode);
    printf(">> Name: ");
    scanf("%s", pokename);
    ////////////////////
    int cond = 0 ;
    do{
      if(cond) printf("dont be stupid!\n\n");
      cond=1;
      printf(">> Element (enter its number):\n\n");
      printf("\t1. Fire\t\t\t2. Water\t\t3. Grass\n");
      printf("\t4. Electric\t\t5. Normal\t\t6. Ice\n");
      printf("\t7. Fighting\t\t8. Poison\t\t9. Ground\n");
      printf("\t10. Flying\t\t11. Psychic\t\t12. Bug\n");
      printf("\t13. Rock\t\t14. Ghost\t\t15. Dragon\n");
      printf("\t16. Dark\t\t17. Steel\t\t18. Fairy\n");
      /////////////Normal - Fire - Water - Electric - Grass - Ice - Fighting - Poison - Ground - Flying - Psychic - Bug - Rock - Ghost - Dragon - Dark - Steel - Fairy///////
      printf(">> ");
      scanf("%d", &nElement);
    }while(nElement < 1 || nElement > 18);
    switch(nElement){
      case 1:
        addCODE(pokename, pokecode, "Fire"); 
        addNAME(pokename, pokecode, "Fire");      break;
      case 2: 
        addCODE(pokename, pokecode, "Water");
        addNAME(pokename, pokecode, "Water");        break;
      case 3: 
        addCODE(pokename, pokecode, "Grass");
        addNAME(pokename, pokecode, "Grass");       break;
      case 4: 
        addCODE(pokename, pokecode, "Electric");
        addNAME(pokename, pokecode, "Electric");    break;
      case 5: 
        addCODE(pokename, pokecode, "Normal");
        addNAME(pokename, pokecode, "Normal");       break;
      case 6: 
        addCODE(pokename, pokecode, "Ice");
        addNAME(pokename, pokecode, "Ice");         break;
      case 7: 
        addCODE(pokename, pokecode, "Fighting");
        addNAME(pokename, pokecode, "Fighting");    break;
      case 8: 
        addCODE(pokename, pokecode, "Poison");
        addNAME(pokename, pokecode, "Poison");      break;
      case 9: 
        addCODE(pokename, pokecode, "Ground");
        addNAME(pokename, pokecode, "Ground");      break;
      case 10: 
        addCODE(pokename, pokecode, "Flying");
        addNAME(pokename, pokecode, "Flying");     break;
      case 11: 
        addCODE(pokename, pokecode, "Psychic");
        addNAME(pokename, pokecode, "Psychic");    break;
      case 12: 
        addCODE(pokename, pokecode, "Bug");
        addNAME(pokename, pokecode, "Bug");        break;
      case 13: 
        addCODE(pokename, pokecode, "Rock");
        addNAME(pokename, pokecode, "Rock");       break;
      case 14: 
        addCODE(pokename, pokecode, "Ghost");
        addNAME(pokename, pokecode, "Ghost");      break;
      case 15: 
        addCODE(pokename, pokecode, "Dragon");
        addNAME(pokename, pokecode, "Dragon");     break;
      case 16: 
        addCODE(pokename, pokecode, "Dark");
        addNAME(pokename, pokecode, "Dark");       break;
      case 17: 
        addCODE(pokename, pokecode, "Steel");
        addNAME(pokename, pokecode, "Steel");      break;
      case 18: 
        addCODE(pokename, pokecode, "Fairy");
        addNAME(pokename, pokecode, "Fairy");      break;
      
    }
  }
}
///////////////////////////////////////////////////////////
int main(){
	rootCODE = NULL;
  rootNAME = NULL;
  buffer = NULL;
  aux = NULL;
	system("cls");
	opening();
	int menu;	
	do{
		system("cls");
		menu = -9999;
		
		printf("\n\t\t ___   ___   _  _   ___    __    ___   __  __");
		printf("\n\t\t|   | |   | | |/ | | __|  |  \\  | __| \\  \\/  /");
		printf("\n\t\t|  _| | | | |   <  | __|  | | \\ | __|  >    <   ");
		printf("\n\t\t|_|   |___| |_|\\_\\ |___|  |___| |___| /__/\\__\\    \n\n\n");
		printf("\t1 - Register Pokemon;\n");
		printf("\t2 - Search by Pokecode -- returns only the Pokename;\n");
		printf("\t3 - Search by Pokename -- returns all Pokemon's info;\n");
		printf("\t4 - List Pokemons disposed by code;\n");
		printf("\t5 - List Pokemons disposed by name;\n");
		printf("\t6 - Recovery by a 'code-name-element(number)' file;\n");
		printf("\t0 - Turn Pokedex off.\n");

		do{
			if(menu != -9999){
				system("cls");
				printf("\n\t\t ___   ___   _  _   ___    __    ___   __  __");
				printf("\n\t\t|   | |   | | |/ | | __|  |  \\  | __| \\  \\/  /");
				printf("\n\t\t|  _| | | | |   <  | __|  | | \\ | __|  >    <   ");
				printf("\n\t\t|_|   |___| |_|\\_\\ |___|  |___| |___| /__/\\__\\    \n\n\n");
				printf("\t1 - Register Pokemon;\n");
				printf("\t2 - Search by Pokecode -- returns only the Pokename;\n");
				printf("\t3 - Search by Pokename -- returns all Pokemon's info;\n");
				printf("\t4 - List Pokemons disposed by code;\n");
				printf("\t5 - List Pokemons disposed by name;\n");
				printf("\t6 - Recovery by a 'code-name-element(number)' file;\n");
				printf("\t0 - Turn Pokedex off.\n");
				printf("\n\n\t\t!!!! don't be stupid, options 0 to 5! !!!!\n");
			}
			printf("\n>> Pokeoption: ");
			scanf("%d", &menu);

		}while(menu != 1 && menu != 2 && menu != 3 && menu != 4 && menu != 5 && menu != 6 && menu != 0);
	
		switch(menu){
			case 1: REGISTER();     							      				 break;
			case 2:
			  system("cls");
	      printf("\n\t\t\tP O K E D E X\n");
	      printf("\t\t\t\tSEARCH\n\n");
			  if(rootCODE != NULL) codeSEARCH();				  	
			  else printf(">> There is any registered Pokemon!\n"); 
			  printf("\nPress ENTER to continue...");
        getchar();
        getchar();                                         break;
			case 3:
			  system("cls");
	      printf("\n\t\t\tP O K E D E X\n");
	      printf("\t\t\t\tSEARCH\n\n");
			  if(rootNAME != NULL) nameSEARCH();						
			  else printf(">> There is any registered Pokemon!\n"); 
			  printf("\nPress ENTER to continue...");
        getchar();
        getchar();                                         break;
			case 4:
			  system("cls");
			  printf("\n\t\t\tP O K E D E X\n\n\n");
			  if(rootCODE != NULL) codeLIST(rootCODE);
			  else printf(">> There is any registered Pokemon!\n"); 
			  printf("\nPress ENTER to continue...");
        getchar();
        getchar();                                         break;
			case 5:
			  system("cls");
			  printf("\n\t\t\tP O K E D E X\n\n\n");
			  if(rootNAME != NULL) nameLIST(rootNAME);
			  else printf(">> There is any registered Pokemon!\n"); 
			  printf("\nPress ENTER to continue...");
        getchar();
        getchar();                                         break;
      case 6:
        system("cls");
        printf("\n\t\t\tP O K E D E X\n");
	      printf("\t\t\t\tRECOVERY\n\n");
        recovery();
        printf("\nPress ENTER to continue...");
        getchar();
        getchar();                                                break;
		  case 0: closing();      								  break;
		}
	}while(menu != 0);
	return 0;
}
void strcopy(char * nome1, char * nome2){
  int i=0;
  while(nome2[i] != '\0'){
    nome1[i] = nome2[i];
    i++;
  }
  nome1[i] = '\0';
}

int strcomp(char * nome1, char * nome2){
  int i=0;
  while(nome1[i] != '\0' && nome2[i] != '\0'){
    if(nome1[i] < nome2[i]) return -1;
    else if(nome1[i] > nome2[i]) return 1;
    i++;
  }
  if(nome1[i] == '\0' && nome2[i] == '\0') return 0;
  else if(nome1[i] != '\0' && nome2[i] == '\0') return 1;
  else if(nome1[i] == '\0' && nome2[i] != '\0') return -1; 
}

void opening(){

  system("cls");
  printf("\n\n\n");
  printf("\n\t\t\t ___ ");
	printf("\n\t\t\t|   |");
	printf("\n\t\t\t|  _|");
	printf("\n\t\t\t|_|  \n");
	usleep(100000);
	///
	system("cls");
	printf("\n\n\n");
	printf("\n\t\t\t ___   ___ ");
	printf("\n\t\t\t|   | |   |");
	printf("\n\t\t\t|  _| | | |");
	printf("\n\t\t\t|_|   |___|\n");
	usleep(100000);
  ///	
  system("cls");
  printf("\n\n\n");
	printf("\n\t\t\t ___   ___   _  _ ");
	printf("\n\t\t\t|   | |   | | |/ |");
	printf("\n\t\t\t|  _| | | | |   < ");
	printf("\n\t\t\t|_|   |___| |_|\\_\\\n");
	usleep(100000);
	///	
  system("cls");
  printf("\n\n\n");
	printf("\n\t\t\t ___   ___   _  _   ___");
	printf("\n\t\t\t|   | |   | | |/ | | __|");
	printf("\n\t\t\t|  _| | | | |   <  | __|");
	printf("\n\t\t\t|_|   |___| |_|\\_\\ |___|\n");
	usleep(100000);
	///
	system("cls");
	printf("\n\n\n");
	printf("\n\t\t\t ___   ___   _  _   ___");
	printf("\n\t\t\t|   | |   | | |/ | | __|");
	printf("\n\t\t\t|  _| | | | |   <  | __|");
	printf("\n\t\t\t|_|   |___| |_|\\_\\ |___|\n");
	
	printf("\n\n\n\n\n");
	
	printf("\n\t\t\t   __ ");
	printf("\n\t\t\t  |  \\ ");
	printf("\n\t\t\t  | | \\");
	printf("\n\t\t\t  |___|");
	printf("\n\n");
	usleep(100000);
	///
	system("cls");
	printf("\n\n\n");
	printf("\n\t\t\t ___   ___   _  _   ___");
	printf("\n\t\t\t|   | |   | | |/ | | __|");
	printf("\n\t\t\t|  _| | | | |   <  | __|");
	printf("\n\t\t\t|_|   |___| |_|\\_\\ |___|\n");
	
	printf("\n\n\n\n\n");
	
	printf("\n\t\t\t   __    ___  ");
	printf("\n\t\t\t  |  \\  | __|");
	printf("\n\t\t\t  | | \\ | __|");
	printf("\n\t\t\t  |___| |___|");
	printf("\n\n");
	usleep(100000);
	///
	system("cls");
	printf("\n\n\n");
	printf("\n\t\t\t ___   ___   _  _   ___");
	printf("\n\t\t\t|   | |   | | |/ | | __|");
	printf("\n\t\t\t|  _| | | | |   <  | __|");
	printf("\n\t\t\t|_|   |___| |_|\\_\\ |___|\n");
	
	printf("\n\n\n\n\n");
	
	printf("\n\t\t\t   __    ___   __  __");
	printf("\n\t\t\t  |  \\  | __| \\  \\/  /");
	printf("\n\t\t\t  | | \\ | __|  >    <");
	printf("\n\t\t\t  |___| |___| /__/\\__\\");
	printf("\n\n");
	usleep(500000);
  //////////////////////////////////////////////////////////
  system("cls");
  printf("\n\n\n");
  printf("\n\t\t\t ___   ___   _  _   ___");
	printf("\n\t\t\t|   | |   | | |/ | | __|");
	printf("\n\t\t\t|  _| | | | |   <  | __|");
	printf("\n\t\t\t|_|   |___| |_|\\_\\ |___|\n");
	
	printf("\n\t\t\t|         ____         |");
	printf("\n\t\t\t|________/    \\________|");
	printf("\n\t\t\t ________      ________");
	printf("\n\t\t\t|        \\____/        |");
	printf("\n\t\t\t|                      |");
	printf("\n\t\t\t   __    ___   __  __");
	printf("\n\t\t\t  |  \\  | __| \\  \\/  /");
	printf("\n\t\t\t  | | \\ | __|  >    <");
	printf("\n\t\t\t  |___| |___| /__/\\__\\");
	printf("\n\n");
  usleep(1000000);
}

void closing(){
  system("cls");
  printf("			\n");	
  printf("			\n");	
  printf("0			\n");										
  printf("00 		\n");											
  printf("00		\n");
  printf("			\n");
  printf("00		\n");
  printf("00 		\n");
  printf("0			\n");
  printf("			\n");
  printf("			\n");
  usleep(100000);
  
  system("cls");
  printf("				\n");	
  printf("0				\n");	
  printf("000			\n");										
  printf("0000 		\n");											
  printf("0000		\n");
  printf("				\n");
  printf("0000		\n");
  printf("0000 		\n");
  printf("000			\n");
  printf("0				\n");
  printf("				\n");
  usleep(100000);
  
  system("cls");
  printf("					\n");	
  printf("000				\n");	
  printf("00000			\n");										
  printf("000000 		\n");											
  printf("000000		\n");
  printf("					\n");
  printf("000000		\n");
  printf("000000 		\n");
  printf("00000			\n");
  printf("000				\n");
  printf("					\n");
  usleep(100000);
  
  system("cls");
  printf("0						\n");	
  printf("00000				\n");	
  printf("0000000			\n");										
  printf("00000000 		\n");											
  printf("00000000		\n");
  printf(" 						\n");
  printf("00000000		\n");
  printf("00000000 		\n");
  printf("0000000			\n");
  printf("00000				\n");
  printf("0						\n");
  usleep(100000);
  
  system("cls");
  printf("000						\n");	
  printf("0000000				\n");	
  printf("000000000			\n");										
  printf("0000000000 		\n");											
  printf("  00000000		\n");
  printf("0  						\n");
  printf("  00000000		\n");
  printf("0000000000 		\n");
  printf("000000000			\n");
  printf("0000000				\n");
  printf("000						\n");
  usleep(100000);

  system("cls");
  printf("00000						\n");	
  printf("000000000				\n");	
  printf("00000000000			\n");										
  printf("000000000000 		\n");											
  printf("    00000000		\n");
  printf(" 00  						\n");
  printf("    00000000		\n");
  printf("000000000000 		\n");
  printf("00000000000			\n");
  printf("000000000				\n");
  printf("00000						\n");
  usleep(100000);
  
  system("cls");
  printf("\n");
  printf(" 000000						\n");	
  printf("00000000000				\n");	
  printf("0000000000000			\n");										
  printf("00000000000000 		\n");											
  printf("00    00000000		\n");
  printf("   00  						\n");
  printf("00    00000000		\n");
  printf("00000000000000 		\n");
  printf("0000000000000			\n");
  printf("00000000000				\n");
  printf(" 000000						\n");
  usleep(100000);
  
  system("cls");
  printf("\n\n");
  printf("   000000						\n");
  printf("0000000000000				\n");
  printf("000000000000000			\n");
  printf("0000000000000000 		\n");
  printf("0000    00000000		\n");
  printf("     00  						\n");
  printf("0000    00000000		\n");
  printf("0000000000000000 		\n");
  printf("000000000000000			\n");
  printf("0000000000000				\n");
  printf("   000000						\n");
  usleep(100000);
  
  system("cls");
  printf("\n\n\n\n\n\n");
  printf("     000000						\n");	
  printf(" 00000000000000				\n");	
  printf("00000000000000000			\n");										
  printf("000000000000000000 		\n");											
  printf("000000    00000000		\n");
  printf("       00  						\n");
  printf("000000    00000000		\n");
  printf("000000000000000000 		\n");											
  printf("00000000000000000			\n");										
  printf(" 00000000000000				\n");	
  printf("     000000						\n");	
  usleep(100000);
  
  system("cls");
  printf("\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("       000000						\n");	
  printf("   00000000000000				\n");	
  printf(" 000000000000000000			\n");										
  printf("00000000000000000000 		\n");											
  printf("00000000    00000000		\n");
  printf("         00  						\n");
  printf("00000000    00000000		\n");
  printf("00000000000000000000 		\n");
  printf(" 000000000000000000			\n");
  printf("   00000000000000				\n");
  printf("       000000						\n");
  usleep(100000);
  
  system("cls");
  printf("\n\n\n\n\n\n\n\n\n");
  printf("         00  00						\n");	
  printf("     000000  000000				\n");	
  printf("   00000000  00000000			\n");										
  printf("  000000000  000000000 		\n");											
  printf("  00000000    00000000		\n");
  printf("  00000000 00 00000000		\n");
  printf("  00000000    00000000		\n");
  printf("  000000000  000000000 		\n");
  printf("   00000000  00000000			\n");
  printf("     000000  000000				\n");
  printf("         00  00						\n");
  usleep(100000);
  
  system("cls");
  printf("\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("           000000						\n");	
  printf("       00000000000000				\n");	
  printf("     000000000000000000			\n");										
  printf("    00000000000000000000 		\n");											
  printf("    00000000    00000000		\n");
  printf("             00  						\n");
  printf("    00000000    00000000		\n");
  printf("    00000000000000000000 		\n");
  printf("     000000000000000000			\n");
  printf("       00000000000000				\n");
  printf("           000000						\n");
  usleep(100000);
  
  system("cls");
  printf("\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("             00  00						\n");	
  printf("         000000  000000				\n");	
  printf("       00000000  00000000			\n");										
  printf("      000000000  000000000 		\n");											
  printf("      00000000    00000000		\n");
  printf("      00000000 00 00000000		\n");
  printf("      00000000    00000000		\n");
  printf("      000000000  000000000 		\n");
  printf("       00000000  00000000			\n");
  printf("         000000  000000				\n");
  printf("             00  00						\n");
  usleep(100000);
  
  system("cls");
  printf("\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("               000000						\n");	
  printf("           00000000000000				\n");	
  printf("         000000000000000000			\n");										
  printf("        00000000000000000000 		\n");											
  printf("        00000000    00000000		\n");
  printf("                 00  						\n");
  printf("        00000000    00000000		\n");
  printf("        00000000000000000000 		\n");
  printf("         000000000000000000			\n");
  printf("           00000000000000				\n");
  printf("               000000						\n");
  usleep(500000);
  ////////////////////////////////////////////////////////////
  system("cls");
  printf("\n\n\n\n\n\n\n\n\n\n");
  printf("                                     00000000\n");
  printf("                                   0000000\n");
  printf("               000000				     00000000000\n");	
  printf("           00000000000000		    0000000000\n");	
  printf("         000000000000000000	   000000000000\n");										
  printf("        00000000000000000000 00000000000\n");											
  printf("        00000000    000000000000000000000\n");
  printf("                 00  			00000000000000\n");
  printf("        00000000    00000000000000000000\n");
  printf("        000000000000000000000000000000000\n");
  printf("         0000000000000000000000000000000\n");
  printf("           00000000000000	     000000000\n");
  printf("               000000			      000000000000\n");
  usleep(50000);
  
  system("cls");
  printf("\n\n\n\n\n\n\n\n\n\n");
  printf("                   0000000000000000000000000000\n");
  printf("                    000000000000000000000000000\n");
  printf("               0000000000000000000000000000000000000\n");	
  printf("           0000000000000000000000000000000000\n");	
  printf("         0000000000000000000000000000000000000000\n");										
  printf("        00000000000000000000000000000000\n");											
  printf("        00000000    000000000000000000000\n");
  printf("                 00  			00000000000000\n");
  printf("        00000000    00000000000000000000\n");
  printf("        000000000000000000000000000000000\n");
  printf("         0000000000000000000000000000000\n");
  printf("           00000000000000000000000000000000\n");
  printf("               000000	0000000000000000000000\n");
  usleep(10000);

  system("cls");
  printf("00000000000000000000000000000000000000000000000000000000000000000000000000000\n");
  printf("00000000000000000000000000000000000000000000000000000000000000000000000000000\n");
  printf("00000000000000000000000000000000000000000000000000000000000000000000000000000\n");
  printf("00000000000000000000000000000000000000000000000000000000000000000000000000000\n");
  printf("00000000000000000000000000000000000000000000000000000000000000000000000000000\n");
  printf("00000000000000000000000000000000000000000000000000000000000000000000000000000\n");
  printf("00000000000000000000000000000000000000000000000000000000000000000000000000000\n");
  printf("00000000000000000000000000000000000000000000000000000000000000000000000000000\n");
  printf("00000000000000000000000000000000000000000000000000000000000000000000000000000\n");
  printf("00000000000000000000000000000000000000000000000000000000000000000000000000000\n");
  printf("00000000000000000000000000000000000000000000000000000000000000000000000000000\n");
  printf("00000000000000000000000000000000000000000000000000000000000000000000000000000\n");
  printf("00000000000000000000000000000000000000000000000000000000000000000000000000000\n");
  printf("00000000000000000000000000000000000000000000000000000000000000000000000000000\n");
  printf("00000000000000000000000000000000000000000000000000000000000000000000000000000\n");
  printf("00000000000000000000000000000000000000000000000000000000000000000000000000000\n");
  printf("00000000000000000000000000000000000000000000000000000000000000000000000000000\n");
  printf("00000000000000000000000000000000000000000000000000000000000000000000000000000\n");
  printf("00000000000000000000000000000000000000000000000000000000000000000000000000000\n");
  printf("00000000000000000000000000000000000000000000000000000000000000000000000000000\n");
  printf("00000000000000000000000000000000000000000000000000000000000000000000000000000\n");
  printf("00000000000000000000000000000000000000000000000000000000000000000000000000000\n");
  printf("00000000000000000000000000000000000000000000000000000000000000000000000000000\n");
  usleep(100000);
  system("cls");
}
