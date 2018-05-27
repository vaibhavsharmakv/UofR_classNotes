function SignUpForm(event){ 
    var elements = event.currentTarget;
    var a = elements[0].value;
    var b = elements[1].value;
    var c = elements[2].value;
      
    var result = true;    
       
    var email_v = /^\w+@[a-zA-Z_]+?\.[a-zA-Z]{2,3}$/; 
    var Uname_v = /^[a-zA-Z0-9_-]+$/;
       
    document.getElementById("email_msg").innerHTML ="";
    document.getElementById("uname_msg").innerHTML ="";
    document.getElementById("photo_msg").innerHTML ="";  
 

    if (a==null || a==""||!email_v.test(a))
        {   
	    document.getElementById("email_msg").innerHTML="Invalid email address (should be name@somewhere.sth)";
	    result = false;
        }
		
	if (b==null || b==""||!Uname_v.test(b))
        {
	    document.getElementById("uname_msg").innerHTML="Username should not have any leading or trailing spaces";
           result = false;
        }
		
    if (c==null || c=="")
        {
	    	   
	    document.getElementById("photo_msg").innerHTML="Please upload a photo";
           result = false;
        }
		
    if(result == false )
        {    
            
            event.preventDefault();
        }
}