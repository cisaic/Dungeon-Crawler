# CONTENTS OF THIS FILE


* Introduction
* Gameplay
* Features
* Bugs

## INTRO

This is the final project for a software systems course I took. Instructions can be found in instructions.pdf

I have decided to display this code on my account as evidence of my progress (and folly). I haven't formatted or edited this code since my submission, so although it may be difficult to read or replicate, I'd still like to document this as a marker of what it took to achieve. This was a course I foolishly neglected to attend, so I scrambled to learn C and python in the two weeks leading up to the deadline of this assignment (right before exams). Naturally, I finished going through the lectures the day before the due date, so I had about 24 hours to do a 2-3 person, 2 week project, by myself. Story of my freakin undergrad. And so commenced 4 days of straight coding (there were server issues on the actual due date, so I had a few extra days to submit). She ain't pretty, but she got the job done and I was able to submit, so that's really all that mattered in the end. 

Anyway, enjoy the catastrophe.  

## GAMEPLAY

The theme of this room is the Room of Requirement from Harry Potter.

Inputs must be exact (I didn't have time to implement ignore case/accept variation)

Valid commands:

- PLAY
	- QUIT
	- Expelliarmus
	- Reducto
	- ExpectoPatronum
	- n n (for win scenario)
- DROP n
- EXIT


**Boss/Challenge:**

Type in one of the three spells (4 if you count the AvadaKedavra Easter egg)
Each condition generates a random number between varying intervals corresponding with the "difficulty" level of the spell

* Expelliarmus: 1-10
* Reducto: 1-20
* ExpectoPatronum: 1-30

The user has 10 attempts. After 5 attempts, the user "levels up" and the range decreases for each spell, so the change of succeeding increases

If the random number is 7 (the magic number) the spell succeeds, and the player is offered gold and mana from the room's resources


## FEATURES

**TERMINOLOGY:**

* Inventory = User gold/mana
* Resources = Room gold/mana/occupancy

## HTML/CSS

- Responsive layout
- col1: Instructions/List of commands
- col2: Room image, text input form, and teleportation buttons
- col3: Interaction column where printf responses from the game are printed (also used for debugging)

## JS

- Dictates where the form target is based on the user input (evaluated using RegEx)
- i.e. values in PLAY only write to the iframe in the Interaction Column. This way the entire room doesn't need to be rewritten on every input
- Also hides the teleportation field during PLAY mode so the page doesn't need to be rewritten
- Displays teleportation field at the end of PLAY mode (either user wins or quits or exceeds attempts)
- At the end of the game, count is reset so user can PLAY again


## GAME.C

- spellHit(int hit, int count, char spelltype)
	- Returns boolean value if the spell was successful or not
	- Takes random value assigned in main depending on user input
	- If the 'hit' value == 7, print win messages
	- For ExpectoPatronum
		- If the user is successful in under 5 attempts, they produce a corporeal patronus (i.e. it looks like an animal)
		- Next interation: Select randomly from list of animals and assign the user a patronus
		- If it takes >5 tries for a successful hit, the user still produces a patronus, but it's not corporeal

- UseResourceFile(int goldUsrval, int manaUsrval, int isEnd, char inventoryG[], char inventoryM[])
	- Reads resource values from resources.csv
	- Determines if the player can take anything or not
	- Does appropriate calculations (subtract value from resources, add to inventory)
	- Overall win management (if user gold > 99, print win page)


- Main
	- Store POST content in char[] "userin". 
	- Parse userin and break into values "spell" (command from user), "counts" (client side counter that keeps track of how many valid spells have been attempted), "inventory".
	- Farther parse inventory and split into "gold"/"mana" values
	- Enter if loop (if user hasn't exceeded tries and the game isn't over)
	- 4 conditions: if the spell matches Expelliarmus (spell1), Reducto (spell2), ExpectoPatronum (spell3), AvadaKedavra(spell4), else (not one of spells, either win input or )


## ROOM.C

- isInt(charn[])
	- For the DROP n command, checks if n is indeed a valid number

- Main

	- Store POST content in char[] "userin". 
	- Parse userin and break into values "spell" (command from user), "counts" (client side counter that keeps track of how many valid spells have been attempted), "inventory".
	- Farther parse inventory and split into "inventoryG"/"inventoryM" (i.e. gold/mana) values
	- Reads the resource file and stores the values into "gold" and "mana"
	- if the command matches DROP n
		- Check if deduction from inventory is valid
		- If not, print page with msg that the user doesn't have enough gold
		- If it is, deduct from inventory gold, and add appropriate mana
		- If user inputs odd number ex. 3, only 2 gold is deducted from the inventory
	- if the command matches EXIT
		- Add user gold/mana to values in resources
		- Create string with new gold,mana,occupancy value (occupancy = 0)
		- Print the end screen

## DUMMY ROOM.HTML
---------------
- Due to my amazing social skills, I didn't collaborate with anyone on this project, so nobody's room links to mine. I know the whole point was that all the rooms create a system, but let's pretend I'm just an isolated node
- To make up for it, I created a dummy room that links to my transporter.py
- My room does transport to someone else's, though

## TRANSPORTER.PY
--------------
- Reads url and inventory values passed from form in prev room
- Opens resources.csv, checks if room is occupied or not
- If it is occupied, display submit form that sends usr back to initial url, passes inventory through POST
- If the room isn't occupied, reads inventory field and determines if user has enough mana
- If they do, print out room page with updated inventory, updates occupancy of room
- If they don't, prints death page (Umbridge's office) 
- I know my move buttons all go to the same place, but there's no time left

## BUGS
----
These are all bugs that can be avoided if you don't try to break the system (: 

*Gameplay:*

If "n n" ex. (1 4) is entered at any time, the game accepts the value and makes the changes as if it were a win scenario. Didn't have time to catch that

*DROP n, n>9*
Page is rewritten to the iframe but nothing else changes. Like above, didn't have time to catch this error

*QUIT:*
Command QUIT to exit spellcasting game doesn't clear DOM of iframe 

*EXIT:*
Exit during gameplay executes exit but doesn't display proper screen

 
## TODO
----
- Modularize functions such as read file, write to csv, read input, etc
