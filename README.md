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
3. FailureHandling  - contains Failure logging on console. 
4. StateOfChargeMonitoring
5. TemparatureMonitoring
6. MathUtil
7. Config/ParameterConfig - To configure limits. There is a chance to play with limits. 
                            can only be tested with UT as preprocessor cannot handle floats.
                            or else #if and #error would have been sufficient.

Every module contains a controldata struct which contains the following
<Took the name from my regular practice but there can be a better name for this>
1. Identifier in string which is name of the parameter under monitoring
2. thresholds (higher and lower)
3. Failure type

### Things done:
- Added case specific failure logging.
- Limits may change based on new research -- So thought of adding configurable parameters.

### My answers to some interesting questions
The answers are only based on my experience so i am not sure if these are correct answers or not.
- Can we add new functionality without disturbing the old? :
 We can try but no gaurantee. But one thing what we can do is to write a function closer to a pure function and then the amount of changes we get because of a feature addition or deletion
 may be less.

- Predicting the future requires Astrology! : I sometimes feel the same lol.
    There can be times where some part of legacy code needs to be reworked because of one weird feature which we would never thought about. - rare case
    But if the component is new, the design or the architecture of the component can be made flexibile enough so it can be extended to new features rather than modifying it.
    In this case too we can give a try but thinking extensivly then gain it requires astrology.
    <It sounds like a good idea to document birth time, birth place and other details of a feature >

    










