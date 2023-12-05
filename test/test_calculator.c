#include "calculator.h"
#include <assert.h>
#include <math.h>

/* Prototyper til test-funktioner */
void test_do_next_op_0_plus_5(void);

/* Prototype til en funktion der sammenligner doubles men tillader små
 * afrundingsfejl. */
int is_almost_equal(double, double);

int main(void) {
  /* Kør alle test-funktioner. */
  test_do_next_op_0_plus_5();
}

/*********************************************
 * Skriv dine egne unit test af 'do_next_op' *
 *********************************************/
void test_do_next_op_0_plus_5(void) {
  // double akkumulator = 5.0;                   // Arrange
  // do_next_op('+', 5.0, &akkumulator);         // Act
  // assert(is_almost_equal(akkumulator, 10.0)); // Assert
}

// int is_almost_equal(double actual, double expected) {
//   return fabs(actual - expected) < 0.000001;
// }
