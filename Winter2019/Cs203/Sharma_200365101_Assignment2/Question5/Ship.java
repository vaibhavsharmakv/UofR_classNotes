class Ship{
	protected String name;
	protected String yearBuilt;

	Ship(){

	}
	Ship(String name, String yearBuilt){
		this.name = name;
		this.yearBuilt = yearBuilt;
	}	
	public String getName(){
		return name;
	}

	public String getYearBuilt(){
		return this.yearBuilt;
	}

	public void setName(String name){
		this.name = name;
	}

	public void setYearBuilt(String yearBuilt){
		this.yearBuilt = yearBuilt;
	}

	@Override
    public String toString() { 
        return String.format("Ship: " + this.name +", " + this.yearBuilt); 
    }
    public static void main(String[] args) {

	Ship[] testShips = new Ship[5];
		
		int capacity = 24;
		int tonnage = 5000;
		testShips[0] = new Ship("Lolipop","1968");
		testShips[1] = new CruiseShip("Disney Magic","1968", capacity);
		testShips[2] = new cargoShip("Black Pearl", "1968",tonnage);

		System.out.println(testShips[0].toString() );
		System.out.println(testShips[1].toString() );
		System.out.println(testShips[2].toString() );

    }

}

class CruiseShip extends Ship {


 
	protected int passengerCapacity;
	CruiseShip(){

	}
	CruiseShip(String name, String yearBuilt, int passengerCapacity){

		super.name = name;
		super.yearBuilt = yearBuilt;
		this.passengerCapacity = passengerCapacity;
		

	}
	public int getPassengerCapacity(){
		return passengerCapacity;
	}

	public void setpassengerCapacity(int passengerCapacity){
		this.passengerCapacity = passengerCapacity;
	}

	@Override
    public String toString() { 
        return String.format("CruiseShip: " + super.name +", " + this.passengerCapacity); 
    }
    public static void main(String[] args) {


    }


}

class cargoShip extends CruiseShip{

	private int tonnage;

	cargoShip(){

	}
	cargoShip(String name, String yearBuilt, int tonnage){
		super.name = name;
		super.yearBuilt = yearBuilt;
		this.tonnage = tonnage;
	}

	public int getTonnage(){
		return tonnage;
	}

	public void setTonnage(int tonnage){
		this.tonnage = tonnage;
	}

	@Override
    public String toString() { 
        return String.format("cargoShip: " + super.name +", " + this.tonnage); 
    }



}

class TestShips{


     public static void main(String[] args) {
		
	}


}