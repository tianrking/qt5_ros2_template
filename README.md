## SET UP ENV
source /opt/ros/humble/setup.bash

## Build
mkdir build
cd build
cmake ..
make

## RUN 
./my_executable
