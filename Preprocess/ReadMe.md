# Download Data
Data can be found in the url below \
http://www.cvl.isy.liu.se/en/research/datasets/traffic-signs-dataset/download/ 

# Training - Test Split
There are two different sets with the annotations in the download url. \
Set1Part0 was used for training. \
Set2Part0 was used for test. 

# Opencv Haar Object Detection Cascade Model Format
The format must be like that \
{image path} {object number in the} {object1 upper corner x coordinate} {object1 upper corner y coordinate} {object1 width} {object1 height} ...

# Opencv Background Work
Opencv uses two subsets for training which are negative samples and positive samples. 
* Negative samples contain no object/objects. 
* Positive samples include one or more objects.

# Obtaining Different Positive Samples from positiveSamples.cpp Code
Just change **_temp_** variable in the posList method in the code.

# Assumptions
* Set1Part0 or the folder that contains training images must be in same directory of the code.
* Named **_neg_** and **_pos_** folders must be created in the directory.
