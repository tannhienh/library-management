#ifndef MANAGE_BORROW_H_
#define MANAGE_BORROW_H_

#include "borrow.h"

// Hien thi menu chinh
void menu_main_option();

// Menu lua chon kieu sap xep danh sach sach
void menu_list_book_option();

// Menu lua chon hien thi danh sach phieu muon
void menu_list_borrow_option();

// Menu lua chon tim kiem sach/phieu muon
void menu_search_option();

// Menu lua chon tim kiem sach
void menu_search_book();

// Menu lua chon tim kiem phieu muon
void menu_search_borrow();

// Menu lua chon sap xep phieu dang muon
void menu_sort_borrowing();

// Menu lua chon sap xep phieu muon da tra
void menu_sort_returned();

// Xu ly lua chon menu chinh
void main_menu();

// Thuc hien chuc nang tim kiem
void search_option();

// Tim kiem sach
void search_book(list<Book> &);

// Tim kiem phieu muon
void search_borrow(list<Borrow> &);

// Thuc hien sap xep theo lua chon
void sort_borrows(list<Borrow> &, string, int &, int);

// Thuc hien lua chon menu danh sach phieu muon
void display_borrowed_option();

// Xuat danh sach phieu dang muon
void display_borrowing_list(list<Borrow>);

// Xuat danh sach phieu da tra
void display_returned_list(list<Borrow>);

// Thay doi so luong sach sau khi tao phieu muon hoac tra sach
void change_amount(list<Book> &, string, int);

// Thay doi noi dung phieu muon khi tra sach thanh cong
void change_borrow(list<Borrow> &, Borrow &);

// Nhap thong tin sach/phieu muon
template <class Container, class Obj>
void input_info(Container &, string);

// Ghi thong tin sach/phieu muon vua nhap vao file
template <class Container>
void write_info_to_file(Container, string);

// Ghi sanh sach thong tin sach/phieu muon tu container vao file
template <class Container, class It>
void write_list_to_file(Container, string);

// Doc danh sach sach/phieu muon tu file
// Luu vao contain
template <class Container, class Obj>
void read_list_from_file(Container &, string);

// Hien thi danh sach sach
template <class Container, class It, class Obj>
void display_list(Container);

// Xuat danh sach phieu muon
void display_borrow_list(list<Borrow>, string);

// Hoan doi
template <class It, class Obj>
void my_swap(It, It);

// Sap xep noi bot - Bubble sort
template <class Container, class It, class Obj, class Mem_func>
void bubble_sort(Container &, Mem_func);

// Sap xep chon - Selection sort
template <class Container, class It, class Obj, class Mem_func>
void selection_sort(Container &, Mem_func);

// Sap xep chen - Insertion sort
template <class Container, class It, class Obj, class Mem_func>
void insertion_sort(Container &, Mem_func);

// Tron 2 phan thanh mot container duoc sap xep
template <class Container, class It, class Mem_func>
void merge(Container &, It, It, It, Mem_func);

// Sap xep tron - Merge sort
template <class Container, class It, class Mem_func>
void merge_sort(Container &, It, It, Mem_func);

// Sap xep nhanh - Quick sort
template <class It, class Obj, class Mem_func>
void quick_sort(It, It, int, int, Mem_func);

// Tim kiem tuyen tinh - Linear search
template <class Container, class It, class Key, class Mem_func>
void linear_search(Container, Key, Container &, Mem_func);

// Tim kiem nhi phan - Binary search
template <class Container, class It, class Key, class Mem_func>
void binary_search(Container, Key, Container &, Mem_func);

// Xoa man hinh
void clear_screen();

#endif // MANAGE_BORROW_H_