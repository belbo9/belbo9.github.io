#include "RobotArm.h"

RobotArm::RobotArm()
{
}

void RobotArm::Setup(int* JointOffset)
{
  
    Serial.begin(9600);
    Joint1Offset = JointOffset[0]; 
    Joint2Offset = JointOffset[1]; 
    Joint3Offset = JointOffset[2]; 
    
    Joint1.attach(Joint1Pin);
    Joint2.attach(Joint2Pin);
    Joint3.attach(Joint3Pin);
    Gripper.attach(GripperPin);
    
    int angle[3] = {90,90,90};
    Set_Angle(angle);
    
    
    delay(1000); // 1 seconds before loop function
}

void RobotArm::Set_Angle(int* angle)
{
   // Function that actuates the 3 arm joints (excluding gripper servo joint)
   Joint1.write(angle[0]+Joint1Offset);
   Joint2.write(angle[1]+Joint2Offset);
   Joint3.write(angle[2]+Joint3Offset);
   Data_Copy(angle,now_angle);
   
}

void RobotArm::Set_Gripper(int isOpen)
{
  if(isOpen)
  {
    // Moves the respective joint by '60' as stated in the member variable decleration in 'RobotArm.h'
    Gripper.write(GripperOpen);  
    now_gipper = 1;
  }
  else
  {
    Gripper.write(GripperClose);  
    now_gipper = 0;
  }
}

void RobotArm::Get_Angle_Potentiometer(int* pin, int* output_angle)
{
  output_angle[0] = map(analogRead(pin[0]),0,1023,0,180);
  output_angle[1] = map(analogRead(pin[1]),0,1023,0,180);
  output_angle[2] = map(analogRead(pin[2]),0,1023,0,180);
  output_angle[3] = map(analogRead(pin[3]),0,1023,0,180);
}

void RobotArm::Get_Position_Potentiometer(int* pin, int* output_position)
{
  output_position[0] = map(analogRead(pin[0]),0,1023,-80,80);
  output_position[1] = map(analogRead(pin[1]),0,1023,-100,-150);
  output_position[2] = map(analogRead(pin[2]),0,1023,0,170);
  output_position[3] = map(analogRead(pin[3]),0,1023,0,180);
}

void RobotArm::Set_Position(double* target_position)
{
  double xyz[3];
  Position_Map_to(target_position,xyz);
  // Remapped coordinates to ensure points are within workspace are outputted here via the template
  double x = xyz[0];
  double y = xyz[1];
  double z = xyz[2];

  double theta1;
  double k;
  double beta;
  double phi;
  double theta2;
  double theta3 ;

  double pi = 3.1415926;

  // Inverse kinematics to obtain desired joint angles from end position provided
  theta1 = -atan2(y,x)/pi * 180;
  k = sqrt(x*x + y*y);
  beta = atan2(z,k);
  phi = acos((L1 * L1 + k*k + z*z - L2*L2) / (2 * L1 * sqrt((k*k + z*z))));
  theta2 = (beta + phi)/pi * 180;
  theta3 = acos((k*k+z*z-L1*L1-L2*L2)/(2*L1*L2))/pi * 180;

  // Required angles for desired end position
  int angle[3] = {int(theta1),int(theta2),int(theta3)};

  // Command that actuates the motors after inverse kinematics calculations carried out
  Set_Angle(angle);
  
  Data_Copy(target_position, now_position);
  Position_Map_to(target_position,now_maped_position);

  
  Serial.println("Actual position");
  Serial.print("x = ");
  Serial.print(now_maped_position[0]);
  Serial.print(",y = ");
  Serial.print(now_maped_position[1]);
  Serial.print(",z = ");
  Serial.println(now_maped_position[2]);

  
  Serial.println("Actual angle");
  Serial.print(now_angle[0]);
  Serial.print(",");
  Serial.print(now_angle[1]);
  Serial.print(",");
  Serial.println(now_angle[2]);
}

void RobotArm::Move_Position(double* start_position, double* end_position, double tf)
{
  // Trajectroy planning definition and use function
  double a0_x, a1_x, a2_x, a3_x, a0_y, a1_y, a2_y ,a3_y, a0_z, a1_z, a2_z ,a3_z;
  double x, y, z;
  
  double theta1;
  double k;
  double beta;
  double phi;
  double theta2;
  double theta3 ;

  double pi = 3.1415926;

  double end_xyz[3];
  Position_Map_to(end_position,end_xyz);
  double u0_x = end_xyz[0];
  double u0_y = end_xyz[1];
  double u0_z = end_xyz[2];

  double start_xyz[3];
  Position_Map_to(start_position,start_xyz);
  // Ouputted mapped values
  double uf_x = start_xyz[0];
  double uf_y = start_xyz[1];
  double uf_z = start_xyz[2];
  
  a0_x = u0_x;
  a1_x = 0;
  // In-built Arduino.h power function
  // Cubic polynominal funciton coefficients defined here
  a2_x = 3/pow(tf,2)*(uf_x-u0_x);
  a3_x = -2/pow(tf,3)*(uf_x-u0_x);
  a0_y = u0_y;
  a1_y = 0;
  a2_y = 3/pow(tf,2)*(uf_y-u0_y);
  a3_y = -2/pow(tf,3)*(uf_y-u0_y);
  a0_z = u0_z;
  a1_z = 0;
  a2_z= 3/pow(tf,2)*(uf_z-u0_z);
  a3_z = -2/pow(tf,3)*(uf_z-u0_z);
  
  // Obtaining respective x,y and z coordinates from the cubic polynominal function
  for(double t = tf; t >= 0; t = t-0.1)
  {
    x = a0_x + a1_x*t + a2_x*pow(t,2) + a3_x*pow(t,3);
    y= a0_y + a1_y*t + a2_y*pow(t,2) + a3_y*pow(t,3);
    z= a0_z + a1_z*t + a2_z*pow(t,2) + a3_z*pow(t,3);

    

    double position[3] = {x,y,z};

    Position_Map_Back(position,position);

    // Set_Position function is called to calculate the required angles for each point on this trajectory path
    Set_Position(position);
    delay(100);
  }
}


void RobotArm::Goto(double* target_point, double tf)
{
  Move_Position(this->now_position, target_point, tf);
}

void RobotArm::MutiPoints(double* points[], double tf,int num)
{
  for(int i=0; i<num; i++)
  {
    Goto(points[i],tf);
  }
}
