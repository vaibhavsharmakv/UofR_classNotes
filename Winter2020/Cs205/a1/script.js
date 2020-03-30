// Variables for the program

// variable for the slider that determines the number of stars 
// this slider will record data from 0 to 200 with default value of 50  
var slider;

// An array that stores all the stars on the screen. PUSH function will be used to add stars into this array
var stars = [];

// currentNumberOfStars store the total number of stars that are currently on the screen and numberOfStars store the total number of stars that should be there. Both of these variables are  used to store the value from Star Slider which helps redraw the new number of stars when slider value is changed.
var currentNumberOfStars,numberOfStars ;

// These variables are used to for red blue and green sliders.
var rSlider, gSlider, bSlider;


 function setup(){

 	createCanvas(window.innerWidth, window.innerHeight);
 	textSize(15);
 	noStroke();

 	// Initializing all the sliders with their default values and position on the screen
 	// for changes -> createSlider(min value, max value, default )
 	slider = createSlider(0, 200, 50)
  	slider.position(20, 110)
  	rSlider = createSlider(0, 255, 0);
  	rSlider.position(20, 20);
  	gSlider = createSlider(0, 255, 0);
  	gSlider.position(20, 50);
  	bSlider = createSlider(0, 255, 0);
  	bSlider.position(20, 80);

  	// assiging number of stars from default slider value during the setup
  	numberOfStars =slider.value();

  	// pushing stars into Stars array to put on canvas on page load
  	currentNumberOfStars = numberOfStars;
 	for(let i = 0; i< numberOfStars;i++){
 		stars.push(new Star())
 	}
  	
 }

 

 function draw(){


 	// Assinging values from red, green and blue slider to r, g, b variables on every call of draw function
 	const r = rSlider.value();
  	const g = gSlider.value();
  	const b = bSlider.value();

  	// assigining background color according to the values from the sliders
	background(r, g, b );

	// adding text in UserInterface to indicate which slider is which. example "Red" means red sldier
	text('red', rSlider.x * 2 + rSlider.width, 35);
	text('green', gSlider.x * 2 + gSlider.width, 65);
	text('blue', bSlider.x * 2 + bSlider.width, 95);
	text('Stars',slider.x * 2 + slider.width, 125);

	//delete before production
 	//background(155,100,144);
 	
 	// Checking if the total number of stars on starSlider has been changed. 
 	//If changed -> newStars function is called
 	// newStars() : no parameters, returns a Integer value of total number of stars at the moment
  	currentNumberOfStars = slider.value();
 	if (numberOfStars != currentNumberOfStars) {

 		numberOfStars = newStars();
 	}

 	// looping throgh each index of stars array to appy functions on each star
 	// for each is passing two variables :
 	// s is used for each star 
 	// index is used to point at current index of the array which is important to connect the stars together
 	stars.forEach((s,index)=>{
 		// applying movement to stars
 		s.movement();
 		// making the stars
 		s.make();
 		// connectting the stars with a line if they are closer than 111 to each other
 		s.connectStars(stars.slice(index));
 	});


 	
 	
 	
 }

/**
 * Summary - New Stars function draw new stars when star slider value changes.
 *
 * Description - This function is fired when the numberOfStars are not equal to  currentNumberOfStars. It empties the Stars array and push new number of stars accoridng to slider value.  
 *
 * @access     public

 * @fires   function Empty()
 * @listens function Draw()
 *
 * @param {NULL}   No parametets used           
 * @return {Integer} Returns the value of numberOfStars
 */

function newStars(){
 	
	empty();
	var numberOfStars =slider.value();
 	for(let i = 0; i< numberOfStars;i++){
 		stars.push(new Star())
 	}
 	
 	numberOfStars = slider.value();
 	return numberOfStars;
 }


/**
 * Summary - Empties the Stars array
 * @access     public
 * @param {NULL}   No parametets used           
 * @return {NULL} Returns nothing
 */
function empty() {
    stars = [];
}	


/**
 * Summary.  The star class with methods used on the each star. 
 *
 * Description. (use period)
 *
 *
 * @constructs - nameless consturctor 
 	initializing 
 		pos = Initializing position of the star.
 		This variable creates a vector which uses two parameters. 
 		Random function is used on both parameters to slect a random location between width and height of the window.
 		this is done to make sure that the stars are not initializing outside the current window

		radius1, radius2, npoints = used to determine the size, shape of the star.

		move = used to move the stars in the window. This initialize a vector which choose a random value between -2 and 2 for both x and y axix to determine the velocity of the stars.

 *
 * @alias    realName
 * @memberof namespace
 *
 * @see   Function/class relied on
 * @link  URL
 */
class Star{
 	constructor(){
 		this.pos = createVector(random(width), random(height));
 		this.radius1 = 5;
 		this.radius2 = 10;
 		this.npoints = 5;
 		this.move = createVector(random(-2,2), random(-2,2));
 	}
 	make(){
 		noStroke();
 		fill('rgba(255,255,255,0.5)')
 		starShape(this.pos.x, this.pos.y,this.radius1, this.radius2, this.npoints);

 	}
 	movement(){
 		this.pos.add(this.move);
 		this.boundries();
 	}

 	boundries(){
 		if(this.pos.x<0 || this.pos.x>width){
 			this.move.x *= -1;
 		}
 		if(this.pos.y<0 || this.pos.y>height){
 			this.move.y *= -1;
 		}
 		
 	}

 	connectStars(stars){
 		
 		stars.forEach(star =>{
 			const distance  = dist(this.pos.x, this.pos.y, star.pos.x,star.pos.y);

 			if(distance< 111){
 				stroke("rgba(255,255,255, 0.3)");
 				line(this.pos.x, this.pos.y, star.pos.x,star.pos.y);
 			}
 		});
 	}

 }

function starShape(x, y, radius1, radius2, npoints) {
	  let angle = TWO_PI / npoints;
	  let halfAngle = angle / 2.0;
	  beginShape();
	  for (let a = 0; a < TWO_PI; a += angle) {
	    let sx = x + cos(a) * radius2;
	    let sy = y + sin(a) * radius2;
	    vertex(sx, sy);
	    sx = x + cos(a + halfAngle) * radius1;
	    sy = y + sin(a + halfAngle) * radius1;
	    vertex(sx, sy);
	  }
	  endShape(CLOSE);
}



/* References 

*/




