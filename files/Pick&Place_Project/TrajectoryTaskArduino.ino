///////////////////////////////////////////////////
// Control 3 servo motors using 3 potentiometers //
///////////////////////////////////////////////////

#include <Servo.h>
#include "RobotArm.h"

int JointOffset[3] = {10,20,33}; // Your value may be different

RobotArm MyRobot = RobotArm();

double* p_home = new double[3]{50, 50, 50};
double* p_pick = new double[3]{0, 50, 0};
double* p_place = new double[3]{100, 50, 0};



void setup()
{
  int initial_angle[3] = {90,90,90};
  MyRobot.Setup(JointOffset);
  MyRobot.Set_Angle(initial_angle);
  MyRobot.Set_Gripper(1);
  delay(1000);
  MyRobot.Goto(p_home,1);
  MyRobot.Set_Gripper(1);
  delay(1000);
  MyRobot.Goto(p_pick,5);
  MyRobot.Set_Gripper(0);
  delay(10000);
}

void loop()
{
  MyRobot.Goto(p_home,5);
  delay(5000);
  MyRobot.Goto(p_place,5);
  MyRobot.Set_Gripper(1);
  delay(10000);
  MyRobot.Goto(p_home,5);
  delay(5000);
  MyRobot.Goto(p_pick,5);
  MyRobot.Set_Gripper(0);
  delay(10000);
}