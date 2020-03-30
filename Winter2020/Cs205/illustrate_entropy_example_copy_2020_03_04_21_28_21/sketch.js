//
// Interactive example of zooming into a bitmap (text as
// image)
//

// Define variables to count the number of occurences of each
// of the 4 pixel values:

var count0 = 0
var count1 = 0
var count2 = 0
var count3 = 0
var surpriseSlider
var tinyCanvas
var surprise = -1
var img
var new_surprise

function setup() {
  createCanvas(480, 480)
  img = loadImage('myCanvas.jpg');
  //draw()
  //saveCanvas(c, 'myCanvas', 'jpg');
  // create slider and position it
  surpriseSlider = createSlider(48, 480, 100)
  surpriseSlider.position(40, 10)
  pixelDensity(1)
  frameRate(1)
  imageMode(CORNER);
  image(img, 0, height / 2, img.width / 2, img.height / 2);
  
  //tinyCanvas = createGraphics(200, 200)
  //image(img, 100, 100);
  //img.resize(new_surprise, new_surprise)
} 

function draw() {
  count0 = 0
  count1 = 0
  count2 = 0
  count3 = 0
  background(255,0,0) // red
  noSmooth()
  pos = 0
  //frameRate(1)
  sc = surpriseSlider.value()
  push()
  translate(-(sc / 100.0) * (width/2),-(sc / 100.0) *(height/2))
  scale(sc/100)
  
  //image(img, width /2, height/2, img.width * (sc / 100.0), img.height * (sc / 100.0));
  image(img, width /2, height/2)
  pop()
  
  
  //print(new_surprise)
  
  
  /*textSize(32);
text('word', 30, 60);
fill(0, 102, 153);
text('word', 30, 90);
fill(0, 102, 153, 51);
text('word', 30, 120)
  for (var i = 0; i < 400; i++) 
  {
    var pxval = nextValue() * 255
  	for (var j = 0; j < 3; j++) 
    {
    	tinyCanvas.pixels[pos+j] = pxval
  	}
    tinyCanvas.pixels[pos+3] = 255
  	pos += 4;
  }
  */
  //tinyCanvas.updatePixels();
  //scale(20);
  //image(tinyCanvas,200,2,0,0)
  //print(count0,count1,count2,count3)
}

