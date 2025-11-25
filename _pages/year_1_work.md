---
title: ""
layout: single
permalink: /talks/year_1_work/
---

<!--Year 1 Work-->
<h2 style="text-align: center; margin-bottom: 0.5em;">3D Printed Stirling Engine Project</h2>

<p style="margin-top: 30px; font-size: 14px;">
This project was part of the Design and Proffesional Skills module. Each stuednt was provided with a Creality Ender 3 printer in whihc w had to assembel ourselves and print out the respective parts for a Stirling Engine. Below is a video showing each part of the Stirling Engine being printed. After this, the stirling engine was then assmebled and tested to see how long it could run for whilst on top of a single hot mug of water. The Stirling Engine works by cycling air between a hot and cold side using a displacer piston. When the air moves to the hot side it expands and pushes the power piston, and when it moves to the cold side it contracts and pulls it back. This repeating pressure change drives the crankshaft and flywheel, allowing the engine to spin continuously.
</p>

<div style="display: flex; gap: 20px; justify-content: center; align-items: flex-start; flex-wrap: wrap;">

  <div style="width: 200px; height: 200px; position: relative; box-shadow: 0 4px 8px rgba(0,0,0,0.2);">
     <iframe
     src="https://www.youtube.com/embed/6m-51JdF1vE"
     frameborder="0"
     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture"
     allowfullscreen
     style="position: absolute; top: 0; left: 0; width: 100%; height: 100%; border: none;">
     </iframe>
   </div>

  <div style="width: 200px; height: 200px; position: relative; box-shadow: 0 4px 8px rgba(0,0,0,0.2);">
     <iframe
     src="https://www.youtube.com/embed/Bpgt76rbVkM"
     frameborder="0"
     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture"
     allowfullscreen
     style="position: absolute; top: 0; left: 0; width: 100%; height: 100%; border: none;">
     </iframe>
   </div>

</div>

<h2 style="text-align: center; margin-bottom: 0.5em;">Arduino Based Stirling Engine Measurement Task</h2>

<p style="margin-top: 30px; font-size: 14px;">
For this project, an Arduino-based Stirling engine was used to record a range of performance measurements. These included the temperature at the top of the engine, the temperature beneath the engine, and the temperature readings captured by a light-dependent sensor. The light sensor was used to determine the rotational speed of the flywheel by measuring the time taken for one of the six spokes to complete a full revolution. Angular velocity as a function of time was analysed, along with the overall efficiency of the engine. Two efficiency models were considered: the Carnot efficiency and the Chambadal–Novikov efficiency. A graph below presents the efficiency data obtained from the Stirling engine during analysis. The primary factors limiting efficiency were frictional losses—particularly at the piston rods—which could be reduced through improved lubrication, and air leakage, which lowers internal pressure and therefore performance. The full results and a step-by-step walkthrough of the project can be found in the Jupyter Notebook available for download below. Images of the experiment setup can also be seen below.
</p>

<div style="display: flex; gap: 20px; justify-content: center; align-items: flex-start; flex-wrap: wrap;">

  <img src="{{ '/assets/images/Arduino_Stirling_Engine_Image_One.jpg' | relative_url }}"
       style="height: 200px; width: auto; box-shadow: 0 4px 8px rgba(0,0,0,0.2);">

  <img src="{{ '/assets/images/Arduino_Stirling_Engine_Image_Two.jpg' | relative_url }}"
       style="height: 200px; width: auto; box-shadow: 0 4px 8px rgba(0,0,0,0.2);">

</div>

<div style="display: flex; gap: 20px; justify-content: center; align-items: flex-start; flex-wrap: wrap margin-top: 40px;">

  <img src="{{ '/assets/images/Arduino_Stirling_Engine_Efficiency.png' | relative_url }}"
       style="height: 200px; width: auto; box-shadow: 0 4px 8px rgba(0,0,0,0.2);">

  <img src="{{ '/assets/images/Arduino_Stirling_Engine_Efficiency.png' | relative_url }}"
       style="height: 200px; width: auto; box-shadow: 0 4px 8px rgba(0,0,0,0.2);">

</div>

<div style="text-align: center; margin-top: 20px;">
  <a href="/files/Arduino_Stirling_Engine_Project.ipynb" download>Stirling Engine Analysis Jupyter Notebook</a>
</div>

<h2 style="text-align: center; margin-bottom: 0.5em;">LVAC Impeller Manufacturing and Design Module Project</h2>

<p style="margin-top: 30px; font-size: 14px;">
This module focused on designing an impeller based on client requirements. In my project, the brief was to design an impeller for an implantable ventricular assist device that had to fit within a 100 mm housing. I produced a full technical report documenting the entire design process, covering the following core areas:
</p>

<ul style="font-size: 14px;"> 
  <li><strong>Problem Definition:</strong> Identification of functions, objectives (including an objective tree), and key constraints.</li> 
  <li><strong>Impeller Design Development:</strong> 
  CAD models for multiple impeller concepts and derivation of key design parameters such as leading/trailing edge angles, inlet and outlet blade heights, and flow path geometry.</li> 
  <li><strong>Material Analysis & Selection:</strong> 
  Definition of property constraints (e.g., stiffness, strength), derivation of Material Performance Indices (MPIs), and screening using Ashby plots generated in ANSYS EduPack.</li> 
  <li><strong>Manufacturing Method Selection:</strong> 
  Comparative analysis considering capital cost, production rate, tool life, and geometric suitability. Closed-die forging was selected as the proposed manufacturing method.</li> 
  <li><strong>Sustainability Analysis:</strong> 
  An Eco-Audit assessing material quantity, process impacts, mass, and end-of-life considerations.</li> 
</ul>

<p style="margin-top: 20px; font-size: 14px;">
I thoroughly enjoyed this project as it provided a holistic understanding of the multidisciplinary factors involved in engineering product development. It strengthened my knowledge of manufacturing processes and deepened my understanding of the considerations behind high-performance impeller design. I also gained experience using ANSYS EduPack—tools I later applied effectively during the IMechE Design Challenge.

The final impeller was SLS-printed and tested using an industrial-grade pump, achieving an efficiency of approximately 35%. While this is relatively low, it is expected given that the prototype was printed in nylon rather than aluminium. Rendered images of the impeller, MPI comparison plots, the printed part and mounting assembly are shown below, and the full project report is available for download.
</p>

<div style="display: flex; gap: 20px; justify-content: center; align-items: flex-start; flex-wrap: wrap margin-top: 40px;">

  <img src="{{ '/assets/images/Impeller_Picture.png' | relative_url }}"
       style="height: 200px; width: auto; box-shadow: 0 4px 8px rgba(0,0,0,0.2);">

  <img src="{{ '/assets/images/Impeller_Ashby_Plot.png' | relative_url }}"
       style="height: 200px; width: auto; box-shadow: 0 4px 8px rgba(0,0,0,0.2);">

</div>





