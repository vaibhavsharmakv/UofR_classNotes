//Variables 
// Shocked and hain flag initialised as false 
// These flags used later to determine if potrait is shocked or hain
shocked = false;
hain = false;


function setup() {
  // Basic setup creating canvas and selecting the color modem 

  createCanvas(400, 400);
  colorMode(RGB);
  // Selecting background color as light yellow
  background(255, 255, 209);

}

function draw(){
  //Skin Color
  fill(255, 220, 177);
 
  //Ears
  noStroke();
  //Left
  arc(109, 170, 40, 60, PI / 3, 3 * PI / 2);
  //Right
  arc(290, 170, 40, 60, 3 * PI / 3, PI /1.5);

  //Face
  strokeWeight(0);
  ellipse(width / 2, height / 2, 200, 300);

  // Eyes
  fill(255);
  noStroke();

  // if potrait is shocked 
  if (shocked) {

   // Big eyes
  ellipse(width / 2.5, 165, 60, 35);
  ellipse(width / 1.6, 165, 60, 35);
  }
  // if potrait is not shocked
  else{
      //normal eyes
  ellipse(width / 2.5, 165, 60, 25);
  ellipse(width / 1.6, 165, 60, 25);

  }

  // Iris
  fill(169, 58, 4);
  stroke(46, 180, 25);
  ellipse(width / 2.5, 165, 30, 28);
  ellipse(width / 1.6, 165, 30, 28);
  // Pupils
  fill(0)
  ellipse(width / 2.5, 165, 15, 15);
  ellipse(width / 1.6, 165, 15, 15);

  
  //Eye Brows
  noFill();
  strokeWeight(10);
  stroke(0, 0, 0,200);
  
  // if shocked and not hain then 
  if (shocked && !hain) {

   // Raise eyebrow
  bezier(190, 146, 173, 125, 140, 130, 125, 149, );
  bezier(220, 145, 230, 125, 285, 135, 282, 149, );
  
  }
  // If not shocked and only hain
  else if(hain){ 

  bezier(190, 146, 173, 137,140, 120, 125, 142, );
    //Right
  bezier(220, 145, 230, 140, 285, 145, 282, 149, );
  
  }
  // if both are false
  else{

   //Left
   bezier(190, 146, 173, 137, 140, 140, 125, 149, );
     //Right
  bezier(220, 145, 230, 140, 285, 145, 282, 149, );
  }

  //Nose
  fill(0, 0);
  curve(150, 20, 202, 182, 199, 246, 350, 150);

  //Mouth
  //Lips Color
  stroke(169, 58, 4);
  //Lips Width
  strokeWeight(1);
  //Inner Mouth Color and Shape
  fill(255);

  // different mouth allignment when surprised
  if (shocked) {
    // surprise
  ellipse(198, 285, 50, 35);
  
  }else{
  
  arc(width / 2 , height / 1.55 +10, 90, 50, 0, HALF_PI + HALF_PI, PIE);
  }
  

  //Hair
  //Main
  rectMode(CENTER);
  fill(0, 0, 0);
  noStroke();
  rect(width / 2, 80, 180, 60, 40);
  //TOP
  rectMode(CORNER);
  //arc(width / 2, 85, 200, 80, PI, 0);
  //BANGS
  triangle(163, 96, 195, 99, 163, 125);
  triangle(196, 96, 215, 99, 200, 125);
  triangle(220, 96, 240, 98, 216, 125);
  //SIDEBURNS
  arc(120, 110, 20, 90, 2 * PI / 2.75, 5 * PI / 3);
  arc(280, 110, 20, 95, -2 * PI / 2.5, -5 * PI / 3);

}
// If mouse if pressed then shocked is true
function mousePressed() {
  shocked = true;
}
// If mouse if released then shocked is false
function mouseReleased(){

  shocked = false;

}
// if the key pressed is up arrow then hain is true
function keyPressed() {
  if (keyCode === UP_ARROW) {
    hain = true;
  }
}
// if the key released is up arrow then hain is false
function keyReleased() {
  if (keyCode === UP_ARROW) {
    hain = false;
  }
}



