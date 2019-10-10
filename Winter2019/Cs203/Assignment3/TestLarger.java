abstract class Larger{

    public abstract void getPerimeter();

    public abstract void getArea();

    static GeometricObject larger(GeometricObject g1, GeometricObject g2){ //throws DifferentTypeException{
        boolean x = true;
    if(x){

    }
    else{
        //throw new DifferentTypeException()
    }



    }
}


class Triangle extends GeometricObject{

    private double side1 ;
    private double side2 ;
    private double side3 ;

    public Triangle(){
        this.side1 = 1.0;
        this.side2 = 1.0;
        this.side3 = 1.0;
    }

    public void setSide1(double incomingValue){
        this.side1 = incomingValue;
    }

    public Triangle(double side1, double side2, double side3) throws MyException {
      Boolean x = false;
      if (side1 < (side2 +side3)) {
            if (side2 < (side1+side3)) {
                if (side3<(side1+side2)) {
                    x = true;
                }
            }
        }  

      if(x){
            this.side1 = side1;
            this.side2 = side2;
            this.side3 = side3; 
            System.out.println("Legal Triangle Created Successfully"); 

      }else {
        
         throw new MyException(side1,side2,side3,"The sum of Any two sides cannot be greater than other side");
      }
    }


    

    public void getArea(){

    double s = (side1+side2+side3)/2;
    s = s*(s-side1)*(s-side2)*(s-side3);
    System.out.println("Area of the triangle is " + Math.sqrt(s));

    }

    public void getPerimeter(){
    
    double s = side1+side2+side3;
    System.out.println("Perimeter of the triangle is " + s); 
        
    }

    @Override
    public String toString(){
        return "Triangle: side1 = " + side1 + ", side2 = " + side2 + ", side3 = " + side3;

    }

    public static void main(String[] args) {
    // Triangle object 
    try{
        Triangle triObj = new Triangle(2.0,2.0,3.0);
        triObj.getPerimeter();
        triObj.getArea();

        triObj.setSide1(4.0);

        Triangle illegalObj = new Triangle(1.0,2.0,3.0);
        illegalObj.getPerimeter();
        illegalObj.getArea();
        
    }
    catch(MyException excp){

        excp.getInfo();
    }
}



}

class MyException extends Exception {
    private double side1 ;
    private double side2 ;
    private double side3 ;
    private String message;

    public MyException(double side1, double side2, double side3,String message) {
        
            this.side1 = side1;
            this.side2 = side2;
            this.side3 = side3; 
            this.message = message;

    }

    public void getInfo(){
        System.out.println("Illegal Triangle: ");
        System.out.println("Side 1: " + side1);
        System.out.println("Side 2: " + side2);
        System.out.println("Side 3: " + side3);
        System.out.println(message);
    }
}





