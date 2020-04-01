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
real_time: 6.175133s
 CPU_time: 23.964408s
 PI value: 3.141592653590

n_threads: 2
real_time: 9.992137s
 CPU_time: 16.767874s
 PI value: 3.141592653590

n_threads: 1
real_time: 11.340937s
 CPU_time: 11.297006s
 PI value: 3.141592653590
*/

int main(int argc, char* argv[]) {
  for (int n_threads : {LOGIC, PHYSICAL, HALF}) {
    omp_set_num_threads(n_threads);
    double pi, sum = 0.0;
    volatile double tmp_sums[n_threads];
    Measurement* measurement = new Measurement(n_threads);

    // ***************** obliczenia *****************
#pragma omp parallel default(none) shared(sum, tmp_sums)
    {
      int my_num = omp_get_thread_num();
      double x = 0.0;
#pragma omp for
      for (int i = 0; i < NUM_STEPS; i++) {
        x = (i + .5) * STEP;
        tmp_sums[my_num] += 4.0 / (1. + x * x);
      }
#pragma omp atomic
      sum += tmp_sums[my_num];
    }
    pi = sum * STEP;
    // ***************** obliczenia *****************

    delete measurement;
    printf(" PI value:%15.12f\n\n", pi);
  }

  return 0;
}
