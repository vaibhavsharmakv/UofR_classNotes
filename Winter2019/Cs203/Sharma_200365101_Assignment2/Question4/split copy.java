class split{
	public static void main(String[] args){

		String s = "ab#12#453";
		String s1 = "a?b?gf#e##";
		String regex = "#";

		String[] tokens = split(s,regex);
		for (int i = 0; i< tokens.length;i++ ) {
			System.out.print(tokens[i]+" ");
		}

		tokens = split(s1,regex);
		for (int i = 0; i< tokens.length;i++ ) {
			System.out.print(tokens[i]+" ");
		}
		
		
    
	}

	public static String[] split (String s, String regex){

		
		String[] inputs = s.split("(?!^)\\b");
		for (int i=0; i<inputs.length; i++) {
  		 System.out.println(inputs[i] );
		}

		return inputs;

	}
}
