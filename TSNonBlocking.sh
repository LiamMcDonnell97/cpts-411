#!/bin/sh

#SBATCH --time=00:10:00
mpirun ~/PA1/NONBLOCKING 1
mpirun ~/PA1/NONBLOCKING 2
mpirun ~/PA1/NONBLOCKING 4
mpirun ~/PA1/NONBLOCKING 8
mpirun ~/PA1/NONBLOCKING 16
mpirun ~/PA1/NONBLOCKING 32
mpirun ~/PA1/NONBLOCKING 64
mpirun ~/PA1/NONBLOCKING 128
mpirun ~/PA1/NONBLOCKING 256
mpirun ~/PA1/NONBLOCKING 512
mpirun ~/PA1/NONBLOCKING 1024
mpirun ~/PA1/NONBLOCKING 2048
mpirun ~/PA1/NONBLOCKING 4096
mpirun ~/PA1/NONBLOCKING 8192
mpirun ~/PA1/NONBLOCKING 16384
mpirun ~/PA1/NONBLOCKING 32768
mpirun ~/PA1/NONBLOCKING 65536
mpirun ~/PA1/NONBLOCKING 131072
mpirun ~/PA1/NONBLOCKING 262144
mpirun ~/PA1/NONBLOCKING 512428
mpirun ~/PA1/NONBLOCKING 1048576
mpirun ~/PA1/NONBLOCKING 2097152
mpirun ~/PA1/NONBLOCKING 4194304
mpirun ~/PA1/NONBLOCKING 8388608




