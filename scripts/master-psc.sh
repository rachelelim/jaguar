#!/bin/bash
fnamePattern="s080-res1-*"
fpath=$SCRATCH/meshes/proj/first

#################### Loop through Multiple Domains ####################
for i in $fpath/${fnamePattern}.inp
do
        fname=${i##*/}
        fnameBase=${fname%.*}
        logPath=$SCRATCH/job-logs/${fpath#*meshes/}
        outPath=../../stoat-out/${fpath#*meshes/}
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
	
	## Split Meshes
	## Remember to make the /parmesh directory!
	#sbatch \
	#--export fnameBase=$fnameBase,fpath=$fpath,outPath=$outPath \
	#--job-name split-$fnameBase \
	#--output $logPath/split-$fnameBase.log \
	#split-mesh-psc.sh
	
	## Run STOAT
	sbatch \
	--export fnameBase=$fnameBase,fpath=$fpath,outPath=$outPath \
	--job-name stoat-$fnameBase \
	--output $logPath/$fnameBase.log \
	run-stoat-psc.sh
done
#######################################################################
