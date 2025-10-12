#ifndef _ROBOTARM_H_
#define _ROBOTARM_H_
#include <Servo.h>
#include "Arduino.h"
class RobotArm
{
  public:
    /*——————————————————————————————————————————————
    |	function:	  RobotArm
    |	parameter:	None
    |	used to:	  Initialize a RobotArm object.
    ——————————————————————————————————————————————*/
    RobotArm();

    /*——————————————————————————————————————————————
    |	function:	  Setup							
    |	parameter:	int* JointOffset  - array containing joint angle offsets	
    |	used to:	  Initialize the robot with given joint offsets and set initial angles.	
    ——————————————————————————————————————————————*/ 
    void Setup(int* JointOffset);

    /*——————————————————————————————————————————————
    |	function:	  Set_Angle						
    |	parameter:	int* angle        - array containing joint angles	
    |	used to:	  Set the angles of the robot arm's joints.
    ——————————————————————————————————————————————*/ 
    void Set_Angle(int* angle);

    /*——————————————————————————————————————————————
    |	function:	  Set_Gripper						
    |	parameter:	int isOpen        - flag indicating whether to open or close the gripper 
    |                                 (1 for open, 0 for close)	
    |	used to:	  open or close the Gripper
    ——————————————————————————————————————————————*/ 
    void Set_Gripper(int isOpen);

    /*——————————————————————————————————————————————
    |	function:	  Get_Angle_Potentiometer			
    |	parameter:	int* pin          - array containing analog pins for potentiometers	
    |				      int* output_angle - array to store output angles	
    |	used to:	  Read angles from potentiometers
    ——————————————————————————————————————————————*/ 
    void Get_Angle_Potentiometer(int* pin, int* output_angle);

    /*——————————————————————————————————————————————
    |	function:	  Get_Position_Potentiometer		
    |	parameter:	int* pin          - array containing analog pins for potentiometers	
    |				      int* output_position 
    |                               - array to store output positions	
    |	used to:	  Read positions from potentiometers
    ——————————————————————————————————————————————*/ 
    void Get_Position_Potentiometer(int* pin, int* output_position);

    /*——————————————————————————————————————————————
    |	function:	  Set_Position					
    |	parameter:	double* target_position 
    |                               - array containing target position coordinates (x, y, z)	
    |	used to:	  Set the target position of the end of the arm.	
    ——————————————————————————————————————————————*/ 
    void Set_Position(double* target_position);

    /*——————————————————————————————————————————————
    |	function:	  Move_Position					
    |	parameter:	double* start_position 
    |                               - array containing start position coordinates (x, y, z)	
    |				      double* end_position 
    |                               - array containing end position coordinates (x, y, z)	
    |				      double tf         - time duration for the movement	
    |	used to:	  Move the endof the arm from start position to end position within the specified time duration.	
    ——————————————————————————————————————————————*/ 
    void Move_Position(   double* start_position,
                          double* end_position,
                          double tf);

    /*——————————————————————————————————————————————
    |	function:	  Goto							
    |	parameter:	double* target_point 
    |                               - array containing target position coordinates (x, y, z)	
    |				      double tf         - time duration for the movement	
    |	used to:	  Move the end of the arm to a target position within the specified time duration.	
    ——————————————————————————————————————————————*/ 
    void Goto(double* target_point, double tf);

    /*——————————————————————————————————————————————
    |	function:	  MutiPoints							
    |	parameter:	double* points [] - array containing muti target points
    |				      double tf         - time duration for the movement	
    |             num               - number of points in the array
    |	used to:	  Move the end of the arm arcoss the points in the array
    ——————————————————————————————————————————————*/ 
    void MutiPoints(double* points[], double tf, int num);

    /*——————————————————————————————————————————————
    |	function:	  Data_Copy (static template function)	
    |	parameter:	T1* Data1         - array containing source data	
    |				      T2* Data2         - array to store copied data	
    |				      int length        - length of the arrays	(default 3) 
    |	used to:	  Copy data from one array to another.	
    ——————————————————————————————————————————————*/ 
    template<typename T1, typename T2>
    static void RobotArm::Data_Copy(T1* Data1, T2* Data2, int length = 3)
    {
      for(int times = 0; times < length; times ++)
      {
        Data2[times] = T2(Data1[times]);
      }
    }

    /*——————————————————————————————————————————————
    |	function:	  Position_Map_to (static template function)	
    |	parameter:	T1* Data          - array containing input data	
    |				      T1* output        - array to store mapped data	
    |	used to:	  Map a position from absolute coordinates to Workspace coordinates to ensure movement is within workspace
    ——————————————————————————————————————————————*/ 
    template<typename T1>
    static void RobotArm::Position_Map_to(T1* Data, T1* output)
    {
      output[0] = map(Data[0],0,100,-80,80);
      output[1] = map(Data[1],0,100,-120,-220);
      output[2] = map(Data[2],0,100,0,200);
    }

    /*——————————————————————————————————————————————
    |	function:	  Position_Map_Back (static template function)	
    |	parameter:	T1* Data          - array containing input data	
    |				      T1* output        - array to store mapped data	
    |	used to:	  Map a position back from Workspace coordinates to absolute coordinates	
    ——————————————————————————————————————————————*/ 
    template<typename T1>
    static void RobotArm::Position_Map_Back(T1 Data, T1 output)
    {
      output[0] = map(Data[0],-80,80,0,100);
      output[1] = map(Data[1],-120,-220,0,100);
      output[2] = map(Data[2],0,200,0,100);
    }


  private:
    int Joint1Pin = 2;
    int Joint2Pin = 3;
    int Joint3Pin = 4;
    int GripperPin = 11;
    // default Pin value
    int Joint1Angle = 120; // Change 5 sets of angles
    int Joint2Angle = 90; // Change 5 sets of angles
    int Joint3Angle = 90; // Change 5 sets of angles
    int GripperOpen = 60; // Open gripper; Need to tune value
    int GripperClose = 120; // Close gripper; Need to tune value
    // Joint Angle Offsets
    int Joint1Offset = 0; 
    int Joint2Offset = 0; 
    int Joint3Offset = 0; 
    
    double L1=100;
    double L2=170;

    double now_position[3] = {50,50,50};
    double now_maped_position[3] = {0,-170,100};
    double now_angle[3] = {90,90,90};
    int now_gipper = 1;
    
    Servo Joint1;
    Servo Joint2;
    Servo Joint3;
    Servo Gripper;
  
};

#endif
