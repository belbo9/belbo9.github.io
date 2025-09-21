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

  <!-- Video 1 -->
  <div style="display: flex; flex-direction: column; align-items: center;">
    <iframe 
      src="https://www.youtube.com/embed/-H2SYbATgDw" 
      title="YouTube video player"
      width="350" height="197"
      frameborder="0"
      allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share"
      allowfullscreen
      style="border: none;">
    </iframe>
    <span style="margin-top: 10px;">Figure 1: Milling Task</span>
  </div>

  <!-- Video 2 -->
  <div style="display: flex; flex-direction: column; align-items: center;">
    <iframe 
      width="350" height="197" 
      src="https://www.youtube.com/embed/Zbuuk0audX0" 
      title="YouTube video player"
      frameborder="0"
      allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share"
      allowfullscreen
      style="border: none;">
    </iframe>
    <span style="margin-top: 10px;">Figure 2: Welding Task</span>
  </div>

  <!-- Video 3 -->
  <div style="display: flex; flex-direction: column; align-items: center;">
    <iframe 
      width="350" height="197" 
      src="https://www.youtube.com/embed/Zm06OF7Cao0" 
      title="YouTube video player"
      frameborder="0"
      allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share"
      allowfullscreen
      style="border: none;">
    </iframe>
    <span style="margin-top: 10px;">Figure 3: Deburring Task</span>
  </div>

</div>

<p style="margin-top: 30px;">
RoboDK is a powerful offline programming software that supports many robot brands, with a library of over 500 robots from more than 50 manufacturers including ABB, KUKA, Fanuc, Motoman, and Universal Robots. It can generate real robot programs in the syntax required by each brand. This project focused on simulating three common robotic tasks: deburring (Figure 1), milling (Figure 2) and welding (Figure 3). For the simulation, I selected the ABB IRB 120-3/0.6, a robot with 6 Degrees of Freedom and well-suited for precise operations in limited spaces. The tasks were carried out by manually teaching the arm using RoboDK's jogging tools.
</p>

<p>
Each task began with setting up the station, including the robot, frames, target points, and tools imported from RoboDK’s library. Frames define the orientation and position of targets. I chose to assign the reference frame to the work table, so if the table is moved, only recallibration of the frame is required. Using the robot as the frame would mean re-teaching all points, while assigning it to the object works best for single-part setups but is inefficient in batch production. Since my aim was to simulate a multi-part process, the table frame was the most practical choice.
</p>

<p>
The TCP (Tool Centre Point) was also provided a frame and this refers to the operating position and orientation of the tool, with respect to the robot flange (tip of the robot). Examples are the tip of a welding gun or or in the middle of gripper fingers. The TCP should match the target positions when the robot is in operation. Once this stage was done, the robot was than provided the target points by moving the robot to that position and declaring it a target point. 
</p>

Through this project, I gained hands-on experience in offline programming, learning how to optimize robot trajectories, manage accessibility issues, and understand the trade-offs between accuracy, speed, and flexibility. 

