#define HAS_VTK 1
#define _IS_DEBUG 1

#include "vtkPointData.h"
#include <vtkPointPicker.h>
#include <vtkPolyDataMapper.h>
#include <vtkPolyDataReader.h>
#include <vtkLookupTable.h>
#include <vtkProperty.h>
#include <vtkSmartPointer.h>
#include <vtkPolyDataWriter.h>
#include <vtkCellData.h>
#include <vtkPolyDataReader.h>
#include <vtkFloatArray.h>
#include <vtkPolyData.h>

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

// for random number generation 
#include <time.h>
#include <stdlib.h>


using namespace std;


  
/*
*   Reads scalars from a polydata shell  
*/
void RandomScalars(char* poly_fn, char* poly_out_fn, int t1, int t2, int divider)
{

    double min=1e9, max=-1;
    vtkSmartPointer<vtkPolyData> surface =vtkSmartPointer<vtkPolyData>::New();  
    vtkSmartPointer<vtkPolyDataReader> reader = vtkSmartPointer<vtkPolyDataReader>::New(); 
    reader->SetFileName(poly_fn); 
    reader->Update();
    
    surface = reader->GetOutput();
    
    vtkSmartPointer<vtkFloatArray> scalars = vtkSmartPointer<vtkFloatArray>::New();
    scalars = vtkFloatArray::SafeDownCast(surface->GetPointData()->GetScalars());  
    double count = 0;

    vtkSmartPointer<vtkFloatArray> scalars_out = vtkSmartPointer<vtkFloatArray>::New();

    
    for (int k=0;k<surface->GetNumberOfPoints();k++)
    {

      double rand_scalar = rand() % t2 + t1;
       rand_scalar = (double)rand_scalar/(double)divider;
      cout << rand_scalar << ", ";
      scalars_out->InsertNextTuple1(rand_scalar);
      
      
    }
    
    surface->GetPointData()->SetScalars(scalars_out); 
    
    vtkSmartPointer<vtkPolyDataWriter> writer = vtkSmartPointer<vtkPolyDataWriter>::New(); 
    writer->SetInputData(surface);
    writer->SetFileName(poly_out_fn); 
    writer->Update();
    
  
  // Some debug to output the range of scalars
  //cout << "Min scalar = " << min << "\nMax scalar = " << max << endl;
}

int main(int argc, char **argv)
{
  
  bool write_to_file = false; 
  vector<double> scalar;
  char* poly_fn, *poly_out_fn;
  char* out_fn;  
  
  int t1, t2, t3;
  
  if (argc < 4)
  {
     cerr << "Not enough parameters\nUsage: <file_in.vtk> <file_out.vtk> <t1 - from> <t2 - to> <t3 - divider>"<< endl; 
     exit(1);
  }
 
  poly_fn = argv[1];
  poly_out_fn = argv[2];
  t1 = atoi(argv[3]);
  t2 = atoi(argv[4]);
  t3 = atoi(argv[5]);
  //t2 = atof(argv[3]);
   
  // Set random seed
  srand (time(NULL));


	RandomScalars( poly_fn,poly_out_fn,t1, t2, t3);
  
  
}