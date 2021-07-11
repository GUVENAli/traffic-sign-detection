#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;
using namespace cv;

int main()
{
    const char *signs[20] = {"30_SIGN", "50_SIGN", "60_SIGN", "70_SIGN", "80_SIGN", "90_SIGN", "100_SIGN", "110_SIGN", "120_SIGN", "GIVE_WAY",
                            "NO_PARKING", "NO_STOPPING_NO_STANDING", "OTHER", "PASS_EITHER_SIDE", "PASS_LEFT_SIDE", "PASS_RIGHT_SIDE",
                            "PEDESTRIAN_CROSSING", "PRIORITY_ROAD", "STOP", "URDBL"};
    int sign_num[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    CascadeClassifier cascade;
    vector<int> rej1;
    vector<int> rej2;
    vector<int> rej3;
    vector<int> rej4;
    vector<int> rej5;
    vector<int> rej6;
    vector<int> rej7;
    vector<int> rej8;
    vector<int> rej9;
    vector<int> rej10;
    vector<int> rej11;
    vector<int> rej12;
    vector<int> rej13;
    vector<int> rej14;
    vector<int> rej15;
    vector<int> rej16;
    vector<int> rej17;
    vector<int> rej18;
    vector<int> rej19;
    vector<int> rej20;

    vector<Rect> vec1;
    vector<Rect> vec2;
    vector<Rect> vec3;
    vector<Rect> vec4;
    vector<Rect> vec5;
    vector<Rect> vec6;
    vector<Rect> vec7;
    vector<Rect> vec8;
    vector<Rect> vec9;
    vector<Rect> vec10;
    vector<Rect> vec11;
    vector<Rect> vec12;
    vector<Rect> vec13;
    vector<Rect> vec14;
    vector<Rect> vec15;
    vector<Rect> vec16;
    vector<Rect> vec17;
    vector<Rect> vec18;
    vector<Rect> vec19;
    vector<Rect> vec20;

    double scale = 1.1;
    int minN = 2;
    string path = "annotations_test.txt";
    ifstream myFile;
    string STRING, IMAGE_NAME, IMG_PATH;
    myFile.open(path.c_str());
    while (!myFile.eof())
    {
        getline(myFile, STRING);
        IMAGE_NAME = STRING.substr(0, STRING.find(":"));

        IMG_PATH = "Set2Part0/" + IMAGE_NAME;

        Mat img = imread(IMG_PATH.c_str());

        cascade.load("cascades/cascade_30.xml");
        cascade.detectMultiScale(img, vec1, rej1, scale, minN);
        if (vec1.size() > 0)
        {
            sign_num [0] = 1;
        }

        cascade.load("cascades/cascade_50.xml");
        cascade.detectMultiScale(img, vec2, rej2, scale, minN);
        if (vec2.size() > 0)
        {
            sign_num [1] = 1;
        }

        cascade.load("cascades/cascade_60.xml");
        cascade.detectMultiScale(img, vec3, rej3, scale, minN);
        if (vec3.size() > 0)
        {
            sign_num [2] = 1;
        }

        cascade.load("cascades/cascade_70.xml");
        cascade.detectMultiScale(img, vec4, rej4, scale, minN);
        if (vec4.size() > 0)
        {
            sign_num [3] = 1;
        }

        cascade.load("cascades/cascade_80.xml");
        cascade.detectMultiScale(img, vec5, rej5, scale, minN);
        if (vec5.size() > 0)
        {
            sign_num [4] = 1;
        }

        cascade.load("cascades/cascade_90.xml");
        cascade.detectMultiScale(img, vec6, rej6, scale, minN);
        if (vec6.size() > 0)
        {
            sign_num [5] = 1;
        }

        cascade.load("cascades/cascade_100.xml");
        cascade.detectMultiScale(img, vec7, rej7, scale, minN);
        if (vec7.size() > 0)
        {
            sign_num [6] = 1;
        }

        cascade.load("cascades/cascade_110.xml");
        cascade.detectMultiScale(img, vec8, rej8, scale, minN);
        if (vec8.size() > 0)
        {
            sign_num [7] = 1;
        }

        cascade.load("cascades/cascade_120.xml");
        cascade.detectMultiScale(img, vec9, rej9, scale, minN);
        if (vec9.size() > 0)
        {
            sign_num [8] = 1;
        }

        cascade.load("cascades/cascade_give_way.xml");
        cascade.detectMultiScale(img, vec10, rej10, scale, minN);
        if (vec10.size() > 0)
        {
            sign_num [9] = 1;
        }

        cascade.load("cascades/cascade_no_parking.xml");
        cascade.detectMultiScale(img, vec11, rej11, scale, minN);
        if (vec11.size() > 0)
        {
            sign_num [10] = 1;
        }

        cascade.load("cascades/cascade_no_stopping_no_standing.xml");
        cascade.detectMultiScale(img, vec12, rej12, scale, minN);
        if (vec12.size() > 0)
        {
            sign_num [11] = 1;
        }

        cascade.load("cascades/cascade_pass_either_side.xml");
        cascade.detectMultiScale(img, vec14, rej14, scale, minN);
        if (vec14.size() > 0)
        {
            sign_num [13] = 1;
        }

        cascade.load("cascades/cascade_pass_left_side.xml");
        cascade.detectMultiScale(img, vec15, rej15, scale, minN);
        if (vec15.size() > 0)
        {
            sign_num [14] = 1;
        }

        cascade.load("cascades/cascade_pass_right_side.xml");
        cascade.detectMultiScale(img, vec16, rej16, scale, minN);
        if (vec16.size() > 0)
        {
            sign_num [15] = 1;
        }

        cascade.load("cascades/cascade_pedestrian_crossing.xml");
        cascade.detectMultiScale(img, vec17, rej17, scale, minN);
        if (vec17.size() > 0)
        {
            sign_num [16] = 1;
        }

        cascade.load("cascades/cascade_priority_road.xml");
        cascade.detectMultiScale(img, vec18, rej18, scale, minN);
        if (vec18.size() > 0)
        {
            sign_num [17] = 1;
        }

        cascade.load("cascades/cascade_stop.xml");
        cascade.detectMultiScale(img, vec19, rej19, scale, minN);
        if (vec19.size() > 0)
        {
            sign_num [18] = 1;
        }

        cascade.load("cascades/cascade_urdbl.xml");
        cascade.detectMultiScale(img, vec20, rej20, scale, minN);
        if (vec20.size() > 0)
        {
            sign_num [19] = 1;
        }

        for(size_t j = 0; j < size(sign_num); j++)
        {
            if (sign_num[j] == 1)
            {
                if (j == 0)
                {
                    for( size_t i = 0; i < vec1.size(); i++ )
                    {
                        rectangle(img, vec1[i], Scalar(255, 0, 0), 3, 1, 0);
                        putText(img, signs[j], Point(vec1[i].x, vec1[i].y), FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(255, 0, 0), 2);
                    }
                }
                else if (j == 1)
                {
                    for( size_t i = 0; i < vec2.size(); i++ )
                    {
                        rectangle(img, vec2[i], Scalar(255, 0, 0), 3, 1, 0);
                        putText(img, signs[j], Point(vec2[i].x, vec2[i].y), FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(255, 0, 0), 2);
                    }
                }
                else if (j == 2)
                {
                    for( size_t i = 0; i < vec3.size(); i++ )
                    {
                        rectangle(img, vec3[i], Scalar(255, 0, 0), 3, 1, 0);
                        putText(img, signs[j], Point(vec3[i].x, vec3[i].y), FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(255, 0, 0), 2);
                    }
                }
                else if (j == 3)
                {
                    for( size_t i = 0; i < vec4.size(); i++ )
                    {
                        rectangle(img, vec4[i], Scalar(255, 0, 0), 3, 1, 0);
                        putText(img, signs[j], Point(vec4[i].x, vec4[i].y), FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(255, 0, 0), 2);
                    }
                }
                else if (j == 4)
                {
                    for( size_t i = 0; i < vec4.size(); i++ )
                    {
                        rectangle(img, vec4[i], Scalar(255, 0, 0), 3, 1, 0);
                        putText(img, signs[j], Point(vec4[i].x, vec4[i].y), FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(255, 0, 0), 2);
                    }
                }
                else if (j == 5)
                {
                    for( size_t i = 0; i < vec6.size(); i++ )
                    {
                        rectangle(img, vec6[i], Scalar(255, 0, 0), 3, 1, 0);
                        putText(img, signs[j], Point(vec6[i].x, vec6[i].y), FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(255, 0, 0), 2);
                    }
                }
                else if (j == 6)
                {
                    for( size_t i = 0; i < vec7.size(); i++ )
                    {
                        rectangle(img, vec7[i], Scalar(255, 0, 0), 3, 1, 0);
                        putText(img, signs[j], Point(vec7[i].x, vec7[i].y), FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(255, 0, 0), 2);
                    }
                }
                else if (j == 7)
                {
                    for( size_t i = 0; i < vec8.size(); i++ )
                    {
                        rectangle(img, vec8[i], Scalar(255, 0, 0), 3, 1, 0);
                        putText(img, signs[j], Point(vec8[i].x, vec8[i].y), FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(255, 0, 0), 2);
                    }
                }
                else if (j == 8)
                {
                    for( size_t i = 0; i < vec9.size(); i++ )
                    {
                        rectangle(img, vec9[i], Scalar(255, 0, 0), 3, 1, 0);
                        putText(img, signs[j], Point(vec9[i].x, vec9[i].y), FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(255, 0, 0), 2);
                    }
                }
                else if (j == 9)
                {
                    for( size_t i = 0; i < vec10.size(); i++ )
                    {
                        rectangle(img, vec10[i], Scalar(255, 0, 0), 3, 1, 0);
                        putText(img, signs[j], Point(vec10[i].x, vec10[i].y), FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(255, 0, 0), 2);
                    }
                }
                else if (j == 10)
                {
                    for( size_t i = 0; i < vec11.size(); i++ )
                    {
                        rectangle(img, vec11[i], Scalar(255, 0, 0), 3, 1, 0);
                        putText(img, signs[j], Point(vec11[i].x, vec11[i].y), FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(255, 0, 0), 2);
                    }
                }
                else if (j == 11)
                {
                    for( size_t i = 0; i < vec12.size(); i++ )
                    {
                        rectangle(img, vec12[i], Scalar(255, 0, 0), 3, 1, 0);
                        putText(img, signs[j], Point(vec12[i].x, vec12[i].y), FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(255, 0, 0), 2);
                    }
                }

                else if (j == 13)
                {
                    for( size_t i = 0; i < vec14.size(); i++ )
                    {
                        rectangle(img, vec14[i], Scalar(255, 0, 0), 3, 1, 0);
                        putText(img, signs[j], Point(vec14[i].x, vec14[i].y), FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(255, 0, 0), 2);
                    }
                }
                else if (j == 14)
                {
                    for( size_t i = 0; i < vec15.size(); i++ )
                    {
                        rectangle(img, vec15[i], Scalar(255, 0, 0), 3, 1, 0);
                        putText(img, signs[j], Point(vec15[i].x, vec15[i].y), FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(255, 0, 0), 2);
                    }
                }
                else if (j == 15)
                {
                    for( size_t i = 0; i < vec16.size(); i++ )
                    {
                        rectangle(img, vec16[i], Scalar(255, 0, 0), 3, 1, 0);
                        putText(img, signs[j], Point(vec16[i].x, vec16[i].y), FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(255, 0, 0), 2);
                    }
                }
                else if (j == 16)
                {
                    for( size_t i = 0; i < vec17.size(); i++ )
                    {
                        rectangle(img, vec17[i], Scalar(255, 0, 0), 3, 1, 0);
                        putText(img, signs[j], Point(vec17[i].x, vec17[i].y), FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(255, 0, 0), 2);
                    }
                }
                else if (j == 17)
                {
                    for( size_t i = 0; i < vec18.size(); i++ )
                    {
                        rectangle(img, vec18[i], Scalar(255, 0, 0), 3, 1, 0);
                        putText(img, signs[j], Point(vec18[i].x, vec18[i].y), FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(255, 0, 0), 2);
                    }
                }
                else if (j == 18)
                {
                    for( size_t i = 0; i < vec19.size(); i++ )
                    {
                        rectangle(img, vec19[i], Scalar(255, 0, 0), 3, 1, 0);
                        putText(img, signs[j], Point(vec19[i].x, vec19[i].y), FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(255, 0, 0), 2);
                    }
                }
                else if (j == 19)
                {
                    for( size_t i = 0; i < vec20.size(); i++ )
                    {
                        rectangle(img, vec20[i], Scalar(255, 0, 0), 3, 1, 0);
                        putText(img, signs[j], Point(vec20[i].x, vec20[i].y), FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(255, 0, 0), 2);
                    }
                }

            }
        }


        resize(img, img, Size(640,480));
        imshow("Webcam", img);
        waitKey(0);
    }
    myFile.close();
    return 0;
}
