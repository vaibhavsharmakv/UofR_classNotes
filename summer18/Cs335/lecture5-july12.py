HTTP -
	HTTP Request Message
	- first thing we need is a connection between server and client
	- then we figure out what type of connection it is Mostly TCP/IP
	- then Client request a HTTP request that consist of :
		- Request line -> client tells the server what he wants
		- Header line -> contains info about the server, example- Host, User-Agent
		- Body - option text that we can add
	- Client send the request in his own Http version which then get parsed to server Http version

	HTTP Response Message
	- client sent the Http request to the server 
	- now server send a response back 
	- the request contains 3 things
		- status line -> tell us of the request was sent succesfully and whats server gonna do now. also the HTTP versions
		- header line -> contains info about the response. - connection type, last modified
		- data -> the data that client requested for
	*clients dont have host name
 
	 Server response codes
	 	- 200 -> OK
	 	- 301 -> moved permanently
	 	- 400 -> Bad request
	 	- 404 -> Not found
	 	- 505 -> HTTP version not supported

	 	* HTTP is Stateless
	 	* Client can reject to use cookies

 Cookies 
 	- when client makes a request to the server
 	- the server sends the response and assign client with the id
 	- example - set cookie :1687
 	- when client uses the same server again after 1 week. He run on the same cookie
 	- Not always encrypted
 	- where are cookies used ?
 		- Authetication 
 		- Shopping cart
 		- Product recomendations
 	* cookies is always in the respsonse Message and request Message
 	- In cases of cookies, browser store the cookie number

 Proxy Server
 	- when client makes a http request 
 	- it goes to the proxy server and it checks if it have that website cached
 	- If not -> then the proxy server request it to the orignal server
 	- If Proxy server already have it 
 		- then he checks if its updated
 			- If updated then request the most latest version
 			- If not then he shows the client the version he have

 	* Proxy server is Both server and Client

Email 
	- Contains 3 things
		- User-Agent -> can read,organise emails on mailing clients
		- Mail server 
			- inbox 
			- outbox
		- SMTP
			- Simple mail tranfer protocol 
			- Used for sending emails
			- Also uses TCP and work with Transport layer
			- How does SMTP works ?
				- Handshaking -> open the connection and starts the process 
				- Transfer of messages -> data Transfer
				- closure -> close the connection 
		- SMTP and HTTP 
			- SMTP formal 7 bits of Ascii 
			- SMTP requires a format where a Http does not
			- SMTP is a push client 
			- HTTP is a pull client

		- POP3 
			- Authorization
			- transaction 
			- update
		- IMAP 
			- we can create folders
			










