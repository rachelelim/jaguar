#!/bin/bash -l

#SBATCH -q regular
#SBATCH -N 64                    # num of nodes
#SBATCH -t 05:00:00              # wall time HH:MM:SS
#SBATCH --ntasks-per-node 28 	# cores per node
# #SBATCH --mem 16GB            # LSM parition only
#SBATCH --mail-type ALL         # email (ALL means BEGIN+END+FAIL)
#SBATCH --mail-user timhsu@cmu.edu

cd $SCRATCH/projects/jaguar
export I_MPI_SHM_LMT=shm
fname=$fnameBase
fpath=$fpath
outpath=$outPath

## Run STOAT (cyl-mesh test)
#mpirun ./stoat-opt -i inputs/cyl_mesh.i \
#Mesh/file=$fpath/${fname}.msh    \
#Outputs/file_base=$outpath/$fname


## Run STOAT
#mpirun ./stoat-opt -i inputs/micro_cat.i \
#Mesh/file=$fpath/${fname}.inp \
#GlobalParams/s0=8138.3 \
#Outputs/file_base=$outpath/$fname \
#Outputs/exodus=true


## RUN STOAT (Distributed Mesh)
mpirun ./stoat-opt -i inputs/micro_cat.i \
Mesh/file=$fpath/parmesh/${fname}.cpr \
Mesh/parallel_type=DISTRIBUTED \
Outputs/file_base=$outpath/$fname \
Outputs/exodus=true \
GlobalParams/s0=7252.8 \
Executioner/nl_rel_tol=1e-4 \
Executioner/l_tol=1e-2
