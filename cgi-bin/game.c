#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int hit;
int isEnd = 0;
int count;
int len;
int remaining;
char usrin[100];

char spelltype;
char spell[20];
char spell1[20] = "Expelliarmus";
char spell2[20] = "Reducto";
char spell3[20] = "ExpectoPatronum";
char spell4[20] = "AvadaKedavra";

int spl2R = 21;
int spl3R = 31;

/*
- Boolean method to determine if the spell is successful
- Conditions if the spell succeeds (i.e. the random number was 7, the magic number)

*/
int spellHit(int hit, int count, char spelltype){
	if (hit == 7){
		if (spelltype == 'p'){
			if (count > 5){
				printf("After %d attempts, you finally manage to produce a non corporeal patronus. This is advanced magic, so it's impressive you got this far!\n", count);
			}
			else{
				printf("Your heart swells as a fully formed patronus erupts from your wand and magestically circles the room. Did you catch a glimpse of what animal it is? Don't get too excited though, this spell is much more difficult in the presence of a Dementor!\n");
			}
		}
		else if (spelltype == 'e'){
			printf("You've successfully disarmed your opponent in %d attempts! Their wand glints in the light as it archs towards you and you triumphantly catch it.\n", count);
		}
		else{
			printf("The class runs for cover as your dummy explodes into a thousand pieces. And it only took you %d try/tries!\n", count);
		}
		return 1;
	}
	else if (spelltype == 'e' && count > 5){
		printf("Never let anyone tell you that practice and perseverence is useless. It may have taken you %d attempts, but you've managed to disarm your opponent! ...Or did they just accidentally drop their wand?\n", count);
		return 1;
	}
	else{
		return 0;
	}	
}

/*

- csv processing

*/
int useResourceFile(int goldUsrval, int manaUsrval, int isEnd, char inventoryG[], char inventoryM[]){

	char resourceStr[15];
	char gold[10];
	char mana[10];
	int ch;
	int i = 0;
	int goldval;
	int manaval;
	int buff;
	int validIn = 1;
	char occ[2];

	char newRes[20];
		

	FILE *resourceFile = fopen("resources.csv","r+");

	if (resourceFile){
	
		while ((ch = getc(resourceFile)) != EOF){
				resourceStr[i] = ch;
				i++;
		}
		resourceStr[i] = '\0';
		sscanf(resourceStr, "%[^,]%*c%[^,]%*c%s", gold, mana, occ);
		/*printf("isEnd %d occ %s", isEnd, occ);*/
		
		
		goldval = atoi(gold);
		manaval = atoi(mana);

		/*printf("gold %s mana %s occ %s", gold, mana, occ);
		printf("goldval %d manaval %d goldUsrval %d manaUsrval %d", goldval, manaval, goldUsrval, manaUsrval);*/

		/* Check if request is valid (i.e. user and room have enough gold/mana for transaction */
		

		buff = goldUsrval + manaUsrval;
		if (buff > 5 || buff == 0){
			validIn = 0;
		}
		/*printf("sum %d",buff);*/
		
		buff = goldval - goldUsrval;
		if (buff < 0){
			validIn = 0;
		}
		/*printf("is enough gold %d",buff);*/

		buff = manaval - manaUsrval;
		if (buff < 0){
			validIn = 0;
		}
		/*printf("is enough mana %d",buff);*/

		/* Printed if user wins the game, prompting them to input prize request */
		if (isEnd){
			if (goldval == 0 && manaval == 0){
				printf("<p> I have nothing to offer you. At least you got to practice! Please type QUIT to exit the game </p>");
			}
			else{
				printf("<p>I'm not a professor so I can't offer you house points, but I have have %s gold and %s mana. please type in the amount of gold and mana you'd like to receive, up to a total of 5 (number followed by a space followed by another number). For example, 3 2 will get you 3 gold and 2 mana. 5 1 is not accepted because the total sum is larger than 5. Please don't be greedy, your request cannot exceed what I have to give.\n</p>", mana, gold);
			}
			fclose(resourceFile);
			return 1;
			
		}
		else if (!validIn){
			printf("<p>Your prize input is not valid OR:\n\n</p>");
		}

		else{
			
			int ninventoryG;
			int ninventoryM;

			/* calculate new values for gold/mana of room resources*/
			goldval = goldval - goldUsrval;
			manaval = manaval - manaUsrval;

			/* convert gold/mana values of user from string to int and calculate new inventory based on input */
			ninventoryG = atoi(inventoryG);
			ninventoryM = atoi(inventoryM);

			ninventoryG = ninventoryG + goldUsrval;
			ninventoryM = ninventoryM + manaUsrval;

			/* printf("inventory new = %d mana new = %d", ninventoryG, ninventoryM); */

			/* convert new gold/mana values for resources of room from int to string and concat into csv format*/
			char ngoldval[15];
			char nmanaval[15];

			sprintf(ngoldval, "%d", goldval);
			sprintf(nmanaval, "%d", manaval);

			strcpy(newRes, ngoldval);
			strcat(newRes, ",");
			strcat(newRes, nmanaval);
			strcat(newRes, ",");
			
			/* reprint entire page with new inventory values */
			/*printf("<html><head><title>RmReq</title></head><body value =\"%d,%d\"><h1>hello world</h1></body></html>", ninventoryG, ninventoryM);*/
			if(ninventoryG > 99){

				/* Set room occumancy to 0*/
				strcat(newRes, "0");

				printf("<html><head><link rel=\"stylesheet\" href=\"/~cisaic/style.css\"><title> Gryffindor Common Room </title></head><body><div class = \"bg\"><div class=\"col1\"></div><div  class=\"col2\"><h1 style=\"color:white;margin-top:10%%;\"> Congrats! You've mastered all the spells DA can teach you. You're now prepared to face the real world... just in time for the Second Wizarding War. You should head back to your common room now. Good Luck. </h1></div><div class=\"col3\"></div></div></body></html>");
			}
			else{

				strcat(newRes, occ);

				printf("<html><head><link rel=\"stylesheet\" href=\"/~cisaic/style.css\"><title> Room of Requirement </title><script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.2.0/jquery.min.js\"></script><script src=\"/~cisaic/room.js\"></script></head><body><div class=\"col1\"><div class = \"instr\"><h1> Commands </h1><p> <b>DROP n</b> : Drop n gold from your inventory. 2 gold = 1 mana </br><b>PLAY</b> : Start the spellcasting lesson</br><b>QUIT</b> : Stop the lesson</br><b>EXIT</b> : Drop everything in your inventory and leave the game </br><b>REFRESH</b> : Refresh the page</p></div><div class =\"instrGame\"><h1> How to play </h1><p> Today we will be learning three different spells. You win if your spell is successful. You have 10 attempts to cast any combination of the three options. Make sure to spell them exactly as they're written below (no pun intended) <br/><b>Expelliarmus</b> : (Easy) Defensive spell that disarms your opponents  <br/><b>Reducto</b> : (Medium) A curse that can be used to blast solid objects to pieces <br/><b>ExpectoPatronum</b> : (Hard) The only known defense against Dementors. Conjure your animal Patronus by thinking of the happiest memory you can. </p></div></div><div class=\"col2\"><h1 class = \"title\"> Room of Requirement </h1><img class = \"room\" src=\"/~cisaic/rmreq.jpg\"><div class = \"sandbox\"><form action = \"http://cs.mcgill.ca/~syu47/room.html\" class=\"transporter\"><input type = \"hidden\" name = \"inventory\" value=\" %d,%d\"><input type = \"hidden\" name = \"url\" value = \"url\"><input type = \"submit\" value = \"NORTH\" class=\"north cardinal\"><input type = \"submit\" value = \"EAST\" class=\"east cardinal\"><input type = \"submit\" value = \"WEST\" class=\"west cardinal\"></form><form action = \"/~cisaic/cgi-bin/room.cgi\" method = \"POST\" accept-charset= \"utf-8\" name =\"commandf\" id = \"#commandf\" target=\"response\"><input type = \"text\" class = \"command\" name = \"command\"><input type = \"hidden\" name = \"count\" value=\"0\"><input type = \"hidden\" name = \"inventory\" value = \"%d,%d\"><input type = \"submit\" class = \"submit\" onclick = \"return submitCom();\"></form><form action = \"http://cs.mcgill.ca/~syu47/room.html\" class=\"transporter\"><input type = \"hidden\" name = \"inventory\" value =\"%d,%d\"><input type = \"hidden\" name = \"url\" value = \"url\"><input type = \"submit\" value = \"SOUTH\" class=\"south cardinal\"></form></div></div><div class=\"col3\"><h1> Interaction </h1><iframe name=\"response\" class=\"response\"></iframe></div></body></html>",ninventoryG,ninventoryM,ninventoryG,ninventoryM,ninventoryG,ninventoryM);
			}
			/* printf("newRes %s", newRes); */

			/* overwrite csv file with new values */

			resourceFile = freopen("resources.csv","w", stdout);
			fprintf(resourceFile, "%s", newRes);

			fclose(resourceFile);

			
			return 1;

		}


		
	}

	fclose(resourceFile);
	return 0;

}


int main(void){

	/*
	- Store POST content in userin. 
	- Parse userin and break into values spell (command from user), counts (client side counter that keeps track of how many valid spells have been attempted), inventory.
	- Farther parse inventory and split into gold/mana values
	*/

	srand(time(NULL));
	char c;
	int a = 0;
	int n = atoi(getenv("CONTENT_LENGTH"));

	printf("Content-Type:text/html; charset=UTF-8\n\n");

	while((c = getchar()) != 0 && a<n){
		if (a<100){
			usrin[a] = c;
			a++;
		}
	}
	usrin[a] = '\0';
	/* printf("<p>usrin %s\n</p>",usrin);*/

	char inventory[10];
	char inventoryG[2];
	char inventoryM[2];

	char counts[1];
	char string[10];
	sscanf(usrin, "%*[^=]%*c%[^&]%*[^=]%*c%[^&]%*[^=]%*c%s", spell, counts, inventory);
	count = atoi(counts);
	sscanf(inventory, "%[^\%]%*c%*c%*c%s", inventoryG, inventoryM);

	if(count < 11 && !isEnd){

		/* Expelliarmus */
		if(!strcmp(spell,spell1)){
			spelltype = 'e';
			hit = rand()%11;
			remaining = 10 - count;
			isEnd = spellHit(hit, count, spelltype);
			
			/* printf("<p>hit %d remaining %d isEnd %d Count %d</p>", hit, remaining, isEnd, count); */
			if (!isEnd){
				printf("Your wand comically flies across the room. Did you accidentally throw it, or did you somehow manage to disarm yourself? Pick up your wand (and your dignity) and try again. You have %d attempts left.\n", remaining);
			}
			
		}

		/* Reducto */
		else if(!strcmp(spell,spell2)){
			spelltype = 'r';
			if (count > 5){
				spl2R = 11;
			}
			hit = rand()%spl2R;
			remaining = 10 - count;
			isEnd = spellHit(hit, count, spelltype);
			/* printf("<p>hit %d remaining %d isEnd %d Count %d</p>", hit, remaining, isEnd, count); */
			if (!isEnd){
				if (count == 10){
					printf("It may seem hopeless now, but keep practicing and we know you'll get it next time! Please press submit again to exit the game.\n");
				}
				else{
					printf("Nothing happens. You have %d attempts left, so try to focus next time!\n", remaining);
				}
			}
			
		}

		/* ExpectoPatronum */
		else if(!strcmp(spell,spell3)){
			spelltype = 'p';
			if (count > 5){
				spl3R = 15;
			}
			hit = rand()%spl3R;
			remaining = 10 - count;
			isEnd = spellHit(hit, count,spelltype);
			/* printf("<p>hit %d remaining %d isEnd %d Count %d</p>", hit, remaining, isEnd, count); */
			if(!isEnd){
				if (count == 10){
				printf("The Patronus charm is very advanced magic, so don't be discouraged that you didn't get it even on your 10th attempt! Please press submit again to exit the game.\n");
				}
				else {
					printf("Was it a trick of the light, or did you just see a faint whisp of silver? Have some chocolate, think of something happier, and try again. You have %d attempts left\n", remaining);
				}
			}
			
		}

		/* AvadaKedavra */
		else if(!strcmp(spell,spell4)){
			printf("Unforgivable! There are children around, what's wrong with you?\n");
		}

		/* User input isn't one of valid options */
		else{
			
			char goldUsr6[10];
			char manaUsr6[10];
			int goldUsrval6;
			int manaUsrval6;
			

			sscanf(spell, "%[^+]%*c%s", goldUsr6, manaUsr6);

			goldUsrval6 = atoi(goldUsr6);
			manaUsrval6 = atoi(manaUsr6);

			/* Processing win transaction gold/mana request */
			int done = useResourceFile(goldUsrval6, manaUsrval6, isEnd, inventoryG, inventoryM);
			
			/* If user types invalid answer*/
			if(!done){
				printf("Please correctly type in any of the provided spells with attention to capitalization and no spaces");
			}
			
		}
	}

	if(isEnd){
		
		char goldUsr[10];
		char manaUsr[10];
		int goldUsrval;
		int manaUsrval;
		

		sscanf(spell, "%[^+]%*c%s", goldUsr, manaUsr);

		goldUsrval = atoi(goldUsr);
		manaUsrval = atoi(manaUsr);

		useResourceFile(goldUsrval, manaUsrval, isEnd, inventoryG, inventoryM);
		
	}

	return 0;
}


