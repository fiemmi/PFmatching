# PFmatching
Label the true noPU PF candidates

WORKFLOW:

i) ntuplize a given number of events from noPU files
ii) print runNo, lumiSec, evtNo and use this info to extract the very same events from PU miniAOD file using edmPickEvents.py; ntuplize them
iii) Now you have 2 root files with the very same events. They're still in a different order though. Sort the events based on evtNo with the macro sortTrees.C
iv) Now that you have sorted events, pick the first of each file, merge, pick the second, merge and so on using createTreePU_noPU.C
v) Perform the matching on the output using PFmatching.C
