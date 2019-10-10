abstract class GeometricObject{

 public abstract void getPerimeter();

 public abstract void getArea();

 public static void main(String[] args) {
    // rectangle object 
    rectangle rectObj = new rectangle(2.0,3.0);
    

    System.out.println("the Area of rectangle : ");
    rectObj.getArea();
    System.out.println("the Perimeter of rectangle : ");
    rectObj.getPerimeter();
    System.out.println(rectObj.toString());


  	// Circle object 
    circle cirObj = new circle(2.0);

    System.out.println("the Area of Circle : ");
    cirObj.getArea();
    System.out.println("the Perimeter of Circle : ");
    cirObj.getPerimeter();
    System.out.println(cirObj.toString());




  }

}

class circle extends GeometricObject{

	private double radius = 0;

	public circle(double radius){
		this.radius = radius;
	}
	public void getArea(){
	
	double area = 3.14 * radius * radius;

	System.out.println("The area is " + area);
	}
	public void getPerimeter(){

	double perimeter = 3.14 * radius * 2;

	System.out.println("The perimeter is " + perimeter);	

	}

	@Override
	public String toString(){
        return "Circle: radius = " + radius;
    }

}

class rectangle extends GeometricObject{

	private double height = 0;
	private double width = 0;

	public rectangle(double height, double width){
		this.height = height;
		this.width = width;
	}
	public void getArea(){

		double area = height * width;
	}
	public void getPerimeter(){

		double perimeter = (2 * (height+width));
	}
	@Override
	public String toString(){
        return "Rectangle: width = " + width + ", height = " + height;
    }


}




