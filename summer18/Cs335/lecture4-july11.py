Chapter 2 - Application layer

Port numbers = 16 bit
	0-> ((2^16) -1)
	Port from 0 to 1023 are reserved 
	If we want a new application to run on a new port then we user 1024+ -> 2^16

Ip adress is 32 but

senidng a message 
M = message
H = header
S = segement
D = Datagram
F = Frame


Application = M is encrypted
Transport = M + H = S
Network = S + H = D .... uses ARP
Link = D + Mac(source) +Mac(destination) = Frame(packet)
----------------------
*** HTTP always uses tcp
