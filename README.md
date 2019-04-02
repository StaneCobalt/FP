# Time Cost Analysis

Estimates cost in time for software development using either Function Points, Basic COCOMO, or Intermediate COCOMO.

<details>
  <summary>### CLI</summary>

The cli version is built in C++.
To view the documentation for it [click here](https://stanecobalt.github.io/TCA/html/)

#### How to Use

- To run the program just open up a command line and run `make all`
- Then run `tca.exe`
- Note that you will need to have [make](https://www.gnu.org/software/make/) and [gcc](https://gcc.gnu.org/) installed.
If you're on Windows, I recommend using [MinGW](https://nuwen.net/).
</details>

<details>
  <summary>### Web</summary>

The web version is built in JavaScript and is much easier to use since it has a GUI.

#### How to Use

To use the web version, you can simply [click here](https://stanecobalt.github.io/TCA/web/) and start using it immediately inside of your browser.
</details>

<details>
  <summary>## Function Points</summary>

#### Algorithm
N = number of that type of component

C = component complexity value

I = influence value

Unadjusted Function Points (UFP) = (N0 x C0) + (N1 x C1) + (N2 x C2)...

Degree of Influence (DI) = I0 + I1 + I2 + ... + I14

Technical Complexity Factor (TCF) = 0.65 + (0.01 x DI)

Adjusted Function Points (FP)= UFP x TCF

#### Component Complexities
| Component | Simple | Average | Complex |
| ----------- | - | - | - |
| Input item | 3 | 4 | 6 |
| Output item | 4 | 5 | 7 |
| Inquiry | 3 | 4 | 6 |
| Master file | 7 | 10 | 15 |
| Interface | 5 | 7 | 10 |

#### Technical Factors
These are used for degrees of influence and range from values 0 for no influence to 5 for strong influence
1. Data communication
2. Distributed data processing
3. Performance criteria
4. Heavily utilized hardware
5. High transaction rates
6. Online data entry
7. End-user efficiency
8. Online updating
9. Complex computations
10. Reusability
11. Ease of installation
12. Ease of operation
13. Portability
14. Maintainability
</details>

<details>
  <summary>## COCOMO</summary>

### Basic COCOMO
#### Algorithm
KDSI = estimated lines of code in thousands

A and B are constants given by project size.

Person-Months = A x KDSI <sup>B</sup>

#### Project Complexity Constants
| Type | Size | A | B |
| ------------- | -------- | --- | ---- |
| Organic | Small | 2.4 | 1.05 |
| Semi-detached | Medium | 3.0 | 1.12 |
| Embedded | Complex | 3.6 | 1.20 |


### Intermediate COCOMO

#### Algorithm
KDSI = estimated lines of code in thousands

A and B are constants given by project size.

Person-Months (basic) = A x KDSI <sup>B</sup>

C = cost driver complexity score

Cost Driver Total = C0 * C1 * C2 * ... * C14

Person-Months (intermediate) = Person-Months (basic) x Cost Driver Total

#### Project Complexity Constants
| Type | Size | A | B |
| ------------- | -------- | --- | ---- |
| Organic | Small | 3.2 | 1.05 |
| Semi-detached | Medium | 3.0 | 1.12 |
| Embedded | Complex | 2.8 | 1.20 |

#### Cost Drivers
| Cost Driver | Very Low | Low | Nominal | High | Very High | Extra High |
| ----------------------------------- | ---- | ---- | ---- | ---- | ---- | ---- |
| Required software reliability | 0.75 | 0.88 | 1.00 | 1.15 | 1.40 |
| Database size | | 0.94 | 1.00 | 1.08 | 1.16 |
| Product complexity | 0.70 | 0.85 | 1.00 | 1.15 | 1.30 | 1.65 |
| Execution time constraint | | | 1.00 | 1.11 | 1.30 | 1.66 |
| Main storage constraint | | | 1.00 | 1.06 | 1.21 | 1.56 |
| Virtual machine volatility | | 0.87 | 1.00 | 1.15 | 1.30 |
| Computer turnaround time | | 0.87 | 1.00 | 1.07 | 1.15 |
| Analyst capabilities | 1.46 | 1.19 | 1.00 | 0.86 | 0.71 |
| Applications experience | 1.29 | 1.13 | 1.00 | 0.91 | 0.82 |
| Programmer capability | 1.42 | 1.17 | 1.00 | 0.86 | 0.70 |
| Virtual machine experience | 1.21 | 1.10 | 1.00 | 0.90 |
| Programming language experience | 1.14 | 1.07 | 1.00 | 0.95 |
| Use of modern programming practices | 1.24 | 1.10 | 1.00 | 0.91 | 0.82 |
| Use of software tools | 1.24 | 1.10 | 1.00 | 0.91 | 0.83 |
| Required development schedule | 1.23 | 1.08 | 1.00 | 1.04 | 1.10 |

</details>
