# This is a simple python binding of [Stag Fiducial Marker System](https://github.com/bbenligiray/stag)

# Dependency

1. **numpy** `pip install numpy`
2. **cmake**
3. **Pybind11** `pip install pybind11`


# Usage

1. clone this repository

2. Find out your `numpy include` Path 	

   ```python
   In [1]: import numpy
   In [2]: numpy.get_include()
   Out[2]: '/Users/bytedance/anaconda3/lib/python3.8/site-packages/numpy/core/include'
   ```

3. Fill `numpy include` to `CmakeLists.txt`

   ```cmake
   include_directories(
       pybindSrc/opencv2numpy
       # You need to change this follow Path  to  your own Path. 
       # "# You need to change this follow Path  to  your own Path. "
       # "# You need to change this follow Path  to  your own Path. "
       # "# You need to change this follow Path  to  your own Path. "
       # "# You need to change this follow Path  to  your own Path. "
       
       /Users/bytedance/anaconda3/lib/python3.8/site-packages/numpy/core/include
   )
   ```

   

4. make

   ```shell
   mkdir build 
   cmake ..
   make
   ```

   

5. then you will got a `pyStag.cpython-3*-**.so`  in `./lib`

6. **install Python package**

   ```
   python setup.py install 
   ```

#  Test

```python
python test_warpper.py
```





# PS.

Now, this is  just a prototype for warpping Stag system. It has only few attributes and interfaces, and function, And I will add some more in the future.

thank to [edmBernard](https://github.com/edmBernard)'s work https://github.com/edmBernard/pybind11_opencv_numpy, let the conversion between numpy and cv::Mat works fine.












# STag: A Stable Fiducial Marker System

Code used in the following paper:

[B. Benligiray; C. Topal; C. Akinlar, "STag: A Stable Fiducial Marker System," Image and Vision Computing (Accepted), 2019.](https://arxiv.org/abs/1707.06292)

Markers (see `ref/marker generator` for reference code for marker generation):

https://drive.google.com/drive/folders/0ByNTNYCAhWbIV1RqdU9vRnd2Vnc

### ROS Package

- [STag ROS: A ROS package for the Stable Fiducial Marker System](https://github.com/usrl-uofsc/stag_ros/) by Unmanned Systems & Robotics Lab - UofSC

- [ROS wrapper for STag](https://github.com/dartmouthrobotics/stag_ros) by Dartmouth Reality and Robotics Lab

[![Supplementary Video](https://user-images.githubusercontent.com/19530665/57184379-6a250580-6ec3-11e9-8ab3-7e139966f13b.png)](https://www.youtube.com/watch?v=vnHI3GzLVrY) 

Some figures from the paper:

<p align="center">
  <img src="https://user-images.githubusercontent.com/19530665/57179654-c0c11e00-6e88-11e9-9ca5-0c0153b28c91.png"/>
</p>

<p align="center">
  <img src="https://user-images.githubusercontent.com/19530665/57179660-cae31c80-6e88-11e9-8f80-bf8e24e59957.png"/>
</p>
