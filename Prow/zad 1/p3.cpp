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
Aby zapewnić niepodzielność na poziomie wątku możemy użyć dyrektywy
omp critical.

n_threads: 4
real_time: 107.719747s
 CPU_time: 409.347773s
 PI value: 3.141592653590

n_threads: 2
real_time: 68.058967s
 CPU_time: 135.720004s
 PI value: 3.141592653590

n_threads: 1
real_time: 20.612911s
 CPU_time: 20.569152s
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
      double x = 0.0;
#pragma omp for
      for (int i = 0; i < NUM_STEPS; i++) {
        x = (i + .5) * STEP;
#pragma omp atomic
        sum = sum + 4.0 / (1. + x * x);
      }
    }
    pi = sum * STEP;
    // ***************** obliczenia *****************

    delete measurement;
    printf(" PI value:%15.12f\n\n", pi);
  }

  return 0;
}
