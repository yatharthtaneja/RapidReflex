import processing.serial.*;

Serial arduinoPort;

String p1_score = "0";


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
p1_score=rawInput;
}

void draw()
{
  noStroke();
  
  fill(255, 0, 0);
  rect(0, 0, width, height);
 
  textSize(400);
  fill(0, 0, 0);
  text(p1_score, 500, 500);

  

  

}
