import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.stage.Stage;
import javafx.scene.layout.StackPane;
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
import javafx.geometry.HPos;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;
import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.layout.BorderPane;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.stage.Stage;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.stage.Stage;
import javafx.scene.layout.StackPane;

public class Answer1 extends Application {
  @Override // Override the start method in the Application class
  public void start(Stage primaryStage) {
    // Create a scene and place a button in the scene
    Pane pane = new Pane();
    
  

    String[] names = {"  ","W","E","L","C","O","M","E"," ","T","O"," ","J","A","V","A"," "," "};
    for (int i =0;i< 17 ;i++ ) {
        
        int center = 100;
        int a1,a2;
        a1 = (int)((center) + Math.sin(i/15.0*Math.PI*2)* 125/2);
        a2 = (int)((center)- Math.cos(i/15.0 * Math.PI*2)* 125/2);

        
        Text tt = new Text(a1+100, a2+100, names[i]);
        if (i<8) {
          tt.setRotate(a2);
        }
        else{
          tt.setRotate(-a2);
        }
        
        pane.getChildren().add(tt);
    }
    
    
    pane.setStyle(
      "-fx-border-color: red; -fx-background-color: lightgray;");
    
    Scene scene = new Scene(pane, 200, 250);
    primaryStage.setTitle("Answer1"); // Set the stage title
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