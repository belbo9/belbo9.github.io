---
title: ""
layout: single
permalink: /talks/robotics_module_info/
---

<!--Page Title-->
<h1 style="text-align: center;">Module Projects</h1>

<!--RoboDK Work Section-->
<h2 style="text-align: center; margin-bottom: 0.5em;">Year 1: RoboDK Offline Programming</h2>

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
RoboDK is a powerful offline programming software that supports many robot brands, with a library of over 500 robots from more than 50 manufacturers including ABB, KUKA, Fanuc, Motoman, and Universal Robots. It can generate real robot programs in the syntax required by each brand. This project focused on simulating three common robotic tasks: milling (Figure 1), welding (Figure 2), and deburring (Figure 3). For the simulation, I selected the ABB IRB 120-3/0.6, a 6‑DOF robot well suited to precise operations in limited spaces. The tasks were carried out by manually teaching the arm using RoboDK’s jogging tools.
</p>

<p style="font-size: 14px;">
Each task began with setting up the station, including the robot, frames, target points, and tools imported from RoboDK’s library. Frames define the orientation and position of targets. I chose to assign the reference frame to the work table so that, if the table is moved, only recalibration of the frame is required. Using the robot as the frame would mean re‑teaching all points, while assigning it to the object works best for single‑part setups but is inefficient in batch production. Since my aim was to simulate a multi‑part process, the table frame was the most practical choice.
</p>

<p style="font-size: 14px;">
The TCP (tool centre point) was also given a frame; this refers to the operating position and orientation of the tool with respect to the robot flange (the tip of the robot). Examples include the tip of a welding gun or the midpoint between gripper fingers. The TCP should match the target positions when the robot is in operation. Once this stage was complete, the robot was then given the target points by moving it to each desired position and declaring it a target. Approach and retract positions were also included to ensure collision‑free motion. I did encounter difficulties with singularities, as seen in the deburring video at 0:15, which led to some inefficient movements. 
</p>


<h2 style="text-align: center; margin-bottom: 0.5em;">Year 1: Pick and Place Robot Arm</h2>
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
  This project focused on building and controlling a 4‑DOF robot arm. An Arduino Duemilanove‑inspired “BotBoarduino” was used as the microcontroller, and HiTec servo motors were used to drive each joint. There were three main tasks, including an inverse kinematics task in which the arm’s end effector had to follow a horizontal linear motion of 5 cm in both the positive and negative x‑directions. The project concluded with a pick‑and‑place task, demonstrated by our team’s robot in the video above. We used a geometric approach to inverse kinematics to obtain the required joint angles for the pick‑and‑place motion. The cubic polynomial and function definitions used were as follows:
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
A for loop was used to compute 50 trajectory points for x, y, and z between the initial and final positions, with the loop iterating from t = 0 to t ≤ t<sub>f</sub> in steps of 0.1 seconds. The cubic polynomial function above was used to calculate the coordinates at each time step along the trajectory. The <code>Set_Position</code> member contains the inverse kinematics routine, which calculates the joint angles required to actuate the motors. Within the loop, a 100 ms delay was added so that the total motion time was 5 seconds. Target points were defined as home, pick, and place positions, and the robot was programmed to move in the sequence home → pick → home → place → home. The header, source, and sketch files for the project are attached below.
</p>

<!--Need to figure out how to make the folder isntallable-->
<div style="text-align: center;">
  <a href="/files/Robotics_Module_Project.7z" download>Pick and Place Arm Project Files</a>
</div>

<h2 style="text-align: center; margin-bottom: 0.5em;">Year 2: Image Processing and Object Detection Project</h2>

<p style="font-size: 14px;">
This was the first project of my second year on this elective module. It built on image‑processing fundamentals such as thresholding, Gaussian filters, median filters, and Sobel filters, as well as methods for finding an object’s centroid and orientation in an image. The project consisted of two tasks: the first required identifying the centroids and drawing bounding boxes around different fruits in a given image, and the second involved determining the centroid, orientation, and perimeter of an object in another image.
</p>

<p style="font-size: 14px;">
Once the image was pre‑processed, I applied a connected‑components algorithm based on a breadth‑first search. This method starts from a given pixel and checks its eight neighbours; any neighbour that is part of the same object is assigned the same label as the original pixel. This efficiently groups connected pixels into distinct regions, which in this case corresponded to different fruits in the image. The largest connected regions in each area matched the capsicum, apple, and lemon specified in the task, and the algorithm successfully identified all three fruits.
</p>

<div style="display: flex; gap: 20px; justify-content: center; align-items: flex-start; flex-wrap: wrap;">
  <img src="{{ '/assets/images/Capsicum_Detection.png' | relative_url }}"
       alt="Regionals PCB Schematic"
       style="height: 200px; width: auto; box-shadow: 0 4px 8px rgba(0,0,0,0.2);">

  <img src="{{ '/assets/images/Apple_Detection.png' | relative_url }}"
       alt="Regionals PCB Schematic"
       style="height: 200px; width: auto; box-shadow: 0 4px 8px rgba(0,0,0,0.2);">

  <img src="{{ '/assets/images/Lemon_Detection.png' | relative_url }}"
       alt="Regionals PCB Schematic"
       style="height: 200px; width: auto; box-shadow: 0 4px 8px rgba(0,0,0,0.2);">

</div>

<p style="margin-top: 20px; font-size: 14px;">
The next part of the task focused on identifying the orientation and centroid of an object within an image. Since the image had a clear intensity difference between foreground and background, only thresholding was required for preprocessing. To determine the centroid, image moments were used to calculate the weighted average of pixel intensities. The orientation was computed using second‑order image moments. Additionally, the eigenvalues and eigenvectors were used to construct the inertia matrix, which defines the major and minor axes of the object. To calculate the perimeter, a Sobel filter was first applied to extract edges. Once the edges were detected, the Moore–Neighbour tracing algorithm was used, which follows the 8‑connected neighbours around the boundary pixels. Previously, I used a simpler method that always chose the top‑left high‑intensity neighbour in a 3×3 grid, which sometimes caused the algorithm to loop incorrectly and miscalculate the perimeter. The Moore–Neighbour method avoids this by considering the previous neighbour’s position and starting two positions before it, effectively “hugging” the object boundary and producing the correct perimeter. The images below show the analysed object, including the region that previously caused issues with perimeter calculation. The code for both tasks is provided below and can be downloaded to see the implementation in action.

<div style="display: flex; gap: 20px; justify-content: center; align-items: flex-start; flex-wrap: wrap;">
  <img src="{{ '/assets/images/Issue_Case.png' | relative_url }}"
       alt="Regionals PCB Schematic"
       style="height: 200px; width: auto; box-shadow: 0 4px 8px rgba(0,0,0,0.2);">

  <img src="{{ '/assets/images/Object_Centroid.png' | relative_url }}"
       alt="Regionals PCB Schematic"
       style="height: 200px; width: auto; box-shadow: 0 4px 8px rgba(0,0,0,0.2);">
</div>

<div style="text-align: center; margin-top: 20px;">
  <a href="/files/Image_Processing_Tasks_Code.7z" download>Image Detection Project Files</a>
</div>
