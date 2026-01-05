//THAO TAC ANH VOI DLIB: fasle
#include <iostream>
#include <dlib/image_io.h>        // De doc/ghi anh
#include <dlib/image_transforms.h> // De cat/resize anh

using namespace std;
using namespace dlib;

int main() {
    cout << "=== THAO TAC ANH VOI DLIB  ===" << endl;

    try {
        // 1. Khai bao bien chua anh
        array2d<rgb_pixel> img;

        // 2. Load anh
        // QUAN TRONG: Ban phai co file "test.bmp" nam canh file code nay
        // Neu chua co, hay mo Paint ve va luu lai duoi dang .bmp
        load_image(img, "test.bmp"); 
        
        cout << "Kich thuoc anh goc: " << img.nr() << "x" << img.nc() << endl;

        // --- PHAN SUA LOI (RESIZE) ---
        array2d<rgb_pixel> img_small;
        
        // Buoc 1: Tinh toan kich thuoc moi (Nhan voi 0.5)
        long new_rows = img.nr() * 0.5;
        long new_cols = img.nc() * 0.5;

        // Buoc 2: Thiet lap kich thuoc cho anh dich TRUOC
        img_small.set_size(new_rows, new_cols);

        // Buoc 3: Copy va co dan anh tu img sang img_small
        // Dlib se tu dong tinh toan noi suy dua tren kich thuoc cua img_small
        resize_image(img, img_small); 
        // -----------------------------
        
        cout << "Kich thuoc sau resize: " << img_small.nr() << "x" << img_small.nc() << endl;

        // 4. Cat anh (Crop)
        array2d<rgb_pixel> img_crop;
        img_crop.set_size(100, 100); 
        
        // Copy pixel thu cong (Manual crop)
        for(long r=0; r<100; ++r) {
            for(long c=0; c<100; ++c) {
                // Kiem tra bien de tranh loi neu anh goc nho hon 100x100
                if(r < img.nr() && c < img.nc()) {
                    img_crop[r][c] = img[r][c];
                }
            }
        }

        // 5. Luu anh ra file moi
        save_bmp(img_small, "ket_qua_resize.bmp");
        save_bmp(img_crop, "ket_qua_crop.bmp");
        
        cout << "Da luu file 'ket_qua_resize.bmp' va 'ket_qua_crop.bmp' thanh cong!" << endl;

    } catch (exception& e) {
        cout << "Loi: " << e.what() << endl;
        cout << "Hay dam bao ban da co file 'test.bmp' (dinh dang BMP) trong thu muc code." << endl;
    }

    return 0;
}