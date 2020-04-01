#include <omp.h>
#include <stdio.h>
#include <time.h>

#include "measurement.cpp"

long long num_steps = 1000000000;
double step;

/*
n_threads: 1
real_time: 9.003374s
 CPU_time: 8.892694s
 PI value: 3.141592653590
*/

int main(int argc, char* argv[]) {
  double x, pi, sum = 0.0;
  step = 1. / (double)num_steps;
  Measurement* measurement = new Measurement(1);

  // ***************** obliczenia *****************
  for (int i = 0; i < num_steps; i++) {
    x = (i + .5) * step;
    sum = sum + 4.0 / (1. + x * x);
  }
  pi = sum * step;
  // ***************** obliczenia *****************

  delete measurement;
  printf(" PI value:%15.12f\n\n", pi);
  return 0;
}
