import java.util.*; 
class Account{

	private int id = 0;
	private double balance = 0; 
	static private double annualInterest = 0.012;
	private Date dateCreated ;

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

	//Setters

	public void setId(int id) {
		id = this.id;
	}

	public void setbalance(double balance) {
		balance = this.balance;
	}

	public void setId(double annualInterest) {
		annualInterest = this.annualInterest;
	}

	//Getters

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

	//Methods

	double getMonthlyInterestRate( double annualInterest){
		double monthyInterest = annualInterest/12;
		return monthyInterest;
	}

	double getMonthlyInterest(double monthyInterestRate, double balance){

		double monthyInterestValue = balance* monthyInterestRate;
		return monthyInterestValue;
	}

	void withdraw(double amount){

		if ((amount - this.balance)>0) {
			this.balance = this.balance - amount;
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
	//Main
	public static void main(String args[]){

		Account TestAccount = new Account(1112,2500.00);
		TestAccount.deposit(3000.00);
		TestAccount.printBalance();

		//Printing Anual Interest
		TestAccount.printAnnualInterest();

		//Printing Monthly Interest Rate
		TestAccount.printMonthlyInterestRate(TestAccount.getMonthlyInterestRate(TestAccount.annualInterest()));

		//Printing Monthly Interest
		TestAccount.printMonthlyInterest(TestAccount.getMonthlyInterest(TestAccount.getMonthlyInterestRate(TestAccount.annualInterest()),TestAccount.getbalance()));
		
		//Printing Created Date
		TestAccount.printDate(TestAccount.getDate());
	}	

}