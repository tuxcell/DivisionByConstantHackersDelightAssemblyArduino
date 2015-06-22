# DivisionByConstantHackersDelightAssemblyArduino
Optimized division by a constant based on code from the book "Hackers Delight"

Jose Gama June, 2015

The Arduino has library "FastDivision" for division by a constant value, however, its algorithms are based on hardware multiplication. The author created a library "HackersDelight", which is an Assembly language implementation of the algorithms from the book "Hacker's Delight 2nd ed" by Henry S. Warren, it uses bit-shifts instead of hardware multiplication, being compatible with all AVR® chips, although slower than "FastDivision".
Both "FastDivision" and "HackersDelight" are faster than using the division operator.


Reference:

Henry S. Warren, 2012
Hacker's Delight 2nd ed
Addison-Wesley Professional
