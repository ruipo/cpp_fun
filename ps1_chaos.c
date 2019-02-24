#include<stdio.h>
#include<complex.h>
#include<math.h>

int main(){

  int N;
  int M;
  // printf("Enter two intergers N,M");
  scanf("%d %d",&N,&M);

  //char mandelbrot[M][N];

  for (int b  = 0; b < M; b++){
    for (int a  = 0; a < N; a++){

      double complex c = ((double)a/(double)N*3.5-2.5)+((double)b/(double)M-.5)*2.0*I;
      double zreal = 0;
      double zimag = 0;
      for (int n = 1; n < 501; n++){
	double zr = zreal;
	double zi = zimag;
	zreal = zr*zr-zi*zi+creal(c);
	zimag = 2*zr*zi+cimag(c);
      }

      if (zreal*zreal+zimag*zimag <= 4){
	//mandelbrot[b][a] = '*';
	printf("%c",'*');
      }

      else {
	//mandelbrot[b][a] = ' ';
	printf("%c",' ');
      }

      //printf("%c", mandelbrot[b][a]);

    }

    printf("\n");

  }	

  return 0;

}
