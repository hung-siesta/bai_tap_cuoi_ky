//Dung OpenCV de doc anh: Fasle
#include <iostream>

// 1. Include OpenCV (Xu ly anh co ban)
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

// 2. Include Dlib (Xu ly thong minh)
#include <dlib/opencv.h> // Cau noi quan trong giua OpenCV va Dlib
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/gui_widgets.h>

using namespace std;
using namespace dlib;

int main() {
    try {
        cout << "=== OPENCV + DLIB DEMO ===" << endl;

        // B1: Dung OpenCV de doc anh (hoac mo Camera: cv::VideoCapture cap(0))
        // Ban hay chuan bi san 1 file anh 'test_face.jpg'
        cv::Mat cv_img = cv::imread("test_face.jpg");

        if (cv_img.empty()) {
            cout << "Khong tim thay file anh 'test_face.jpg'!" << endl;
            return 1;
        }

        // B2: CHUYEN DOI (BRIDGE) - Tu OpenCV Mat sang Dlib Image
        // cv_image la wrapper giup Dlib hieu du lieu cua OpenCV ma khong can copy
        cv_image<bgr_pixel> dlib_img(cv_img);

        // B3: Dung Dlib de nhan dien khuon mat
        frontal_face_detector detector = get_frontal_face_detector();
        std::vector<rectangle> faces = detector(dlib_img);

        cout << "Tim thay " << faces.size() << " khuon mat." << endl;

        // B4: Ve khung chu nhat bang OpenCV
        for (auto& face : faces) {
            // Chuyen toa do tu Dlib (long) sang OpenCV (int)
            cv::Point top_left(face.left(), face.top());
            cv::Point bottom_right(face.right(), face.bottom());

            // Ve hinh chu nhat mau Xanh La (Green), do day 2
            cv::rectangle(cv_img, top_left, bottom_right, cv::Scalar(0, 255, 0), 2);
        }

        // B5: Hien thi ket qua bang OpenCV
        cv::imshow("Ket qua nhan dien", cv_img);

        // Cho nguoi dung an phim bat ky de thoat
        cv::waitKey(0); 

    } catch (exception& e) {
        cout << "Loi: " << e.what() << endl;
    }

    return 0;
}