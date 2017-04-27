Here are the codes I made in the Numerical Methods 2 course in my Computer Science graduation at Federal University of Ceará, taught by [Prof. Emanuele Santos](https://github.com/emanueles). They were made in 2014 and maybe not fully functional.
- If you see any writing errors or typos, please warn me;
- Any doubts, sugestions and/or issues, please contact me.
### Sumary
1. [Compiling](#compiling)
1.1 [Compiling Everything](#compiling-everything)
1.2 [Inidividual Compilation](#individual-compilation)
2. [Executing](#executing)
2.1 [General Execution](#general-execution)
2.2 [Specific Execution](#specific-execution)
3. [Appendix: General "main" files](#appendix)
3.1. [Numerical Integration](#numerical-integration)
3.2. [Numerical Derivative](#numarical-derivative)
3.3. [Initial Value Problems](#initial-value-problems)
3.4. [Boundary Value Problems](#boundary-value-problems)
3.5. [Eigenvalues and Eigenvectors](#eigenvalues-and-eigenvectors)
### 1. Compiling
##### 1.1 Compiling Everything
- To compile all methods at the same time it is enough to go into the folder where *Makefile* is and use the *make* command:
```
$ make
```
##### 1.2 Inidividual Compilation
- To compile only one method, use the corresponding *make* command.
- For this, you should go into the folder where the *Makefile* is and execute the *help* command:
```
$ make help
```
### 2. Executing
##### 2.1 General Execution
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
##### 2.2 Specific execution
- To execute a specific method, you should execute its own method with convenient arguments (you can verify it in `$ make help`).
- E.g.: to execute the trapezoidal rule without using the general *main* file your executable will be `execTrapezium` (please forgive my typo here, at that time I didn't know that the correct name is *trapezoidal rule*):
```
$ ./execTrapezium inputfile.txt
```
### 3. General *main* files
##### 3.1 Numerical Integration
- `main_closedNewtonCotes.cpp`
  * Used to solve single integrals using Closed Newton-Cotes methods;
  * It accepts order from 1 to 6, where 1 is the trapezoidal rule, 2 is the Simpson's 1/3 rule and 3 is the Simpson's 3/8 rule.
- `main_doubleIntegration.cpp`
  * Used to solve double integrals using Closed Newton-Cotes methods;
  * It accepts order from 1 to 6, where 1 is the trapezoidal rule, 2 is the Simpson's 1/3 rule and 3 is the Simpson's 3/8 rule.
- `main_romberg.cpp`
  * Used to solve double integrals using Romberg's method, which in turn uses Closed Newton-Cotes methods;
  * It accepts order from 1 to 6, where 1 is the trapezoidal rule, 2 is the Simpson's 1/3 rule and 3 is the Simpson's 3/8 rule.
##### 3.2. Numerical Derivative
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
##### 3.3. Initial Value Problems
- TODO
##### 3.4. Boundary Value Problems
- TODO
##### 3.5. Eigenvalues and Eigenvectors
- TODO
