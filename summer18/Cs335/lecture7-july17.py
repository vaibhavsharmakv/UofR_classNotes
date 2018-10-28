In client server architecture 
	- clients cant interact with each other 


If server has a file of size f bits and it needs to be sent 
	- u1, u2, ... un for upload rate
	- d1, d2, ....dn for download rate
so the time it will take for the server to download the file on N users
	screenshit - IOS
--------------XXX-----------------------
Transport Layer 
	- Process to Process 
	- Error checking 
	- Reliable data transfer
	- Congestion control
	- flow control
	- Connection establishment

	We have 2 types 
		- UDP -> process to process, Error checking
		- TCP/IP -> all of the abhove 

	Process to Process 
		- there are way too many process running at the same time that wants to use 
			the internet but there is only 1 communication link we pack them all together using port number and 
			ip adress, its called multiplexer and then its taken out and everything goes to correct process and its called
			demultiplexer
		- There are 2 ways to to this 
			- Connectionless MUX/DMUX
				- to identify which process it is, only port number is used
				- we only need source and destination port number
				- so the client ask the destination for the port number and thats how they connect 
			- Connection oriented MUX/DMUX
				- Both Ip adress and port numbers are used to fiure out where the packet is going
	UDP - Segment 
		- Message + Transport layer packet
			- we add 8 bytes - 64 bits
			- it includes 
				- Source port
				- Destination port
				- Length 
				- Checksum
	TCP /Ip - Segment
		- 20 byte is the maximum segment size
		- 8 bytes are required for relaible tranfer 
		- so message can only be 12 bytes long
	
	 
