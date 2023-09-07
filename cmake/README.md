## How to compile & run

Compile using **cmake ..** in the **/build** folder followed by **make** in the same folder. 

Run by calling **./main** also in the **build** folder

## How to make a project like this

### Installing Eigen: 
```
sudo apt install libeigen3-dev
```
### CMake
* In the top directory of this repo
    * Make the CMakerLists.txt file like this one
    * Make the other files in this folder
    * Then do the following Bash
    ```Bash
    mkdir build
    cd build
    cmake .. # This will give you the Makefile and all the other files in the /build folder
    make # This will create your executable
    ./main # This will execute your executable  
    ```
