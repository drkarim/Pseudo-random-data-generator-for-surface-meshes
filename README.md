# Random scalars for VTK mesh 

This program assigns a random scalar value between t1 and t2 to a VTK mesh. 

## Usage 
The usage is through command line: 
```
RandomScalar <input_VTK> <output_VTK> <t1> <t2> <divider>
```

## Parameters

The first two parameters ```t1``` and ```t2``` is the range of numbers for the random number generation. Note ```t1 < t2```. 

the ```divider``` is divisor which should be set to ```1``` unless random fractions are desired

For random number generation, the program uses the [C++ rand()](http://www.cplusplus.com/reference/cstdlib/rand/) function. 

## Author 
```
Dr. Rashed Karim 
Department of Biomedical Engineering 
King's College London 
```
