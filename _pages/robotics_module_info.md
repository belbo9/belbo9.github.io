---
title: ""
layout: single
permalink: /talks/robotics_module_info/
---

<!--Page Title-->
<h1 style="text-align: center;">Module Projects</h1>

<!--RoboDK Work Section-->
<h2 style="text-align: center; margin-bottom: 0.5em;">RoboDK Offline Programming</h2>

<div style="display: flex; gap: 20px; justify-content: center; align-items: flex-start; flex-wrap: wrap;">

  <!-- Milling Video -->
  <div style="width: 233px;">
    <div style="position: relative; padding-bottom: 56.25%; height: 0; overflow: hidden;">
      <iframe
        width="350" height="197" 
        src="https://www.youtube.com/embed/-H2SYbATgDw"
        frameborder="0"
        allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture"
        allowfullscreen
        style="position: absolute; top:0; left:0; width:100%; height:100%; border: none;">
      </iframe>
    </div>
    <span style="display: block; text-align: center; margin-top: 10px;">Figure 1: Milling Task</span>
  </div>

  <!-- Welding Video -->
  <div style="width: 233px;">
    <div style="position: relative; padding-bottom: 56.25%; height: 0; overflow: hidden;">
      <iframe 
        width="350" height="197" 
        src="https://www.youtube.com/embed/Zbuuk0audX0" 
        frameborder="0"
        allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share"
        allowfullscreen
        style="border: none;">
      </iframe>
    </div>
    <span style="display: block; text-align: center; margin-top: 10px;">Figure 2: Welding Task</span>
  </div>

  <!-- Deburring Video -->
  <div style="width: 233px;">
    <div style="position: relative; padding-bottom: 56.25%; height: 0; overflow: hidden;">
      <iframe 
        width="350" height="197" 
        src="https://www.youtube.com/embed/Zm06OF7Cao0" 
        frameborder="0"
        allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share"
        allowfullscreen
        style="border: none;">
      </iframe>
    </div>
    <span style="display: block; text-align: center; margin-top: 10px;">Figure 3: Deburring Task</span>
  </div>

</div>

<p style="margin-top: 30px; font-size: 14px;">
RoboDK is a powerful offline programming software that supports many robot brands, with a library of over 500 robots from more than 50 manufacturers including ABB, KUKA, Fanuc, Motoman, and Universal Robots. It can generate real robot programs in the syntax required by each brand. This project focused on simulating three common robotic tasks: millig (Figure 1), welding (Figure 2) and deburring (Figure 3). For the simulation, I selected the ABB IRB 120-3/0.6, a robot with 6 Degrees of Freedom and well-suited for precise operations in limited spaces. The tasks were carried out by manually teaching the arm using RoboDK's jogging tools.
</p>

<p style="font-size: 14px;">
Each task began with setting up the station, including the robot, frames, target points, and tools imported from RoboDK’s library. Frames define the orientation and position of targets. I chose to assign the reference frame to the work table, so if the table is moved, only recallibration of the frame is required. Using the robot as the frame would mean re-teaching all points, while assigning it to the object works best for single-part setups but is inefficient in batch production. Since my aim was to simulate a multi-part process, the table frame was the most practical choice.
</p>

<p style="font-size: 14px;">
The TCP (Tool Centre Point) was also provided a frame and this refers to the operating position and orientation of the tool, with respect to the robot flange (tip of the robot). Examples are the tip of a welding gun or or in the middle of gripper fingers. The TCP should match the target positions when the robot is in operation. Once this stage was done, the robot was than provided the target points by moving the robot to the desired position and declaring it a target point. Approach and retract positions were also included to ensure collision-free movement. I did also face difficulties when singularities were faced which can be seen in the deburring video at (0:15), which required inefficient movements as shown. 
</p>


<h2 style="text-align: center; margin-bottom: 0.5em;">Pick and Place Robot Arm</h2>
<!--Pick and place task vid-->
  <div style="width: 350px; margin: 0 auto; text-align: center;">
    <div style="position: relative; padding-bottom: 56.25%; height: 0; overflow: hidden;">
      <iframe 
        width="350" height="197" 
        src="https://www.youtube.com/embed/GSOhORPYmpA" 
        frameborder="0"
        allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share"
        allowfullscreen
        style="border: none;">
      </iframe>
    </div>
    <span style="display: block; text-align: center; margin-top: 10px;">Figure 4: Pick-and-place robotic arm task</span>
  </div>

  <p style="margin-top: 30px; font-size: 14px;">
  This project focused on building and controlling a 4DOF freedom robot arm. A Arduino Duemoilanove inspired 'BotBoarduino' as the microprocessor. HiTec servo motors were useed to control each joint. There were 3 total tasks which included an Inverse Kinematics Task where the arm had to move to ensure it's end effector followed a horzintal linear motion both 5cm in the positive and negative x directions. This project completed with a pick-and-place task in which a demonstration by our team's robot shown above. We used a geometric apporach wehn using inverse kinematics to obtian the required joint angles for end effector actuation for the pick-and-place task. The cubic polynominal and fucniton definitions used were as follows:
  </p>
  
  <html>
  <head>
  <script src="https://polyfill.io/v3/polyfill.min.js?features=es6"></script>
  <script id="MathJax-script" async
    src="https://cdn.jsdelivr.net/npm/mathjax@3/es5/tex-mml-chtml.js">
  </script>
  </head>

  <body>
  \[ 
  u(t) = 
  \begin{cases} 
  a_0 + a_1 t + a_2 t^2 + a_3 t^3 & \text{if } t \le t_f \\[2mm]
  \displaystyle u_f & \text{if } t \ge t_f
  \end{cases}
  \]


  \[
    a_{i0} = u_{0i}
  \]

  \[
  a_{i1} = 0
  \]

  \[
  a_{i2} = \frac{3}{t_f^2} \left( u_{fi} - u_{0i} \right)
  \]

  \[
  a_{i3} = -\frac{2}{t_f^3} \left( u_{fi} - u_{0i} \right)
  \]

</body>
</html>

<p style="font-size: 14px;">
A for loop was employed to compute 50 trajectory points for x, y, and z between the initial and
final points, with the loop iterating from t = 0 to t <= 𝑡2 in intervals of 0.1 seconds. The cubic polynominal function shown above is used to calculate the coordinates within each time step in the trajectory path. The 'Set_Position' member contains the inverse kinematics script which caluculates the required joint angles to actuate the motors. Within the for loop, a delay of 100ms was added so that the total time the
robot takes to move is equal to 5s. Target points were declared as home, pick and place positions
and the robot is programmed using the for loop to go in the order home → pick → home → place →
home. The header, source and sketch files for the project are attached below.
</p>

<!--Need to figure out how to make the folder isntallable-->
<div style="text-align: center;">
  <a href="/files/Robotics_Module_Project.7z" download>Pick and Place Arm Project Files</a>
</div>

<h2 style="text-align: center; margin-bottom: 0.5em;">Year 2: Image Processing and Object Detection Project</h2>

<p style="font-size: 14px;">
This was the first project of my 2nd year taking this elective module. This built upon image processing fundamentals learnt which indluded threshdoling, Gaussain filters, median filters, Sorbel filters etc. Alongisde this, methods of obtaining the orietnation and centroid of an object within an image was also covered. In this project there were 2 tasks with the first focused on identifying the centroids and drawing a bounding box for different fruits within a given image. The next focused on determining the centrodi adn oreintaiotn of an object within another image as well as the perimeter. To carry out the first task, I carried out the follwing steps:
</p>

<ul style="font-size: 14px;">
  <li>My initial</li>
</ul>

<p style="font-size: 14px;">
Whilst the image was now preporcessed, I then applied the 'Connected Component's algorithm whihc uses a Breadth-First Search. This works by essentially starting at one pixel within the image, tehn if another image is one of the 8 direct neighbours of the pixel, it gets labelled with the same class as the original pixel. This is efficeint as it means that groups of connected pixels are labelled accorindlgy and worked perfectly in this case as groups of pixels indicated the differnt fruits here, with the largest intensity of pixels in a specific region correlating to the fruit that is being looked for. The image below show this funciotnaing and successfully idenityfing the capsiscum, apple and lemon as required by the task.
</p>

<div style="display: flex; gap: 20px; justify-content: center; align-items: flex-start; flex-wrap: wrap;">
  <img src="{{ '/assets/images/Capsicum_Detection.png' | relative_url }}"
       alt="Regionals PCB Schematic"
       style="height: 200px; width: auto; box-shadow: 0 4px 8px rgba(0,0,0,0.2);">

  <img src="{{ '/assets/images/Apple_Detection.png' | relative_url }}"
       alt="Regionals PCB Schematic"
       style="height: 300px; width: auto; box-shadow: 0 4px 8px rgba(0,0,0,0.2);">

  <img src="{{ '/assets/images/IMECHE_ANSYS_Blog.png' | relative_url }}"
       alt="Regionals PCB Schematic"
       style="height: 300px; width: auto; box-shadow: 0 4px 8px rgba(0,0,0,0.2);">

</div>

<p style="font-size: 14px;">
The next part of the task focused on identifying the orientation and centroid of an object within an image. Since the image had a distinct color gradient between the foreground and background, only thresholding was required for preprocessing. To determine the centroid, image moments were used, which calculate the weighted average of pixel intensities. The orientation was computed using second-order image moments. Additionally, the eigenvalues and eigenvectors were used to construct the inertia matrix, which defines the major and minor axes of the object. To calculate the perimeter of the object, the Sobel filter was first applied to extract the edges. Once the edges were detected, the Neighbour-Moore Trace algorithm was employed. This algorithm uses the 8-connected neighbours to follow the boundary pixels around the object. Previously, I had used a simpler method that selected the next pixel based solely on the top-left high-intensity neighbour in a 3×3 grid. However, this sometimes caused the algorithm to loop incorrectly around boundary pixels, producing an inaccurate perimeter. The Neighbour-Moore Trace solves this issue by considering the previous neighbour’s position and starting two positions before it, effectively “hugging” the object boundary. This approach produced the correct perimeter. The images below show the analysed object, including the area that previously caused issues with perimeter calculation. The code for both tasks is also provided below and is available for download to see the implementation in action:

<div style="display: flex; gap: 20px; justify-content: center; align-items: flex-start; flex-wrap: wrap;">
  <img src="{{ '/assets/images/IMECHE_ANSYS_Blog.png' | relative_url }}"
       alt="Regionals PCB Schematic"
       style="height: 300px; width: auto; box-shadow: 0 4px 8px rgba(0,0,0,0.2);">

  <img src="{{ '/assets/images/IMECHE_ANSYS_Blog.png' | relative_url }}"
       alt="Regionals PCB Schematic"
       style="height: 300px; width: auto; box-shadow: 0 4px 8px rgba(0,0,0,0.2);">

  <img src="{{ '/assets/images/IMECHE_ANSYS_Blog.png' | relative_url }}"
       alt="Regionals PCB Schematic"
       style="height: 300px; width: auto; box-shadow: 0 4px 8px rgba(0,0,0,0.2);">

</div>

<div style="text-align: center;">
  <a href="/files/Image_Processing_Tasks_Code.7z" download>Image Detection Project Files</a>
</div>
