---
title: ""
layout: single
permalink: /talks/year_1_work/
---

<!--Page Title-->
<h1 style="text-align: center;">Year 1 Projects</h1>

<!--RoboDK Work Section-->
<h2 style="text-align: center; margin-bottom: 0.5em;">3D Printer Stirling Engine Work</h2>

<p style="margin-top: 30px; font-size: 14px;">
This project was part of the Design and Proffesional Skills module. Each stuednt was provided with a Creality Ender 3 printer in whihc w had to assembel ourselves and print out the respective parts for a Stirling Engine. Below is a video showing each part of the Stirling Engine being printed:
</p>

<div style="width: 233px; margin: 0 auto;">   <!-- centers the container -->
    <div style="position: relative; padding-bottom: 56.25%; height: 0; overflow: hidden;">
      <iframe
        width="350" height="197" 
        src="https://www.youtube.com/embed/Bpgt76rbVkM"
        frameborder="0"
        allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture"
        allowfullscreen
        style="position: absolute; top:0; left:0; width:100%; height:100%; border: none;">
      </iframe>
    </div>
</div>

<p style="margin-top: 30px; font-size: 14px;">
After this, the stirling engine was then assmebled and tested to see how long it could run for whilst on top of a single hot mug of water. The Stirling Engine works by cycling air between a hot and cold side using a displacer piston. When the air moves to the hot side it expands and pushes the power piston, and when it moves to the cold side it contracts and pulls it back. This repeating pressure change drives the crankshaft and flywheel, allowing the engine to spin continuously.
</p>

<div style="width: 233px; margin: 0 auto;">   <!-- centers the container -->
    <div style="position: relative; padding-bottom: 56.25%; height: 0; overflow: hidden;">
      <iframe
        width="350" height="197" 
        src="https://www.youtube.com/embed/6m-51JdF1vE"
        frameborder="0"
        allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture"
        allowfullscreen
        style="position: absolute; top:0; left:0; width:100%; height:100%; border: none;">
      </iframe>
    </div>
</div>

<h2 style="text-align: center; margin-bottom: 0.5em;">Arduino Based Stirling Engine Work</h2>

<p style="margin-top: 30px; font-size: 14px;">
In this project, an Arduino-based low-temperature Stirling engine was used to collect real-time measurements. Three sensors were used: a lower-temperature sensor positioned near the cold reservoir, an upper-temperature sensor positioned near the hot reservoir, and a light sensor aimed at the flywheel spokes to detect each rotation and determine the engine’s RPM. Once the experimental data were gathered, post-processing was carried out to calculate both the Carnot efficiency and the Chambadal–Novikov efficiency. The results showed a clear positive correlation between temperature difference and both efficiency values, with the Carnot efficiency consistently higher because it represents the theoretical maximum efficiency of a perfectly reversible cycle. In contrast, the Chambadal–Novikov efficiency gives a more realistic estimate because it accounts for irreversibilities such as heat losses and friction within the engine. Ways to increase the efficiency for this experiment would have been to increase the temperature gradient, improve heat insulation, reduce mechanical friction through lubrication of the piston rods, and optimizing the phase angle and dead-space volume. An image of the Stirling engine setup used in this experiment is shown below. Additionally, the accompanying Jupyter notebook provides a step-by-step walkthrough of the code implementation and the analysis of the Stirling engine’s performance.
</p>

<div style="text-align: center; margin-top: 20px;">
  <a href="/files/Arduino_Stirling_Engine_Project.ipynb" download>Stirling Engine Analysis Jupyter Notebook</a>
</div>

