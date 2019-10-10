Sep 11 
-----------------------
SDLC - software development life cycle 
	- Requirement 
	- Design 
	- development 
	- testing 
	- maintanence 

Types of maintanence 
	- Corrective 
		- We correct the problems  
	- adaptive 
		- we make changes according to the change in need
	- perfective
		- making changes according to the changing user requirments
	- preventive
	- Evolutionary

!! everything else is genernal 

Sep 18
-----------------------

- Why we need software managment ?
	- we need software management to make sure everything is on time and 
	goals are being met 
	management tasks need to be perfoemed regarldess of big or small project



- Project Control
	- time
		- Brooks's law ? 
			- more people = more delay 
		- Measuring time is diffcicult as there are diffrent variables when it come to development
	- information
		- Documentation
			- Project Managers make sure the documentation is on time and accoridng to the standards
		- In Agile -> the tactical knowlegede of people is given more preference over documentation
	- people
		- builing a health work enviorment in the team 
		- working together and building a team
	- cost 
		- meausruing progress with cost is irrelevant 
		- need to divide cost in diffrent cycles 
	- quality
		- Everyone have their own standards of quality and it needs to checked throughout and discussed with the stakeholder
		- quality explectations need to be designed and set 

- Project Manager 
		-  the highest ranking post in a team
		- wokrs throughout all the diffrent phases in the development
		- managisk risk, tracking project milestones

**Pert Chart 
Program evaluation review technique 
critical time = longest time
** Gant Chart

Sep 25
------------------------
- software development life cycles 
	- SDLC 
	- waterfall
		- follow V&V
			- verification and validation
		Water follows Iteration and feedback and V&V
		Problems  
			- once the phase is gone then its gone 
			- not optimal for changing requirments
	- Lightweight Agile Aproach
		- prototyping
			- Gives user a hand on feel on what the fnished application will look like
			- good protyping is cheap and gives user and developers better idea about requirments
			- ThrowAway prototyping
				- The last protype is used towards the waterfall development
			- Evolutionary prototyping
				- the nth protype is delivered
			- Advantages 
				- the result is more friendly with the user 
				- the result is the expected system 
			- Disadvantages 
				- the resulting system have more features 
				- the design is of less quality 
				- this aproach requires more experienced team
			- Recomendations 
				- the users are the designers must be well aware about the issues 
				- best to use when requiremnts are unclear 
				- needs to be properly planned and controlled

		- incremental development
			- starts with a base with very less features but everythig working properly 
			then slowly add more features with full fidelity
			- Advantages
				- software system is delivered in small increments
				- the waterfall model is employed in each phase
				- prevents overfunctionality  
		- RAD
			- The basic idea is that things alwasy change
			- Timebox 
				- a specific time period in which the team have to deploy or finish the task 
			- devlopment is done using timeboxes
			- fixed time schedules
			- development in SWAT team 
				- Skiller workers with Advanced tools
			Have 4 phases 
				- Requirement
					- Everyone agree on genral requirments
					- this includes programmer, other teams and stakeholders
				- User design 
					- Requirements are converted into Design 
					- uses brainstorming, prototyping
				- Contruction
					- developers build application from the design
				- Cutover
					- the finsihes applciation is delivered
		- DSDM
			- Dynamic system development method 
			- one of the heavy agile methods
			- Also uses timeboxes
			- total three phases
				- Pre project 
					- this is the time before development, everythig is designed and requirments are gathered
				- project life cycle - actual product is built
				- post project  - maintanence
		- XP
			- Extreme programming
				-everythig done in small steps 
				- client as the center of the development team 
	- Diffrent Between light weight Agile and heavy Weight agile
		Lightweight - 
			- knowledgeable, collacted and collaborative
			- rapid changes 
			- designed for current requirments
			- smaller teams and products
		HeavyWeight	- 
			- Plan driven, acces to external knowledge
			-  largely stable and knowable early 
			- designed for current and foreseeable requirments
			- larger teams

OCt 2 
------------------------------------
Software Quality
	- Software quality is important to make sure the product conforms to the standards and norms 
	- quality in process and product
	- process quality metrices
	- product quality metrices
	- project quality metrices
Quality 
	- Attribute 
	- entitty 
	- Attribute relations


Oct 9 
---------------------------------------

What is a model ?
why do we model ?
	- Model is a representative of the reality, we model to get better understanding about the the product. Its just the representative of the reality but its not a relaity itslef 
We model to 
	- manage complexity 
	- To detect errors in the early stages 
	- to understand requirments
	- to communicate with stakeholders
We use model to descibe software systems 


Requirements
	- three type of requirments
		- Functional 
			- the essential functions that system needs to carry out
		- Non Functional
			- the functions that are related to qulaity and performance
		- enviormental 
			- legal issues and standards

UML
	- Unified modeling language 
	- two types of Diagrams 
		- Structure Diagrams
			- Class Diagrams
			- object Diagrams
		- Behavior Diagrams
			- USe Case Diagrams
			- state machines Diagrams
			- Interactions Diagrams
				- Sequence Diagrams
	- Why we use UML?
		- We use UML for 3 things 
			- As a sketch 
			- As a blueprint 
			- As a programming language
	- Use case Diagrams
		- Objective
			- Helps user understand the system architecture
			- helps identifying users and functionality 
			- identufy how the system will be used.
		- Components
			- Actor 
			- Use Case 
			- Connector 
			- Generalisation 
			- stereotype(Relationship)
				- include 
					- Implicit function 
				- extend 
					- explict function 

Oct 16
----------------------------------------
- Structure and Behavior Diagrams
	- Structure 
		- Structure diagrams define the structure of the archtitecture and model
		- it explains the layput and how everything is connected together
		- defines Relationship in structures
	- Behavior
		- Its the OO design of the objects in Class
		- Relationship between objects

Class Diagrams
	- Assosiations
	- Objects Diagrams
	- Aggregation
	- Compsition
	- Dependencies
	- Interface and Ingeritence

Oct 23
-----------------------------------------
- Sequence Diagrams 
	- Objective 
		- Detailed UML use case 
		- show the model in flow state 
		- see how onjects interact with each other
	- Components
		- messages 
		- reply messages 
		- actors
		- activation
		- request message

Oct 30
-----------------------------------------
- what is User Interface
	User Interface is how the use interact with the system. 
	- UVM ?
		- User Virtual machines
	- design aspect 
		- how to design for the user !
	- human aspect
		- what human needs to undersatnd about the design !
- Model in HCL 
	- Internal Model
		- mental model 
		- user modem 
	- External model 
		- Conceptual model 
		- programming model 
- Mental model
	- How user assume the syste will behave
	- door knob
	- how user want system to work 
- Conceptual model
	- how the systems actually work  
	- what user need to know about the system
- Guidelines
	- rules or documentaion about the UI for the user to use the system
- UI prototyping
	- a working model of the System that needs to be approved by the stakeholders before its developed
	- a basic UI structure to give user an idea about how the UI of the final product


Nov 6
---------------------------------------
- Concurrency 
	- Race condition 
		- when resources are accessed at the same time then nil can be a expected result which leads to system crash
	- Resoruce Starvation 
		- priority increases with age 
	- Deadlocks
		- two candian threads


Nov 13 
---------------------------------------
- FSM 
	- used for design and communication purposes
- State machine diagram
	- The state machine diagram {You know it!!}


Nov 27
---------------------------------------
- Abstratc data type 
	- Objective 
		- The intent is tp provide clear and defined semantics for the o0perations

































