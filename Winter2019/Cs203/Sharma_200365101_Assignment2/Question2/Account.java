import java.util.*; 
class Account{

	//-------Variables

	private int id = 0;
	private double balance = 0; 
	static private double annualInterest = 0.012;
	private Date dateCreated ;

	//-------Constructors

	Account(){
	 id = 0;
	 balance = 0; 
	 annualInterest = 0.012;
	}

	Account(int id, double balance){

		 this.id = id;
		this.balance = balance;
		this.dateCreated = new Date();

	}


	//------------------Setters

	public void setId(int id) {
		id = this.id;
	}

	public void setbalance(double balance) {
		balance = this.balance;
	}

	public void setId(double annualInterest) {
		annualInterest = this.annualInterest;
	}

	//------------------Getters

	public int getId() {
		return this.id;
	}

	
	public double getbalance() {
		return this.balance;
	}

	public double annualInterest() {
		return this.annualInterest;
	}

	public Date getDate() {
		return this.dateCreated;
	}

	//---------------------Methods

	double getMonthlyInterestRate( double annualInterest){
		double monthyInterest = annualInterest/12;
		return monthyInterest;
	}

	double getMonthlyInterest(double monthyInterestRate, double balance){

		double monthyInterestValue = balance* monthyInterestRate;
		return monthyInterestValue;
	}

	void withdraw(double amount){

		if (( this.balance - amount )>0) {
			this.balance = this.balance - amount;
			System.out.println("Your New balance is : " + this.balance);
		}
		else{

			System.out.println("Invalid, Not enough balance ");
		}

	}

	void deposit(double amount){

		this.balance = this.balance + amount;
		System.out.println("Your New balance is : " + this.balance);

	}

	void printBalance(){
		System.out.println("Your current balance is : " + this.balance);
	}

	

	void printAnnualInterest(){

		System.out.println("The Annual Interest Rate is : " + (this.annualInterest*100) + "%");
	}

	void printMonthlyInterest(double monthyInterest){

		System.out.println("The Monthly Interest  is : " + monthyInterest);
		
	}

	void printMonthlyInterestRate(double monthyInterestRate){
		System.out.println("The Monthly Interest Rate  is : " + (monthyInterestRate*100)+"%");
	}

	void printDate(Date date){
		System.out.println("The Account was created on  : " + date);
	}	

	
	//-----------Main
	public static void main(String args[]){

		

		//Manuall Account setup for debugging purposes
			//could have used a for loop, manual setup is just a personal preference at this moment

		Account[] testAccounts = new Account[11];
		testAccounts[1]= new Account(1,100.00);
		testAccounts[2]= new Account(1,100.00);
		testAccounts[3]= new Account(1,100.00);
		testAccounts[4]= new Account(1,100.00);
		testAccounts[5]= new Account(1,100.00);
		testAccounts[6]= new Account(1,100.00);
		testAccounts[7]= new Account(1,100.00);
		testAccounts[8]= new Account(1,100.00);
		testAccounts[9]= new Account(1,100.00);
		testAccounts[10]= new Account(1,100.00);

		testAccounts[0] = null;

	
		boolean running = true;

		
		
		while(true){
			int id = 100;
			id = validateID();
			while(id > 11){
			id = validateID();
			}
			if (id == 0){
				for (int i = 1;i<11 ;i++ ) {
					System.out.println("Account "+i+" balance is :"+ testAccounts[i].getbalance());
					
					
				}
			}
			else{
				int exit = 4;
				exit = atmMachine(testAccounts[id]);
				while(exit !=  4){
					exit = atmMachine(testAccounts[id]);
				}
			}
		}




		
	}

	public static void idMethods(){

		

		

	}

	public static int atmMachine(Account testAccount){
		printMenu();
		Scanner myObj = new Scanner(System.in);
		int choice = myObj.nextInt();
		if (choice == 1) {
			testAccount.printBalance();
			return 100;
			
		}
		else if (choice == 2) {
			System.out.println("Please enter the amount you want to withdraw :" );
			double money = myObj.nextDouble();
			testAccount.withdraw(money);
			return 100;
			
		}
		else if (choice == 3) {
			System.out.println("Please enter the amount you want to deposit:" );
			double depositAmount = myObj.nextDouble();
			testAccount.deposit(depositAmount);
			return 100;
			
		}
		else if (choice == 4) {
			System.out.println("you have exit the Account" );
			return 4;
			
		}
		return 100;

	}

	public static void printMenu(){

		System.out.println("       " );
		System.out.println("Main Menu" );
		System.out.println("1: check Balance" );
		System.out.println("2: withdraw" );
		System.out.println("3: deposit" );
		System.out.println("4: exit" );
		System.out.println("Enter a choice" );
		System.out.println("       " );

	}

	public static int validateID(){

		Scanner myObj = new Scanner(System.in);
		System.out.println("Enter an Account id : " );
		int id = myObj.nextInt();

		if (id < 0 || id >10 ) {
			System.out.println("Invalid Id, Please try again " );
			return 100;
		}
		else{
			return id;
		}

	}


}











