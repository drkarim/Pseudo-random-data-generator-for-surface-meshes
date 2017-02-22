# Random scalars for VTK mesh 

This program assigns a random scalar value between t1 and t2 to a VTK mesh. 

## Usage 
The usage is through command line: 
```
RandomScalar <input_VTK> <output_VTK> <t1> <t2> <divider>
```

## Parameters

The first two parameters ```t1``` and ```t2``` is the range of numbers for the random number generation. Note ```t1 < t2```. 

the ```divider``` is the divisor which should be set to ```1``` when whole random numbers are desired. Otherwise set it to ```10``` or ```100``` for fractions. 

For example, ```t1=0``` and ```t2=70```and ```divider=10``` where random numbers between ```1.0``` and ```7.0``` will be generated. 

For random number generation, the program uses the [C++ rand()](http://www.cplusplus.com/reference/cstdlib/rand/) function. 

## Author 
```
Dr. Rashed Karim 
Department of Biomedical Engineering 
King's College London 
```
