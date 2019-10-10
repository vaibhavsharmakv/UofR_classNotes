class Stringy{
	/*private String s1;
	private String s2;
	Stringy(String s1){

		this.s1 = s1;
	}
	Stringy(String s1,String s2){
		this.s1 = s1;
		this.s2 = s2;
	}
	public void sets1(String s1){
		this.s1 = s1;
	}

	public void sets2(String s2){
		this.s2 = s2;
	}

	public String gets1(){
		return this.s1;
	}

	public String gets2(){
		return this.s2;
	}

	public String replaceCh(String s1){

		return "";
	
	}*/

	public static void main(String[] args){

		String s1 = "Welcome";
		String s2 = "welcome";

		System.out.println("Before replacing : "+s1 );
      	System.out.println(s1.replace('e', 'E'));
      	s2 = s1; 
      	System.out.println("After replacing : "+s1 );
      	System.out.println("       " );

      	String s3 = "Welcome to Java and HTML";

      	char[] stringToCharArray = s3.toCharArray();
 
		for (char output : stringToCharArray) {
			System.out.println(output);
		}


		char sq1 = stringToCharArray[0];
		char sq2 = stringToCharArray[1];

		StringBuilder stringWithChar = new StringBuilder(s1);
		stringWithChar.setCharAt(0, sq1);
		stringWithChar.setCharAt(1, sq2);
		System.out.println(s1 );
		

	}
}