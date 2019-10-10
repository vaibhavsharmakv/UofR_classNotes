
import javafx.animation.PathTransition;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;
import javafx.util.Duration;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.scene.shape.Line;
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


import javafx.application.Application;
import javafx.stage.Stage;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.util.Duration;

public class Answer3 extends Application {
  @Override // Override the start method in the Application class
  public void start(Stage primaryStage) {
    // Create a pane 
    Pane pane = new Pane();

    
    
    // Create a rectangle
    Rectangle rectangle = new Rectangle (0, 0, 25, 50);
    rectangle.setFill(Color.ORANGE);
    
    // Create a circle
    Circle circle = new Circle(125, 100, 50);
    circle.setFill(Color.WHITE);
    circle.setStroke(Color.BLACK);


    // Create a line 
    Line line1 = new Line(0,650, 650, 650);

    line1.setStrokeWidth(5);
    line1.setStroke(Color.GREEN);
    
    // Add circle and rectangle to the pane
   // pane.getChildren().add(circle);
    pane.getChildren().add(rectangle);
    pane.getChildren().add(line1);
    
    // Create a path transition 
    PathTransition pt = new PathTransition();
    pt.setDuration(Duration.millis(4000));
    pt.setPath(line1);
    pt.setNode(rectangle);
    pt.setOrientation(
      PathTransition.OrientationType.ORTHOGONAL_TO_TANGENT);
    pt.setCycleCount(Timeline.INDEFINITE);
    pt.setAutoReverse(false);
    pt.play(); // Start animation 

    
    
    line1.setOnMousePressed(e -> pt.pause());
    line1.setOnMouseReleased(e -> pt.play());
    
    // Create a scene and place it in the stage
    Scene scene = new Scene(pane, 650, 650);
    primaryStage.setTitle("Answer3"); // Set the stage title
    primaryStage.setScene(scene); // Place the scene in the stage
    primaryStage.show(); // Display the stage
    primaryStage.setResizable(false);
  }
  
  /**
   * The main method is only needed for the IDE with limited
   * JavaFX support. Not needed for running from the command line.
   */
  public static void main(String[] args) {
    launch(args);
  }
}