#ifndef MANAGE_BORROW_H_
#define MANAGE_BORROW_H_

#include "borrow.h"

// Hien thi menu chinh
void menu_main_option();

// Menu lua chon kieu sap xep danh sach sach
void menu_list_book_option();

// Menu lua chon hien thi danh sach phieu muon
void menu_list_borrow_option();

// Menu lua chon tim kiem
void menu_search_option();

// Menu tim kiem sach
void menu_search_book();

// Menu tim kiem phieu muon
void menu_search_borrow();

// Menu sap xep phieu dang muon
void menu_sort_borrowing();

// Menu sap xep phieu muon da tra
void menu_sort_returned();

// Thuc hien sort theo lua chon
void sort_borrows(list<Borrow> &, string, int &, int);

// Thuc hien cac lua chon menu chinh
void main_menu();

// Tim kiem sach
void search_book();

// Tim kiem phieu muon
void search_borrow();

// Thuc hien chuc nang tim kiem
void search_option();

// Thuc hien lua chon menu danh sach phieu muon
void display_borrowed_option();

// Xuat danh sach phieu dang muon
void display_borrowing_list(list<Borrow>);

// Xuat danh sach phieu da tra
void display_returned_list(list<Borrow>);

/*---------------------------------------------------------------------------//
// Phan chuc nang so sanh de sap xep danh sach
// Da duoc thay the bang chuc nang sap xep theo nhieu kieu
//---------------------------------------------------------------------------//
// So sanh tieu de sach
bool compare_title(Book, Book);

// So sanh nam xuat ban
bool compare_year(Book, Book);

// So sanh nha xuat ban
bool compare_publisher(Book, Book);

// So sanh ten tac gia
bool compare_author(Book, Book);

// So sanh ngay muon sach
bool compare_day_borrowed(Borrow, Borrow);

// So sanh ten nguoi muon
bool compare_person_name(Borrow, Borrow);

// So sanh ngay tra
bool compare_day_returned(Borrow, Borrow);
//---------------------------------------------------------------------------*/

// Xoa man hinh
void clear_screen();

// Thay doi so luong sach sau khi tao phieu muon hoac tra sach
void change_amount(list<Book> &, string, int);

// Thay doi noi dung phieu muon khi tra sach thanh cong
void change_borrow(list<Borrow> &, Borrow &);

// Nhap thong tin sach/phieu muon
template <typename container, typename T>
void input_info(container &, string, T &);

// Ghi thong tin sach/phieu muon vua nhap vao file BOOK_FILE/BORROW_FILE
template <typename container>
void write_info_to_file(container, string);

// Ghi sanh sach thong tin sach/phieu muon tu container vao file
template <typename container, typename iterator>
void write_list_to_file(container, string);

// Doc danh sach sach/phieu muon tu file
// Luu vao contain
template <typename container, typename T>
void read_list_from_file(container &, string);

// Hoan doi
template <typename It, typename Obj>
void my_swap(It, It);

// Sap xep noi bot - Bubble sort
// Sap xep danh sach sach theo ten sach
void bubble_sort(list<Book> &);

// Sap xep chon - Selection sort
// Sap xep danh sach sach theo nam xuat ban
// Sap xep danh sach phieu muon theo ngay muon
template <typename T, typename It, typename Obj>
void selection_sort(T &);

// Sap xep chen - Insertion sort
// Sap xep danh sach sach theo nha xuat ban
template <typename T, typename It, typename Obj>
void insertion_sort(T &);

// Tron 2 phan thanh mot container duoc sap xep
template <typename T, typename It>
void merge(T &, It, It, It);

// Sap xep tron - Merge sort
// Sap xep danh sach sach theo tac gia
// Sap xep danh sach phieu muon theo ten nguoi muon
template <typename T, typename It>
void merge_sort(T &, It, It);

// Sap xep nhanh - Quick sort
// Sap xep danh sach phieu muon da tra theo ngay tra
template <typename It, typename Obj>
void quick_sort(It, It, int, int);

#endif // MANAGE_BORROW_H_