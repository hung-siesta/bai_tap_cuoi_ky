//THAO TAC ANH VOI DLIB : Fasle
#include <iostream>
// --- THAY DOI O DAY ---
// Khong dung image_io.h nua vi no doi hoi PNG/JPEG
// #include <dlib/image_io.h> 

// Chi dung thu vien ho tro BMP (khong can cai them gi ca)
#include <dlib/image_loader/load_bmp.h>
#include <dlib/image_saver/save_bmp.h>
// ----------------------

#include <dlib/image_transforms.h> 

using namespace std;
using namespace dlib;

int main() {
    cout << "=== THAO TAC ANH VOI DLIB (BMP ONLY) ===" << endl;

    try {
        array2d<rgb_pixel> img;

        // 2. Load anh
        // Luu y: Doi ham load_image -> load_bmp
        load_bmp(img, "test.bmp"); 
        
        cout << "Kich thuoc anh goc: " << img.nr() << "x" << img.nc() << endl;

        // --- PHAN RESIZE ---
        array2d<rgb_pixel> img_small;
        
        long new_rows = img.nr() * 0.5;
        long new_cols = img.nc() * 0.5;

        img_small.set_size(new_rows, new_cols);
        resize_image(img, img_small); 
        
        cout << "Kich thuoc sau resize: " << img_small.nr() << "x" << img_small.nc() << endl;

        // --- PHAN CROP ---
        array2d<rgb_pixel> img_crop;
        img_crop.set_size(100, 100); 
        
        for(long r=0; r<100; ++r) {
            for(long c=0; c<100; ++c) {
                if(r < img.nr() && c < img.nc()) {
                    img_crop[r][c] = img[r][c];
                }
            }
        }

        // 3. Luu anh
        save_bmp(img_small, "ket_qua_resize.bmp");
        save_bmp(img_crop, "ket_qua_crop.bmp");
        
        cout << "Thanh cong! Kiem tra file ket qua." << endl;

    } catch (exception& e) {
        cout << "Loi: " << e.what() << endl;
        cout << "Hay dam bao ban co file 'test.bmp' (dinh dang BMP chuan)!" << endl;
    }

    return 0;
}