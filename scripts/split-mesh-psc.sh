#!/bin/bash
#SBATCH -p LM			# partition
#SBATCH -t 48:00:00		# wall time HH:MM:SS
#SBATCH -N 1			# num of nodes
##SBATCH --ntasks-per-node 8	# cores per node
#SBATCH --mem 128GB 		# LM parition only
#SBATCH --mail-type ALL		# email (ALL means BEGIN+END+FAIL)
#SBATCH --mail-user timhsu@cmu.edu

module load moose-dev-gcc
cd $SCRATCH/projects/stoat
export I_MPI_SHM_LMT=shm
fname=$fnameBase
fpath=$fpath
outpath=$outPath

## Convert to ExodusII
./stoat-opt -i inputs/dummy.i \
Mesh/file=$fpath/${fname}.inp \
Outputs/exodus=true \
Outputs/file_base=$outpath/$fname \
--mesh-only \
$fpath/parmesh/${fname}.e

## Run Mesh Splitter
$SCRATCH/projects/moose/libmesh/installed/bin/splitter-opt \
--mesh=$fpath/parmesh/${fname}.e \
--n-procs=252
