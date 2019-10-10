class animal{

	private String name = "";
	private int id = 0;

	public animal(){
		this.name = "none";
		this.id = 0;
	} 

	public animal(String name , int id){
		this.name = name;
		this.id = id;
	}


}

class deadlyAnimals extends animal {

	private int killRate = 0;

	public deadlyAnimals(String name, int id, int killRate){
		super( name , id);
		this.killRate = killRate;
	}
	int getKillRate()throws customException{
		try{
			throw new customException("dividing by zero Failed");
			return this.killRate/0;	
			
		}
		catch(Exception e){
			System.out.println(e);
			return 2;
		}
		
	}

}

class customException extends Exception{
	customException(String s){  
  	super(s);  
 }  


}


public class finalExam{
	 public static void main(String[] args) {

	 	try{
	 	deadlyAnimals d = new deadlyAnimals("Test", 2, 2);
	 	System.out.println(d.getKillRate());
	 	throw new customException();
		}
		catch(Exception e){
		System.out.println(e);

		}
	 }
}
