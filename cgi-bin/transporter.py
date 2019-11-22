#!/usr/bin/env python

import cgi, cgitb, csv
cgitb.enable()

# Store inventory and url values passed from prev room through post

print "Content-type:text/html\r\n\r\n"

form = cgi.FieldStorage()

inventory = form["inventory"].value
url = form["url"].value

with open('resources.csv', "rb") as csvfile:
	reader = csv.reader(csvfile)
	mycsv = list(reader)
	occ = mycsv[0][2]

print "<html>"

# print "<p> inventory %s url %s occ %s mycsv %s</p>" % (inventory, url, mycsv, text) 
# If the room is occupied, display form to send user back to prev page

if occ == "1":
	print "<body>"
	print "<p> The inquisitorial squad is on the prowl! It's not safe to enter the Room of Requirement at this time. Head back to your common room!\n</p>"
	print "<form action = \"http://%s\" method = \"POST\">" % (url)
	print "<input type = \"hidden\" name = \"inventory\" value=\"%s\">" % (inventory)
	print "<input type = \"submit\" name = \"submit\" value = \"CLICK ME\">"

# If room is unoccupied
else:
	invRead = csv.reader(inventory)
	invArr = list(invRead)
	invMan = invArr[2]
	invGold = invArr[0]

	newInvMan = ''.join(str(e) for e in invMan)
	newInvGold = ''.join(str(e) for e in invGold)
	costInvMan = int(newInvMan) - 1


	# If the user has 0 mana left after the cost of teleportation is deducted, print death screen

	if costInvMan < 0:
		#print "<p>life %s</p>" % (newInvMan) 
		print "<head>"
		print "<link rel=\"stylesheet\" href=\"/~cisaic/style.css\">"
		print "<title> Umbridge's office </title>"
		print "</head>"
		print "<body>"
		print "<div class = \"bg2\">"
		print "<div class=\"col1\">"
		print "</div>"
		print "<div  class=\"col2\">"
		print "<h1 style=\"color:white;margin-top:10%%;\"> BUSTED! You've been caught by the Inquisitorial Squad! Report to Umbridge's office for detention... and some tea."
		print "</h1>"
		print "</div>"
		print "<div class=\"col3\">"
		print "</div>"
		print "</div>"

	# If the user has at least one mana left, print the room with the user's gold and mana inventory fields passed from prev room
	else:

		# change occupancy of resources.csv
		RmGold = mycsv[0][0]
		NRmGold = str(RmGold)
		RmMana = mycsv[0][1]
		NRmMana = str(RmMana)


		newResources = [NRmGold, NRmMana, '1']

		with open ('resources.csv', "w") as f:
			wtr = csv.writer(f)
			wtr.writerow(newResources)

		print "<html>"
		print "<head>"
		print "<link rel=\"stylesheet\" href=\"/~cisaic/style.css\">"
		print "<title> Room of Requirement </title>"
		print "<script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.2.0/jquery.min.js\"></script>"
		print "<script src=\"/~cisaic/room.js\"></script>"
		print "</head><body>"
		print "<div class=\"col1\">"
		print "<div class = \"instr\">"
		print "<h1> Commands </h1><p> <b>DROP n</b> : Drop n gold from your inventory. 2 gold = 1 mana </br><b>PLAY</b> : Start the spellcasting lesson</br><b>QUIT</b> : Stop the lesson</br><b>EXIT</b> : Drop everything in your inventory and leave the game </br><b>REFRESH</b> : Refresh the page</p></div>"
		print "<div class =\"instrGame\"><h1> How to play </h1><p> Today we will be learning three different spells. You win if your spell is successful. You have 10 attempts to cast any combination of the three options. Make sure to spell them exactly as they're written below (no pun intended) <br/><b>Expelliarmus</b> : (Easy) Defensive spell that disarms your opponents  <br/><b>Reducto</b> : (Medium) A curse that can be used to blast solid objects to pieces <br/><b>ExpectoPatronum</b> : (Hard) The only known defense against Dementors. Conjure your animal Patronus by thinking of the happiest memory you can. </p></div></div>"
		print "<div class=\"col2\">"
		print "<h1 class = \"title\"> Room of Requirement </h1>"
		print "<img class = \"room\" src=\"/~cisaic/rmreq.jpg\">"
		print "<div class = \"sandbox\"><form action = \"http://cs.mcgill.ca/~syu47/room.html\" class=\"transporter\">"
		print "<input type = \"hidden\" name = \"inventory\" value=\" %s,%s\">" % (newInvGold, newInvMan)
		print "<input type = \"hidden\" name = \"url\" value = \"cs.mcgill.ca/~cisaic/room.html\">"
		print "<input type = \"submit\" value = \"NORTH\" class=\"north cardinal\">"
		print "<input type = \"submit\" value = \"EAST\" class=\"east cardinal\">"
		print "<input type = \"submit\" value = \"WEST\" class=\"west cardinal\">"
		print "</form>"
		print "<form action = \"/~cisaic/cgi-bin/room.cgi\" method = \"POST\" accept-charset= \"utf-8\" name =\"commandf\" id = \"#commandf\" target=\"response\">"
		print "<input type = \"text\" class = \"command\" name = \"command\">"
		print "<input type = \"hidden\" name = \"count\" value=\"0\"><input type = \"hidden\" name = \"inventory\" value = \"%s,%s\">" % (newInvGold, newInvMan)
		print "<input type = \"submit\" class = \"submit\" onclick = \"return submitCom();\">"
		print "</form>"
		print "<form action = \"http://cs.mcgill.ca/~syu47/room.html\" class=\"transporter\"><input type = \"hidden\" name = \"inventory\" value =\"%s,%s\">" % (newInvGold, newInvMan)
		print "<input type = \"hidden\" name = \"url\" value = \"cs.mcgill.ca/~cisaic/room.html\"><input type = \"submit\" value = \"SOUTH\" class=\"south cardinal\"></form></div></div>"
		print "<div class=\"col3\">"
		print "<h1> Interaction </h1>"
		print "<iframe name=\"response\" class=\"response\"></iframe></div>"

print "</body>"
print "</html>"

