import java.util.*;
class Flight{
	private String flightNo;
	private GregorianCalendar departureTime;
	private GregorianCalendar arrivalTime;

	Flight(String flightNo , GregorianCalendar departureTime, GregorianCalendar arrivalTime){

		this.flightNo = flightNo;
		this.departureTime = departureTime;
		this.arrivalTime = arrivalTime;
	}

	Flight(){

	}

	public String getFlightNo(){
		return flightNo;
	}
	public GregorianCalendar getDepartureTime(){
		return departureTime;
	}

	public GregorianCalendar getArrivalTime(){
		return arrivalTime;
	}

	public void setDepartureTime(GregorianCalendar departureTime){
		this.departureTime = departureTime;
	}

	public void setArrivalTime(GregorianCalendar arrivalTime){
		this.arrivalTime = arrivalTime;
	}

	public GregorianCalendar getFlightTime(GregorianCalendar departureTime,GregorianCalendar arrivalTime){

		return new GregorianCalendar();
	}
	public static void main(String[] args) {

		Flight[] flights = new Flight[3];
		GregorianCalendar depart1 = new GregorianCalendar(2014, 4, 5, 0, 5, 0);
		GregorianCalendar arrive1 = new GregorianCalendar(2014, 4, 1, 5, 6, 0);

		GregorianCalendar depart2 = new GregorianCalendar(2014, 4, 4, 5, 7, 0);
		GregorianCalendar arrive2 = new GregorianCalendar(2014, 4, 1, 5, 6, 0);

		GregorianCalendar depart3 = new GregorianCalendar(2014, 4, 5, 3, 9, 0);
		GregorianCalendar arrive3 = new GregorianCalendar(2014, 4, 5, 5, 1, 2);

		flights[0] = new Flight("US230", depart1, arrive1);

		flights[1] = new Flight("US235", depart2, arrive2);

		flights[2] = new Flight("US237", depart3, arrive3);
		
		// Sorry, I ran out of time at this point
		// I still appreacite the extra time given to me.
		// Thank you. :)
		


	}

}
class Itinerary extends Flight{

	private ArrayList<Flight> flights;

	Itinerary(ArrayList<Flight> flights){
		this.flights = flights;
		
	}
	/*public GregorianCalendar getTotalFlightTime(){

		return
	}

	public GregorianCalendar getTotalTravelTime() {


	}*/


}
