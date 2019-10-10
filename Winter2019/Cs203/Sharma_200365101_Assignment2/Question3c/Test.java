public class Test {
	public static void main(String[] args){

		String s = "Java";
		StringBuilder builder = new StringBuilder(s);
		change(s,builder);

		System.out.println(s);
		System.out.println(builder);

	}

	private static void change(String s, StringBuilder builder){
		s = s + "and HTML";
		builder.append(" and HTML");
	}

	/* In this question 
		-->  main() program have a string builder which calls a static function change() 
		--> change() function add a new string into a previous string with the help of Builder from main()
	*/

}