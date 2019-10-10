
import java.awt.SecondaryLoop;
import java.math.MathContext;
import java.util.Calendar;
import java.util.GregorianCalendar;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Line;
import javafx.scene.text.Text;
import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.layout.BorderPane;

public class detailedClock extends Application {
  @Override // Override the start method in the Application class
  public void start(Stage primaryStage) {
    // Create a clock and a label
    ClockPane clock = new ClockPane();
    String timeString = clock.getHour() + ":" + clock.getMinute() 
      + ":" + clock.getSecond();
    Label lblCurrentTime = new Label(timeString);

    // Place clock and label in border pane
    BorderPane pane = new BorderPane();
    pane.setCenter(clock);
    pane.setBottom(lblCurrentTime);
    BorderPane.setAlignment(lblCurrentTime, Pos.TOP_CENTER);

    // Create a scene and place it in the stage
    Scene scene = new Scene(pane, 250, 250);
    primaryStage.setTitle("detailedClock"); // Set the stage title
    primaryStage.setScene(scene); // Place the scene in the stage
    primaryStage.show(); // Display the stage
  }

  /**
   * The main method is only needed for the IDE with limited
   * JavaFX support. Not needed for running from the command line.
   */
  public static void main(String[] args) {
    launch(args);
  }
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/**
 *
 * # @author allison
 */
class ClockPane extends Pane{
    private int hour;
    private int minute;
    private int second;
    
    // Clock pane's width and height
    private double w = 250, h = 250;
    
    /** Construct a default clock with the current time */
    public ClockPane(){
        setCurrentTime();
    }
    
    /** Construct a clock with specified hour, minute, and second */
    public ClockPane(int hour, int minute, int second){
        this.hour = hour;
        this.minute = minute;
        this.second = second;
        paintClock();
    }
    
    /** Return hour */
    public int getHour(){
        return hour;
    }
    
    /** Set a new hour */
    public void setHour(int hour){
        this.hour = hour;
        paintClock();
    }
    
    /** Return minute */
    public int getMinute(){
        return minute;
    }
    
    /** Set a new minute */
    public void setMinute(int minute){
        this.minute = minute;
        paintClock();
    }
    
    /** Return second */
    public int getSecond(){
        return second;
    }
    
    /** Set a new second */
    public void setSecond(int second){
        this.second = second;
        paintClock();
    }
    
    /** Return clock pane's width */
    public double getW(){
        return w;
    }
    
    /** Set clock pane's width */
    public void setW(double w){
        this.w = w;
        paintClock();
    }
    
    /** Return clock pane's height */
    public double getH(){
        return h;
    }
    
    /** Set clock pane's height */
    public void setH(double h){
        this.h = h;
        paintClock();
    }
    
    /** Set the current time for the clock */
    public void setCurrentTime(){
        // Construct a calendar for the current date and time
        Calendar calendar = new GregorianCalendar();
        
        // Set current hour, minute, and second
        this.hour = calendar.get(Calendar.HOUR_OF_DAY);
        this.minute = calendar.get(Calendar.MINUTE);
        this.second = calendar.get(Calendar.SECOND);
        
        paintClock();// Repaint the clock
        
    }
    
    /** Paint the clock */
    public void paintClock(){
        // Initialize clock parameters
        double clockRadius = Math.min(w, h) * 0.8 * 0.5;
        double centerX = w / 2;
        double centerY = h /2;
        
        Circle circle = new Circle(centerX, centerY, clockRadius);
        circle.setFill(Color.WHITE);
        circle.setStroke(Color.BLACK);
        
        
        Text t1 = new Text(centerX +40, centerY - clockRadius +22, "1");
        Text t2 = new Text(centerX +clockRadius -30, centerY -50, "2");
        Text t3 = new Text(centerX + clockRadius - 10, centerY + 3, "3");
        Text t4 = new Text(centerX +clockRadius -30, centerY +50, "4");
        Text t5 = new Text(centerX +44, centerY + clockRadius - 20, "5");
        Text t6 = new Text(centerX -3, centerY + clockRadius - 3, "6");
        Text t7 = new Text(centerX - clockRadius+60, centerY + 89, "7");
        Text t8 = new Text(centerX - clockRadius+20, centerY + 50, "8");
        Text t9 = new Text(centerX - clockRadius + 3, centerY + 5, "9");
        Text t10 = new Text(centerX - clockRadius+20, centerY - 50, "10");
        Text t11 = new Text(centerX - 40, centerY - clockRadius + 20, "11");
        Text t12 = new Text(centerX -5, centerY - clockRadius +12, "12");

        // Draw second hand
        double sLength = clockRadius * 0.8;
        double secondX = centerX + sLength * Math.sin(second * (2 * Math.PI / 60));
        double secondY = centerY - sLength * Math.cos(second * (2 * Math.PI / 60));
        Line sline = new Line(centerX, centerY, secondX, secondY);
        sline.setStroke(Color.GREEN);
        
        // Draw minute hand
        double mLength = clockRadius * 0.65;
        double minuteX = centerX + mLength * Math.sin(minute * (2 * Math.PI / 60));
        double minuteY = centerY - mLength * Math.cos(minute * (2 * Math.PI / 60));
        Line mLine = new Line(centerX, centerY, minuteX, minuteY);
        mLine.setStroke(Color.BLUE);
        
        //Draw hour hand
        double hLength = clockRadius * 0.5;
        double hourX = centerX + hLength * Math.sin((hour + minute / 60) * (2 * Math.PI) / 12);
        double hourY = centerY - hLength * Math.cos((hour + minute / 60) * (2 * Math.PI) / 12);
        Line hLine = new Line(centerX, centerY, hourX, hourY);
        hLine.setStroke(Color.RED);

        
        getChildren().clear();
        getChildren().addAll(circle, t1,t2, t3, t4, t5, t6,t7,t8,t9,t10,t11,t12, sline, mLine,hLine);
        
    }
    
}
