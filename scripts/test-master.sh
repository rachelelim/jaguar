#!/bin/bash
fnamePattern="msri"
fpath=$SCRATCH/meshes/proj/first

#################### Loop through Multiple Domains ####################
for i in $fpath/$fnamePattern*.inp
do	
	fname=${i##*/}
	fnameBase=${fname%.inp}
	logPath=$SCRATCH/job-logs/${fpath#*meshes/}
	outPath=$SCRATCH/model-out/${fpath#*meshes/}
	echo "------------------------------------------------------"	
	echo "Full Path: $i"
	echo "File Name: $fnameBase"
	echo "File Path: $fpath"
	echo "Log Path:  $logPath"
	echo "Out Path:  $outPath"
	if [ ! -f $i ]; then
		echo "ERROR! FILE DOES NOT EXIST!"
		break
	fi		
done

