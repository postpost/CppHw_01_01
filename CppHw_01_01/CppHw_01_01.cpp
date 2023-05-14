#include <iostream>
#include <fstream>

void read_array(int* array, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::ifstream rf("../in.txt"); //create input file

    // Create vars for arrays size:
    int n =0, m=0;

   //Read size for the first array 
    if (rf.is_open()) {
        rf >> n;
    }
    else {
        std::cout << "File cannot be open" << std::endl;
    }
        
    int* array_01 = new int[n]; //create first dynamic array

    //Fill first array from the file data
    for (int i = 0; i < n; i++) {
        rf >> array_01[i];
    }

    //Read size for the second array 
        rf >> m;
    //Create second dynamic array
        int* array_02 = new int[m];

        for (int i = 0; i < m; i++) {
            rf >> array_02[i];
        }
        rf.close();

    //Read arrays
       // read_array(array_01, n);
       // read_array(array_02, m);

    //Write array to out.txt
        std::ofstream wf("out.txt", std::ios::out);

    //Write 2nd array to out.txt
        wf << m << std::endl;

        int* temp_array02 = new int[m];

        for (int j = 1; j < m; ++j) {
            if (j == m - 1) {
                temp_array02[0] = array_02[m - 1];
            }
                temp_array02[j] = array_02[j-1];         
        }

        //Write 2nd array to the file
        for (int i = 0; i < m; ++i) {
            wf << temp_array02[i] << " ";
        }

        wf << std::endl;

        //Write 1st array
        wf << n << std:: endl; //write size of the 2nd array

        int* temp_array01 = new int[n]; //create 1st temp array
       
        for (int j = 1; j < n; ++j) {     
            temp_array01[j-1] = array_01[j];
        }
        temp_array01[n - 1] = array_01[0];
        

        //Write 1st array to the file
        for (int i = 0; i < n; ++i) {
            wf << temp_array01[i] << " ";
        }

        wf << std::endl;
             
        wf.close();

    //Clear memory 
    delete[] array_01;
    delete[] array_02;
    delete[] temp_array02;
    delete[] temp_array01;
}
