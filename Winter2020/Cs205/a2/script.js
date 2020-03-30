
var textInput ;

function getTextInput(){
	document.getElementById("myCanvas").style.display = "none";
	var textInput = document.getElementById("myText").value;
	return textInput;


}
function writeText(){

	var c = document.getElementById("myCanvas");
	var ctx = c.getContext("2d");
	ctx.font = "30px Arial";
	ctx.fillStyle ="white";
	ctx.clearRect(0, 0, canvas.width, canvas.height);
	ctx.fillRect(0, 0, ctx.width, ctx.height);
	ctx.fillText(textInput,10,50);



}

function displayText(){
	var c = document.getElementById("myCanvas");
	const dataURI = c.toDataURL("image/jpeg");
	var newImage = document.getElementById("textImage");
	newImage.src = dataURI;


	//newImage.setAttribute("data-hight-src",newImage.src)


}

function downloadImage(){

	var a =  document.getElementById("downloadTag");
	var c = document.getElementById("myCanvas");
	a.href = c.toDataURL("image/jpeg");
	a.download = "image.jpg";


}

function setup(){

  	
}

 

function draw(){

	textInput = getTextInput();

	writeText();

	displayText();

	downloadImage();


 	
 }







