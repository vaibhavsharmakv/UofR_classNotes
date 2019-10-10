Chapter 3 
--------------------
- MVC 
	- A design architecture to organise the project 
	- Model 
		- All the data manipulation and retrivel from database is stored here
		- Selcet, where
		- decoupled from view
	- View 
		- Everything that user can see and interact with is in the view 
		- decoupled from the model 
		- have buttons, text and other interactions
	- Controller
		- Controller connects model with view
		- active listener, listens to the notifications from view and chnages from model and update each other
		- does not do any data manipulation
	- benefits 
		- eveything is decoupled which promotes reusability 
		- easy to add changing requirements 
		- easy to follow for a new developer 
		- prevent sideeffects of one file to another

- protocol and delegate 
	- This allows a class to confrom to certain rules when being a delegate of another class
	- protocols are set of rules declared in the class but defined in the class which is using it
	- an example would be base class being the delegate of the second class and confofrming to the protocol by defining the function 

- target event 
	- this is event driven. when user interacts with the view then something happens through the controller 
	- the view have no knowledge of whats gonna happen other than who to notify when certain event takes place

- multiThreading
	- dispatching diffrent task on diffrent queues accoring to the priority and time to maintain asyccornity
	- user interactions are alwasy on the main thread to avoid latency 

Chapter 4 
-------------------
- types of applications
	- Immersive 
	- utility 
	- productive
- HCI
	- Design priciples 
	- feedback 
	- choose over recall
	- priotiyy on primary task 
	- easy to exit 
	- gestures and interactions
	- user readable from


Chapter 6 
-------------------------

- Ambient Intelligence
	- Intelligence of the device to perform events based on location , motion and past activities
-Location Awareness	
	- iphone awareness of where it is, gets better with time
	-wifi 	- uses wifi access points to figure out the location of the user
	- cellular  - use cellular towers to figure ou the location of the user
	- gps	- use sattelites to figure out the location of the user

- Core Location - core location is IOS librarry which helps finding the accurate location bases on gps -> cellular -> wifi 	
	- handles all this automatically 
	- heading
		- finding the locatoin of the devcie using compas in the phone. this is when user does not allow location settings
	-  Geocoding
		Converting gps human readable to lattitute and longitude and other way arround
		- forward geocoding 
			- converting lat and long to human readable 
		- reverse geocoding 
			- converting human to readable to lat and long

- Core Motion ->Motion Awareness - Iphone have diffculty finding the exact motion due to gracity so it s not accurate
	- Motion sensor 
		- the movement and the gravity
	- gyroscope
		- fix the issue with gravity and allows accelerameter to figure out when its gravity and when its Motion
	- Acclerometer 
		- how fast the device moves
	- magnetometer
		- the orientation of the device 
		-	pitch, roll , yaw

Device motion -> Gyrocope + accelerameter + magnetometer = given accrurate motion 


Chapter 7 
---------------------------
Why use a delegate over completion handler ?
	We need to make the request asyc so we dont disturb the main thread. Using delegate will automatically run the url session or task
	on a new thread and we can get back on main thread using DispatchQueue.main.asyc
	This takes care of the completion handler and make url request and data retrivel two diffrent task which help in debugging


Chapter 8
---------------------------
Queues 
	- main 
	- cocurrent
Grand central dispatch
	- main queue 
	- global queue 
	- custom queue
multi peer conectivity 
push notifications


Chapter 9 
---------------------------
document 
document/inbox
librarry
librarry/caches
temp

why specify the path using url sessions ?

archeive files
archive 

saving bool/emum from model class

chapter 10
----------------------------
Evaluations methods ?

why ?
	- to test the the app against requirements
	- to test if its easy to use 
	- easy to learn 
	- can users understand the flow

how ?
	- expert reivews 
	- lab testing 
	- usability test
	- field trials
	- longitude trials



