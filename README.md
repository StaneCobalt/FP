# Time Cost Analysis

Estimates cost in time for software development using either Function Points or Intermediate COCOMO.

### Basic COCOMO

KDSI = estimated lines of code in thousands

A and B are constants given by project size.

| Type | Size | A | B |
| ------------- | -------- | --- | ---- |
| Organic | Small | 2.4 | 1.05 |
| Semi-detached | Medium | 3.0 | 1.12 |
| Embedded | Complex | 3.6 | 1.20 |

Person-Months = A x KDSI <sup>B</sup>

### Intermediate COCOMO

KDSI = estimated lines of code in thousands

A and B are constants given by project size.

| Type | Size | A | B |
| ------------- | -------- | --- | ---- |
| Organic | Small | 3.2 | 1.05 |
| Semi-detached | Medium | 3.0 | 1.12 |
| Embedded | Complex | 2.8 | 1.20 |

Person-Months (basic) = A x KDSI <sup>B</sup>

Person-Months (intermediate) = Person-Months (basic) x Cost Drivers
