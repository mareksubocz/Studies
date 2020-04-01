#include <omp.h>
#include <stdio.h>
#include <time.h>

#include <initializer_list>

#include "measurement.cpp"

#define LOGIC 4
#define PHYSICAL 2
#define HALF PHYSICAL / 2

long long num_steps = 1000000000;
double x, pi, sum, step;

/*
n_threads: 4
real_time: 16.443293s
 CPU_time: 62.248417s
 PI value: 1.110113697821

n_threads: 2
real_time: 22.365031s
 CPU_time: 44.424872s
 PI value: 2.952779286642

n_threads: 1
real_time: 15.040152s
 CPU_time: 15.007047s
 PI value: 3.141592653590

Błędy w liczeniu pi wynikają z tego, że wszystkie zmienne są współdzielone,
Co powoduje m.in. odczyt innej wartości zmiennej sum niż tej, która zostaje
nadpisywana.
*/

int main(int argc, char* argv[]) {
  for (int n_threads : {LOGIC, PHYSICAL, HALF}) {
    x, pi, sum = 0.0;
    step = 1. / (double)num_steps;
    omp_set_num_threads(n_threads);
    Measurement* measurement = new Measurement(n_threads);

    // ***************** obliczenia *****************
    // wszystkie zmienne są współdzielone
#pragma omp parallel default(shared)
    {
#pragma omp for
      for (int i = 0; i < num_steps; i++) {
        x = (i + .5) * step;
        sum = sum + 4.0 / (1. + x * x);
      }
    }
    pi = sum * step;
    // ***************** obliczenia *****************

    delete measurement;
    printf(" PI value:%15.12f\n\n", pi);
  }

  return 0;
}
