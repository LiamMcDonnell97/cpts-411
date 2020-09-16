/*	Cpt S 411, Introduction to Parallel Computing
 *	School of Electrical Engineering and Computer Science
 *	
 *	Example code
 *	Send receive test:
 *   	rank 1 sends to rank 0 (all other ranks sit idle)
 *   	For timing use of C gettimeofday() is recommended.
 * */


#include <stdio.h>
#include <mpi.h> 
#include <assert.h>
#include <sys/time.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{

   int rank,p;
   int size = 1;
   int loops = 10;
   struct timeval t1,t2;

   MPI_Init(&argc,&argv);
   MPI_Comm_rank(MPI_COMM_WORLD,&rank);
   MPI_Comm_size(MPI_COMM_WORLD,&p);

   if(argc>=2){
   	size = atoi(argv[1]);
	assert(size>=1);
	printf("Test for blocking send recive with bites m=%d\n", size);
	printf("my rank=%d\n",rank);
   	printf("Rank=%d: number of processes =%d\n",rank,p);
   }

   if(rank==1) {
		char *x = (char *)malloc(sizeof(char)*size);
		int dest = 0;
		gettimeofday(&t1,NULL);
		for(int i = 0; i < loops; i++)
			MPI_Send(x,size,MPI_CHAR,dest,0,MPI_COMM_WORLD);
		gettimeofday(&t2,NULL);
		int tSend = (t2.tv_sec-t1.tv_sec)*1000000 + (t2.tv_usec-t1.tv_usec);

		printf("Rank=%d: sent message size %d to rank %d; Send time %d microsec\n", rank,size,dest,tSend/loops);
   } else 
   if (rank==0) {
   		char *y = (char *)malloc(sizeof(char)*size);
		MPI_Status status;
		gettimeofday(&t1,NULL);
		for(int i = 0; i < loops; i++)
   			MPI_Recv(y,size,MPI_CHAR,MPI_ANY_SOURCE,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
		gettimeofday(&t2,NULL);
		int tRecv = (t2.tv_sec-t1.tv_sec)*1000000 + (t2.tv_usec-t1.tv_usec);
		printf("Rank=%d: received message size %d from rank %d; Recv time %d icrosec\n",rank,size,status.MPI_SOURCE,tRecv/loops);
   }

   MPI_Finalize();
   printf("\n\n\n\n");
}
