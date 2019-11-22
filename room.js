function submitCom(){
	var input = document.forms["commandf"]["command"].value;
	var count = $('input[name="count"]').val();
	if ( $(".transporter").css('display') == 'none'){var isHidden = true;};
	var isMatchWin = /\b\d\s\d\b/.test(input);
	var isMatchDrop = /\bDROP\s\d\b/.test(input);
	var isMatchExit = /\bEXIT\b/.test(input);
	$(".notEnoughGold").hide();
	count++;
	
	// Hide transporter elements if user is in play mode
	if (input === "PLAY"){
		//console.log("PlayMode");
		$(".transporter").hide();
		$(".instr").css('display','none');
		$(".instrGame").css('display','block');
		$('form[name="commandf"]').attr('action','/~cisaic/cgi-bin/game.cgi');
	}
	if (input === "Expelliarmus" || input === "Reducto" || input === "ExpectoPatronum"){
		$('input[name="count"]').val(count);
	}

	// Show transporter elements when game exits (either user exceeds attempts or QUITs)
	if (isHidden && count == 11 || isHidden && input == "QUIT"){
		$(".transporter").show();
		$(".instr").css('display','block');
		$(".instrGame").css('display','none');
		$('form[name="commandf"]0').attr('action','/~cisaic/cgi-bin/room.cgi');
		$('input[name="count"]').val(0);
		$(".response").contents().find("body").html("");
	}

	// Change target of form to rewrite to page instead of iframe 
	// if user wins the spellcasting game or exits the room
	if (isHidden && isMatchWin){
		//console.log("isMatchWin");
		$('form[name="commandf"]').attr('target','_self');
	}
	if (isMatchDrop || isMatchExit){
		//console.log("isMatchDrop");
		$('form[name="commandf"]').attr('target','_self');
	}


}
