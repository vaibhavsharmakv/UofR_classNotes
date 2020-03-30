let img;
let env;
var attackLevel = 1.0;
var releaseLevel = 0;
var x, y;
var attackTime = 0.001;
var decayTime = 0.2;
var susPercent = 0.2;
var releaseTime = 0.5;
var sFreq = 220;
var rfrac, gfrac, bfrac;
var rgb8 = 4;
var visited;
var missed = 0;
var recorder;
var soundFile;

var osc;

function preload() {
  //img = loadImage('http://www2.cs.uregina.ca/~hepting/assets/about/img/dhh-2012-360x360.jpg');
	img = loadImage('http://www2.cs.uregina.ca/~hepting/assets/gallery/img/1990-Hep-Fiery-Dragon-tn.png');
}

function setup() {
  // loadPixels must be called before img.width and img.height have values
  img.loadPixels();
  // allocate storage to keep track of which pixels have been visited
	// and initialize it to 0's
  visited = new Array(img.width * img.height);
  for (x = 0; x < img.width; x++) {
    for (y = 0;y < img.height;y++) {
      visited[y*img.width + x] = 0;
    }
  }
  var cnv = createCanvas(img.width, img.height);
  noStroke();
  background(192);
  
  frameRate(rgb8);
  x = img.width / 2.0;
  y = img.height / 2.0;
  
  env = new p5.Envelope();
  env.setADSR(attackTime, decayTime, susPercent, releaseTime);
  env.setRange(attackLevel, releaseLevel);
  
  //  'sine' (default), 'triangle', 'sawtooth', 'square'
  osc = new p5.Oscillator('sine');
  osc.amp(env);
 	osc.start();
  osc.freq(400);
  // create a sound recorder
  recorder = new p5.SoundRecorder();

  // connect the oscillator to the recorder
  recorder.setInput(env);
  soundFile = new p5.SoundFile();
  recorder.record(soundFile);
}

function draw() 
{
  x = int(x + random(-rgb8,rgb8*1.1));
  y = int(y + random(-rgb8,rgb8*1.1));
  if (x < 0 || x >= img.width) {
    x = floor(random(img.width));
  }
  if (y < 0 || y >= img.height) {
    y = floor(random(img.height));
  }
  if (visited[y*img.width+x] == 1)
  {
    while(visited[missed] == 1 && missed <= (img.width * img.height) - 1)
    {
      missed++;
    }
    if (missed == img.width * img.height)
    {
      print("DONE");
      noLoop();
      osc.stop();
      recorder.stop();
    	//soundFile.play(); // play the result!
      save(soundFile, 'mySound.wav');
    }
  	visited[missed] = 1;
  	y = int(missed/img.width);
  	x = missed - (y * img.width);
  }
  let pix = img.get(x, y);
  fill(pix);

  var tottime = 0;
  if (rfrac = pix[0]/255.0) 
  {
    attackTime = 0.01 + rfrac* 0.1;
    tottime += attackTime;
  }
  if (gfrac = pix[1]/255.0)
  {
    decayTime = 0.02 + gfrac* 0.2;
    tottime += decayTime;
  }
  if (bfrac = pix[2]/255.0) 
  {
    releaseTime = 0.04 + bfrac* 0.4;
    tottime += releaseTime;
  }
  osc.freq(rfrac*880+gfrac*440+bfrac*220+missed);
  rgb8 = int((rfrac+gfrac+bfrac)*2+2);
  frameRate(rgb8);
  env.setADSR(attackTime, decayTime, rgb8/8.0, releaseTime);
  env.setRange(1.0, 0.0);
  playSound();
  ellipse(x, y, 1,1);
  visited[y*img.width+x] = 1;
}

function playSound()
{
  env.play();
  env.ramp(osc, 0, 1, 0);
}

