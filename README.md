Here are the codes I made in the Numerical Methods 2 course in my Computer Science graduation at Federal University of Ceará, taught by [Prof. Emanuele Santos](https://github.com/emanueles). They were made in 2014 and maybe not fully functional.
- If you see any writing errors or typos, please warn me;
- Any doubts, sugestions and/or issues, please contact me.
### Sumary
- [Compiling](#compiling)
  * [Compiling Everything](#compiling-everything)
  * [Individual Compilation](#individual-compilation)
- [Executing](#executing)
  * [General Execution](#general-execution)
  * [Specific Execution](#specific-execution)
- [General *main* files](#general-main-files)
  * [Numerical Integration](#numerical-integration)
  * [Numerical Derivative](#numerical-derivative)
  * [Initial Value Problems](#initial-value-problems)
  * [Boundary Value Problems](#boundary-value-problems)
  * [Eigenvalues and Eigenvectors](#eigenvalues-and-eigenvectors)

### Compiling
##### Compiling Everything
- To compile all methods at the same time it is enough to go into the folder where *Makefile* is and use the *make* command:
```
$ make
```
##### Individual Compilation
- To compile only one method, use the corresponding *make* command.
- For this, you should go into the folder where the *Makefile* is and execute the *help* command:
```
$ make help
```
### Executing
##### General Execution
- To execute a method that has variations, you should execute the general *main* file of this method, whose last line argument should be the id of a specific method;
- E.g.: there are three specfic *main* files for Closed Newton-Cotes Methods: trapezoidal rule (1st order), Simpson's 1/3 rule (2nd order) and Simpson's 1/8 rule (3rd order). 
- However, it is possible to execute a Closed Newton-Cotes method up to 6th order. For this, you should use the general *main* file, `main_closedNewtonCotes.cpp`, with the executable `execClosedNC` (you can verify it in `$ make help`). The execution should be:
```
$ ./execClosedNC inputfile.txt order
```
- Example:
```
$ ./execClosedNC entrada1.txt 6
```
- A general *main* file can be used to execute specific examples without problems. Specific *main* files are nothing more than a provided use of a general *main* file.
- For specific informations of every method, please see the [Appendix](#appendix).
##### Specific execution
- To execute a specific method, you should execute its own method with convenient arguments (you can verify it in `$ make help`).
- E.g.: to execute the trapezoidal rule without using the general *main* file your executable will be `execTrapezium` (please forgive my typo here, at that time I didn't know that the correct name is *trapezoidal rule*):
```
$ ./execTrapezium inputfile.txt
```
### General *main* files
##### Numerical Integration
- `main_closedNewtonCotes.cpp`
  * Used to solve single integrals using Closed Newton-Cotes methods;
  * It accepts order from 1 to 6, where 1 is the trapezoidal rule, 2 is the Simpson's 1/3 rule and 3 is the Simpson's 3/8 rule.
- `main_quadrature.cpp`
  * Used to solve integrals using Gaussian Quadrature methods.
- `main_doubleIntegration.cpp`
  * Used to solve double integrals using Closed Newton-Cotes methods;
  * It accepts order from 1 to 6, where 1 is the trapezoidal rule, 2 is the Simpson's 1/3 rule and 3 is the Simpson's 3/8 rule.
- `main_romberg.cpp`
  * Used to solve double integrals using Romberg's method, which in turn uses Closed Newton-Cotes methods;
  * It accepts order from 1 to 6, where 1 is the trapezoidal rule, 2 is the Simpson's 1/3 rule and 3 is the Simpson's 3/8 rule.
##### Numerical Derivative
- `main_firstDerivative.cpp`
  * Used to solve first derivatives using finite difference methods or Lagrange multiplier;
  * It accepts values from 0 to 2, where 0 is Backward Difference, 1 is Forward Difference and 2 is Central Difference;
  * To use the Lagrange multiplier method, you should use the specific *main* file `main_lagrangeDerivative.cpp`.
- `main_richardsonExtrapolation.cpp`
  * Used to solve first derivatives using Richardson extrapolation method, which in turn uses finite difference;
  * It accepts values from 0 to 2, where 0 is Backward Difference, 1 is Forward Difference and 2 is Central Difference.
- `main_secondDerivative.cpp`
  * Used to solve second derivatives using finite difference methods;
  * It accepts values from 0 to 2, where 0 is Backward Difference, 1 is Forward Difference and 2 is Central Difference.
##### Initial Value Problems
- `mainAdamsPredictorCorrector.cpp`
  * It accepts order values of 0 or 1, where 0 is Adams Predictor-Corrector 3rd order and 1 is Adams Predictor-Corrector 4th order.
- `mainRungeKutta.cpp`
  * It accepts order values from 0 to 3, where 0 is Forward Euler method (Runge-Kutta 1st order), 1 is Runge-Kutta 2nd order, 2 is Runge-Kutta 3rd order and 3 is Runge-Kutta 4th order.
##### Boundary Value Problems
```
Please, see also the "Intructions" file inside the folder "BoundaryValueProblems"
```
- `main_tridiagonalMatrx.cpp`
  * Used to solve a linear system, represented by a tridiagonal matrix.
- `main_gaussianElimination.cpp`
  * Used to solve a linear system, represented by a two-dimensional matrix, using Gaussian ELimination.
- `main_gaussSeidel.cpp`
  * Used to solve a linear system, represented by a two-dimensional matrix, using Gauss-Seidel method.
##### Eigenvalues and Eigenvectors
```
Incomplete*
```
- `main_powerIteration.cpp`
- `main_inverseIteration.cpp`
- `main_powerIteration.cpp`
- `main_jacobi.cpp`
- `main_qrAlgorithm.cpp`
- `main_householderTransformation.cpp`
