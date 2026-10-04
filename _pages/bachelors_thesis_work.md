---
title: ""
layout: single
permalink: /talks/bachelors_thesis_work/
---

<!--Year 1 Work-->
<h2 style="text-align: center; margin-bottom: 0.5em;">Design of a Robotic Platform for Air Velocity Mapping in an Operating Theatre</h2>

<p style="margin-top: 30px; font-size: 14px;">
My bachelor thesis focused on developing a device capable of carrying out automated air velocity mapping beneath surgical canopies found in operating theatres. This forms part of a wider research aim to investigate the overexpeditation of energy expenditure, where the velocities found beneath canopies tend to exceed the required thresholds provided by HTM 0301 regulations. Current methods rely on manual air sampling, which introduces inaccuracies due to inconsistent positioning and thermal plumes due to the operator’s presence. I worked under the supervision of Professor Ian Eames and was able to successfully execute the development of the prototype model. Its components include the use of a DRV8825 motor driver for control of the NEMA 17 stepper motors, alongside an ESP32 WROOM for the microcontroller. 3D models of the prototype designed in Fusion 360 can be seen below with the whole device, base area and air velcoity components shown.
</p>

<div style="display: flex; gap: 20px; justify-content: center; align-items: flex-start; flex-wrap: wrap;">

  <img src="{{ '/assets/images/Robot_Device_Final_Render.png' | relative_url }}"
       style="height: 300px; width: auto; box-shadow: 0 4px 8px rgba(0,0,0,0.2);">

  <img src="{{ '/assets/images/Robot_Base.png' | relative_url }}"
       style="height: 300px; width: auto; box-shadow: 0 4px 8px rgba(0,0,0,0.2);">

  <img src="{{ '/assets/images/Robot_Top.png' | relative_url }}"
       style="height: 300px; width: auto; box-shadow: 0 4px 8px rgba(0,0,0,0.2);">

</div>






<p style="margin-top: 30px; font-size: 14px;">
The device operates using the boustrophedron pattern, allowing the robot to log air velocity in a line-by-line fashion whilst pausing at each desired position. The video below demonstrates an example trial process (at 10x speed). The air velocity sensor is able to attia readings at the desired 1 m and 2 m heights from ground level, where a smooth execution of all functionalities is evident.  
</p>
<div style="display: flex; gap: 20px; justify-content: center; align-items: flex-start; flex-wrap: wrap;">


  <div style="width: 700px; height: 300px; position: relative; box-shadow: 0 4px 8px rgba(0,0,0,0.2);">
     <iframe
     src="https://www.youtube.com/embed/QI12ygJ2eks?si=VN35PWAEFPTNqFUQ"
     frameborder="0"
     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture"
     allowfullscreen
     style="position: absolute; top: 0; left: 0; width: 100%; height: 100%; border: none;">
     </iframe>
   </div>

</div>