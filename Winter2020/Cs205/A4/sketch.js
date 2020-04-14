//Variables 
//animate is used to make eclipse bigger and smaller during electtric shock
let animate = 45;
//size is used to make eyes smaller or bigger
let size = 10;
//strokeColor used to select color of the stroze
let strokeColor = 0;
//shock variable used for the mp3 file 
let shock;

function preload() {
// importing sound and image 
 shock = loadSound('shock.mp3'); 
 bg = loadImage('assets/chair.jpg');
 
}

function setup() {
  //Creating canvas with the size of 700 X 600 rather than using image height and width on purpose
  createCanvas(700, 600);
  angleMode(DEGREES);
  // selecting imported background image during the setup
  background(bg);
}

function draw() {

  //Left Eye
  fill(255, 255, 0);
  strokeWeight(1);
  //Ellipse to animate while shock
  ellipse(380, 200, size);
  //animate is constrainted
  animate = constrain(animate, 0, 45);
  // making the inside of the ellipse hollow
  noFill();
  // bigger stroke weight to only have border outside
  strokeWeight(16);
  stroke(strokeColor, strokeColor, 0);
  arc(380, 200, 20, 20, 0 + animate, 360 - animate);
    
  // Right Eye
  fill(255, 255, 0);
  strokeWeight(1);
  ellipse(400, 200, size);
  animate = constrain(animate, 0, 45);
  noFill();
  strokeWeight(16);
  stroke(strokeColor, strokeColor, 0);
  arc(400, 200, 20, 20, 0 + animate, 360 - animate);

  // when the key is pressed 
  if(keyIsPressed) {
    // ellipse animates and completes
   animate -= 8;
  } else {
    // if the key is not pressed 
   animate += 8;
  }
  if(animate < 1) {
    //size of the eyes getting bigger
   size = 10; 
   //selcting random eyes color
    strokeColor = random(175, 255);
  } else {
   size = 5; 
    strokeColor = 0;
  }
}
// function implemented when key is pressed
function keyPressed() {
    // selecting imported background image 
  background(bg);
  //plays the shock sound
  shock.loop(); 
}

function keyReleased() {
   // selecting black background image 
  background(0);
  //stops playing the shock sound
  shock.pause(); 
}