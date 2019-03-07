# Time Cost Analysis

Estimates cost in time for software development using either Function Points or Intermediate COCOMO.

### Intermediate COCOMO

KDSI = estimated lines of code in thousands

A and B are constants given by project size.

| Type | Size | A | B |
| ------------- | -------- | --- | ---- |
| Organic | Small | 3.2 | 1.05 |
| Semi-detached | Medium | 3.0 | 1.12 |
| Embedded | Complex | 2.8 | 1.20 |


Person-Months (unrefined) = A x KDSI <sup>B</sup>

Person-Months (refined) = Person-Months (unrefined) x Cost Drivers
