#include <omp.h>
#include <stdio.h>
#include <time.h>

#include <initializer_list>

#include "measurement.cpp"

#define LOGIC 4
#define PHYSICAL 2
#define HALF PHYSICAL / 2
#define NUM_STEPS 1000000000
#define STEP 1. / (double)NUM_STEPS

/*
n_threads: 4
real_time: 4.647594s
 CPU_time: 17.852087s
 PI value: 3.141592653590

n_threads: 2
real_time: 5.664190s
 CPU_time: 11.297614s
 PI value: 3.141592653590

n_threads: 1
real_time: 11.330755s
 CPU_time: 11.295867s
 PI value: 3.141592653590
*/

int main(int argc, char* argv[]) {
  for (int n_threads : {LOGIC, PHYSICAL, HALF}) {
    omp_set_num_threads(n_threads);
    double pi, sum = 0.0;
    Measurement* measurement = new Measurement(n_threads);

    // ***************** obliczenia *****************
#pragma omp parallel default(none) shared(sum)
    {
      double x = 0.0, tmp_sum = 0.0;
#pragma omp for
      for (int i = 0; i < NUM_STEPS; i++) {
        x = (i + .5) * STEP;
        tmp_sum += 4.0 / (1. + x * x);
      }
#pragma omp atomic
      sum += tmp_sum;
    }
    pi = sum * STEP;
    // ***************** obliczenia *****************

    delete measurement;
    printf(" PI value:%15.12f\n\n", pi);
  }

  return 0;
}
