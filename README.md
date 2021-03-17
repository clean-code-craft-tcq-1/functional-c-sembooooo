# Programming Paradigms

Electric Vehicles have BMS - Battery Management Systems

[Here is an article that helps to understand the need for BMS](https://circuitdigest.com/article/battery-management-system-bms-for-electric-vehicles)

[Wikipedia gives an idea of the types and topologies](https://en.wikipedia.org/wiki/Battery_management_system)

[This site gives the optimum Charging-temperature limits](https://batteryuniversity.com/learn/article/charging_at_high_and_low_temperatures)

[This abstract suggests a range for the optimum State of Charge](https://www.sciencedirect.com/science/article/pii/S2352484719310911)

[Here is a reference for the maximum charge rate](https://www.electronics-notes.com/articles/electronic_components/battery-technology/li-ion-lithium-ion-charging.php#:~:text=Constant%20current%20charge:%20In%20the%20first%20stage%20of,rate%20of%20a%20maximum%20of%200.8C%20is%20recommended.)

## Possible purpose

- Protect batteries while charging:
at home, in public place, within vehicle / regenerative braking
- Estimate life, inventory and supply chains

## The Starting Point

We will explore the charging phase of Li-ion batteries to start with.

## Issues

- The code here has high complexity in a single function.
- The tests are not complete - they do not cover all the needs of a consumer

## Tasks

1. Reduce the cyclomatic complexity.
1. Separate pure functions from I/O
1. Avoid duplication - functions that do nearly the same thing
1. Complete the tests - cover all conditions.
1. To take effective action, we need to know
the abnormal measure and the breach -
whether high or low. Add this capability.

## The Exploration

How well does our code hold-out in the rapidly evolving EV space?
Can we add new functionality without disturbing the old?

## The Landscape

- Limits may change based on new research
- Technology changes due to obsolescence
- Sensors may be from different vendors with different accuracy
- Predicting the future requires Astrology!

## Keep it Simple

Shorten the Semantic distance

- Procedural to express sequence
- Functional to express relation between input and output
- Object oriented to encapsulate state with actions
- Apect oriented to capture repeating aspects

## Assignment solution details
less time hence brief readme 
modularized code into the following units
1. BatteryHealthMonitoring - successor of checker.c
2. ChargeRateMonitoring 
3. FailureHandling  - contains Failure logging. For now its console. As mentioned in the 
                comments if its text to speech then we need not use a different function.
                changing one function should do it.
4. LimitedRangeParameterMonitoring - For temparature and state of charge as their values
                                    can only be with in a range.
                                    
6. MathUtil
7. Config/ParameterConfig - To configure limits. There is a chance to play with limits. 
                            can only be tested with UT as preprocessor cannot handle floats.
                            or else #if and #error would have been sufficient.

Every module contains a controldata struct which contains the following
<Took the name from my regular practice but there can be a better name for this>
1. Identifier in string which is name of the parameter under monitoring
2. thresholds (higher and lower)
3. Failure type

### What new this time ?
I tried to create a test environment and execution environment.
In the test environment only testing of a unit happens.
For this line in the assignment- "Test the accumulator and reporter separately." - i have created 
another unit console which capsulates printf.
During my test i have a stub function to the function which capsulates printf to test.
In the execution environment the src code with dummy controller runs.
Workflows were only added but not modified.

















