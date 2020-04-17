#OPENMP JOB
#!/bin/bash

# name job - output at for each job
#$ -N ex2

#execute job in queue "std.q"
#$ -q std.q

# The batch system should use the current directory as working directory.
#$ -cwd

# Redirect output stream to this file
#$ -o ex2_output.txt

# Join the error stream to the output stream.
#$ -j yes

# use openmp with 8 job slots - each will be assigned one core
#$ -pe openmp 8

# Allocate 4 Gigabytes per job slot.
#$ -l h_vmem=4G

# check if job scribt syntax is ok
# -w v

# tell OpenMP how many threads to start
export OMP_NUM_THREADS=1
echo "1 Thread" &&./ex2_b 1500

export OMP_NUM_THREADS=2
echo "2 Threads" &&./ex2_b 1500

export OMP_NUM_THREADS=4
echo "4 Threads" &&./ex2_b 1500

export OMP_NUM_THREADS=8
echo "8 Threads" &&./ex2_b 1500