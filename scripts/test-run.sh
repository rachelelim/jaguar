#!/bin/bash
#SBATCH -p RM 			# partition
#SBATCH -t 00:30:00             # wall time HH:MM:SS
#SBATCH -N 9                    # num of nodes
#SBATCH --ntasks-per-node 28 	# cores per node
# #SBATCH --mem 16GB            # LSM parition only
#SBATCH --mail-type ALL         # email (ALL means BEGIN+END+FAIL)
#SBATCH --mail-user timhsu@cmu.edu

module load moose-dev-gcc
cd $SCRATCH/projects/stoat
export I_MPI_SHM_LMT=shm
ls -lh

## Run ERMINE 
#mpirun \
#./stoat-opt -i inputs/cyl_mesh.i \
#Mesh/file=$fpath/${fname}.msh    \
#Outputs/file_base=$outpath/$fname

#mpirun ermine-opt -i inputs/micro_cat.i \
#Mesh/file=meshes/${fpath}/${fname}.inp \
#GlobalParams/s0=8138.3 \
#Outputs/file_base=outputs/${fpath}/${fname} \
#Outputs/exodus=true


## RUN ERMINE (Distributed Mesh)
#mpirun ermine-opt -i inputs/micro_cat.i \
#Mesh/file=meshes/${fpath}/parmesh/${fname}.256.cpr \
#Mesh/parallel_type=DISTRIBUTED \
#Outputs/file_base=outputs/${fpath}/nltol-1e-4/${fname} \
#Outputs/exodus=true \
#GlobalParams/s0=3472.6 \
#Executioner/nl_rel_tol=1e-4 \
#Executioner/l_tol=1e-2
