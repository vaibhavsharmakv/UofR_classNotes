public class Test {
	public static void main(String[] args){

		//This line of code comparing the two String to check if they match 
		// it clearly returns false
		System.out.println("Hi, ABC, good".matches("ABC "));

		// This like of code is checking if the substring is present in the intial String
		System.out.println("Hi, ABC, good".matches(".*ABC.* "));

		// this line of code is replacing all the ',' and ';' with #
		System.out.println("A,B;C".replaceAll(",;","#"));

		// this line of code is replacing all ',;'' with #
		System.out.println("A,B;C".replaceAll("[,;]","#"));

		// this line of code is replacing all ';,' with spaces 
		String[] tokens = "A,B;C".split("[,;]");
		for (int i = 0; i< tokens.length;i++ ) {
			System.out.print(tokens[i]+" ");
		}
		

	}

	

}