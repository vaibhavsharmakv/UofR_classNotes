from last class

~(PvQ)=(~P)^(~Q)
~(P^Q)=(~P)v(~Q)
==========================================
Example 1.0 - Notebook 1.0

Obeservation - 
By looking at the truth table
     PvQ = QvP
     P^Q = Q^P 

Another connective "=>" means Imply
We define P => Q via truth table 
table - Notebook table 1.0 

Using the table 1.0 prof prooved the ~(P=>Q) = P^(~Q)
Example 1 - It rains then I get an umbrealla

            P = it rains
            Q = I get an umbrealla

            ~(P=>Q) = P ^ (~Q)

            It rains and i dont get an umbrealla

Example 2 - If your older then 18 or you have parents permission then you can go on this trip 
            P1 = if you are older then 18 
            P2 = if you have parents permission
            Q = you can go to the trip 

            P=>Q =(P1vP2)=>Q
            ~(P=>Q) = P ^ (~Q)
                    = (P1vP2)^(~Q)
            "IF YOU ARE OLDER THEN 18 AND HAVE PARENTS PERMISION THEN YOU CANNOT GO THE TRIP "

Example 3 - "IF YOU ARE HUNGRY THEN YOU CAN HAVE CAKE AND JUICE "
            P =  if you are hungry 
            Q1 = you can have cake 
            Q2 = you can have juice 

            ~(P=>Q) = P^ (~Q)
                    = P ^ (~(Q1^Q2))
                    = p ^(~Q1 v ~Q2)
            "IF YOU ARE HUNGRY THEN YOU CANT HAVE CAKE OR YOU CANT HAVE JUICE"

(P=> Q) != (Q=> P)
so they are order dependent, we cannot change the order
Notations to remember
    "P<=Q" means "Q => P"
    "P<=>Q" means IF AND ONLY IF "P=>Q" &"Q=>P"





