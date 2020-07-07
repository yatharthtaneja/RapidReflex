import processing.serial.*;

Serial arduinoPort;

String p1_score = "0";
String p2_score = "0";

void setup()
{
  String portName = Serial.list()[1];
  arduinoPort = new Serial(this, "COM5" , 9600);
  arduinoPort.bufferUntil('\n');
  fullScreen();
}

void serialEvent(Serial port)
{
  String rawInput = port.readStringUntil('\n');
  int end = rawInput.indexOf(':');
  p1_score = rawInput.substring(0, end);
  p2_score = rawInput.substring(end+1);
}

void draw()
{
  noStroke();
  
  fill(255, 0, 0);
  rect(0, 0, width/2, height);
  fill(255, 255, 0);
  rect(width/2, 0, width/2, height);
  textSize(400);
  text(p1_score, 10, 500);
  fill(0, 102, 153, 51);
  textSize(400);
  text (p2_score , 800, 500);
  
    if (p1_score.equals("50") || p1_score.equals("52") || p1_score.equals("53") || p1_score.equals("54") || p1_score.equals("51"))
    {
      fill(105, 105, 105);
      rect(0, 0, width, height);
      textSize(150);
      fill(255, 0, 0);
      text("WINNER!!!" , 250, 250);
      text("PLAYER 1" , 250, 450);
    }
    
    if (p2_score.equals("50")|| p2_score.equals("52") || p2_score.equals("53") || p2_score.equals("54") || p2_score.equals("51"))
    {
      fill(105, 105, 105);
      rect(0, 0, width, height);
      textSize(150);
      fill(255, 0, 0);
      text("WINNER!!!" , 250, 250);
      text("PLAYER 2" , 250, 350);
    }
  

}
