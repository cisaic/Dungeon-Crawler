#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count = 0;
char usrin[100];

char spell[110];

char comD[10] = "DROP";
char comE[10] = "EXIT";

/* Check if a string is equivalent to an integer */
int isnInt(char n[]){
	int ni;

	int nlength = strlen(n);
	for (ni =0; ni<nlength; ni++){
		if (!isdigit(n[ni])){
			return 0;
		}
	}
	return 1;
}

int main(void){
	/* Read POST data and store in userin (user input)*/

	char c;
	int a = 0;
	int contentlength = atoi(getenv("CONTENT_LENGTH"));
	char command[50];
	int ch;
	char resourceStr[15];
	FILE *resourceFile = fopen("resources.csv","r");

	printf("Content-Type:text/html; charset=UTF-8\n\n");
	

	while((c = getchar()) != 0 && a<contentlength){
		if (a<100){
			usrin[a] = c;
			a++;
		}
	}
	usrin[a] = '\0';
	/* printf("%s",usrin);*/
	
	char inventory[10];
	char inventoryG[2];
	char inventoryM[2];
	int ninventoryG;
	int ninventoryM;
	
	char counts[1];
	char n[10];
	char gold[10];
	char mana[10];
	int resourceG;
	int resourceM;
	
	/* Parse user input and separate into spell, count, inventory 
	(keeping the var names the same as in game.c for cohesion even if the values don't match the var. 
	This will be changed in a bit*/

	sscanf(usrin, "%*[^=]%*c%[^&]%*[^=]%*c%[^&]%*[^=]%*c%s", spell, counts, inventory);

	/*
	Further parse the user command for two values, n and command (i.e. DROP n) 
	Break inventory val into gold and mana values, then convert to integers
	*/
	sscanf(spell, "%[^+]%*c%s", command, n);
	sscanf(inventory, "%[^\%]%*c%*c%*c%s", inventoryG, inventoryM);
	
	/*printf("<p>inventory %s G: %s M: %s</p>", inventory, inventoryG,inventoryM); */

	ninventoryG = atoi(inventoryG);
	ninventoryM = atoi(inventoryM);


	int i = 0;

	if (resourceFile){
		
		/* Read resource.csv, convert gold and mana values to int */
		while ((ch = getc(resourceFile)) != EOF){
				resourceStr[i] = ch;
				i++;
		}
		resourceStr[i] = '\0';
		/* printf("<p>resources %s\n</p>", resourceStr); */
		sscanf(resourceStr, "%[^,]%*c%[^,]%*s", gold, mana);
		/* printf("<p>I have %s gold %s mana\n</p>", mana, gold); */
		resourceG = atoi(gold);
		resourceM = atoi(mana);


		/* if user types DROP command */

		if(!strcmp(command,comD)){
			int quotient;
			int remainder;
			int isInt;
			int deduct;
			int isEnough;


			isInt = isnInt(n);
			if (isInt){
				int divide = atoi(n);
				quotient = divide/2;
				remainder = divide%2;
				deduct = divide - remainder;


				isEnough = ninventoryG - divide;

				/* If user doesn't have enough to DROP, print room with warning message. Don't change inventory values */
				if (isEnough < 0 ){
					printf("<html><head><link rel=\"stylesheet\" href=\"/~cisaic/style.css\"><title> Room of Requirement </title><script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.2.0/jquery.min.js\"></script><script src=\"/~cisaic/room.js\"></script></head><body><div class=\"col1\"><div class = \"instr\"><h1> Commands </h1><p> <b>DROP n</b> : Drop n gold from your inventory. 2 gold = 1 mana </br><b>PLAY</b> : Start the spellcasting lesson</br><b>QUIT</b> : Stop the lesson</br><b>EXIT</b> : Drop everything in your inventory and leave the game </br><b>REFRESH</b> : Refresh the page</p></div><div class =\"instrGame\"><h1> How to play </h1><p> Today we will be learning three different spells. You win if your spell is successful. You have 10 attempts to cast any combination of the three options. Make sure to spell them exactly as they're written below (no pun intended) <br/><b>Expelliarmus</b> : (Easy) Defensive spell that disarms your opponents  <br/><b>Reducto</b> : (Medium) A curse that can be used to blast solid objects to pieces <br/><b>ExpectoPatronum</b> : (Hard) The only known defense against Dementors. Conjure your animal Patronus by thinking of the happiest memory you can. </p></div></div><div class=\"col2\"><h1 class = \"title\"> Room of Requirement </h1><img class = \"room\" src=\"/~cisaic/rmreq.jpg\"><div class = \"sandbox\"><form action = \"http://cs.mcgill.ca/~syu47/room.html\" class=\"transporter\"><input type = \"hidden\" name = \"inventory\" value=\" %d,%d\"><input type = \"hidden\" name = \"url\" value = \"url\"><input type = \"submit\" value = \"NORTH\" class=\"north cardinal\"><input type = \"submit\" value = \"EAST\" class=\"east cardinal\"><input type = \"submit\" value = \"WEST\" class=\"west cardinal\"></form><form action = \"/~cisaic/cgi-bin/room.cgi\" method = \"POST\" accept-charset= \"utf-8\" name =\"commandf\" id = \"#commandf\" target=\"response\"><input type = \"text\" class = \"command\" name = \"command\"><input type = \"hidden\" name = \"count\" value=\"0\"><input type = \"hidden\" name = \"inventory\" value = \"%d,%d\"><input type = \"submit\" class = \"submit\" onclick = \"return submitCom();\"></form><form action = \"http://cs.mcgill.ca/~syu47/room.html\" class=\"transporter\"><input type = \"hidden\" name = \"inventory\" value =\"%d,%d\"><input type = \"hidden\" name = \"url\" value = \"url\"><input type = \"submit\" value = \"SOUTH\" class=\"south cardinal\"></form></div></div><div class=\"col3\"><h1> Interaction </h1><p class=\"notEnoughGold\">You don't have enough gold to do that!</p><iframe name=\"response\" class=\"response\"></iframe></div></body></html>",ninventoryG,ninventoryM,ninventoryG,ninventoryM,ninventoryG,ninventoryM);
				}
				else{

				ninventoryG = ninventoryG - deduct;
				ninventoryM = ninventoryM + quotient;

				/* If user has enough to drop, deduct the DROP value requested
				If odd number requested, only drop n-1 gold
				Add half of the drop value to mana and reprint room with appropriate inventory vals */

				printf("<html><head><link rel=\"stylesheet\" href=\"/~cisaic/style.css\"><title> Room of Requirement </title><script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.2.0/jquery.min.js\"></script><script src=\"/~cisaic/room.js\"></script></head><body><div class=\"col1\"><div class = \"instr\"><h1> Commands </h1><p> <b>DROP n</b> : Drop n gold from your inventory. 2 gold = 1 mana </br><b>PLAY</b> : Start the spellcasting lesson</br><b>QUIT</b> : Stop the lesson</br><b>EXIT</b> : Drop everything in your inventory and leave the game </br><b>REFRESH</b> : Refresh the page</p></div><div class =\"instrGame\"><h1> How to play </h1><p> Today we will be learning three different spells. You win if your spell is successful. You have 10 attempts to cast any combination of the three options. Make sure to spell them exactly as they're written below (no pun intended) <br/><b>Expelliarmus</b> : (Easy) Defensive spell that disarms your opponents  <br/><b>Reducto</b> : (Medium) A curse that can be used to blast solid objects to pieces <br/><b>ExpectoPatronum</b> : (Hard) The only known defense against Dementors. Conjure your animal Patronus by thinking of the happiest memory you can. </p></div></div><div class=\"col2\"><h1 class = \"title\"> Room of Requirement </h1><img class = \"room\" src=\"/~cisaic/rmreq.jpg\"><div class = \"sandbox\"><form action = \"http://cs.mcgill.ca/~syu47/room.html\" class=\"transporter\"><input type = \"hidden\" name = \"inventory\" value=\" %d,%d\"><input type = \"hidden\" name = \"url\" value = \"url\"><input type = \"submit\" value = \"NORTH\" class=\"north cardinal\"><input type = \"submit\" value = \"EAST\" class=\"east cardinal\"><input type = \"submit\" value = \"WEST\" class=\"west cardinal\"></form><form action = \"/~cisaic/cgi-bin/room.cgi\" method = \"POST\" accept-charset= \"utf-8\" name =\"commandf\" id = \"#commandf\" target=\"response\"><input type = \"text\" class = \"command\" name = \"command\"><input type = \"hidden\" name = \"count\" value=\"0\"><input type = \"hidden\" name = \"inventory\" value = \"%d,%d\"><input type = \"submit\" class = \"submit\" onclick = \"return submitCom();\"></form><form action = \"http://cs.mcgill.ca/~syu47/room.html\" class=\"transporter\"><input type = \"hidden\" name = \"inventory\" value =\"%d,%d\"><input type = \"hidden\" name = \"url\" value = \"url\"><input type = \"submit\" value = \"SOUTH\" class=\"south cardinal\"></form></div></div><div class=\"col3\"><h1> Interaction </h1><iframe name=\"response\" class=\"response\"></iframe></div></body></html>",ninventoryG,ninventoryM,ninventoryG,ninventoryM,ninventoryG,ninventoryM);

				}
				

				/* printf("quotient %d remainder %d deduct %d inventoryG %s inventoryM %s ninventoryM %d ninventoryG %d divide %d isint %d", quotient, remainder, deduct, inventoryG, inventoryM, ninventoryM, ninventoryG, divide, isInt);*/ 
			}

		}

		/* if usr types EXIT command, set room occupancy to 0, add user inventory to room, and print exit screen */
		if(!strcmp(command,comE)){
			char newRes[15];
			char ngoldval[15];
			char nmanaval[15];

			resourceG = resourceG + ninventoryG;
			resourceM = resourceM + ninventoryM;
			
			sprintf(ngoldval, "%d", resourceG);
			sprintf(nmanaval, "%d", resourceM);

			strcpy(newRes, ngoldval);
			strcat(newRes, ",");
			strcat(newRes, nmanaval);
			strcat(newRes, ",");
			strcat(newRes, "0");

			printf("<html><head><link rel=\"stylesheet\" href=\"/~cisaic/style.css\"><title> Gryffindor Common Room </title></head><body><div class = \"bg\"><div class=\"col1\"></div><div  class=\"col2\"><h1 style=\"color:white;margin-top:10%%;\"> Goodness, is that the time?! You should hurry back to your common room before the Inquisetorial squad comes prowling! </h1></div><div class=\"col3\"></div></div></body></html>");

			resourceFile = freopen("resources.csv", "w", stdout);
			fprintf(resourceFile, "%s", newRes);
		}


		fclose(resourceFile);
	}

	return 0;
}

