#include <omp.h>
#include <stdio.h> 
#include <stdlib.h> 
int main() {
   int data, flag = 0;

   #pragma omp parallel num_threads(2)
   {
      if (omp_get_thread_num()==0) {
         data = 42;
	#pragma omp flush(data)  
	//Schreibt vom Cache in den gemeinsamen Speicher
	//Garantiert richtigen Wert, falls flag=1 durch die Optimierung vor data=42 ausgeführt
	//Ohne Flush möglicherweise undefiniert

         flag = 1;
	#pragma omp flush(flag)
	// Schreibt vom Cache in den gemeinsamen Speicher
	// Kann auch ohne Flush durchlaufen aber keine Garantie, 
	// dass die Zeile verdrängt wird, daher zurückgeschrieben wird.

      }
      else if (omp_get_thread_num()==1) {

	#pragma omp flush(flag)
	// Nicht unbedingt notwendig, flag=0 würde nur die Schleife einmal mehr wiederholen

         while (flag < 1) {
		#pragma omp flush(flag)
		// Muss FAST sicher gesetzt werden, wenn T1 flag liest bevor T0 flag schreibt
		// Höchst unwarscheinlich, dass flag verdrängt wird und der aktuelle Stand vom Cache

         }
         /* print flag and data */
	#pragma omp flush(data) // Garantiert richtigen Wert
         printf("flag=%d data=%d\n", flag, data);
      }
   } // Hier auto flush
   return 0;
}
