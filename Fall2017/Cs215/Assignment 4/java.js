function messageCount(Event)
{

	var msg = document.getElementById("Message");
	var len= msg.value.length;
	
	if (len<500) {
	document.getElementById("Message_err").innerHTML= len +"/500";

	}
	if(len>500){
		document.getElementById("Message_err").innerHTML= len +"/500"+" Count increased the Max limit. ";

	}
	
}



function funcEmail(Event)
{
	var result = true;
	var mail = /^\w+@[a-zA-Z_]+?\.[a-zA-Z]{2,3}$/; 

	var Email= document.getElementById("email");
	var a= Email.value;
	if (mail.test(a)== true) {
		document.getElementById("email_err").innerHTML= "";
	}
	 if (a==null || a==""||!mail.test(a))
	{
	document.getElementById("email_err").innerHTML= "*The Email adress is not valid.Example of a valid email adress'abc@abc.com'";
	result = false;
	Event.preventDefault();
	}

	
}

function funcPassword(Event)
{
	var pass= /^(?=.*[0-9])(?=.*[!@#$%^&*])[a-zA-Z0-9!@#$%^&*]{8,15}$/;
	var password= document.getElementById("password");
	var passV=password.value;
	if (passV.match(pass))
	{
		document.getElementById("password_err").innerHTML= "";	
	}
	if (!passV.match(pass))
	 {
	 	document.getElementById("password_err").innerHTML= "*The Password is not valid.";
	 	Event.preventDefault();
	 }

		
}

function password(Event)
{
	var pass= /^(?=.*[0-9])(?=.*[!@#$%^&*])[a-zA-Z0-9!@#$%^&*]{8,8}$/;
	var password= document.getElementById("password");
	var passwordValue= password.value;
	var passs= document.getElementById("pswdr");
	var passwordValue2= passs.value;

	if (passwordValue.match(pass))
	{
		document.getElementById("password_err").innerHTML= "";	
	}
	if (!passwordValue==""||!passwordValue2=="")
		{
			document.getElementById("password_err").innerHTML= "";
			document.getElementById("pswdr_err").innerHTML= "";
		}
	

	if (!passwordValue.match(pass)||passwordValue=="")
	{
		

		document.getElementById("password_err").innerHTML= "*The Password is not valid.";
		Event.preventDefault();
	}

		
		// i have 2 if statement doing same thing becuase javascrip is weird and if i add them all in one, it will skip one option
		if (passwordValue==""||passwordValue2=="")
		{
			document.getElementById("password_err").innerHTML= "*The Password is not valid.You need exactly 8 characters long,with atleast 1 non-letter character";
			document.getElementById("pswdr_err").innerHTML= "*The passwords does not match ";
		}
		if (password.value!==passs.value) 
		{

		document.getElementById("password_err").innerHTML= "*The Password is not valid.You need exactly 8 characters long,with atleast 1 non-letter character";				document.getElementById("pswdr_err").innerHTML= "*The passwords does not match ";
	
		}



}


function functionSet1(Event)
{
	
	//vadidating UserName
  	var myName= document.getElementById("Fname");
  	var x = myName.value;
	var NAME= myName.name;
	if(x!="")
	{
		document.getElementById(NAME+"_err").innerHTML ="";
	}
 	if (x == "")
 	{

    	document.getElementById(NAME+"_err").innerHTML ="*This feild cannot be left empty. Please Enter Fisrt name";
   		Event.preventDefault();
   	} 


	var lName=document.getElementById("lname");
	var l_value= lname.value;
	var lname_name= lname.name;
	if (l_value!="")
 	{
		document.getElementById(lname_name+"_err").innerHTML ="";
   		
	}

	if (l_value=="")
 	{
		document.getElementById(lname_name+"_err").innerHTML ="*This feild cannot be left empty. Please Enter Last name";
   		Event.preventDefault();
	}


	var pattern =/^([0-9]{2})\/([0-9]{2})\/([0-9]{4})$/;
	 var dob = document.forms["myForm"]["Dob"].value;
	if (pattern.test(dob)) 
	{
		document.getElementById("Dob_err").innerHTML ="";
	}

	 if (dob == null || dob == "" || !pattern.test(dob)) 
	 {
        document.getElementById("Dob_err").innerHTML ="*Invalid DOB";

	 }

	funcEmail(Event);
	password(Event);
	

}


function functionSet2(Event)
{

	funcEmail(Event);
	funcPassword(Event);

}

function functionset3(Event)

{

passcode(Event);
messagelen(Event);
	

}

function functionset4(Event)
{

	messagelen(Event);
}



function passcode(Event)
{
	var valid = /[a-zA-Z0-9]{8,8}$/;
	var validtext= document.getElementById("secretCode");
	var validtextValue=validtext.value;
	if (validtextValue.match(valid)) 
	{
		document.getElementById(validtext.name+"_err").innerHTML ="";
	}
	if (!validtextValue.match(valid)) 
	{
		document.getElementById(validtext.name+"_err").innerHTML ="*Passcode is not valid.exactly 8 characters, letters or numbers only";
		Event.preventDefault();
	}


}
function messagelen(Event){
var msg = document.getElementById("Message");
	var len= msg.value.length;
	
	if (len==0) 
	{
		document.getElementById("Message_err").innerHTML = "*Message cannot be blank";
	}
	if (len>500) {

	document.getElementById("alert_err").innerHTML= "*Message cannot be sent with more then 500 characters";
	Event.preventDefault();
	}
}

